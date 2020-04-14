

all: BestFirstSearch

PriorityQueue.o: PriorityQueue.cpp PriorityQueue.h Node.h
	g++ -c PriorityQueue.cpp -o PriorityQueue.o
BestFirstSearch.o: BestFirstSearch.cpp Node.h PriorityQueue.h
	g++ -c BestFirstSearch.cpp -o BestFirstSearch.o
BestFirstSearch: BestFirstSearch.o PriorityQueue.o
	g++ BestFirstSearch.o PriorityQueue.o -o BestFirstSearch

run: BestFirstSearch
	./BestFirstSearch input.txt

clean:
	rm *.o BestFirstSearch
