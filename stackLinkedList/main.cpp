
#include <ctime>
#include <cassert>
#include <string>
#include <iostream>
#include "stack.h"

using namespace std;

int main() 
{
	Stack s1, s2; // [}
	assert(s1.size() == 0);

	s1.push("hello"); // ["hello"}
	assert(s1.top() == "hello");
	assert(s1.size() == 1);

	s1.push("dog"); // ["hello", "dog"}
	assert(s1.size() == 2);
	assert(s1.top() == "dog");

	s1.push("phone"); // ["hello", "dog", "phone"}
	assert(s1.size() == 3);
	assert(s1.top() == "phone");

	s1.pop(); // ["hello", "dog"}
	assert(s1.size() == 2);
	assert(s1.top() == "dog");
	
	s1.push("cat"); // ["hello", "dog", "cat"}
	assert(s1.size() == 3);
	assert(s1.top() == "cat");

	s1.pop(); // ["hello", "dog"}
	assert(s1.size() == 2);
	assert(s1.top() == "dog");
	//*
	s1.pop(); // ["hello"}
	assert(s1.size() == 1);
	assert(s1.top() == "hello");

	s1.pop(); // [}
	assert(s1.size() == 0);

	cout << "Passed basic assertions1." << endl;
	
	// Test popping off empty stack	
	for (int i = 0; i < 100; ++i)
	{
		assert(s1.size() == 0);
		s1.pop();
		s1.top();
	}
	cout << "Passed pop()ing off empty stack." << endl;
	//*/
	// Test many pushes
	int large = 1000;    // 10000000;
	clock_t start = clock();
	for (int i = 0; i < large; ++i)
		s2.push("dog");
	clock_t end = clock();
	float elapsed_time = static_cast<float>(end - start) / CLOCKS_PER_SEC;
	cout << "Elapsed time was " << elapsed_time << " seconds1." << endl;
	assert(s2.size() == large);
	assert(s2.top() == "dog");
	s1.pop();
	assert(s2.top() == "dog");
	cout << "Passed pushing " << large << " items1." << endl;
}




