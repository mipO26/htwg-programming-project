#pragma once

#include <stdint.h>
#include <stdbool.h>



void set_bpm(uint32_t bpm);
uint64_t add_time_ms(uint64_t time, uint32_t ms);
uint64_t add_time_note(uint64_t time, double note_length);
bool is_in_future(uint64_t time);
bool is_in_past(uint64_t time);

uint64_t time_from_start(uint64_t start);
uint64_t time_to_end(uint64_t end);

void sleep_ms(unsigned int ms);

/*
    --- Enable this during testing ---
*/ 

uint64_t now_us(void);