#include "noteScheduler.h"
#include "timing.h"
#include "queue.h"
#include "audio.h"
#include "ui/ui_active.c"

#define SCHEDULER_COUNT 4

Queue schedulers[SCHEDULER_COUNT];

void initSchedulers()
{
    for (int i = 0; i < SCHEDULER_COUNT; i++)
    {
        schedulers[i] = create_queue();
    }
}

bool enqueueNote(int schedId, Note note, double length)
{
    Queue *q = &schedulers[schedId];
    ScheduledNote lastSchNote = safe_queue_peak_tail(q);
    ScheduledNote newSchNote;
    //note_vis(note);
    newSchNote.start = lastSchNote.end;
    newSchNote.end = add_time_note(lastSchNote.end, length);
    newSchNote.note = note;
    newSchNote.length = length;
    return enqueue(q, newSchNote);
}

bool isNextNoteReady(int schedId)
{
    Queue *q = &schedulers[schedId];
    ScheduledNote q_head = safe_queue_peak_head(q);
    return queue_is_empty(q) == false && is_in_future(q_head.end) && is_in_past(q_head.start);
}

ScheduledNote dequeueNote(int schedId)
{
    Queue *q = &schedulers[schedId];
    return dequeue(q);
}

void runSchedulers()
{
    for (int i = 0; i< SCHEDULER_COUNT; i++)
    {
        if (isNextNoteReady(i))
        {
            ScheduledNote schNote = dequeueNote(i);
            playNote(schNote.note, schNote.length);
        }
    }
}