#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void read_string(char *buf, int size) {
    (void)size;
    scanf("%s", buf);
    clear_buffer();
}

int read_int(void) {
    int n;
    scanf("%d", &n);
    clear_buffer();
    return n;
}

float read_float(void) {
    float f;
    scanf("%f", &f);
    clear_buffer();
    return f;
}

/* Convert 1, 01, 001 into 001 */
void format_train_no(char *dest, char *input) {
    int n = 0;
    int i;

    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            n = n * 10 + (input[i] - '0');
        }
    }
    if (n < 1) {
        n = 1;
    }
    if (n > 999) {
        n = 999;
    }
    sprintf(dest, "%03d", n);
}

void read_train_no(char *dest) {
    char temp[20];
    printf("(e.g. 001 or 1): ");
    read_string(temp, 20);
    format_train_no(dest, temp);
}

void make_pnr(char *pnr, int num) {
    sprintf(pnr, "PNR%03d", num);
}

void make_passenger_id(char *id, int num) {
    sprintf(id, "%03d", num);
}

char *class_name(int cls) {
    if (cls == 1) return "Sleeper";
    if (cls == 2) return "AC 3-Tier";
    if (cls == 3) return "AC 2-Tier";
    if (cls == 4) return "AC First";
    return "Sleeper";
}

float class_multiplier(int cls) {
    if (cls == 2) return 1.8;
    if (cls == 3) return 2.5;
    if (cls == 4) return 4.0;
    return 1.0;
}

void print_line(void) {
    printf("----------------------------------------\n");
}
