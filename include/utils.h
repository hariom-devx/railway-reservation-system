#ifndef UTILS_H
#define UTILS_H

void clear_buffer(void);
void read_string(char *buf, int size);
int read_int(void);
float read_float(void);
void format_train_no(char *dest, char *input);
void read_train_no(char *dest);
void make_pnr(char *pnr, int num);
void make_passenger_id(char *id, int num);
char *class_name(int cls);
float class_multiplier(int cls);
void print_line(void);

#endif
