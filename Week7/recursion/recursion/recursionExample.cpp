#include <iostream>
#include <memory>


class CRecursionExample
{
public:
	void Recurse( int amount );
};

void CRecursionExample::Recurse( int currentAmount )
{
	currentAmount--;

	if( currentAmount > 0 )
	{
		Recurse( currentAmount );
	}
	std::cout << currentAmount << std::endl;
}

#include <iostream>
using namespace std;

// Class to demonstrate quicksort
class CQuickSort
{
public:
	void Display(int data[], int left, int right);
	int Partition(int data[], int left, int right);
	void Quicksort(int data[], int left, int right);
};

// Display the elements of the array between the indices 'left' and 'right'
void CQuickSort::Display(int data[], int left, int right)
{
	for (int i = left; i <= right; ++i)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

// This version of partition assumes that the pivot is the rightmost element of the array
int CQuickSort::Partition(int data[], int left, int right)
{
	// The rightmost element is the pivot.
	int pivotValue = data[right];  // Value of the pivot

	int stackTop = left; // Keeps track of section containing elements smaller than the pivot

						 // go through all of the elements of the array from left through to the element just before right
	for (int i = left; i < right; ++i)
	{
		// The section of the array that contains elements smaller than the pivot
		// is implemented as a stack.
		// If the element is smaller than the pivot then swap it with the element at the current top
		// of the stack and the increment top.
		if (data[i] <= pivotValue)
		{
			swap(data[i], data[stackTop]);
			++stackTop;
		}
	}
	// Every value inside the stack is now smaller than the pivot.
	// Every value from stackTop upwards is greater than the pivot.
	// Swap the pivot with the element at the current top of the stack. This guarantees that
	// pivot is inbetween the two partitions.
	swap(data[stackTop], data[right]);// Move pivot to its final place

									  // return the index of the pivot
	return stackTop;
}

// The choice of pivot can vary. However, the essential structure of partitioning
// into two sections, and then a recursive call on each of the sections, is always the same.
void CQuickSort::Quicksort(int data[], int left, int right)
{
	// The array has less than two elements when right > left
	if (right > left)
	{
		int pivot = Partition(data, left, right);

		Quicksort(data, left, pivot - 1);
		Quicksort(data, pivot + 1, right);
	}
}

int main()
{
	constexpr int_fast32_t kSize = 100;

	std::unique_ptr<CRecursionExample> myRecursion = std::make_unique<CRecursionExample>();
	myRecursion->Recurse(4);

	int myData[kSize] = { 4, 9, 1, 5, 3, 7, 6 };
	int left = 0; // index of start of array
	int right = 6; // index of end of array

	std::unique_ptr<CQuickSort> myQuickSort = std::make_unique<CQuickSort>();
	myQuickSort->Quicksort(myData, left, right);
	myQuickSort->Display(myData, left, right);

	std::cin.get();
	return 0;
}