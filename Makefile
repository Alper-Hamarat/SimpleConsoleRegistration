CC=g++

SRC=./src/
OUTPUT=./

all: clean main

clean: 
	rm -f $(OUTPUT)main $(SRC)*.o

User-IO.o:
	$(CC) $(SRC)User-IO.cpp -c -o $(SRC)User-IO.o

main.o:
	$(CC) $(SRC)main.cpp -c -o $(SRC)main.o

main: main.o User-IO.o
	$(CC) $(SRC)main.o $(SRC)User-IO.o -o $(OUTPUT)main