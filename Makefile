CC := gcc
CFLAGS := -Wall -Wextra -fsanitize=address -Wshadow -Wpedantic -g
#OBJS := build/main.o build/input.o build/output.o build/dummy_table.o 
SRC := $(wildcard src/*.c)
OBJS := $(patsubst src/%.c, build/%.o, $(SRC))
all: build/minidb
build/minidb: $(OBJS)
	@echo "Building binary..."
	@$(CC) $(CFLAGS) $^ -o $@
build/%.o: src/%.c
	@echo "Compiling..." $<
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -r build/*.o build/minidb
