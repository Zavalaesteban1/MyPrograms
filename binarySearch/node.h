
#ifndef NODE_H
#define NODE_H

class Node
{
	public:
		// We actually implement the constructor here,
		// in the header file (it's too little to "earn" a .cpp)
		Node(int n)
		{
			this->n = n;
			left = right = nullptr;
		}

		int n;
		Node* left;
		Node* right;
};

#endif



