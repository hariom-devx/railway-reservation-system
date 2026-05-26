# Railway Reservation System — Flow Diagrams

Use this page for project report, PPT, or viva explanation.

---

## 1. High-Level System

```mermaid
flowchart TB
    USER[User] --> APP[Railway Reservation System]
    APP --> DS[Data Structures Layer]
    APP --> IO[File Storage data/]

    DS --> Q[Queue]
    DS --> LL[Linked List]
    DS --> ST[Stack]
    DS --> BST[BST]
```

---

## 2. Main Menu Flow

```mermaid
flowchart TD
    A[Start] --> B[system_load]
    B --> C[load_predata if empty]
    C --> D{Menu Loop}
    D --> E[User selects 0-13]
    E --> D
    E -->|0| F[system_save + Exit]
```

---

## 3. Ticket Booking — Step by Step

| Step | Action |
|:----:|--------|
| 1 | User enters train number |
| 2 | BST search by train number |
| 3 | Enter name, phone, date, class |
| 4 | Calculate fare |
| 5 | If seat available → confirm |
| 6 | If full → add to Queue |
| 7 | Store in bookings array |

```mermaid
sequenceDiagram
    participant U as User
    participant M as main.c
    participant B as booking.c
    participant T as BST
    participant Q as Queue

    U->>M: Book Ticket
    M->>B: book_ticket()
    U->>B: Train 001
    B->>T: bst_find(001)
    T-->>B: Train node
    alt Seat available
        B->>B: Allocate seat
        B-->>U: PNR + Seat printed
    else Full
        B->>Q: queue_add()
        B-->>U: Waiting list message
    end
```

---

## 4. Cancellation Flow

```mermaid
flowchart TD
    A[Enter PNR] --> B[Find in bookings]
    B --> C{Found?}
    C -->|No| D[Error]
    C -->|Yes| E{Confirmed?}
    E -->|Waiting| F[Remove from Queue]
    E -->|Yes| G[Increase train seats]
    G --> H[stack_push cancelled ticket]
    H --> I[check_waiting - Queue dequeue]
    F --> J[Mark cancelled]
    I --> J
```

---

## 5. File Save Flow (on Exit)

```mermaid
flowchart LR
    A[Menu 0 Save] --> B[trains.dat]
    A --> C[passengers.dat]
    A --> D[bookings.dat]
    A --> E[waiting.dat]
    A --> F[counters.dat]
```

---

## 6. Admin Panel Flow

```mermaid
flowchart TD
    A[Admin Login] --> B{Valid?}
    B -->|No| C[Exit]
    B -->|Yes| D[Admin Menu]
    D --> E[Add Train → BST insert]
    D --> F[Delete Train → BST delete]
    D --> G[Update Fare → BST find]
    D --> H[Add Passenger → List add]
    D --> I[Show Statistics]
```

---

## 7. Data Structure — Where Used

```mermaid
mindmap
  root((Railway System))
    Queue
      Waiting list
      FIFO order
    Linked List
      Passenger records
      Search by name/phone
    Stack
      Undo cancel
      LIFO order
    BST
      Train records
      Search by 001 002
```

---

Back to [README](../README.md)
