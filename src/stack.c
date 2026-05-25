#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void stack_init(CancelStack *s) {
    s->top = NULL;
    s->count = 0;
}

int stack_empty(CancelStack *s) {
    return s->top == NULL;
}

void stack_push(CancelStack *s, Booking b) {
    CancelStackNode *new_node = (CancelStackNode *)malloc(sizeof(CancelStackNode));

    new_node->booking = b;
    new_node->next = s->top;
    s->top = new_node;
    s->count++;
}

int stack_pop(CancelStack *s, Booking *b) {
    CancelStackNode *temp;

    if (stack_empty(s)) {
        return 0;
    }

    *b = s->top->booking;
    temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->count--;
    return 1;
}

void stack_show(CancelStack *s) {
    CancelStackNode *temp = s->top;
    int i = 1;

    if (stack_empty(s)) {
        printf("No cancelled tickets to undo.\n");
        return;
    }

    printf("\n--- Cancel Stack ---\n");
    while (temp != NULL) {
        printf("%d. PNR:%s | %s | Train:%s\n",
               i, temp->booking.pnr, temp->booking.passenger_name,
               temp->booking.train_no);
        temp = temp->next;
        i++;
    }
}

void stack_clear(CancelStack *s) {
    Booking b;

    while (!stack_empty(s)) {
        stack_pop(s, &b);
    }
}
