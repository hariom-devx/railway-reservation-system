# Railway Reservation System - Makefile
# All modules linked into one program

CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -Iinclude -g
LDFLAGS =

BIN     = railway_system
OBJ_DIR = build
DATA_DIR = data

# All source files (linked together)
SRCS = src/main.c \
       src/utils.c \
       src/queue.c \
       src/linked_list.c \
       src/stack.c \
       src/bst.c \
       src/booking.c \
       src/admin.c \
       src/file_io.c \
       src/predata.c

OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

.PHONY: all clean run reset dirs

all: dirs $(BIN)

dirs:
	@mkdir -p $(OBJ_DIR) $(DATA_DIR)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)
	@echo "Build OK: ./$(BIN)"

$(OBJ_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(BIN)

reset: clean
	@rm -f $(DATA_DIR)/*.dat
	@echo "Data cleared. Run: make run"

clean:
	rm -rf $(OBJ_DIR) $(BIN)
