
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <string>

using namespace std;

class singlyList
{
    public:
        singlyList(); 
        void insert(int num);
        void earse();
        void printNodes();
        void Reverse();
        int size();
		~singlyList();
    private:
		class Node
		{
		public:
			int number;
			Node* next;
		};

		Node * head;
		Node * tail;
		int count;
};

#endif