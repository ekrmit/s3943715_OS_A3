CC = g++
CFLAGS = -Wall -Werror -g

all: firstfit beestfit

firstfit: main.cpp
	$(CC) $(CFLAGS) $? -o $@

bestfit: main.cpp
	$(CC) $(CFLAGS) $? -o $@

clean: 
	rm -f *.o firstfit bestfit *.o
