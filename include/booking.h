#ifndef BOOKING_H
#define BOOKING_H

#include "bst.h"
#include "linked_list.h"
#include "queue.h"
#include "stack.h"
#include "types.h"
#include "file_io.h"

typedef struct {
    TrainBST trains;
    PassengerList passengers;
    WaitingQueue waiting;
    CancelStack cancel_stack;
    Booking bookings[MAX_BOOKINGS];
    int booking_count;
    Counters counters;
} RailwaySystem;

void system_init(RailwaySystem *sys);
void system_reset(RailwaySystem *sys);
void system_save(RailwaySystem *sys);
void system_load(RailwaySystem *sys);

void book_ticket(RailwaySystem *sys);
void cancel_ticket(RailwaySystem *sys);
void undo_cancel(RailwaySystem *sys);
void show_seats(RailwaySystem *sys);
void search_passenger(RailwaySystem *sys);
void search_train(RailwaySystem *sys);
void show_bookings(RailwaySystem *sys);
float calc_fare(Train *t, int cls);
Booking *find_booking(RailwaySystem *sys, char *pnr);

#endif
