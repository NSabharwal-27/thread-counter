CC = gcc
CFLAGS = -Wall -lpthread
SRC = src
OUT = count

all: main

main:
	$(CC) $(CFLAGS) $(SRC)/main.c -o $(OUT)

clean:
	rm -f $(OUT)
