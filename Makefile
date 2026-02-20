CC := gcc
CFLAGS := -Wall -Wextra -fsanitize=address -Wshadow -Wpedantic -g
OBJS := build/main.o build/input.o build/output.o build/dummy_table.o
all: build/minidb
build/minidb: $(OBJS)
	@echo "Building binary..."
	@$(CC) $(CFLAGS) $^ -o $@
build/main.o: src/main.c
	@echo $<
	@$(CC) $(CFLAGS) -c $< -o $@
build/input.o: src/input.c
	@echo $<
	@$(CC) $(CFLAGS) -c $< -o $@
build/output.o: src/output.c
	@echo $<
	@$(CC) $(CFLAGS) -c $< -o $@
build/dummy_table.o: src/dummy_table.c
	@echo $<
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -r build/*.o build/minidb
