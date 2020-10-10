// Name: Tanner Dryden
// Program 11 CS132
// Description: Driver program given to utilize my merge sort function
//
// Top Down Design
//    Load an array with random numbers
//    Display the array contents (comment out for larger arrays)
//    Sort the array with MergeSort
//    Display the array contents (comment out for larger arrays)

#include <iostream>
#include <string>
#include <ctime>
#include <cassert>

using namespace std;

// Global types

// Global consts
const int NUM_INTS(10);

// Global function declarations
void displayArray(string name, int array[], int numElements, bool isSorted = false);
void doMerge(int array[], int numElements);
void mergeSort(int array[], int numElements);

int main()
{
	//  Initialize variables
	static int array[NUM_INTS];
	srand(static_cast<unsigned int> (time(0)));

	cout << "Sorting int array of " << NUM_INTS << " elements." << endl;

	// Load random numbers into the array
	for (int i = 0; i < NUM_INTS; i++)
	{
		array[i] = rand()/100;
	}
	displayArray("Before: ", array, NUM_INTS);

	// start timing here
	time_t startTime = clock();
	mergeSort(array, NUM_INTS);
	time_t endTime = clock();
	// end timing here

	displayArray("After : ", array, NUM_INTS, true);

	// Display the total time taken
	cout << "Sort took " << endTime - startTime << " ticks" << endl;

	return 0;
}

// Functions

// merge sort helper
void doMerge(int array[], int numElements)
{
	// dynamically allocate a temp array
	int* temp = new int[numElements];

	// copy the array passed to a temporary array
	for (int i = 0; i < numElements; i++)
	{
		temp[i] = array[i];
	}

	// create a middle of the array to split the array using the respective pointers
	int middle = array[0] + ((array[numElements] - array[0]) / 2);
	int* left = &temp[0];
	int* right = &temp[middle];

	// set copy pointer to the start of the original array
	int* copy = &array[0];

	// while left is in bounds or right is in bounds
	while ((left < &temp[middle]) || (right < &temp[numElements - 1]))
	{

		// if left is out of bounds, copy right, and increment copy/right pointers
		if (left >= &temp[middle])
		{
			copy = right;
			copy++;
			right++;
		}
		// if right is out of bounds, copy left, and increment copy/left pointers
		else if (right > &temp[numElements])
		{
			copy = left;
			copy++;
			left++;
		}
		// , copy left and increment copy/left pointers
		else if (*left < *right)
		{
			copy = left;
			copy++;
			right++;
		}
		// else copy right and increment copy/right pointers
		else
		{
			copy = right;
			copy++;
			right++;
		}
	}
	for (int i = 0; i < numElements; i++)
	{
		array[i] = temp[i];
	}
	// deallocate dynamic array
	delete[] temp;
}

// recursive merge sort call
void mergeSort(int array[], int numElements)
{
	int middle;

	if (array[0] < array[numElements])
	{
		middle = array[0] + ((array[numElements] - array[0]) / 2);
		mergeSort(&array[0], middle);
		mergeSort(&array[middle + 1], numElements - middle);
		doMerge(&array[0], numElements);
	}
}

// Function to display the contents of an array
void displayArray(string name, int array[], int numElements, bool isSorted)
{
	cout << name;
	for (int i = 0; i < numElements; i++)
	{
		if (isSorted && i > 0)
		{
		assert(array[i - 1] <= array[i]);
		}
		cout << array[i];
		if (i < numElements - 1)
		{
			cout << ", ";
		}
	}
	cout << endl;
}
