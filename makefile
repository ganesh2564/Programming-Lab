CC := g++
CFLAGS := -std=c++11 -Wall
TARGETS := question1 question2 question3
SOURCES := question1.cpp question2.cpp question3.cpp
INCLUDE_DIR := /path/to/your/include/directory

.PHONY: all clean

all: $(TARGETS)

question1: question1.cpp $(INCLUDE_DIR)/list.h
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ $<

question2: question2.cpp $(INCLUDE_DIR)/list.h
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ $<

question3: question3.cpp $(INCLUDE_DIR)/list.h
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ $<

run_question1: question1
	./question1

run_question2: question2
	./question2

run_question3: question3
	./question3

clean:
	rm -f $(TARGETS)
