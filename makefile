CC := g++
CFLAGS := -std=c++11 -Wall
TARGETS := question1 question2 question3
SOURCES := question1.cpp question2.cpp question3.cpp

.PHONY: all clean

all: $(TARGETS)

question1: question1.cpp list.h
	$(CC) $(CFLAGS) -o $@ $<

question2: question2.cpp list.h
	$(CC) $(CFLAGS) -o $@ $<

question3: question3.cpp list.h
	$(CC) $(CFLAGS) -o $@ $<

run_question1: question1
	./question1

run_question2: question2
	./question2

run_question3: question3
	./question3

clean:
	rm -f $(TARGETS)
