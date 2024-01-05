
#include <string>
#include <iostream>
#include "queue.h"

using namespace std;


inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl;
	//abort();
}
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))


int main()
{
	int i;
	Queue q, q2;			// FRONT {] BACK
	test(q.size() == 0);

	q.push("A");			// {A]
	q.push("B");			// {A, B]
	q.push("C");			// {A, B, C]
	q.push("D");			// {A, B, C, D]
	q.push("E");			// {A, B, C, D, E]
	q.push("F");			// {A, B, C, D, E, F]
	q.push("G");			// {A, B, C, D, E, F]
	cout << "size: " << q.size() << endl;
	q2 = q;

	for (i = 0; i < q.size(); ++i)
	{
		cout << q2.front() << ',';
		q2.pop();
	}
	cout << endl;
	cout << "size: " << q.size() << endl;
	q.pop();				// {B, C, D, E, F]
	cout << "size: " << q.size() << endl;
	q.push("G");			// {B, C, D, E, F, G]
	q.pop();				// {C, D, E, F, G]
	q.push("H");			// {C, D, E, F, G, H]
	q.push("I");			// {C, D, E, F, G, H]
	cout << "size: " << q.size() << endl;

	q2 = q;

	for (i = 0; i < q.size(); ++i)
	{
		cout << q2.front() << ',';
		q2.pop();
	}
	cout << endl;
	q.pop();				// {D, E, F, G, H]
	q.pop();				// {E, F, G, H]
	q.push("I");			// {E, F, G, H, I]
	q.push("J");			// {E, F, G, H, I, J]
	q.push("K");			// {E, F, G, H, I, J]
	cout << "size: " << q.size() << endl;

	q2 = q;

	for (i = 0; i < q.size(); ++i)
	{
		cout << q2.front() << ',';
		q2.pop();
	}
	cout << endl;

}

