#ifndef CW_PRIORITYQUEUE
#define CW_PRIORITYQUEUE

#include "Node.h"
#include <vector>

class PriorityQueue{
private:
	std::vector<Node *> queue;
public:
	PriorityQueue();
	void Heapify(std::vector<Node *>);
	void siftdown(std::vector<Node *>&, int);
	int left(unsigned int, std::vector<Node *>);
	int right(unsigned int, std::vector<Node *>);
	void addElement(Node *);
	Node * getPriority();
	bool empty();
	unsigned long size(){return queue.size();};
};

#endif
