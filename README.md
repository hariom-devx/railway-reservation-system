# Railway Reservation System

**Language:** C  
**Data Structures:** Queue, Stack, Linked List, Binary Search Tree  

## Overview

This is a **CLI-based Railway Reservation System** designed for academic purposes. It demonstrates real-world booking and cancellation workflows using multiple data structures. Users can also **signup and login** to manage reservations securely.

## Features

- **Booking Engine**: Reserve tickets with automatic seat management (FIFO queue).  
- **Cancellation**: Cancel tickets and maintain waitlist.  
- **Passenger Records**: View all passengers stored in CSV.  
- **Undo/Cancel Operations**: Rollback last operations using a Stack.  
- **Train Lookup**: Efficient train search using Binary Search Tree.  
- **Login/Signup System**: Basic authentication for multiple users.

## Directory Structure

## Directory Structure

railway-reservation-system/
src/ # C source files
include/ # Header files
data/ # CSV data storage
.gitignore
README.md

## Usage

1. **Compile the program**:

``bash
gcc -Iinclude src/*.c -o app

## Usage

1. Compile:

  terminal:
  gcc -Iinclude src/*.c -o app

2. Run:

  ./app

3. Follow on-screen instructions to signup/login and manage bookings.

   
## Future Improvements

* Add hashed password storage for security.
* Integrate train schedules with file input.
* Expand GUI support for better user experience.

