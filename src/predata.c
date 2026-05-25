#include "predata.h"
#include "utils.h"

#include <stdio.h>
#include <string.h>

static void add_booking(RailwaySystem *sys, char *pnr, char *name, char *phone,
                        char *train_no, char *date, int cls, int confirmed) {
    TrainNode *train;
    Booking b;

    if (sys->booking_count >= MAX_BOOKINGS) {
        return;
    }

    train = bst_find(&sys->trains, train_no);
    if (train == NULL) {
        return;
    }

    strcpy(b.pnr, pnr);
    strcpy(b.passenger_name, name);
    strcpy(b.phone, phone);
    strcpy(b.train_no, train_no);
    strcpy(b.source, train->data.source);
    strcpy(b.destination, train->data.destination);
    strcpy(b.journey_date, date);
    b.travel_class = cls;
    b.fare = calc_fare(&train->data, cls);
    b.cancelled = 0;

    if (confirmed && train->data.available_seats > 0) {
        train->data.available_seats--;
        b.seat_number = train->data.total_seats - train->data.available_seats;
        b.confirmed = 1;
    } else {
        b.seat_number = 0;
        b.confirmed = 0;
        queue_add(&sys->waiting, b.pnr, b.passenger_name, b.train_no, b.journey_date, cls);
    }

    sys->bookings[sys->booking_count] = b;
    sys->booking_count++;
}

void load_predata(RailwaySystem *sys) {
    Train tr;
    Passenger p;

    /* If old train numbers exist, reset and load new 001 format */
    if (sys->trains.count > 0) {
        if (bst_find(&sys->trains, "001") != NULL) {
            return;
        }
        printf("\nUpdating to train numbers 001, 002, 003 ...\n");
        system_reset(sys);
    }

    printf("Loading pre-loaded data...\n");

    /* TRAINS - numbers 001 to 008 */
    tr = (Train){"001", "Rajdhani Express", "Mumbai", "Delhi", "17:00", "08:30", 500, 500, 2.5f, 1384};
    bst_insert(&sys->trains, tr);

    tr = (Train){"002", "Karnataka Express", "Bangalore", "Delhi", "19:20", "05:30", 400, 400, 1.8f, 2150};
    bst_insert(&sys->trains, tr);

    tr = (Train){"003", "Howrah Rajdhani", "Kolkata", "Delhi", "16:55", "10:00", 450, 450, 2.2f, 1447};
    bst_insert(&sys->trains, tr);

    tr = (Train){"004", "Shatabdi Express", "Mumbai", "Ahmedabad", "06:25", "13:15", 300, 300, 3.0f, 491};
    bst_insert(&sys->trains, tr);

    tr = (Train){"005", "Tamil Nadu Express", "Chennai", "Delhi", "22:00", "07:00", 600, 600, 1.5f, 2181};
    bst_insert(&sys->trains, tr);

    tr = (Train){"006", "Goa Express", "Mumbai", "Goa", "07:10", "14:40", 350, 350, 1.2f, 594};
    bst_insert(&sys->trains, tr);

    tr = (Train){"007", "Coromandel Express", "Chennai", "Kolkata", "08:45", "04:20", 550, 550, 1.6f, 1661};
    bst_insert(&sys->trains, tr);

    tr = (Train){"008", "Duronto Express", "Delhi", "Kolkata", "23:00", "06:15", 420, 420, 2.0f, 1447};
    bst_insert(&sys->trains, tr);

    /* PASSENGERS - IDs 001 to 005 */
    p = (Passenger){"001", "Rahul Sharma", "9876543210", 28};
    list_add(&sys->passengers, p);

    p = (Passenger){"002", "Priya Patel", "9123456780", 24};
    list_add(&sys->passengers, p);

    p = (Passenger){"003", "Amit Kumar", "9988776655", 32};
    list_add(&sys->passengers, p);

    p = (Passenger){"004", "Sneha Reddy", "9012345678", 26};
    list_add(&sys->passengers, p);

    p = (Passenger){"005", "Vikram Singh", "8899001122", 35};
    list_add(&sys->passengers, p);

    sys->counters.pnr_no = 6;
    sys->counters.passenger_no = 6;

    /* BOOKINGS linked to trains 001, 002, 003, 004 */
    add_booking(sys, "PNR001", "Rahul Sharma", "9876543210", "001", "15-06-2026", 2, 1);
    add_booking(sys, "PNR002", "Priya Patel", "9123456780", "001", "15-06-2026", 1, 1);
    add_booking(sys, "PNR003", "Amit Kumar", "9988776655", "004", "20-06-2026", 3, 1);
    add_booking(sys, "PNR004", "Sneha Reddy", "9012345678", "002", "22-06-2026", 2, 1);
    add_booking(sys, "PNR005", "Vikram Singh", "8899001122", "003", "25-06-2026", 1, 0);

    show_predata_info();
    system_save(sys);
}

void show_predata_info(void) {
    printf("\n========================================\n");
    printf("   PRE-LOADED DATA (for testing)\n");
    printf("========================================\n");

    printf("\nTRAIN NUMBERS (enter 1 or 001 both work):\n");
    printf("  001 - Rajdhani Express      (Mumbai - Delhi)\n");
    printf("  002 - Karnataka Express     (Bangalore - Delhi)\n");
    printf("  003 - Howrah Rajdhani       (Kolkata - Delhi)\n");
    printf("  004 - Shatabdi Express      (Mumbai - Ahmedabad)\n");
    printf("  005 - Tamil Nadu Express    (Chennai - Delhi)\n");
    printf("  006 - Goa Express           (Mumbai - Goa)\n");
    printf("  007 - Coromandel Express    (Chennai - Kolkata)\n");
    printf("  008 - Duronto Express       (Delhi - Kolkata)\n");

    printf("\nPASSENGER IDs:\n");
    printf("  001 - Rahul Sharma  (9876543210)\n");
    printf("  002 - Priya Patel   (9123456780)\n");
    printf("  003 - Amit Kumar    (9988776655)\n");
    printf("  004 - Sneha Reddy   (9012345678)\n");
    printf("  005 - Vikram Singh  (8899001122)\n");

    printf("\nSAMPLE PNR:\n");
    printf("  PNR001 - Rahul  | Train 001 | Confirmed\n");
    printf("  PNR002 - Priya  | Train 001 | Confirmed\n");
    printf("  PNR003 - Amit   | Train 004 | Confirmed\n");
    printf("  PNR004 - Sneha  | Train 002 | Confirmed\n");
    printf("  PNR005 - Vikram | Train 003 | Waiting List\n");

    printf("\nADMIN: admin / admin123\n");
    printf("========================================\n\n");
}
