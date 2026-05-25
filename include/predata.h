#ifndef PREDATA_H
#define PREDATA_H

#include "booking.h"

/* Load trains, passengers and sample bookings when database is empty */
void load_predata(RailwaySystem *sys);
void show_predata_info(void);

#endif
