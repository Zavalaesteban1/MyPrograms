#include "lot.h"

// setData copies the argument w to private member width and
// l to private member length.
void lot::setData(string t, int w, int l)
{
	title = t;
	width = w;
	length = l;
}

// getTitle returns the value stored in the private member title.
string lot::getTitle()
{
	return title;
}

// getWidth returns the value stored in the private member width.
int lot::getWidth()
{
	return width;
}

// getLength returns the value stored in the private member length.
int lot::getLength()
{
	return length;
}

// getArea returns the value stored in the private member area.
int lot::getArea()
{
	return width * length;
}

// getPerimeter calculates the perimeter and returns its value
int lot::getPerimeter()
{
	return 2 * (getWidth() + getLength());
}

// Parameterized constructor. Assigns to the private data members the values passed through
// the parameter list by the client program.
// This function is called automatically when an object of this class is declared with a parameter list.
lot::lot(string t, int w, int l)
{
	title = t;
	width = w;
	length = l;
}
