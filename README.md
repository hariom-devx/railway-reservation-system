# Railway Reservation System

A **simple console-based Railway Reservation System** in **C** for college / internship projects. Uses basic **Queue**, **Linked List**, **Stack**, and **BST** with easy-to-read code (`scanf`, fixed arrays, simple functions).

![Language](https://img.shields.io/badge/Language-C-blue)
![Standard](https://img.shields.io/badge/Standard-C11-green)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey)

---

## Features

| Feature | Description |
|---------|-------------|
| Ticket Booking | Book by train number or route; auto seat allocation |
| Ticket Cancellation | Cancel confirmed/waiting tickets with refund info |
| Waiting List | FIFO queue when seats are full |
| Passenger Search | Search by name or phone (Linked List) |
| Train Search | Search by train number or name (BST) |
| Seat Availability | Real-time seat count and occupancy |
| Fare Calculator | Distance × fare/km × class multiplier |
| Admin Panel | Add/remove trains, update fare, statistics |
| Undo Cancellation | LIFO stack restores last cancelled ticket |
| File Handling | Binary persistence in `data/` directory |

---

## Data Structures Used

| Structure | Purpose | Implementation File |
|-----------|---------|---------------------|
| **Queue** | Waiting list (FIFO) | `src/queue.c` |
| **Linked List** | Passenger records | `src/linked_list.c` |
| **Stack** | Undo cancellation (LIFO) | `src/stack.c` |
| **Binary Search Tree** | Train records (sorted by train number) | `src/bst.c` |

---

## Project Structure

```
Railway Reservation System/
├── include/           # Header files (.h)
│   ├── types.h
│   ├── queue.h
│   ├── linked_list.h
│   ├── stack.h
│   ├── bst.h
│   ├── booking.h
│   ├── admin.h
│   ├── file_io.h
│   └── utils.h
├── src/               # Source files (.c)
│   ├── main.c
│   ├── queue.c
│   ├── linked_list.c
│   ├── stack.c
│   ├── bst.c
│   ├── booking.c
│   ├── admin.c
│   ├── file_io.c
│   └── utils.c
├── data/              # Runtime data files (.dat)
├── docs/              # Documentation
├── Makefile
├── README.md
└── .gitignore
```

---

## Quick Start

### Prerequisites

- GCC or any C11-compatible compiler
- Make (optional but recommended)

### Compile & Run

```bash
make
./railway_system
```

Or use the run script:

```bash
chmod +x run.sh
./run.sh
```

Reset data and start fresh:

```bash
make reset
make run
```

### Default Admin Credentials

| Field | Value |
|-------|-------|
| Username | `admin` |
| Password | `admin123` |

---

## Main Menu

```
 1. Book Ticket
 2. Cancel Ticket
 3. Undo Cancellation (Stack)
 4. View Seat Availability
 5. Search Passenger (Linked List)
 6. Search Train (BST)
 7. Fare Calculator
 8. View Waiting List (Queue)
 9. View All Bookings
10. View All Trains (BST Inorder)
11. View Cancel Stack
12. Admin Panel
 0. Save & Exit
```

---

## Pre-loaded Data (First Run)

On first run, the system auto-loads **8 trains**, **5 passengers**, and **5 sample bookings**.

| Train No | Name | Route |
|----------|------|-------|
| **001** | Rajdhani Express | Mumbai → Delhi |
| **002** | Karnataka Express | Bangalore → Delhi |
| **003** | Howrah Rajdhani | Kolkata → Delhi |
| **004** | Shatabdi Express | Mumbai → Ahmedabad |
| **005** | Tamil Nadu Express | Chennai → Delhi |
| **006** | Goa Express | Mumbai → Goa |
| **007** | Coromandel Express | Chennai → Kolkata |
| **008** | Duronto Express | Delhi → Kolkata |

**Test PNR:** `PNR001`–`PNR005` | **Passengers:** `001`–`005` | Type train **1** or **001**

Full list: [docs/PREDATA.md](docs/PREDATA.md) | Menu option **13** shows this anytime.

---

## Fare Calculation

```
Fare = Distance (km) × Fare per km × Class Multiplier
```

| Class | Multiplier |
|-------|------------|
| Sleeper (SL) | 1.0× |
| AC 3-Tier (3A) | 1.8× |
| AC 2-Tier (2A) | 2.5× |
| AC First (1A) | 4.0× |

---

## Documentation

| Document | Description |
|----------|-------------|
| [docs/COMPILATION.md](docs/COMPILATION.md) | Detailed build instructions |
| [docs/PROJECT_REPORT.md](docs/PROJECT_REPORT.md) | Project report summary |
| [docs/SAMPLE_OUTPUT.md](docs/SAMPLE_OUTPUT.md) | Sample console output |
| [docs/INTERVIEW_QA.md](docs/INTERVIEW_QA.md) | Viva / interview Q&A |
| [docs/GITHUB_UPLOAD.md](docs/GITHUB_UPLOAD.md) | GitHub upload commands |
| [docs/RESUME_DESCRIPTION.md](docs/RESUME_DESCRIPTION.md) | Resume bullet points |

---

## Author

Developed as a **Data Structures and Algorithms** academic / internship project.

---

## License

This project is open-source for educational purposes.
