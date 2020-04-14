#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cassert>
#include <sstream>
#include <algorithm>
#include "Node.h"
#include "PriorityQueue.h"

//hold inupt info for each item
struct item{
	int weight;
	int profit;
};

//clean up memory of tree
void deleteTree(Node *n){
	if(n == nullptr) return;

	deleteTree(n->left);
	deleteTree(n->right);
	delete n;
}

//calculate bound value
double bound(unsigned int i, std::vector<item> items, Node * n, int C, int n_items){
	//bound tracks bound value, weight to track weight value, and vector for calculating fractional value fo rlast weight
	double bound = n->profit;
	int weight = n->weight;
	std::vector<double> x(n_items, 0.0);
	while(weight < C && i <= n_items){
		if(weight + items[i].weight <= C){
			x[i] = 1.0;
			weight += items[i].weight;
			bound += items[i].profit;
		}else{
			x[i] = (C-weight)/(double)items[i].weight;
			weight = C;
			bound += items[i].profit * x[i];
		}
		i++;
	}
	//std::cout << "Bound = " << bound << std::endl;
	return bound;

}

//To compare items based on p/w value
bool compareFrac(item i1, item i2){
	//val1 holds p/w for i1 and val2 does the same for i2
	double val1 = (double)i1.profit/i1.weight;
	double val2 = (double)i2.profit/i2.weight;
	return val2 <  val1;
}

int main(int argc, char ** argv){
	//assert(argc == 3);

	//read in input, put all item values into vector of item structs
	std::ifstream reader(argv[1]);
	//line holds current line 
	//n_items holds number of items for problem and capacity holds weight capacity
	//track to know when to start adding values as items
	//assume all items values are integer and not doubles or floats
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


	//algorithm implementation
	int maxprofit = 0;
	Node * max = nullptr;
	int leaves = 0;
	int nodes_visited = 0;
	bool NotAdded = true;
	PriorityQueue q;
	Node * root = new Node();
	root->level = 0;
	root->profit = 0;
	root->weight = 0;
	root->bound = 0.0;
	q.addElement(root);
	while(!q.empty()){
		nodes_visited++;
		Node * n = q.getPriority();
		//std::cout << "Current Dequeued node weight = " << n->weight << std::endl;
		//std::cout << "Current Dequeued node profit = " << n->profit << std::endl;
		//std::cout << "Current Dequed node bound = " << n->bound << std::endl;
		//std::cout << "Current MaxProfit = " << maxprofit << std::endl;
		if(n->weight > capacity || n->bound < maxprofit){
			leaves++;
			continue;
		}
		Node * left = new Node();
		left->level = n->level + 1;

		//yes child

		left->weight = n->weight + items[left->level-1].weight;
		left->profit = n->profit + items[left->level-1].profit;
		left->indexes = n->indexes;
		left->indexes.push_back(left->level);
		if((left->weight <= capacity) && left->profit > maxprofit)
			maxprofit = left->profit;
			max = n;
		left -> bound = bound(left->level, items, left, capacity, n_items);
		if(left->bound > maxprofit){//&& left->weight < capacity){
			q.addElement(left);
			NotAdded = false;
		}
		n->left = left;

		//no child

		Node * right = new Node();
		right->weight = n->weight;
		right->profit = n->profit;
		right->level = n->level + 1;
		right->indexes = n->indexes;
		right->bound = bound(right->level, items, right, capacity, n_items);
		if(right->bound > maxprofit){//&& right->weight < capacity){
			q.addElement(right);
			NotAdded = false;
		}else{
			nodes_visited++;
			leaves++;
		}
		
		n->right = right;
		//if no children added then it is a leaf so add 1 to leaf count

		if(NotAdded) leaves++;

		NotAdded = true;
	}

	//write to output file
	
	std::ofstream output(argv[2]);

	output << n_items << "," << maxprofit << "," << max->indexes.size() << std::endl;

	output << nodes_visited << "," << leaves << std::endl;

	for(unsigned int i = 0; i < max->indexes.size(); i++){
		output << items[max->indexes[i]-1].weight << "," << items[max->indexes[i]-1].profit << std::endl;
	}

	output.close();

	deleteTree(root);



	return 0;
}
