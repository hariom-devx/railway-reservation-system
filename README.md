# Railway Reservation System

> Console-based ticket booking system in **C** using **Queue, Linked List, Stack, and BST**  
> Author: **Hariom** | [hariom-devx/railway-reservation-system](https://github.com/hariom-devx/railway-reservation-system)

---

## Table of Contents

1. [Overview](#overview)
2. [System Architecture](#system-architecture)
3. [Program Flow](#program-flow)
4. [Booking Flow](#booking-flow)
5. [Data Structures Map](#data-structures-map)
6. [Features](#features)
7. [Quick Start](#quick-start)
8. [Test Data](#test-data)
9. [Project Structure](#project-structure)
10. [Documentation](#documentation)

---

## Overview

```mermaid
flowchart LR
    subgraph User
        U[Passenger / Admin]
    end
    subgraph App
        M[Main Menu]
        B[Booking Module]
        A[Admin Panel]
    end
    subgraph Storage
        F[(Binary Files\nin data/)]
    end
    U --> M
    M --> B
    M --> A
    B --> F
    A --> F
```

| Item | Detail |
|------|--------|
| Language | C (C11) |
| Build | Makefile |
| Interface | Menu-driven console |
| Persistence | `fread` / `fwrite` in `data/` folder |

---

## System Architecture

How all modules connect:

```mermaid
flowchart TB
    MAIN["main.c\n(Menu & User Input)"]

    subgraph Business["Business Logic"]
        BOOK["booking.c\nBook / Cancel / Search"]
        ADMIN["admin.c\nTrains & Stats"]
        PRED["predata.c\nSample Data"]
    end

    subgraph DS["Data Structures"]
        BST["bst.c\nTrains"]
        LIST["linked_list.c\nPassengers"]
        QUEUE["queue.c\nWaiting List"]
        STACK["stack.c\nUndo Cancel"]
    end

    subgraph Support["Support"]
        UTIL["utils.c\nInput & PNR"]
        FILE["file_io.c\nSave / Load"]
    end

  MAIN --> BOOK
  MAIN --> ADMIN
  MAIN --> PRED
  BOOK --> BST
  BOOK --> LIST
  BOOK --> QUEUE
  BOOK --> STACK
  ADMIN --> BST
  ADMIN --> LIST
  PRED --> BST
  PRED --> LIST
  BOOK --> FILE
  ADMIN --> FILE
  BOOK --> UTIL
  ADMIN --> UTIL
  FILE --> BST
  FILE --> LIST
  FILE --> QUEUE
```

---

## Program Flow

From start to exit:

```mermaid
flowchart TD
    START([Start Program]) --> LOAD[Load saved data\nfrom data/ folder]
    LOAD --> SAMPLE{Trains\nempty?}
    SAMPLE -->|Yes| PRE[Load sample trains\n001 to 008]
    SAMPLE -->|No| MENU
    PRE --> MENU[Show Main Menu]

    MENU --> C{User Choice}

    C -->|1| BOOK[Book Ticket]
    C -->|2| CAN[Cancel Ticket]
    C -->|3| UNDO[Undo Cancel - Stack]
    C -->|4| SEAT[Seat Availability]
    C -->|5| SP[Search Passenger - List]
    C -->|6| ST[Search Train - BST]
    C -->|7| FARE[Fare Calculator]
    C -->|8| WAIT[View Waiting - Queue]
    C -->|9| ALL[All Bookings]
    C -->|10| TR[All Trains - Inorder]
    C -->|11| STK[Cancel Stack View]
    C -->|12| ADM[Admin Panel]
    C -->|13| INFO[Pre-data Info]
    C -->|0| SAVE[Save all data]

    BOOK --> MENU
    CAN --> MENU
    UNDO --> MENU
    SEAT --> MENU
    SP --> MENU
    ST --> MENU
    FARE --> MENU
    WAIT --> MENU
    ALL --> MENU
    TR --> MENU
    STK --> MENU
    ADM --> MENU
    INFO --> MENU

    SAVE --> END([Exit])
```

---

## Booking Flow

```mermaid
flowchart TD
    A[Enter Train Number\n001 or 1] --> B{BST: Train\nfound?}
    B -->|No| X[Show: Train not found]
    B -->|Yes| C[Enter passenger details\nName, Phone, Date, Class]
    C --> D{Seats\navailable?}

    D -->|Yes| E[Reduce seat count]
    E --> F[Create PNR\nAdd to bookings array]
    F --> G[Print CONFIRMED\nSeat + Fare]

    D -->|No| H[Add to Waiting Queue\nFIFO]
    H --> I[Print WAITING LIST\nPNR + Fare]

    G --> J[(Save on exit)]
    I --> J
```

### Cancel and Undo Flow

```mermaid
flowchart LR
    subgraph Cancel
        C1[Enter PNR] --> C2{Confirmed\nticket?}
        C2 -->|Yes| C3[Free seat on train]
        C3 --> C4[Push booking on Stack]
        C4 --> C5[Promote waiting list\nfrom Queue]
        C2 -->|Waiting| C6[Remove from Queue]
    end

    subgraph Undo
        U1[Stack Pop] --> U2{Seat free?}
        U2 -->|Yes| U3[Restore booking]
        U2 -->|No| U4[Push back on Stack]
    end
```

---

## Data Structures Map

```mermaid
flowchart LR
    subgraph Queue["QUEUE - FIFO"]
        Q1[PNR001] --> Q2[PNR002] --> Q3[PNR003]
    end

    subgraph List["LINKED LIST"]
        L1[001 Rahul] --> L2[002 Priya] --> L3[003 Amit]
    end

    subgraph Stack["STACK - LIFO"]
        direction TB
        S3[Last Cancel] --- S2[...] --- S1[First Cancel]
    end

    subgraph BST["BST - Train No."]
        direction TB
        R((004)) 
        R --> L((002))
        R --> RT((007))
    end
```

| Data Structure | File | Real Use in Project |
|----------------|------|---------------------|
| **Queue** | `queue.c` | Waiting list when train is full |
| **Linked List** | `linked_list.c` | Passenger records |
| **Stack** | `stack.c` | Undo last cancellation |
| **BST** | `bst.c` | Train search by number `001`, `002`... |

---

## Features

| # | Feature | Data Structure |
|---|---------|----------------|
| 1 | Book ticket | BST + Array |
| 2 | Cancel ticket | BST + Stack |
| 3 | Undo cancel | Stack |
| 4 | Seat availability | BST |
| 5 | Search passenger | Linked List |
| 6 | Search train | BST |
| 7 | Fare calculator | BST |
| 8 | Waiting list | Queue |
| 9 | View bookings | Array |
| 10 | View all trains | BST inorder |
| 11 | View cancel stack | Stack |
| 12 | Admin panel | BST + List |
| 13 | Pre-data info | — |
| 0 | Save and exit | File I/O |

---

## Quick Start

```bash
git clone https://github.com/hariom-devx/railway-reservation-system.git
cd railway-reservation-system
make
./railway_system
```

Reset and run with fresh sample data:

```bash
make reset && make run
```

| Admin Login | Value |
|-------------|-------|
| Username | `admin` |
| Password | `admin123` |

---

## Test Data

| Train | Name | Route |
|:-----:|------|-------|
| **001** | Rajdhani Express | Mumbai → Delhi |
| **002** | Karnataka Express | Bangalore → Delhi |
| **003** | Howrah Rajdhani | Kolkata → Delhi |
| **004** | Shatabdi Express | Mumbai → Ahmedabad |
| **005** | Tamil Nadu Express | Chennai → Delhi |
| **006** | Goa Express | Mumbai → Goa |
| **007** | Coromandel Express | Chennai → Kolkata |
| **008** | Duronto Express | Delhi → Kolkata |

**Passengers:** `001` – `005`  
**Sample PNR:** `PNR001` – `PNR005` (`PNR005` = waiting list)

> Tip: Type train `1` or `001` — both work.

---

## Project Structure

```
railway-reservation-system/
│
├── include/              Headers
│   ├── types.h             Structures
│   ├── bst.h               Train BST
│   ├── queue.h             Waiting list
│   ├── stack.h             Undo stack
│   ├── linked_list.h       Passengers
│   ├── booking.h           Core system
│   ├── admin.h             Admin panel
│   ├── file_io.h           File save/load
│   ├── predata.h           Sample data
│   └── utils.h             Helpers
│
├── src/                    Source code
│   ├── main.c              Entry + menu
│   ├── booking.c           Tickets
│   ├── bst.c               Trains
│   ├── queue.c             Waiting
│   ├── stack.c             Undo
│   ├── linked_list.c       Passengers
│   ├── admin.c             Admin
│   ├── file_io.c           Files
│   ├── predata.c           Demo data
│   └── utils.c             Input/PNR
│
├── data/                   Saved .dat files
├── docs/                   Reports & diagrams
├── Makefile
├── run.sh
└── README.md
```

---

## Documentation

| Document | Description |
|----------|-------------|
| [Flow Diagrams (detailed)](docs/FLOW_DIAGRAM.md) | All diagrams in one page |
| [Compilation Guide](docs/COMPILATION.md) | Build on Windows/Linux/Mac |
| [Project Report](docs/PROJECT_REPORT.md) | Report summary |
| [Pre-loaded Data](docs/PREDATA.md) | Test trains & PNR |
| [Sample Output](docs/SAMPLE_OUTPUT.md) | Console examples |

---

## Fare Formula

```
Fare = Distance (km) × Fare per km × Class multiplier
```

| Class | Code | Multiplier |
|-------|:----:|:----------:|
| Sleeper | 1 | 1.0 |
| AC 3-Tier | 2 | 1.8 |
| AC 2-Tier | 3 | 2.5 |
| AC First | 4 | 4.0 |

---

## License

MIT License — free for educational use.
