#include "noteScheduler.h"
#include "timing.h"
#include "queue.h"
#include "audio.h"
#include "ui/ui_active.h"

#define SCHEDULER_COUNT 4

/** Queues containing scheduled notes. */
Queue schedulers[SCHEDULER_COUNT];

/**
 * Initializes all note schedulers.
 *
 * Creates an empty queue for each scheduler.
 */
void initSchedulers(void)
{
    for (int i = 0; i < SCHEDULER_COUNT; i++)
    {
        schedulers[i] = create_queue();
    }
}

/**
 * Enqueues a note for playback.
 *
 * The note is scheduled immediately after the last note currently
 * in the specified scheduler.
 *
 * @param schedId Scheduler identifier.
 * @param note Note to schedule.
 * @param length Duration of the note in beats.
 * @return true if the note was successfully enqueued; otherwise false.
 */
bool enqueueNote(int schedId, Note note, double length)
{
    Queue *q = &schedulers[schedId];
    ScheduledNote lastSchNote = safe_queue_peak_tail(q);

    ScheduledNote newSchNote;
    newSchNote.start = lastSchNote.end;

    // Start slightly before the previous note ends for smoother playback.
    if (newSchNote.start > 5000)
    {
        newSchNote.start -= 5000;
    }

    newSchNote.end = add_time_note(lastSchNote.end, length);
    newSchNote.note = note;
    newSchNote.length = length;

    return enqueue(q, newSchNote);
}

/**
 * Determines whether the next scheduled note is ready to play.
 *
 * @param schedId Scheduler identifier.
 * @return true if the scheduler contains a note whose start time has
 *         been reached but whose end time has not yet passed.
 */
bool isNextNoteReady(int schedId)
{
    Queue *q = &schedulers[schedId];
    ScheduledNote q_head = safe_queue_peak_head(q);

    return queue_is_empty(q) == false &&
           is_in_future(q_head.end) &&
           is_in_past(q_head.start);
}

/**
 * Removes and returns the next scheduled note.
 *
 * @param schedId Scheduler identifier.
 * @return The next scheduled note.
 */
ScheduledNote dequeueNote(int schedId)
{
    Queue *q = &schedulers[schedId];
    return dequeue(q);
}

/**
 * Removes all scheduled notes from a scheduler.
 *
 * @param schedId Scheduler identifier.
 */
void emptyScheduler(int schedId)
{
    Queue *q = &schedulers[schedId];

    while (!queue_is_empty(q))
    {
        dequeue(q);
    }
}

/**
 * Removes all scheduled notes from every scheduler.
 */
void emptyAllSchedulers(void)
{
    for (int i = 0; i < SCHEDULER_COUNT; i++)
    {
        emptyScheduler(i);
    }
}

/**
 * Checks whether all schedulers are empty.
 *
 * @return true if no notes remain scheduled; otherwise false.
 */
bool isSongFinished(void)
{
    for (int i = 0; i < SCHEDULER_COUNT; i++)
    {
        if (!queue_is_empty(&schedulers[i]))
        {
            return false;
        }
    }

    return true;
}

/**
 * Updates all schedulers and starts any notes whose scheduled
 * start time has been reached.
 *
 * This function should be called periodically from the audio thread.
 */
void runSchedulers(void)
{
    for (int i = 0; i < SCHEDULER_COUNT; i++)
    {
        if (isNextNoteReady(i))
        {
            ScheduledNote schNote = dequeueNote(i);
            playNote(schNote.note, schNote.length);
        }
    }
}