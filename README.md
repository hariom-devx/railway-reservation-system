# Railway Reservation System

Console application in **C** for ticket booking and cancellation. Built for a **Data Structures** course project.

**GitHub:** [hariom-devx/railway-reservation-system](https://github.com/hariom-devx/railway-reservation-system)

## Features

- Book and cancel tickets
- Waiting list when seats are full (Queue)
- Passenger list (Linked List)
- Train list sorted by number (BST)
- Undo last cancellation (Stack)
- Save data to files on exit
- Admin login to add/delete trains

## Data Structures

| Structure | Use |
|-----------|-----|
| Queue | Waiting list |
| Linked List | Passengers |
| Stack | Undo cancel |
| BST | Trains by number |

## Folder Structure

```
include/     header files
src/         .c source files
data/        saved .dat files
docs/        report and notes
Makefile
run.sh
```

## How to Run

```bash
make
./railway_system
```

Fresh start (clears old saved data):

```bash
make reset
make run
```

**Admin:** username `admin` , password `admin123`

## Test Data (first run)

| Train | Name |
|-------|------|
| 001 | Rajdhani Express |
| 002 | Karnataka Express |
| 003 | Howrah Rajdhani |
| 004 | Shatabdi Express |
| 005 | Tamil Nadu Express |
| 006 | Goa Express |
| 007 | Coromandel Express |
| 008 | Duronto Express |

Passengers: **001** to **005**  
Sample PNR: **PNR001** to **PNR005** (PNR005 is on waiting list)

You can type train **1** or **001** — both work.

Menu **13** prints full test data list.

## Fare

`Fare = distance × fare_per_km × class multiplier`

Class: 1=Sleeper, 2=3A, 3=2A, 4=1A

## Docs

- [Compilation](docs/COMPILATION.md)
- [Project report](docs/PROJECT_REPORT.md)
- [Pre-loaded data](docs/PREDATA.md)
- [Sample output](docs/SAMPLE_OUTPUT.md)

## Author

Hariom
