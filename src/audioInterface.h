#pragma once

#include <stdbool.h>
#include "notes.h"

void playNote(Note note, double duration);
void playNoteMs(Note note, uint32_t duration_ms);
void stopNote(Note note);