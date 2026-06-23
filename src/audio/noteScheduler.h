#pragma once

#include "notes.h"
#include <stdbool.h>

bool enqueueNote(int schedId, Note note, double duration);
bool isNextNoteReady(int schedId);
ScheduledNote dequeueNote(int schedId);
void initSchedulers();
void runSchedulers();