#Author: Timothy Schultz

CC = g++
CFLAGS = -g -Wall
TARGET = toolbox
OBJ = Main.o dnatoprotein.o burrowwheeler.o
SRC = Main.cpp dnatoprotein.cpp burrowwheeler.cpp

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

main.o: Main.cpp dnatoprotein.h burrowwheeler.cpp
	$(CC) $(CFLAGS) -c Main.cpp

dnatoprotein.o: dnatoprotein.cpp dnatoprotein.h
	$(CC) $(CFLAGS) -c dnatoprotein.cpp

burrowwheeler.o: burrowwheeler.cpp
	$(CC) $(CFLAGS) -c burrowwheeler.cpp

.PHONY: clean
clean:
	/bin/rm -f *.o $(TARGET)
	/bin/rm -f mRNA.txt $(TARGET)
	/bin/rm -f Protein.txt $(TARGET)
	/bin/rm -f Combination.txt $(TARGET)
	/bin/rm -f LastIndexSequence.txt $(TARGET)
