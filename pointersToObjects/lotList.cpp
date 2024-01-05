
#include "lotList.h"
#include <iostream>

using namespace std;

// Default constructor. Initializes the values in A to nullptr to indicate empty list
lotList::lotList()
{
	for (int i = 0; i < 10; ++i)									// Initialize all the array elements to the nullptr to indicate empty lotList
		A[i] = nullptr;
}

// Add a lot if possible
void lotList::add(lot* p)
{
	if (size() < 10)												// If there is room for one more lots
		for (int i = 0; i < 10; ++i)								// Go through the lotList
			if (A[i] == nullptr)									//    If an empty spot is found
			{
				A[i] = p;											//       Add the lot here
				return;												//       Exit immediately the function
			}
	cout << "lotList is full" << endl;								// There is no room for one more lots
}

// Remove the first lot found with the given title
void lotList::remove(string n)
{
	for (int i = 0; i < 10; ++i)									// Go through the lotList
		if (A[i] != nullptr && (*A[i]).lot::getTitle() == n)		//    If there is a lot and has the title to be removed
		{
			A[i] = nullptr;											//       Remove it
			return;													//       Exit immediately the function
		}
}

// Find a lot with a given title
lot* lotList::lookup_by_title(string n)							// Returns a pointer to lot
{
	for (int i = 0; i < 10; ++i)									// Go through the lotList
		if (A[i] != nullptr && A[i]->lot::getTitle() == n)				//    If there is a lot and has the given title
			return A[i];											//       return a pointer to the lot
	return nullptr;													// Return the nullptr to indicate the lot was not found
} 

// Return the size of the lotList
int lotList::size()
{
	int c = 0;														// Set the counter to 0
	for (int i = 0; i < 10; ++i)									// Go through the lotList
		if (A[i])	// A[i] != NULL												//    If there is a lot (Note: if the content of A[i] is the nullptr, A[i] evaluates to 0 (false) then the if clause is not executed)
			++c;													//       Count it
	return c;														// Return the count
}

// Display the list of lots in the lotList
void lotList::listOfLots()
{
	cout << "Lots in the list" << endl;
	for (int i = 0; i < 10; ++i)									// Go through the lotList
		if (A[i] != nullptr)										//    If there is a lot
	{
		cout << A[i]->lot::getTitle() << " data: ";
		cout << "Width: " << A[i]->lot::getWidth() << '\t';			// show width
		cout << "Length: " << A[i]->lot::getLength() << '\t';			// show length
		cout << "Area: " << A[i]->lot::getArea() << '\t';				// show area
		cout << "Perimeter: " << A[i]->lot::getPerimeter() << endl;	// show perimeter
	}
	cout << "----------------------------------------------------------------------" << endl;
}