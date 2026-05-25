#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "types.h"

typedef struct {
    PassengerNode *head;
    int count;
} PassengerList;

void list_init(PassengerList *list);
void list_add(PassengerList *list, Passenger p);
PassengerNode *list_find_phone(PassengerList *list, char *phone);
PassengerNode *list_find_name(PassengerList *list, char *name);
void list_show(PassengerList *list);
void list_clear(PassengerList *list);

#endif
