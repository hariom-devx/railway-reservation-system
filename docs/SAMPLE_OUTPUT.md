# Sample Output Screenshots

> Run `./railway_system` from the project root to reproduce these outputs.

---

## 1. Application Startup

```
============================================================
       RAILWAY RESERVATION SYSTEM
       Data Structures Project (C)
============================================================
 1. Book Ticket
 2. Cancel Ticket
 ...
============================================================
Enter your choice:

Welcome to Railway Reservation System!
Default Admin - Username: admin | Password: admin123

Loading sample train data...
```

---

## 2. Book Ticket (Confirmed)

```
============================================================
  BOOK TICKET
============================================================
1. Book by Train Number
2. Book by Route (Source & Destination)
Choice: 1
Enter Train Number: 12951
Enter Passenger Name: Rahul Sharma
Enter Phone Number: 9876543210
Enter Journey Date (DD-MM-YYYY): 15-06-2026

Select Travel Class:
  1. Sleeper (SL)
  2. AC 3-Tier (3A)
  3. AC 2-Tier (2A)
  4. AC First Class (1A)
Choice: 2

*** TICKET CONFIRMED ***
PNR: PNR100001
Train: 12951 (Rajdhani Express)
Route: Mumbai -> Delhi
Date: 15-06-2026 | Class: AC 3-Tier (3A)
Seat: 1 | Fare: Rs.6220.80
```

---

## 3. Seat Availability

```
============================================================
  SEAT AVAILABILITY
============================================================
Enter Train Number: 12951

Train: 12951 - Rajdhani Express
Route: Mumbai -> Delhi
Available Seats: 499 / 500
Occupancy: 0.2%
```

---

## 4. Waiting List (Queue)

```
============================================================
  WAITING LIST
============================================================

--- Waiting List (Queue: FIFO) ---
1. PNR: PNR100002 | Priya Patel | Train: 12951 | Date: 20-06-2026 | Class: Sleeper (SL)
Total in waiting list: 1
```

---

## 5. Train Search (BST)

```
============================================================
  SEARCH TRAIN
============================================================
1. Search by Train Number
2. Search by Train Name
Choice: 1
Enter Train Number: 12951

Train: 12951 (Rajdhani Express)
Route: Mumbai -> Delhi
Departure: 17:00 | Arrival: 08:30
Seats: 499/500 | Distance: 1384 km | Base Fare/km: Rs.2.50
```

---

## 6. Cancel & Undo (Stack)

```
============================================================
  CANCEL TICKET
============================================================
Enter PNR: PNR100001

Ticket cancelled successfully.
PNR: PNR100001 | Refund Amount: Rs.4665.60
Use 'Undo Cancellation' within this session to restore.

============================================================
  UNDO CANCELLATION
============================================================

Cancellation undone successfully.
PNR: PNR100001 restored | Seat: 500
```

---

## 7. Admin Statistics

```
============================================================
  SYSTEM STATISTICS
============================================================
Trains Registered     : 5
Passengers Registered : 2
Total Bookings        : 3
Confirmed Tickets     : 2
Waiting List (Queue)  : 1
Cancelled Tickets     : 0
Undo Stack Size       : 0
Estimated Revenue     : Rs.12441.60
```

---

## Screenshot Tips for GitHub

1. Run the program in a terminal with dark theme
2. Capture: Main menu, booking confirmation, BST train list, admin panel
3. Save as `docs/screenshots/menu.png`, `booking.png`, etc.
4. Add to README: `![Booking](docs/screenshots/booking.png)`
