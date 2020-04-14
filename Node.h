#ifndef CW_NODE
#define CW_NODE

#include <stdio.h>


class Node{
public:
	Node * left, right;
	int level, profit, weight;
	double bound;

	Node() : left{nullptr}, right{nullptr} {};
};

#endif