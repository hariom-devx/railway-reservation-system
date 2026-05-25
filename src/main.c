/**
 * Railway Reservation System
 * Simple C project using Queue, Linked List, Stack and BST
 */

#include "admin.h"
#include "booking.h"
#include "predata.h"
#include "utils.h"

#include <stdio.h>

void show_menu(void) {
    print_line();
    printf("   RAILWAY RESERVATION SYSTEM\n");
    print_line();
    printf("1. Book Ticket\n");
    printf("2. Cancel Ticket\n");
    printf("3. Undo Cancel (Stack)\n");
    printf("4. Seat Availability\n");
    printf("5. Search Passenger (List)\n");
    printf("6. Search Train (BST)\n");
    printf("7. Fare Calculator\n");
    printf("8. Waiting List (Queue)\n");
    printf("9. All Bookings\n");
    printf("10. All Trains\n");
    printf("11. Cancel Stack\n");
    printf("12. Admin Panel\n");
    printf("13. Show Pre-loaded Data Info\n");
    printf("0. Save and Exit\n");
    print_line();
}

int main(void) {
    RailwaySystem sys;
    int choice;
    char train_no[MAX_TRAIN_NO];
    TrainNode *train;
    int cls;
    float fare;

    system_load(&sys);
    load_predata(&sys);

    printf("\nWelcome!\n");

    do {
        show_menu();
        printf("Enter choice: ");
        choice = read_int();

        if (choice == 1) {
            book_ticket(&sys);
        } else if (choice == 2) {
            cancel_ticket(&sys);
        } else if (choice == 3) {
            undo_cancel(&sys);
        } else if (choice == 4) {
            show_seats(&sys);
        } else if (choice == 5) {
            search_passenger(&sys);
        } else if (choice == 6) {
            search_train(&sys);
        } else if (choice == 7) {
            printf("\nTrain Number ");
            read_train_no(train_no);
            train = bst_find(&sys.trains, train_no);
            if (train == NULL) {
                printf("Train not found.\n");
            } else {
                printf("Class (1-4): ");
                cls = read_int();
                fare = calc_fare(&train->data, cls);
                printf("Fare: Rs.%.2f\n", fare);
            }
        } else if (choice == 8) {
            queue_show(&sys.waiting);
        } else if (choice == 9) {
            show_bookings(&sys);
        } else if (choice == 10) {
            bst_show_all(&sys.trains);
        } else if (choice == 11) {
            stack_show(&sys.cancel_stack);
        } else if (choice == 12) {
            admin_menu(&sys);
        } else if (choice == 13) {
            show_predata_info();
        } else if (choice == 0) {
            system_save(&sys);
            printf("Thank you!\n");
        } else {
            printf("Invalid choice.\n");
        }
    } while (choice != 0);

    bst_clear(&sys.trains);
    list_clear(&sys.passengers);
    queue_clear(&sys.waiting);
    stack_clear(&sys.cancel_stack);

    return 0;
}
