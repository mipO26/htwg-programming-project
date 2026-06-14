#include "audio/noteScheduler.h"
#include <assert.h>
#include "audio/notes.h"
#include "audio/timing.h"
#include <stdio.h>
#include <time.h>

void sleep()
{
    struct timespec ts;
    ts.tv_sec = 1;
    ts.tv_nsec = 500 * 1000000L; // 100 ms
    nanosleep(&ts, NULL);
}

void noteSchedulerTester()
{
    set_bpm(120);

    assert(enqueueNote(0, C3, HALF_NOTE));
    assert(enqueueNote(0, D3, HALF_NOTE));
    assert(isNextNoteReady(0));

    ScheduledNote fistNote = dequeueNote(0);

    assert(isNextNoteReady(0) == false);
    sleep();

    assert(isNextNoteReady(0));

    ScheduledNote secondNote = dequeueNote(0);

    assert(isNextNoteReady(0) == false);
}