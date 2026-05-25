#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void list_init(PassengerList *list) {
    list->head = NULL;
    list->count = 0;
}

void list_add(PassengerList *list, Passenger p) {
    PassengerNode *new_node = (PassengerNode *)malloc(sizeof(PassengerNode));
    PassengerNode *temp;

    new_node->data = p;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    list->count++;
}

PassengerNode *list_find_phone(PassengerList *list, char *phone) {
    PassengerNode *temp = list->head;

    while (temp != NULL) {
        if (strcmp(temp->data.phone, phone) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

PassengerNode *list_find_name(PassengerList *list, char *name) {
    PassengerNode *temp = list->head;

    while (temp != NULL) {
        if (strcmp(temp->data.name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void list_show(PassengerList *list) {
    PassengerNode *temp = list->head;
    int i = 1;

    if (list->head == NULL) {
        printf("No passengers.\n");
        return;
    }

    printf("\n--- Passengers (Linked List) ---\n");
    while (temp != NULL) {
        printf("%d. ID:%s | %s | %s | Age:%d\n",
               i, temp->data.passenger_id, temp->data.name,
               temp->data.phone, temp->data.age);
        temp = temp->next;
        i++;
    }
}

void list_clear(PassengerList *list) {
    PassengerNode *temp;

    while (list->head != NULL) {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    list->count = 0;
}
