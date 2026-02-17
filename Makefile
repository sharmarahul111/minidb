CC = gcc
CFLAGS = -Wall -g
all: minidb
minidb: main.o input.o
	$(CC) $(CFLAGS) $^ -o minidb
main.o: src/main.c
	$(CC) $(CFLAGS) -c $< -o $@
input.o: src/input.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -r *.o minidb
