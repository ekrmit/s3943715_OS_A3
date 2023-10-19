CC = g++
CFLAGS = -Wall -Werror -g

all: firstfit bestfit

firstfit: firstfit.cpp
	$(CC) $(CFLAGS) $? -o $@

bestfit: bestfit.cpp
	$(CC) $(CFLAGS) $? -o $@

clean: 
	rm -f *.o firstfit bestfit *.o
