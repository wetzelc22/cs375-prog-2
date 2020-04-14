#ifndef CW_NODE
#define CW_NODE

#include <stdio.h>
#include <vector>

class Node{
public:
	Node * left;
        Node * right;
	int level, profit, weight;
	double bound;
	std::vector<int> indexes;

	Node() : left{nullptr}, right{nullptr} {};
};

#endif
