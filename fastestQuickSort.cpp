#include <iostream> 
#include <chrono>
#include <iomanip>


using namespace std;
using namespace chrono;



void quickSort(int * A, int left, int right);
void swap(int *A, int i, int j);




int main()
{
    int n = 5000000;
    int* A = new int[n];

    // reapting order
    for (int i = 0; i < n; ++i)
    {
		A[i] = rand() % 10;
    }


    // Test 2: reverse sorted order
	// for (int i = 0; i < n; ++i)
    // {
	// 	A[i] = n - i; 
    // }
    // before sorting
    cout << "before sorting: " << endl;
    for(int i = 0; i < n; ++i)
    {
        cout << A[i] << ", ";
    }
    cout << endl << endl;



    // testing quicksort
    system_clock::time_point start = system_clock::now();
    quickSort(A, 0, n - 1);
    system_clock::time_point  end = system_clock::now();
    float dur = duration<float>(end-start).count();
    cout << "After sorting: " << endl;
    for(int i = 0; i < n; ++i)
    {
        cout << A[i] << ", ";
    }
    cout << endl;
    
    cout << "sorting: " << n << " ints using this fast quicksort took: ";
    cout << fixed << setprecision(10);
    cout << dur << " seconds." << endl;
    cout << endl;

}



void quickSort(int * A, int left, int right) 
{
    // use left and right to keep track of the index we're in
    // the leftIndex will start at the begining of the array and rightIndex will start at the end of the array
    int leftIndex = left, rightIndex = right;
    // for the pivot start at the half or the middle of the array
    int pivot = A[(left + right) / 2];
    /*
    In this while loop we're going through the array checking which values are less and greater than the pivot, 
    and as we're looping we're also moving the position of the leftIndex and rightInddx in the array. This while loop  swaps the values after the rightIndex
    and leftIndex are compared to the pivot. It swaps the corresponding values based on were both indexs are.
    The values of leftIndex and rightIndex will be changing based on the elements compared to the pivot
    */
    while (leftIndex <= rightIndex)
    {
        // while the element in the index at leftIndex is less than the pivot move the leftIndex to the right of the array
        while(A[leftIndex] < pivot)
        {
            // moving the index to the right
            leftIndex++;
        }
        // while the element in the index at rightIndex is greater than the pivot move rightIndex to the left of the array
        while(A[rightIndex] > pivot)
        {
            // moving the index to the left
            rightIndex--;
        }
        // if the value of the left is less than or equal to the value of the right swap the values
        if(leftIndex <= rightIndex) 
        {
            // call the swap function to swap the values in the array based on where leftIndex and rightIndex are in the array
            swap(A, leftIndex, rightIndex);
            // once swapped move the leftIndex to the right of the array, and rightIndex to the left of the array
            leftIndex++;
            rightIndex--;
        }
    }
    // this shows how the array looks after each while loop iteration 
    // cout << "after sorting each time" << endl;
    // for(int i = 0; i < 10; ++i)
    // {
    //     cout << A[i] << ", ";
    // }
    // cout << endl;


    // if the left is less than the rightIndex call quicksort to sort the left side of the array
    // the value of left always stay the same
    // the value of rightIndex will based on how many times it was incremented down
    if (left < rightIndex)
    {
        quickSort(A, left, rightIndex);
    }
    
    // if the value of leftIndex is less than the right call quicksort to sort the right side of the array
    // the value of leftIndex will based on how many times it was incremented up
    // the value of right will always stay the same 
    if (leftIndex < right)
    {
        quickSort(A, leftIndex, right);
    }
}


//Swap Elements
void swap(int *A, int leftIndex, int rightIndex)
{
	// store the value of the leftIndex in the array in tmp
    int tmp = A[leftIndex];
	// swap the values 
    A[leftIndex] = A[rightIndex];
    A[rightIndex] = tmp;
}