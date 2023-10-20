CC = g++
CFLAGS = -Wall -Werror -g

all: firstfit bestfit

firstfit: firstfit.cpp linkedlist.o
	$(CC) $(CFLAGS) $? -o $@

bestfit: bestfit.cpp
	$(CC) $(CFLAGS) $? -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -f *.o firstfit bestfit *.o
