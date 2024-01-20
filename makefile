CC=c++
CFLAGS=-std=c++23 -Wall -Werror
binaries = StringInt.o UnitTest_StringInt.o main.o
binariesFolder = ./binaries

OBJS = $(wildcard $(binariesFolder)/*.o)

all: main

test: main
	./main

$(binariesFolder):
	mkdir -p $(binariesFolder)

main: $(binaries) $(binariesFolder)
	$(CC) -o main $(OBJS)

main.o: main.cpp $(binariesFolder)
	$(CC) -c $(CFLAGS) -o $(binariesFolder)/main.o main.cpp

StringInt.o: StringInt.cpp StringInt.hpp $(binariesFolder)
	$(CC) -c $(CFLAGS) -o $(binariesFolder)/StringInt.o StringInt.cpp

UnitTest_StringInt.o: UnitTest_StringInt.cpp UnitTest_StringInt.hpp $(binariesFolder)
	$(CC) -c $(CFLAGS) -o $(binariesFolder)/UnitTest_StringInt.o UnitTest_StringInt.cpp

clean: 
	rm -rf main $(binariesFolder)

