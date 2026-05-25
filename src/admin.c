#include "admin.h"
#include "utils.h"

#include <stdio.h>
#include <string.h>

int admin_login(void) {
    char user[20];
    char pass[20];

    printf("\n--- ADMIN LOGIN ---\n");
    printf("Username: ");
    read_string(user, 20);
    printf("Password: ");
    read_string(pass, 20);

    if (strcmp(user, ADMIN_USER) == 0 && strcmp(pass, ADMIN_PASS) == 0) {
        printf("Login OK.\n");
        return 1;
    }
    printf("Wrong username or password.\n");
    return 0;
}

void admin_menu(RailwaySystem *sys) {
    int choice;
    Train t;
    TrainNode *node;
    Passenger p;
    char train_no[MAX_TRAIN_NO];
    int i, confirmed = 0;
    float revenue = 0;

    if (!admin_login()) {
        return;
    }

    do {
        printf("\n--- ADMIN PANEL ---\n");
        printf("1.Add Train  2.Delete Train  3.Update Fare\n");
        printf("4.Add Passenger  5.Show Trains  6.Show Passengers\n");
        printf("7.Statistics  0.Back\n");
        printf("Choice: ");
        choice = read_int();

        if (choice == 1) {
            printf("\nTrain Number ");
            read_train_no(t.train_no);
            printf("Train Name: ");
            read_string(t.name, MAX_NAME);
            printf("Source: ");
            read_string(t.source, MAX_STATION);
            printf("Destination: ");
            read_string(t.destination, MAX_STATION);
            printf("Departure Time: ");
            read_string(t.departure_time, 8);
            printf("Arrival Time: ");
            read_string(t.arrival_time, 8);
            printf("Total Seats: ");
            t.total_seats = read_int();
            t.available_seats = t.total_seats;
            printf("Distance (km): ");
            t.distance_km = read_int();
            printf("Fare per km: ");
            t.fare_per_km = read_float();
            bst_insert(&sys->trains, t);
            printf("Train added.\n");
        } else if (choice == 2) {
            printf("Train Number to delete ");
            read_train_no(train_no);
            bst_delete(&sys->trains, train_no);
            printf("Done.\n");
        } else if (choice == 3) {
            printf("Train Number ");
            read_train_no(train_no);
            node = bst_find(&sys->trains, train_no);
            if (node == NULL) {
                printf("Not found.\n");
            } else {
                printf("New fare per km: ");
                node->data.fare_per_km = read_float();
                printf("Fare updated.\n");
            }
        } else if (choice == 4) {
            make_passenger_id(p.passenger_id, sys->counters.passenger_no++);
            printf("Name: ");
            read_string(p.name, MAX_NAME);
            printf("Phone: ");
            read_string(p.phone, MAX_PHONE);
            printf("Age: ");
            p.age = read_int();
            list_add(&sys->passengers, p);
            printf("Passenger added.\n");
        } else if (choice == 5) {
            bst_show_all(&sys->trains);
        } else if (choice == 6) {
            list_show(&sys->passengers);
        } else if (choice == 7) {
            for (i = 0; i < sys->booking_count; i++) {
                if (sys->bookings[i].confirmed && !sys->bookings[i].cancelled) {
                    confirmed++;
                    revenue += sys->bookings[i].fare;
                }
            }
            printf("\n--- STATISTICS ---\n");
            printf("Trains: %d\n", sys->trains.count);
            printf("Passengers: %d\n", sys->passengers.count);
            printf("Bookings: %d\n", sys->booking_count);
            printf("Confirmed: %d\n", confirmed);
            printf("Waiting: %d\n", sys->waiting.count);
            printf("Revenue: Rs.%.2f\n", revenue);
        }
    } while (choice != 0);
}
