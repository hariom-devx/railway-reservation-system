#include "booking.h"
#include "utils.h"

#include <stdio.h>
#include <string.h>

void system_init(RailwaySystem *sys) {
    bst_init(&sys->trains);
    list_init(&sys->passengers);
    queue_init(&sys->waiting);
    stack_init(&sys->cancel_stack);
    sys->booking_count = 0;
    sys->counters.pnr_no = 6;
    sys->counters.passenger_no = 6;
}

void system_reset(RailwaySystem *sys) {
    bst_clear(&sys->trains);
    list_clear(&sys->passengers);
    queue_clear(&sys->waiting);
    stack_clear(&sys->cancel_stack);
    sys->booking_count = 0;
    sys->counters.pnr_no = 6;
    sys->counters.passenger_no = 6;
}

void system_save(RailwaySystem *sys) {
    save_all(&sys->trains, &sys->passengers, sys->bookings,
             sys->booking_count, &sys->waiting, &sys->counters);
    printf("Data saved.\n");
}

void system_load(RailwaySystem *sys) {
    system_init(sys);
    load_all(&sys->trains, &sys->passengers, sys->bookings,
             &sys->booking_count, &sys->waiting, &sys->counters);
}

float calc_fare(Train *t, int cls) {
    return t->distance_km * t->fare_per_km * class_multiplier(cls);
}

Booking *find_booking(RailwaySystem *sys, char *pnr) {
    int i;

    for (i = 0; i < sys->booking_count; i++) {
        if (strcmp(sys->bookings[i].pnr, pnr) == 0 && sys->bookings[i].cancelled == 0) {
            return &sys->bookings[i];
        }
    }
    return NULL;
}

/* If seat free, give first person in waiting list for this train */
static void check_waiting(RailwaySystem *sys, char *train_no) {
    TrainNode *train;
    Booking *b;
    WaitingEntry *w;

    train = bst_find(&sys->trains, train_no);
    if (train == NULL || train->data.available_seats <= 0) {
        return;
    }

    while (train->data.available_seats > 0 && !queue_empty(&sys->waiting)) {
        w = sys->waiting.front;
        if (strcmp(w->train_no, train_no) != 0) {
            break;
        }

        b = find_booking(sys, w->pnr);
        if (b != NULL && b->confirmed == 0) {
            b->confirmed = 1;
            train->data.available_seats--;
            b->seat_number = train->data.total_seats - train->data.available_seats;
            printf("Waiting ticket confirmed: %s | Seat %d\n", b->pnr, b->seat_number);
        }
        queue_remove_first(&sys->waiting);
    }
}

void book_ticket(RailwaySystem *sys) {
    char train_no[MAX_TRAIN_NO];
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    char date[MAX_DATE];
    TrainNode *train;
    Booking b;
    Passenger p;
    int cls;
    if (sys->booking_count >= MAX_BOOKINGS) {
        printf("Booking limit reached.\n");
        return;
    }

    printf("\n--- BOOK TICKET ---\n");
    printf("Train Number ");
    read_train_no(train_no);

    train = bst_find(&sys->trains, train_no);
    if (train == NULL) {
        printf("Train not found.\n");
        return;
    }

    printf("Passenger Name: ");
    read_string(name, MAX_NAME);
    printf("Phone: ");
    read_string(phone, MAX_PHONE);
    printf("Date (DD-MM-YYYY): ");
    read_string(date, MAX_DATE);

    printf("Class (1-Sleeper 2-3A 3-2A 4-1A): ");
    cls = read_int();
    if (cls < 1 || cls > 4) {
        cls = 1;
    }

    make_pnr(b.pnr, sys->counters.pnr_no++);
    strcpy(b.passenger_name, name);
    strcpy(b.phone, phone);
    strcpy(b.train_no, train_no);
    strcpy(b.source, train->data.source);
    strcpy(b.destination, train->data.destination);
    strcpy(b.journey_date, date);
    b.travel_class = cls;
    b.fare = calc_fare(&train->data, cls);
    b.cancelled = 0;

    if (list_find_phone(&sys->passengers, phone) == NULL) {
        make_passenger_id(p.passenger_id, sys->counters.passenger_no++);
        strcpy(p.name, name);
        strcpy(p.phone, phone);
        p.age = 0;
        list_add(&sys->passengers, p);
    }

    if (train->data.available_seats > 0) {
        train->data.available_seats--;
        b.seat_number = train->data.total_seats - train->data.available_seats;
        b.confirmed = 1;
        printf("\nTICKET CONFIRMED!\n");
        printf("PNR: %s | Seat: %d | Fare: Rs.%.2f\n", b.pnr, b.seat_number, b.fare);
    } else {
        b.seat_number = 0;
        b.confirmed = 0;
        queue_add(&sys->waiting, b.pnr, b.passenger_name, b.train_no, b.journey_date, cls);
        printf("\nNo seat. Added to WAITING LIST.\n");
        printf("PNR: %s | Fare if confirmed: Rs.%.2f\n", b.pnr, b.fare);
    }

    sys->bookings[sys->booking_count] = b;
    sys->booking_count++;
}

void cancel_ticket(RailwaySystem *sys) {
    char pnr[MAX_PNR];
    Booking *b;
    TrainNode *train;

    printf("\n--- CANCEL TICKET ---\n");
    printf("Enter PNR: ");
    read_string(pnr, MAX_PNR);

    b = find_booking(sys, pnr);
    if (b == NULL) {
        printf("Booking not found.\n");
        return;
    }

    if (b->confirmed == 0) {
        b->cancelled = 1;
        queue_remove_pnr(&sys->waiting, pnr);
        printf("Waiting list ticket cancelled.\n");
        return;
    }

    train = bst_find(&sys->trains, b->train_no);
    if (train != NULL) {
        train->data.available_seats++;
        check_waiting(sys, b->train_no);
    }

    b->cancelled = 1;
    stack_push(&sys->cancel_stack, *b);
    printf("Ticket cancelled. Refund: Rs.%.2f\n", b->fare * 0.75);
}

void undo_cancel(RailwaySystem *sys) {
    Booking cancelled;
    Booking *b;
    TrainNode *train;
    int i;

    printf("\n--- UNDO CANCELLATION ---\n");

    if (!stack_pop(&sys->cancel_stack, &cancelled)) {
        printf("Nothing to undo.\n");
        return;
    }

    for (i = 0; i < sys->booking_count; i++) {
        if (strcmp(sys->bookings[i].pnr, cancelled.pnr) == 0) {
            b = &sys->bookings[i];
            train = bst_find(&sys->trains, b->train_no);
            if (train == NULL || train->data.available_seats <= 0) {
                printf("No seat available. Cannot undo.\n");
                stack_push(&sys->cancel_stack, cancelled);
                return;
            }
            b->cancelled = 0;
            b->confirmed = 1;
            train->data.available_seats--;
            b->seat_number = train->data.total_seats - train->data.available_seats;
            printf("Undo done. PNR %s active again.\n", b->pnr);
            return;
        }
    }
    printf("Booking not found.\n");
}

void show_seats(RailwaySystem *sys) {
    char train_no[MAX_TRAIN_NO];
    TrainNode *train;

    printf("\n--- SEAT AVAILABILITY ---\n");
    printf("Train Number ");
    read_train_no(train_no);

    train = bst_find(&sys->trains, train_no);
    if (train == NULL) {
        printf("Train not found.\n");
        return;
    }

    printf("Train: %s\n", train->data.name);
    printf("Route: %s to %s\n", train->data.source, train->data.destination);
    printf("Available: %d / %d\n", train->data.available_seats, train->data.total_seats);
}

void search_passenger(RailwaySystem *sys) {
    char key[MAX_NAME];
    PassengerNode *found;
    int ch;

    printf("\n--- SEARCH PASSENGER ---\n");
    printf("1.By Name 2.By Phone: ");
    ch = read_int();

    if (ch == 1) {
        printf("Name: ");
        read_string(key, MAX_NAME);
        found = list_find_name(&sys->passengers, key);
    } else {
        printf("Phone: ");
        read_string(key, MAX_PHONE);
        found = list_find_phone(&sys->passengers, key);
    }

    if (found == NULL) {
        printf("Not found.\n");
    } else {
        printf("Found: %s | %s | %s\n",
               found->data.passenger_id, found->data.name, found->data.phone);
    }
}

void search_train(RailwaySystem *sys) {
    char key[MAX_NAME];
    TrainNode *found;
    int ch;

    printf("\n--- SEARCH TRAIN ---\n");
    printf("1.By Number 2.By Name: ");
    ch = read_int();

    if (ch == 1) {
        printf("Train Number ");
        read_train_no(key);
        found = bst_find(&sys->trains, key);
    } else {
        printf("Train Name: ");
        read_string(key, MAX_NAME);
        found = bst_find_by_name(&sys->trains, key);
    }

    if (found == NULL) {
        printf("Not found.\n");
    } else {
        printf("%s - %s | %s to %s | Seats %d/%d\n",
               found->data.train_no, found->data.name,
               found->data.source, found->data.destination,
               found->data.available_seats, found->data.total_seats);
    }
}

void show_bookings(RailwaySystem *sys) {
    int i;
    Booking *b;

    printf("\n--- ALL BOOKINGS ---\n");
    if (sys->booking_count == 0) {
        printf("No bookings.\n");
        return;
    }

    for (i = 0; i < sys->booking_count; i++) {
        b = &sys->bookings[i];
        printf("%d. %s | %s | Train %s | ", i + 1, b->pnr, b->passenger_name, b->train_no);
        if (b->cancelled) {
            printf("Cancelled\n");
        } else if (b->confirmed) {
            printf("Confirmed Seat %d | Rs.%.2f\n", b->seat_number, b->fare);
        } else {
            printf("Waiting | Rs.%.2f\n", b->fare);
        }
    }
}
