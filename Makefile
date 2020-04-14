

all: BestFirstSearch

BestFirstSearch.o: BestFirstSearch.cpp
	g++ -c BestFirstSearch.cpp -o BestFirstSearch.o
BestFirstSearch: BestFirstSearch.o
	g++ BestFirstSearch.o -o BestFirstSearch

run: BestFirstSearch
	./BestFirstSearch input.txt

clean:
	rm *.o BestFirstSearch
