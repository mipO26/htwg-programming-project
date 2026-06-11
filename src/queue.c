#include "queue.h"
#include <stdlib.h>


ScheduledNote getDefaultScheduledNote()
{
    ScheduledNote note = {0, 0, PAUSE};
    return note;
}

Queue create_queue()
{
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    return q;
}

bool enqueue(Queue *q, ScheduledNote note)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        return false;
    new_node->note = note;
    new_node->next = NULL;

    if (q->tail) {
        q->tail->next = new_node;
    } else {
        q->head = new_node;
    }
    q->tail = new_node;
    return true;
}

bool queue_is_empty(Queue *q)
{
    return q->head == NULL;
}

ScheduledNote dequeue(Queue *q)
{
    if (queue_is_empty(q))
    {
        return getDefaultScheduledNote();
    }
    Node* node = q->head;
    ScheduledNote note = node->note;
    q->head = node->next;
    free(node);

    if (queue_is_empty(q))
        q->tail = NULL;
    return note;
}

ScheduledNote safe_queue_peak_head(Queue *q)
{
    if (queue_is_empty(q))
    {
        return getDefaultScheduledNote();
    }
    return q->head->note;
}

ScheduledNote safe_queue_peak_tail(Queue *q)
{
    if (queue_is_empty(q))
    {
        return getDefaultScheduledNote();
    }
    return q->tail->note;
}