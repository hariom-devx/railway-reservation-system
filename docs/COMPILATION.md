# Compilation Guide

## Requirements

| Tool | Minimum Version |
|------|-----------------|
| GCC / Clang | Supports C11 |
| Make | GNU Make 3.x+ |

---

## Method 1: Using Makefile (Recommended)

```bash
# Clone or navigate to project directory
cd "Railway Reservation System"

# Build
make

# Run
./railway_system

# Clean build artifacts
make clean

# Build and run together
make run
```

---

## Method 2: Manual Compilation

```bash
mkdir -p build data

gcc -Wall -Wextra -std=c11 -Iinclude -g \
  src/main.c \
  src/utils.c \
  src/queue.c \
  src/linked_list.c \
  src/stack.c \
  src/bst.c \
  src/booking.c \
  src/admin.c \
  src/file_io.c \
  -o railway_system
```

---

## Method 3: Windows (MinGW)

```cmd
gcc -Wall -Wextra -std=c11 -Iinclude -g ^
  src\main.c src\utils.c src\queue.c src\linked_list.c ^
  src\stack.c src\bst.c src\booking.c src\admin.c src\file_io.c ^
  -o railway_system.exe

railway_system.exe
```

---

## Troubleshooting

| Issue | Solution |
|-------|----------|
| `gcc: command not found` | Install GCC: `xcode-select --install` (macOS) or `sudo apt install build-essential` (Linux) |
| `make: command not found` | Use manual compilation (Method 2) |
| Permission denied on binary | Run `chmod +x railway_system` |
| Data not saving | Ensure `data/` directory exists; run from project root |

---

## Compiler Flags Explained

| Flag | Purpose |
|------|---------|
| `-Wall -Wextra` | Enable warnings for safer code |
| `-std=c11` | Use C11 standard |
| `-Iinclude` | Include header path |
| `-g` | Debug symbols |
