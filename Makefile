CC = gcc
CFLAGS = -Wall -g
all: minidb
minidb: main.o schema.o
	$(CC) $(CFLAGS) $^ -o minidb
main.o: src/main.c
	$(CC) $(CFLAGS) -c $< -o $@
schema.o: src/schema.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -r *.o minidb
