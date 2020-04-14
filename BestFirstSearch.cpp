#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cassert>
#include <sstream>
#include <algorithm>
#include "Node.h"
#include "PriorityQueue.h"

struct item{
	int weight;
	int profit;
};

double bound(unsigned int i, std::vector<item> items, Node * n, int C, int n_items){
	double bound = n->profit;
	int weight = n->weight;
	std::vector<double> x(n_items, 0.0);
	while(weight < C && i <= n_items){
		if(weight + items[i].weight <= C){
			x[i] = 1.0;
			weight += items[i].weight;
			bound += items[i].profit;
		}else{
			x[i] = (C-weight)/items[i].weight;
			weight = C;
			bound += items[i].profit * x[i];
		}
		i++;
	}
	return bound;

}

//To compare items based on p/w value
bool compareFrac(item i1, item i2){
	double val1 = (double)i1.profit/i1.weight;
	double val2 = (double)i2.profit/i2.weight;
	return val2 <  val1;
}

int main(int argc, char ** argv){
	//assert(argc == 3);

	//read in input, put all item values into vector of item structs
	std::ifstream reader(argv[1]);
	std::string line;
	int n_items, capacity;
	int count = 0;
	std::vector<item> items;
	int track = 0;
	while(std::getline(reader, line)){
		std::stringstream linestream(line);
		std::string value;
		if(track == 0){
			getline(linestream, value, ',');
			n_items = std::stoi(value);
			getline(linestream,value,',');
			capacity = std::stoi(value);
			track++;
		}else{
			int w, p;
			std::getline(linestream, value, ',');
			w = std::stoi(value);
			std::getline(linestream,value, ',');
			p = std::stoi(value);
			items.push_back(item());
			items[count].weight = w;
			items[count].profit = p;
			count++;

		}
	}
	
	//items vector sorted from largest p/w val to smallest
	std::sort(items.begin(), items.end(), compareFrac);




	return 0;
}
