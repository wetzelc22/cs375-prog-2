#include "PriorityQueue.h"
#include <iostream>

void PriorityQueue::Heapify(std::vector<Node *> before){
	for(int i = (before.size()-2)/2; i >= 0; i--){
		siftdown(before, i)
	}
	queue = before;
}

void PriorityQueue::siftdown(std::vector<Node *> &vec, int ind){
	if(ind < 0 || (ind >= (int)vec.size())) return;
	while(left(ind, vec) != -1){
		int check = left(ind, vec);
		int val = right(int, vec);
		if(val != -1 && vec[check]->bound < vec[check+1]->bound){
			check++;
		}
		if(vec[ind]->bound >= vec[check]->bound) return;
		Node * temp = vec[ind];
		vec[ind] = vec[check];
		vec[check] = temp;
		ind = check;
	}
}

int PriorityQueue::left(unsigned int par, std::vector<Node *> vec){
	if(2*par + 1 >= vec.size()){
		return -1;
	}
	return 2*par + 1;
}

int PriorityQueue::right(unsigned int par, std::vector<Node *> vec){
	if(2*par + 2 >= vec.size()){
		return -1;
	}
	return 2*par + 2;
}

void PriorityQueue::addElement(Node * e){
	bool placed = false;
	for(unsigned int i = 0; i < queue.size(); i++){
		if(e->bound > queue[i]->bound){
			queue.insert(queue.begin()+i, e);
			placed = true;
			break;
		}
	}
	if(placed == false){
		pts.push_back(element);
	}
}

double PriorityQueue::peek(){
	return queue[0]->bound;
}

Node * PriorityQueue::getPriority(){
	Node * temp = queue[0];
	queue.erase(queue.begin()+0);
	Heapify(queue);
	return temp;
}
bool PriorityQueue::empty(){
	return queue.size() == 0 ;
}

