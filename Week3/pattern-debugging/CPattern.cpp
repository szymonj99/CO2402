// week 3: debug 
#include <iostream>
using namespace std;

const int TOP = 6;

class CPattern
{
private:
	int mSequence[TOP];
public:
	void Initialise(int sequence[TOP]);
	void Display();
	int FindMax();
	void DisplayReversed();
	int FindLocation(int value);
};

// Initialise the array.
// Better to do this as a constructor - if you are confident about constructors then
// convert this method into one
void CPattern::Initialise(int sequence[TOP])
{
	for (int i = 0; i < TOP; ++i)
	{
		mSequence[i] = sequence[i];
	}
}

// Display the array
void CPattern::Display()
{
	for (int i = 0; i < TOP; ++i)
	{
		cout << mSequence[i] << " ";
	}
	cout << endl;
}

// Display the array in reverse order
void CPattern::DisplayReversed()
{
	for (int i = TOP - 1; i >= 0; i--)
	{
		cout << mSequence[i] << " ";
	}
	cout << endl;
}

// Find maximum value in the array
int CPattern::FindMax()
{
	int max = -100;

	for (int i = 0; i < TOP; i++)
	{
		if (mSequence[i] > max)
		{
			max = mSequence[i];
		}
	}
	return max;
}

// Find the location of the first occurence of a value, i.e. it's index
// Return -1 if not found
int CPattern::FindLocation(int value)
{
	int found = -1;
	for (int i = 0; i < TOP; i++)
	{
		if (value == mSequence[i])
		{
			found = i;
			return found;
		}
	}
	return -1;
}

int main()
{
	CPattern* myPattern = new CPattern;
	int testArray[TOP] = { 2, 4, 5, 7, 1, 3 };
	myPattern->Initialise(testArray);

	cout << "Display the array:" << endl;
	myPattern->Display();

	cout << endl << "Display the array in reverse order:" << endl;
	myPattern->DisplayReversed();

	cout << endl << "max element of the array: " << myPattern->FindMax();

	cout << endl << endl;
	cout << "location of the number 7: " << myPattern->FindLocation(7);
	cout << endl;

	std::cin.get();
}