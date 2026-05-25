# Viva / Interview Questions & Answers

## Data Structures

### Q1. Why did you use a Queue for the waiting list?

**Answer:** A waiting list follows **FIFO (First In, First Out)** — the passenger who registered first gets the seat first when it becomes available. Queue operations (`enqueue` at rear, `dequeue` from front) map directly to this real-world behavior.

---

### Q2. Why use a Stack for undo cancellation?

**Answer:** Undo is naturally **LIFO (Last In, First Out)** — the most recently cancelled ticket should be restored first. When a user cancels multiple tickets, `stack_push` stores each cancellation and `stack_pop` restores the latest one.

---

### Q3. Why use BST instead of an array for trains?

**Answer:** BST provides **O(log n)** average search, insert, and delete when keyed by train number, compared to O(n) linear search in an array. Inorder traversal also displays trains in **sorted order** by train number.

---

### Q4. What is the time complexity of BST search?

**Answer:** **O(log n)** in average case for a balanced tree; **O(n)** in worst case when the tree becomes skewed (sorted insertions). Our train numbers are semi-random strings, so average case applies.

---

### Q5. Why Linked List for passengers?

**Answer:** Linked lists allow **dynamic memory allocation** — no fixed maximum passenger count. Insertion at the end is O(n) for traversal but avoids shifting elements like in arrays.

---

## Project Design

### Q6. Explain the modular architecture.

**Answer:** Each data structure has its own `.c/.h` pair (`queue.c`, `bst.c`, etc.). Business logic is in `booking.c`, admin operations in `admin.c`, and persistence in `file_io.c`. This separation improves **maintainability** and **testability**.

---

### Q7. How does file handling work?

**Answer:** Data is saved in **binary format** using `fwrite`/`fread`. Trains are serialized via BST inorder traversal; passengers via linked list traversal; bookings as a flat array. Counters (PNR, passenger ID) are stored separately to ensure unique IDs across sessions.

---

### Q8. How is fare calculated?

**Answer:**
```
Fare = distance_km × fare_per_km × class_multiplier
```
Class multipliers: SL=1.0, 3A=1.8, 2A=2.5, 1A=4.0

---

### Q9. What happens when a ticket is cancelled?

**Answer:**
1. Seat count is incremented on the train
2. `process_waiting_list` dequeues waiting passengers for that train if seats are free
3. Cancelled booking is pushed onto the **cancel stack** for undo
4. 75% refund amount is displayed

---

### Q10. What error handling is implemented?

**Answer:**
- Input validation for phone numbers, integers, and doubles
- NULL pointer checks before DS operations
- File open failure messages
- Duplicate train/passenger detection
- Memory allocation failure handling with error messages

---

## Advanced Questions

### Q11. How would you improve PNR lookup?

**Answer:** Use a **hash table** for O(1) average PNR lookup instead of linear scan through the bookings array.

---

### Q12. Difference between Queue and Stack in this project?

| Aspect | Queue (Waiting List) | Stack (Undo) |
|--------|---------------------|--------------|
| Order | FIFO | LIFO |
| Add | Rear (enqueue) | Top (push) |
| Remove | Front (dequeue) | Top (pop) |
| Purpose | Fair seat allocation | Restore last cancel |

---

### Q13. Can BST delete be optimized?

**Answer:** Yes — use **AVL** or **Red-Black Tree** for guaranteed O(log n) worst case. For this academic project, standard BST is sufficient.

---

### Q14. What is the space complexity of your system?

**Answer:** **O(n)** for n passengers, trains, and bookings — each stored once in memory. File storage mirrors in-memory structures.

---

### Q15. Real-world difference from IRCTC?

**Answer:** IRCTC uses distributed databases, concurrent booking locks, payment gateways, and complex routing graphs. Our project is a **single-user educational simulation** focusing on core DS concepts.
