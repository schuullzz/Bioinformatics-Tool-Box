#Author: Timothy Schultz

CC = g++
CFLAGS = -g -Wall
TARGET = biotoolbox
OBJ = Main.o
SRC = Main.cpp

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

main.o: Main.cpp
	$(CC) $(CFLAGS) -c Main.cpp 

.PHONY: clean
clean:
	/bin/rm -f *.o $(TARGET)
