# Getting Started

## Prerequisites

Before building Musicify, make sure SDL2 is installed on your system.

### Linux (Debian/Ubuntu)

```bash
sudo apt install libsdl2-dev
```

### macOS

```bash
brew install sdl2
```

## Building the Project

Generate the build files with CMake:


```bash
cmake -S . -B build
```

## Running Musicify

Build and run the application:

```bash
cmake --build build && ./build/Musicify
```

## Using audio interface:

In each file you want to use the audio interface, include the header:

```c
#include "audio/audio.h"
#include "audio/notes.h"
```

### Note constants

in `audio/notes.h`, define a special datatype `Note` for musical notes and their lengths. Available notes are:

- `C3`
- `Cs3`
- `D3`
- `Ds3`
- `E3`
- `F3`
- `Fs3`
- `G3`
- `Gs3`
- `A3`
- `As3`
- `B3`
- `C4`
- `Cs4`
- `D4`
- `Ds4`
- `E4`
- `F4`
- `Fs4`
- `G4`
- `Gs4`
- `A4`
- `As4`
- `B4`
- `C5`
- `Cs5`
- `D5`
- `Ds5`
- `E5`
- `F5`
- `Fs5`
- `G5`
- `Gs5`
- `A5`
- `As5`
- `B5`

### Playing notes

You can use provided constants to play notes with the `playNote` function:

```c
void playNote(Note note, double duration);
```

`audio/notes.h` also defines constants for note durations:

- `WHOLE_NOTE`
- `HALF_NOTE`
- `QUARTER_NOTE`
- `EIGHTH_NOTE`
- `SIXTEENTH_NOTE `
- `THIRTY_SECOND_NOTE`
- `SIXTY_FOURTH_NOTE`

Example usage:

```c
playNote(C4, QUARTER_NOTE);
playNote(D3, WHOLE_NOTE);
playNote(E4, EIGHTH_NOTE);
playNote(F5, SIXTEENTH_NOTE);
```

### Playing notes with custom duration

This function takes a `Note` and a duration in milliseconds:

```c
void playNoteMs(Note note, uint32_t duration_ms);
```

Example usage:

```c
playNoteMs(G4, 500); // Play G4 for 500 milliseconds
playNoteMs(A4, 1000); // Play A4 for 1000 milliseconds (1 second)
```

### Stopping note playback

To stop specific note playback, use the `stopNote` function:

```c
void stopNote(Note note);
```

Example usage:

```c
playNote(C4, WHOLE_NOTE); // Start playing C4
// ... some time later
stopNote(C4); // Stop playing C4
```

### Display of Notes
The notes you can hear are also seen on a visual keyboard using ascii drawing.

```c
note_vis(note)
```

## About

Musicify is a simple music synthesizer and player developed as a school project at HTWG. It provides an intuitive interface for creating and playing synthesized music.