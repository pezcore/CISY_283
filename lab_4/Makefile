CC = gcc
CFLAGS = -Wall -ansi
all: $(patsubst %.c, %.out, $(wildcard *.c))
%.out: %.c Makefile
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm *.out         
