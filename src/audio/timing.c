#include "timing.h"
#include <time.h>
#include "notes.h"

/** Duration of one beat in microseconds. */
uint64_t time_unit;

/**
 * Sets the playback tempo.
 *
 * Computes the duration of one beat from the specified tempo.
 *
 * @param bpm Tempo in beats per minute.
 */
void set_bpm(uint32_t bpm)
{
    time_unit = 60000000ULL / bpm;
}

/**
 * Returns the current system time.
 *
 * @return Current time in microseconds.
 */
uint64_t now_us(void)
{
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    return (uint64_t)ts.tv_sec * 1000000ULL +
           ts.tv_nsec / 1000;
}

/**
 * Adds an amount of time in milliseconds to a timestamp.
 *
 * If the supplied time is in the past, the time is added to the
 * current time instead.
 *
 * @param time Base timestamp in microseconds.
 * @param ms Amount of time in milliseconds.
 * @return Updated timestamp in microseconds.
 */
uint64_t add_time_ms(uint64_t time, uint32_t ms)
{
    if (time < now_us())
        return now_us() + ms * 1000ULL;
    return time + ms * 1000ULL;
}

/**
 * Adds a musical note duration to a timestamp.
 *
 * If the supplied time is in the past, the duration is added to the
 * current time instead.
 * 
 * Note note_length is specified in audio/notes.h
 *
 * @param time Base timestamp in microseconds.
 * @param note_length Note duration in beats.
 * @return Updated timestamp in microseconds.
 */
uint64_t add_time_note(uint64_t time, double note_length)
{
    if (time < now_us())
        return now_us() + (uint64_t)(time_unit * note_length);
    return time + (uint64_t)(time_unit * note_length);
}

/**
 * Returns the elapsed time since a timestamp.
 *
 * @param start Start timestamp in microseconds.
 * @return Elapsed time in microseconds.
 */
uint64_t time_from_start(uint64_t start)
{
    return now_us() - start;
}

/**
 * Returns the remaining time until a timestamp.
 *
 * @param end End timestamp in microseconds.
 * @return Remaining time in microseconds.
 */
uint64_t time_to_end(uint64_t end)
{
    return end - now_us();
}

/**
 * Determines whether a timestamp lies in the future.
 *
 * @param time Timestamp in microseconds.
 * @return true if the timestamp is in the future; otherwise false.
 */
bool is_in_future(uint64_t time)
{
    return time > now_us();
}

/**
 * Determines whether a timestamp has been reached.
 *
 * @param time Timestamp in microseconds.
 * @return true if the timestamp is in the past or present; otherwise false.
 */
bool is_in_past(uint64_t time)
{
    return time <= now_us();
}

#ifdef _WIN32
    #include <windows.h>
#else
    #include <time.h>
#endif

/**
 * Suspends execution for the specified duration.
 *
 * Uses the native operating system sleep function.
 *
 * @param ms Sleep duration in milliseconds.
 */
void sleep_ms(unsigned int ms)
{
#ifdef _WIN32
    Sleep(ms);
#else
    struct timespec ts;
    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (ms % 1000) * 1000000L;
    nanosleep(&ts, NULL);
#endif
}