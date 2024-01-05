
#ifndef lot_H		// if lot_H has not being defined before
#define lot_H		// define lot_H
						// This avoids redefinitions of class lot

#include <string>
using namespace std;

// lot class declaration.
class lot
{
	public:
		void setData(string t, int w, int l);		// assigns values to private data
		string getTitle();
		int getWidth();					// returns value of width
		int getLength();				// returns value of length
		int getArea();					// returns value of area
		int getPerimeter();				// calculates the perimeter and returns its value
		lot(string t, int w, int l);	// parameterized constructor
	private:
		string title;
		int width;						// width of the lot
		int length;						// length of the lot
};

#endif

