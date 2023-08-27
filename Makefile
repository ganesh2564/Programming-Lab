CC=g++
CFLAGS=-std=c++11

all: main

main: main.cpp list.h
    $(CC) $(CFLAGS) -o main main.cpp

clean:
    rm -f main
