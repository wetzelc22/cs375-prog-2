#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cassert>
#include <sstream>
#include <algorithm>

struct item{
	int weight;
	int profit;
};

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
