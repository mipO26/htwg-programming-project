#include "timing.h"
#include <time.h>
#include "notes.h"

uint64_t time_unit;

void set_bpm(uint32_t bpm)
{
    time_unit = 60000000ULL / bpm;
}

uint64_t now_us(void)
{
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    return (uint64_t)ts.tv_sec * 1000000ULL +
           ts.tv_nsec / 1000;
}

uint64_t add_time_ms(uint64_t time, uint32_t ms)
{
    if (time < now_us())
        return now_us() + ms * 1000ULL;
    return time + ms * 1000ULL;
}

uint64_t add_time_note(uint64_t time, double note_length)
{
    if (time < now_us())
        return now_us() + (uint64_t)(time_unit * note_length);
    return time + (uint64_t)(time_unit * note_length);
}

uint64_t time_from_start(uint64_t start)
{
    return now_us() - start;
}

uint64_t time_to_end(uint64_t end)
{
    return end - now_us();
}

bool is_in_future(uint64_t time)
{
    return time > now_us();
}

bool is_in_past(uint64_t time)
{
    return time <= now_us();
}