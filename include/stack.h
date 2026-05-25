#ifndef STACK_H
#define STACK_H

#include "types.h"

typedef struct {
    CancelStackNode *top;
    int count;
} CancelStack;

void stack_init(CancelStack *s);
int stack_empty(CancelStack *s);
void stack_push(CancelStack *s, Booking b);
int stack_pop(CancelStack *s, Booking *b);
void stack_show(CancelStack *s);
void stack_clear(CancelStack *s);

#endif
