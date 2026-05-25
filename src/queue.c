#include "queue.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void queue_init(WaitingQueue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
}

int queue_empty(WaitingQueue *q) {
    return q->front == NULL;
}

void queue_add(WaitingQueue *q, char *pnr, char *name, char *train, char *date, int cls) {
    WaitingEntry *new_node = (WaitingEntry *)malloc(sizeof(WaitingEntry));

    strcpy(new_node->pnr, pnr);
    strcpy(new_node->passenger_name, name);
    strcpy(new_node->train_no, train);
    strcpy(new_node->journey_date, date);
    new_node->travel_class = cls;
    new_node->next = NULL;

    if (queue_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->count++;
}

void queue_remove_pnr(WaitingQueue *q, char *pnr) {
    WaitingEntry *temp = q->front;
    WaitingEntry *prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->pnr, pnr) == 0) {
            if (prev == NULL) {
                q->front = temp->next;
            } else {
                prev->next = temp->next;
            }
            if (temp == q->rear) {
                q->rear = prev;
            }
            free(temp);
            q->count--;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void queue_remove_first(WaitingQueue *q) {
    WaitingEntry *temp;

    if (queue_empty(q)) {
        return;
    }

    temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->count--;
}

void queue_show(WaitingQueue *q) {
    WaitingEntry *temp = q->front;
    int i = 1;

    if (queue_empty(q)) {
        printf("Waiting list is empty.\n");
        return;
    }

    printf("\n--- Waiting List (Queue) ---\n");
    while (temp != NULL) {
        printf("%d. PNR:%s | %s | Train:%s | %s | %s\n",
               i, temp->pnr, temp->passenger_name, temp->train_no,
               temp->journey_date, class_name(temp->travel_class));
        temp = temp->next;
        i++;
    }
}

void queue_clear(WaitingQueue *q) {
    while (!queue_empty(q)) {
        queue_remove_first(q);
    }
}
