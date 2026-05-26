# Project Report Summary

## Railway Reservation System

**Project Type:** Data Structures and Algorithms  
**Language:** C (C11)  
**Platform:** Console Application  
**Author:** Hariom  

### System Flow (Summary)

See full diagrams in [FLOW_DIAGRAM.md](FLOW_DIAGRAM.md) and [README](../README.md).

```
User → Main Menu → Booking / Admin → Data Structures → Save to data/*.dat
```

---

## 1. Introduction

This project is a menu-driven console program for railway ticket booking and cancellation. It uses Queue, Linked List, Stack, and Binary Search Tree as required in the Data Structures syllabus.

---

## 2. Objectives

1. Implement a railway reservation system using **Queue, Linked List, Stack, and BST**
2. Provide ticket booking, cancellation, and waiting list management
3. Enable passenger and train search operations
4. Calculate fare based on distance and travel class
5. Persist data using **binary file handling**
6. Offer an **admin panel** for system management

---

## 3. Data Structures & Algorithms

### 3.1 Queue (Waiting List)

- **Type:** FIFO (First In, First Out)
- **Operations:** enqueue, dequeue, peek, display
- **Use:** When train seats are full, passengers are added to waiting list in order

### 3.2 Linked List (Passenger Records)

- **Type:** Singly Linked List
- **Operations:** append, search (by ID/name/phone), remove, traverse
- **Use:** Dynamic storage of passenger profiles without fixed size limits

### 3.3 Stack (Undo Cancellation)

- **Type:** LIFO (Last In, First Out)
- **Operations:** push, pop, peek, display
- **Use:** Store recently cancelled tickets; undo restores the last cancellation

### 3.4 Binary Search Tree (Train Records)

- **Key:** Train number (string comparison)
- **Operations:** insert, search, delete, inorder traversal
- **Time Complexity:** O(log n) average for search/insert/delete
- **Use:** Efficient train lookup and sorted display

---

## 4. System Modules

| Module | File(s) | Responsibility |
|--------|---------|----------------|
| Main Menu | `main.c` | User interface and menu navigation |
| Booking | `booking.c` | Ticket book/cancel, fare, search |
| Admin | `admin.c` | Train/passenger management, statistics |
| File I/O | `file_io.c` | Load/save binary data files |
| Utilities | `utils.c` | Input validation, PNR generation |

---

## 5. File Handling

Data is stored in binary format under `data/`:

| File | Content |
|------|---------|
| `trains.dat` | Train BST records |
| `passengers.dat` | Linked list passenger nodes |
| `bookings.dat` | Booking array |
| `waiting.dat` | Waiting queue entries |
| `cancel_stack.dat` | Cancelled booking stack |
| `counters.dat` | PNR and passenger ID counters |

---

## 6. Testing Scenarios

1. Book ticket on available train → Confirm seat and PNR
2. Book when seats full → Add to waiting queue
3. Cancel ticket → Seat freed, waiting list processed
4. Undo cancellation → Stack pop restores booking
5. Search train by number → BST lookup
6. Admin add train → BST insert
7. Exit application → Data persisted to files

---

## 7. Conclusion

The Railway Reservation System successfully demonstrates practical application of four fundamental data structures in a real-world domain. The modular architecture, file persistence, and menu-driven interface make it suitable for academic submission and internship portfolios.

---

## 8. Future Work

- GUI version
- Login for each user
- More trains and routes
