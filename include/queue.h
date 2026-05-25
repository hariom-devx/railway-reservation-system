#ifndef QUEUE_H
#define QUEUE_H

#include "types.h"

typedef struct {
    WaitingEntry *front;
    WaitingEntry *rear;
    int count;
} WaitingQueue;

void queue_init(WaitingQueue *q);
int queue_empty(WaitingQueue *q);
void queue_add(WaitingQueue *q, char *pnr, char *name, char *train, char *date, int cls);
void queue_remove_first(WaitingQueue *q);
void queue_remove_pnr(WaitingQueue *q, char *pnr);
void queue_show(WaitingQueue *q);
void queue_clear(WaitingQueue *q);

#endif
