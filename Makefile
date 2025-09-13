CC=g++

SRC=src/
OUTPUT=./

all: clean main

clean: 
	rm -f $(OUTPUT)main $(SRC)*.o

main.o:
	$(CC) $(SRC)main.cpp -c -o $(SRC)main.o

main: main.o
	$(CC) $(SRC)main.o -o $(OUTPUT)main