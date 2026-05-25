#ifndef TYPES_H
#define TYPES_H

#define MAX_NAME 50
#define MAX_STATION 30
#define MAX_PHONE 15
#define MAX_PNR 15
#define MAX_TRAIN_NO 10
#define MAX_DATE 12
#define MAX_BOOKINGS 100

#define ADMIN_USER "admin"
#define ADMIN_PASS "admin123"

#define DATA_DIR "data"
#define TRAINS_FILE DATA_DIR "/trains.dat"
#define PASSENGERS_FILE DATA_DIR "/passengers.dat"
#define BOOKINGS_FILE DATA_DIR "/bookings.dat"
#define WAITING_FILE DATA_DIR "/waiting.dat"
#define COUNTERS_FILE DATA_DIR "/counters.dat"

/* Travel class: 1=SL, 2=3A, 3=2A, 4=1A */
typedef struct {
    char train_no[MAX_TRAIN_NO];
    char name[MAX_NAME];
    char source[MAX_STATION];
    char destination[MAX_STATION];
    char departure_time[8];
    char arrival_time[8];
    int total_seats;
    int available_seats;
    float fare_per_km;
    int distance_km;
} Train;

typedef struct {
    char pnr[MAX_PNR];
    char passenger_name[MAX_NAME];
    char phone[MAX_PHONE];
    char train_no[MAX_TRAIN_NO];
    char source[MAX_STATION];
    char destination[MAX_STATION];
    char journey_date[MAX_DATE];
    int travel_class;
    int seat_number;
    float fare;
    int confirmed;   /* 1=yes, 0=waiting */
    int cancelled;   /* 1=yes, 0=no */
} Booking;

typedef struct {
    char passenger_id[10];
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    int age;
} Passenger;

typedef struct WaitingEntry {
    char pnr[MAX_PNR];
    char passenger_name[MAX_NAME];
    char train_no[MAX_TRAIN_NO];
    char journey_date[MAX_DATE];
    int travel_class;
    struct WaitingEntry *next;
} WaitingEntry;

typedef struct PassengerNode {
    Passenger data;
    struct PassengerNode *next;
} PassengerNode;

typedef struct CancelStackNode {
    Booking booking;
    struct CancelStackNode *next;
} CancelStackNode;

typedef struct TrainNode {
    Train data;
    struct TrainNode *left;
    struct TrainNode *right;
} TrainNode;

#endif
