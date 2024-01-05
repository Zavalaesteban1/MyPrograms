
#include <iostream>
#include "queue.h"

using namespace std;

Queue::Queue()
{
	count = 0;
	b = -1;
	f = -1;
}

void Queue::push(string s)
{
	if (size() < 6)
	{
		b = ++b % 6;
		A[b] = s;
		++count;
	}
}

void Queue::pop()
{
	if (size() > 0)
	{
		f = ++f % 6;
		--count;
	}
}

string Queue::front()
{
	if (size() == 0)
	{
		return "";
	}
	return A[(f + 1) % 6];
}

int Queue::size()
{
	return count;
}
























/*
Queue :: Queue()
{
count = 0;
b = 0;
f = -1;
}

void Queue :: push(string s)
{
if ((b+1)%6 != f)            //(size() < 6)
{
A[b] = s;
//++b;
b = ++b % 6;
//A[b] = s;
++count;
}
}

void Queue :: pop()
{
if (size() > 0)
{
//++f;
f = ++f % 6;
--count;
}
}

string Queue :: front()
{
if (size() == 0)
{
return "";
}
return A[(f+1)%6];
}

int Queue :: size()
{
return count;
}

*/




