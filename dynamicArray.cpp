// Example of a program that uses pointers and nested for-loops to create a table

#include <iostream>		// required to use cout, cin, and endl
#include <iomanip>		// required to setw()
using namespace std;	// required to use the items defined in the above libraries 

void print(int ** table, int maxrow, int maxcol);
void resize(int ** &table, int maxrow, int maxcol, int morecol);

int main()
{
	int ** grid;												// pointer to a pointer to integers to create the grid
	int col;													// loop control variable
	int row;													// control variable
	int maxr, maxc;												// maximum number of rows and columns that the dynamic array will have
	char ans;
	int ar;														// number of rows to be added
	do
	{
		system("cls");		// Use system("clear"); on linux based compilers (replit, xcode)
		cout << "Enter number of rows and columns you want to have: ";
		cin >> maxr >> maxc;
// ---- 1 ----
		grid = new int*[maxr];									// create a dynamic arrays of POINTERS TO INTEGERS with maxr elements
		cout << "grid address: " << grid << endl;				// display the starting address of the array
// ---- 2 ----
		for (row = 0; row < maxr; ++row)						// for each row in the grid
			grid[row] = new int[maxc];							// create a dynamic array of INTEGERS with maxc elements to implement it

		for (int row = 0; row < maxr; ++row)					// for each row in the grid
			for (col = 0; col < maxc; ++col)					//     for each column in the row
				grid[row][col] = (row + 1) * 10 + (col + 1);	//         store the calculated value
		cout << "Enter number of rows to add: ";				// add rows
		cin >> ar;
		print(grid, maxr, maxc);								// call function print to display the table
		resize(grid, maxr, maxc, ar);							// call function resize to add 2 rows to the table
		cout << "grid address: " << grid << endl;				// display the starting address of the array
		print(grid, maxr+ar, maxc);								// call function print to display the table (now with more rows)
		for (row = 0; row < maxr+ar; ++row)						// to avoid MEMORY LEAK for each row in the grid
			delete[] grid[row];									// delete the dynamic array created to implement it
		delete[] grid;											// delete the array of POINTERS TO INTEGERS used to access the rows
		grid = nullptr;											// set grid to the null pointer
		cout << "Do you want to continue[y/n]?:";
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');

	return 0;
}


void print(int ** table, int maxrow, int maxcol)				// receives the pointer to the grid and the max number of rows and columns to display
{
	int row, col;
	for (row = 0; row < maxrow; row++)							// will loop maxrow times
	{
		cout << "Row " << row << ": ";
		for (col = 0; col < maxcol; col++)						// will loop maxcol times
		{
			cout << setw(4) << table[row][col];					// display the using array notation
		}
		cout << endl;
	}
	cout << endl;
}

void resize(int ** &table, int maxrow, int maxcol, int morerow)		// receives the pointer to the grid by reference (so table is the same as grid),
{																	// the max number of rows and columns, and the number of rows to be added
	int row, col;
	// ---- 4 ----
	int ** newgrid;										// pointer to a pointer to integers to create the newgrid
	newgrid = new int*[maxrow+morerow];					// creates a dynamic arrays of POINTERS TO INTEGERS with (maxrow+morerow) elements
	for (row = 0; row < maxrow; row++)					// for each row in table (grid)
		newgrid[row] = table[row];						// points the row pointers of newgrid to the rows of table (grid)
	for (row = maxrow; row < maxrow+morerow; row++)		// adds morerow rows to newgrid
		newgrid[row] = new int[maxcol];					
	// ---- 4 ----
	for (row = maxrow; row < maxrow+morerow; row++)				// will loop morerow times
		for (col = 0; col < maxcol; col++)						//     will loop maxcol times
			newgrid[row][col] = (row + 1) * 10 + (col + 1);		//         store the calculated value in the added rows
// ---- 5 ----
	delete[] table;											// deletes the "old" array of POINTERS TO INTEGERS used to access the rows
// ---- 6 ----
	table = newgrid;										// makes table (grid) point to the "new" array of POINTERS TO INTEGERS used to access the rows
}
