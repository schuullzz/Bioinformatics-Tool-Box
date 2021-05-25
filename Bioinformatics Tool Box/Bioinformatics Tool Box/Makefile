#Author: Timothy Schultz

CC = g++
CFLAGS = -g -Wall
TARGET = toolbox
OBJ = Main.o dnatoprotein.o
SRC = Main.cpp dnatoprotein.cpp

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

main.o: Main.cpp dnatoprotein.h
	$(CC) $(CFLAGS) -c Main.cpp

dnatoprotein.o: dnatoprotein.cpp dnatoprotein.h
	$(CC) $(CFLAGS) -c dnatoprotein.cpp

.PHONY: clean
clean:
	/bin/rm -f *.o $(TARGET)
	/bin/rm -f mRNA.txt $(TARGET)
	/bin/rm -f Protein.txt $(TARGET)
