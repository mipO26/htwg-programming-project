#include "queue.h"
#include <stdlib.h>

/**
 * Creates a default scheduled note.
 *
 * The returned note represents an empty or invalid queue entry and is
 * used when queue operations are performed on an empty queue.
 *
 * @return Default scheduled note.
 */
ScheduledNote getDefaultScheduledNote(void)
{
    ScheduledNote note = {0, 0, PAUSE};
    return note;
}

/**
 * Creates an empty queue.
 *
 * @return Newly initialized queue.
 */
Queue create_queue(void)
{
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    return q;
}

/**
 * Appends a scheduled note to the end of the queue.
 *
 * @param q Queue to modify.
 * @param note Scheduled note to enqueue.
 * @return true if the note was successfully added; otherwise false if
 *         memory allocation failed.
 */
bool enqueue(Queue *q, ScheduledNote note)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        return false;

    new_node->note = note;
    new_node->next = NULL;

    if (q->tail)
    {
        q->tail->next = new_node;
    }
    else
    {
        q->head = new_node;
    }

    q->tail = new_node;
    return true;
}

/**
 * Checks whether a queue is empty.
 *
 * @param q Queue to inspect.
 * @return true if the queue contains no elements; otherwise false.
 */
bool queue_is_empty(Queue *q)
{
    return q->head == NULL;
}

/**
 * Removes and returns the first scheduled note in the queue.
 *
 * If the queue is empty, a default scheduled note is returned.
 *
 * @param q Queue to modify.
 * @return The dequeued scheduled note.
 */
ScheduledNote dequeue(Queue *q)
{
    if (queue_is_empty(q))
    {
        return getDefaultScheduledNote();
    }

    Node *node = q->head;
    ScheduledNote note = node->note;

    q->head = node->next;
    free(node);

    if (queue_is_empty(q))
        q->tail = NULL;

    return note;
}

/**
 * Returns the first scheduled note without removing it.
 *
 * If the queue is empty, a default scheduled note is returned.
 *
 * @param q Queue to inspect.
 * @return The first scheduled note.
 */
ScheduledNote safe_queue_peak_head(Queue *q)
{
    if (queue_is_empty(q))
    {
        return getDefaultScheduledNote();
    }

    return q->head->note;
}

/**
 * Returns the last scheduled note without removing it.
 *
 * If the queue is empty, a default scheduled note is returned.
 *
 * @param q Queue to inspect.
 * @return The last scheduled note.
 */
ScheduledNote safe_queue_peak_tail(Queue *q)
{
    if (queue_is_empty(q))
    {
        return getDefaultScheduledNote();
    }

    return q->tail->note;
}