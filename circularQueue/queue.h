
#ifndef QUEUE_H
#define QUEUE_H

#include <string>

using namespace std;

class Queue
{
public:
	Queue();
	void push(string s);
	void pop();
	string front();
	int size();

private:
	string A[6];
	int count;
	int f;
	int b;
};

#endif

