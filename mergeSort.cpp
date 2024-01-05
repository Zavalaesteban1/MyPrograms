
#include <cassert>
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file ";
	cerr << file << ", line " << line << "." << endl;
        //abort();
}
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

void insertionsort(int* A, int n)
{
	for (int usize = n; usize > 0; --usize)
	{
		// "Fold" in the new element
		// into the sorted portion
		int i = n - usize;
		while (i > 0 && A[i] < A[i-1])
		{
			// Swap
			int tmp = A[i];
			A[i] = A[i-1];
			A[i-1] = tmp;

			// Move down one spot
			--i;
		}
	}
}



void mergesort(int *A, int n)
{
	// Base case: n < 2
	if (n < 2)
		return;

	// Recursive case:
	// Mergesort left half
	mergesort(A, n/2);	
	
	// Mergesort right half
	mergesort(&(A[n/2]), n - n/2);

	// Merge	
	int i = 0;
	int j = 0;
	int* B = new int[n];
	while (i < n/2 || j < n-n/2)
	{
		if (i >= n/2)
		{
			// j wins automatically
			B[i+j] = A[j+n/2]; 
			++j;
		}
		else if (j >= n-n/2)
		{
			// i wins automatically
			B[i+j] = A[i]; 
			++i;
		}
		else if (A[i] <= A[j+n/2])
		{
			B[i+j] = A[i]; 
			++i;
		}	
		else // A[i] > A[j+n/2]
		{
			B[i+j] = A[j+n/2]; 
			++j;
		}
	}

	// Now B has everything in sorted order
	for (int i = 0; i < n; ++i)
		A[i] = B[i];
	
	delete[] B;
}

void quicksort(int* A, int n)
{
	// Base case: n < 2
	if (n < 2)
		return;

	// Pick a pivot
	int pi = 0;  // rand() % n;
	int p = A[pi];

	// Count # things < pivot in A (call that c)
	int c = 0;
	for (int i = 0; i < n; ++i)
		if (A[i] < p)
			++c;

	// Swap the pivot into correct location (index i)
	int tmp = A[pi];
	A[pi] = A[c];
	A[c] = tmp;
	pi = c;

	// Use two-finger algorithm to swap pairs of elements
	//  on incorrect sides of pivot
	int l = 0;
	int r = n-1;
	while (l < pi && r > pi)
	{
		// If l isn't happy, move it rightward
		if (A[l] < p)
			++l;
		// If r isn't happy, move it leftward
		else if (A[r] >= p)
			--r; 
		else
		{
			// Swap
			int tmp = A[r];
			A[r] = A[l];
			A[l] = tmp;
		}
	}

	// Call quicksort on stuff left of pivot
	quicksort(A, pi);

	// Call quicksort on stuff right of pivot
	quicksort(&(A[pi+1]), n-pi-1);
}


void bogosort(int* A, int n)
{
	while (true)
	{
		bool sorted = true;
		for (int i = 0; i < n-1; ++i)
			if (A[i] > A[i+1])
				sorted = false;
		if (sorted)
			return;

		int i = rand() % n;
		int j = rand() % n;
	
		int tmp = A[i];
		A[i] = A[j];
		A[j] = tmp;
	}
}

int main()
{
	int C[11] = { 6, -1, 9, 3, 4, 7, 0 };
	quicksort(C, 7);
	for (int i = 0; i < 7; ++i)
		cout << C[i] << ", ";
	cout << endl;

	int n = 2000;
	int* A = new int[n];
	int* B = new int[n];
	for (int i = 0; i < n; ++i)
		A[i] = B[i] = rand(); 

	system_clock::time_point start = system_clock::now();
	mergesort(A, n); 
	system_clock::time_point end = system_clock::now();
	float dur = duration<float>(end-start).count();
	for (int i = 0; i < n-1; ++i)
		test(A[i] <= A[i+1]);

	cout << "Sorting " << n << " ints using mergesort() took ";
	cout << dur << " seconds." << endl;

	start = system_clock::now();
	insertionsort(B, n);
	end = system_clock::now();
	dur = duration<float>(end - start).count();
	for (int i = 0; i < n - 1; ++i)
		test(B[i] <= B[i + 1]);

	cout << "Sorting " << n << " ints using insertionsort() took ";
	cout << dur << " seconds." << endl;










/*


start = system_clock::now();
quicksort(B, n);
end = system_clock::now();
dur = duration<float>(end - start).count();
for (int i = 0; i < n - 1; ++i)
test(B[i] <= B[i + 1]);

cout << "Sorting " << n << " ints using quicksort() took ";
cout << dur << " seconds." << endl;


	start = system_clock::now();
	bogosort(B, n); 
	end = system_clock::now();
	dur = duration<float>(end-start).count();
	for (int i = 0; i < n-1; ++i)
		test(B[i] <= B[i+1]);

	cout << "Sorting " << n << " ints using bogosort() took ";
	cout << dur << " seconds." << endl;
*/

}
/*
//srand(2017);

int C[11] = {6, -1, 9, 3, 4, 6, 0, -5, -9, 7, 1};

bogosort(C, 11);

test(C[0] == -9);
test(C[1] == -5);
test(C[2] == -1);
test(C[3] == 0);
test(C[4] == 1);
test(C[5] == 3);
test(C[6] == 4);
test(C[7] == 6);
test(C[8] == 6);
test(C[9] == 7);
test(C[10] == 9);
*/




