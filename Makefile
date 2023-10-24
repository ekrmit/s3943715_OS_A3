CC = g++
CFLAGS = -Wall -Werror -g

all: clean firstfit bestfit

firstfit: first_fit_main.cpp AllocationNode.h FirstFit.o
	$(CC) $(CFLAGS) $? -o $@

bestfit: best_fit_main.cpp AllocationNode.h BestFit.o
	$(CC) $(CFLAGS) $? -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -f *.o firstfit bestfit *.o
