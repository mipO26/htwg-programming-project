#pragma once

#include "notes.h"
#include "stdint.h"
#include <stdbool.h>

typedef struct Node {
    ScheduledNote note;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} Queue;


Queue create_queue(void);
bool enqueue(Queue *q, ScheduledNote note);
bool queue_is_empty(Queue *q);
ScheduledNote dequeue(Queue *q);
ScheduledNote safe_queue_peak_head(Queue *q);
ScheduledNote safe_queue_peak_tail(Queue *q);