#ifndef FILE_IO_H
#define FILE_IO_H

#include "bst.h"
#include "linked_list.h"
#include "queue.h"
#include "types.h"

typedef struct {
    int pnr_no;
    int passenger_no;
} Counters;

void save_all(TrainBST *trains, PassengerList *passengers, Booking *bookings,
              int booking_count, WaitingQueue *waiting, Counters *c);
void load_all(TrainBST *trains, PassengerList *passengers, Booking *bookings,
              int *booking_count, WaitingQueue *waiting, Counters *c);

#endif
