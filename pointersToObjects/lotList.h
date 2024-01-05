
#include <string>
#include "lot.h"

using namespace std;

class lotList
{
	public:
		// Default constructor.Initializes the values in A to nullptr to indicate empty list
		lotList();

		// Adds a lot in the first available element in the array, if possible. If not, display"lotList is full"
		void add(lot* p);

		// Removes a lot with the given title
		void remove(string n);

		// Searches for a lot with a given title
		// Returns a pointer to the first lot found
		// If none exists, returns nullptr
		lot* lookup_by_title(string n);

		// Displays the title and data of each lot in the list
		void listOfLots();

		// Returns the number of lots in the list
		int size();

	
	private:
		// The list of lots is implemented as an array of pointers to lots 
		//
		// When the list is created, it must be empty
		// To add a lot, store it's pointer in the array
		// To remove a lot, set the corresponding array element equal to nullptr
		lot* A[10];
};


