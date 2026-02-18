CC = gcc
CFLAGS = -Wall -g
all: minidb
minidb: main.o input.o output.o dummy_table.o
	@echo "Building binary..."
	@$(CC) $(CFLAGS) $^ -o minidb
main.o: src/main.c
	$(CC) $(CFLAGS) -c $< -o $@
input.o: src/input.c
	$(CC) $(CFLAGS) -c $< -o $@
output.o: src/output.c
	$(CC) $(CFLAGS) -c $< -o $@
dummy_table.o: src/dummy_table.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -r *.o minidb
