
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>

using namespace std;

class Stack 
{
        public:
                Stack();
                void push(string s);
                void pop();
                string top();
                int size();
				~Stack();
        private:
		class Node
		{
			public:
				string s;
				Node* next;
		};

		Node* head;
		Node* tail;
		int count;
};

#endif


