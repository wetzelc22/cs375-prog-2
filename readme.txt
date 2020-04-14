How to run program: 
	you can do 'make all' to compile everything then to execute just ./BestFirstSearch input.txt output.txt

Data Structures used:
	Used a struct for holding each items weight and profit 

	Created a max heap to use as a priority queue in order to access then nodes places in the queue in order of most promising bound

	vectors to hold item index values in each node to track all the items in sack for that given node, another vector to hold all of the items that is then sortd using the one from the algorithm library and using my own comparator function that calculates the p/w value for each item to sort by.

Computation Time:
	Sorting the items will be an O(nlgn) time complexity then afterwards the actual best first search algorithm time complexity will be at worst O(nlgn) since you may have to process every single node and then with the priority queue thats a lgn operation to heapify it.  

classes used:
	priorityqueue: made as a max heap data structure to use as a queue to make sure node with highest bound is at top of queue
	Node class: used to create the nodes needed to hold info and create the tree


