#include "PriorityQueue.h"
#include <iostream>

PriorityQueue::PriorityQueue(){
	
}

//used to actually heapify the vector, calls siftdown until whole array has been heapified
void PriorityQueue::Heapify(std::vector<Node *> before){
	for(int i = (before.size()-2)/2; i >= 0; i--){
		siftdown(before, i);
	}
	queue = before;
}

//used to move value through tree
void PriorityQueue::siftdown(std::vector<Node *> &vec, int ind){
	if(ind < 0 || (ind >= (int)vec.size())) return;
	while(left(ind, vec) != -1){
		int check = left(ind, vec);
		int val = right(ind, vec);
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

//find left child index
int PriorityQueue::left(unsigned int par, std::vector<Node *> vec){
	if(2*par + 1 >= vec.size()){
		return -1;
	}
	return 2*par + 1;
}

//find right child index
int PriorityQueue::right(unsigned int par, std::vector<Node *> vec){
	if(2*par + 2 >= vec.size()){
		return -1;
	}
	return 2*par + 2;
}

//add element to queue
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
		queue.push_back(e);
	}
}

//pops top value of queue and returns it
Node * PriorityQueue::getPriority(){
	Node * temp = queue[0];
	queue.erase(queue.begin()+0);
	Heapify(queue);
	return temp;
}
//see if queue empty
bool PriorityQueue::empty(){
	return queue.size() == 0 ;
}

