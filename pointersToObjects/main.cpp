#include <iostream>
#include <string>
using namespace std;
#include "lotList.h"

int main()
{
// Declare auxiliary pointer to lot and other necessary variables
	lot * parcel;
	string ltitle;
// Declare and initialize 5 objects type lot (get their values from sample run)
	lot lot1("Lot#1", 62,62), lot2("Lot#2",80, 95), lot3("Lot#3",70, 95), lot4("Lot#4", 82, 89), lot5("Lot#5", 66, 66);		// working with individual objects
// Display the corresponding data of the lots
	cout << "Lots declared" << endl;
	cout << lot1.getTitle() << " Width: " << lot1.getWidth() << " Length: " << lot1.getLength() << endl;
	cout << lot2.getTitle() << " Width: " << lot2.getWidth() << " Length: " << lot2.getLength() << endl;
	cout << lot3.getTitle() << " Width: " << lot3.getWidth() << " Length: " << lot3.getLength() << endl;
	cout << lot4.getTitle() << " Width: " << lot4.getWidth() << " Length: " << lot4.getLength() << endl;
	cout << lot5.getTitle() << " Width: " << lot5.getWidth() << " Length: " << lot5.getLength() << endl;
// Replace the data of lots 1 & 2 with data shown in my sample run
	lot1.setData("Lot#1b", 60, 70);
	lot2.setData("Lot#2b", 70, 90);
// Display the corresponding data of the lots just modified
	cout << endl;
	cout << "Lots modified (Lot1 & Lot2)" << endl;
	cout << lot1.getTitle() << " Width: " << lot1.getWidth() << " Length: " << lot1.getLength() << endl;
	cout << lot2.getTitle() << " Width: " << lot2.getWidth() << " Length: " << lot2.getLength() << endl;
	cout << endl;
// Create a list of lots
	lotList dir;
// Display the size of the list
	cout << "Initial List of lots size: " << dir.size() << endl;
// Add lots 1, 2, and 3 to the list
	dir.add(&lot1);
	dir.add(&lot2);
	dir.add(&lot3);
	cout << endl;
// Display the size of the list
	cout << "List size after adding 3 lots (lot1, lot2, and lot3): " << dir.size() << endl;
	dir.listOfLots();
// Get the title of a lot
	cout << "Enter title of lot you want to look for: ";
	cin >> ltitle;
	cout << endl;
// Look for that lot by title
	parcel = dir.lookup_by_title(ltitle);
// If the lot is not in the list
	if (parcel == NULL)
// Display a message stating the lot is not in the list
		cout << ltitle << " is not in the list" << endl;
// Otherwise, display the title of the lot followed by the width and the length
	else
		cout << parcel->lot::getTitle() << " is in the List" << " Width: " << parcel->lot::getWidth() << " Length: " << parcel->lot::getLength() << endl;
// Remove Lot1b from the list
	cout << endl;
	cout << "Removing lot#1b" << endl;
	dir.remove("Lot#1b");
	cout << endl;
	// Display the size of the list
	cout << "List size after removing a lot: " << dir.size() << endl;
	dir.listOfLots();
// Add lot 4 to the list
	cout << "Adding lot4" << endl;
	dir.add(&lot4);
	cout << endl;
// Display the size of the list
	cout << "List size after adding a lot: " << dir.size() << endl;
// Display the list of lots
	dir.listOfLots();
// Add lot 2 to the list
	cout << "Adding lot5" << endl;
	dir.add(&lot5);
	cout << endl;
// Display the size of the list
	cout << "List size after adding another lot: " << dir.size() << endl;
// Display the list of lots
	dir.listOfLots();
// Remove lots 2b, 3, and 4
	cout << "Removing Lot#2b, Lot#3, Lot#4" << endl;
	dir.remove("Lot#2b");
	dir.remove("Lot#3");
	dir.remove("Lot#4");
	cout << endl;
// Display the size of the list
	cout << "List size after removing 3 lots: " << dir.size() << endl;
// Display the list of lots
	dir.listOfLots();
// Add lot 2
	cout << "Adding lot2" << endl;
	dir.add(&lot2);
	cout << endl;
// Display the size of the list
	cout << "List size after adding a lot: " << dir.size() << endl;
// Display the list of lots	
	dir.listOfLots();
// Remove lot 2b
	cout << "Removing Lot#2b" << endl;
	dir.remove("Lot#2b");
	cout << endl;
// Display the size of the list
	cout << "List size after removing a lot: " << dir.size() << endl;
// Display the list of lots
	dir.listOfLots();
// Add lot 1 12 times
	cout << "Adding lot1 12 times" << endl;
	for (int i = 0; i < 12; ++i)
		dir.add(&lot1);
	cout << endl;
// Display the size of the list
	cout << "List size after adding a lot 12 times: " << dir.size() << endl;
// Display the list of lots
	dir.listOfLots();
	return 0;
}
