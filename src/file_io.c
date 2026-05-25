#include "file_io.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

static void make_data_folder(void) {
    mkdir(DATA_DIR, 0755);
}

typedef struct {
    char pnr[MAX_PNR];
    char passenger_name[MAX_NAME];
    char train_no[MAX_TRAIN_NO];
    char journey_date[MAX_DATE];
    int travel_class;
} WaitingSave;

static void save_bst(FILE *fp, TrainNode *node) {
    if (node == NULL) {
        return;
    }
    save_bst(fp, node->left);
    fwrite(&node->data, sizeof(Train), 1, fp);
    save_bst(fp, node->right);
}

void save_all(TrainBST *trains, PassengerList *passengers, Booking *bookings,
              int booking_count, WaitingQueue *waiting, Counters *c) {
    FILE *fp;

    make_data_folder();
    PassengerNode *p;
    WaitingEntry *w;
    WaitingSave ws;
    int i;

    fp = fopen(TRAINS_FILE, "wb");
    if (fp != NULL) {
        save_bst(fp, trains->root);
        fclose(fp);
    }

    fp = fopen(PASSENGERS_FILE, "wb");
    if (fp != NULL) {
        p = passengers->head;
        while (p != NULL) {
            fwrite(&p->data, sizeof(Passenger), 1, fp);
            p = p->next;
        }
        fclose(fp);
    }

    fp = fopen(BOOKINGS_FILE, "wb");
    if (fp != NULL) {
        fwrite(&booking_count, sizeof(int), 1, fp);
        for (i = 0; i < booking_count; i++) {
            fwrite(&bookings[i], sizeof(Booking), 1, fp);
        }
        fclose(fp);
    }

    fp = fopen(WAITING_FILE, "wb");
    if (fp != NULL) {
        fwrite(&waiting->count, sizeof(int), 1, fp);
        w = waiting->front;
        while (w != NULL) {
            strcpy(ws.pnr, w->pnr);
            strcpy(ws.passenger_name, w->passenger_name);
            strcpy(ws.train_no, w->train_no);
            strcpy(ws.journey_date, w->journey_date);
            ws.travel_class = w->travel_class;
            fwrite(&ws, sizeof(WaitingSave), 1, fp);
            w = w->next;
        }
        fclose(fp);
    }

    fp = fopen(COUNTERS_FILE, "wb");
    if (fp != NULL) {
        fwrite(c, sizeof(Counters), 1, fp);
        fclose(fp);
    }
}

void load_all(TrainBST *trains, PassengerList *passengers, Booking *bookings,
              int *booking_count, WaitingQueue *waiting, Counters *c) {
    FILE *fp;
    Train t;
    Passenger p;
    WaitingSave ws;
    int i, wcount;

    make_data_folder();
    c->pnr_no = 6;
    c->passenger_no = 6;

    bst_init(trains);
    fp = fopen(TRAINS_FILE, "rb");
    if (fp != NULL) {
        while (fread(&t, sizeof(Train), 1, fp) == 1) {
            bst_insert(trains, t);
        }
        fclose(fp);
    }

    list_init(passengers);
    fp = fopen(PASSENGERS_FILE, "rb");
    if (fp != NULL) {
        while (fread(&p, sizeof(Passenger), 1, fp) == 1) {
            list_add(passengers, p);
        }
        fclose(fp);
    }

    *booking_count = 0;
    fp = fopen(BOOKINGS_FILE, "rb");
    if (fp != NULL) {
        fread(booking_count, sizeof(int), 1, fp);
        if (*booking_count > MAX_BOOKINGS) {
            *booking_count = 0;
        }
        for (i = 0; i < *booking_count; i++) {
            fread(&bookings[i], sizeof(Booking), 1, fp);
        }
        fclose(fp);
    }

    queue_init(waiting);
    fp = fopen(WAITING_FILE, "rb");
    if (fp != NULL) {
        fread(&wcount, sizeof(int), 1, fp);
        for (i = 0; i < wcount; i++) {
            fread(&ws, sizeof(WaitingSave), 1, fp);
            queue_add(waiting, ws.pnr, ws.passenger_name,
                      ws.train_no, ws.journey_date, ws.travel_class);
        }
        fclose(fp);
    }

    fp = fopen(COUNTERS_FILE, "rb");
    if (fp != NULL) {
        fread(c, sizeof(Counters), 1, fp);
        fclose(fp);
    }
}
