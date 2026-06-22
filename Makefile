# Compiler setup
CC=gcc
CFLAGS=-Wall -Wextra -std=c99

# Executables required by the assignment
TARGETS=window_join akari helicopters

build: $(TARGETS)

window_join: window_join.o
	$(CC) $(CFLAGS) window_join.o -o window_join

akari: akari.o
	$(CC) $(CFLAGS) akari.o -o akari

helicopters: helicopters.o
	$(CC) $(CFLAGS) helicopters.o -o helicopters

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGETS) *.o

.PHONY: build clean