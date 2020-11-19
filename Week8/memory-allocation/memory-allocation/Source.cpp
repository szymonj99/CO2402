#include <vector>
#include <memory>
#include <iostream>

std::vector<int>::iterator getLastOccurence(std::vector<int>& intVector, const int item)
{
	std::vector<int>::iterator it;
	std::vector<int>::iterator toReturn;
	for (it = intVector.begin(); it != intVector.end(); it++)
	{
		if (*it == item)
		{
			toReturn = it;
		}
	}

	if (toReturn._Ptr)
	{
		return toReturn;
	}
	else
	{
		return intVector.end();
	}	
}

int main()
{
	std::vector<int> intVector{ 3,5,7,14 };
	intVector.push_back(21);


	std::vector<int>::iterator it;

	for (it = intVector.begin(); it != intVector.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	std::vector<int> newVector;
	newVector.reserve(intVector.size() * 2);

	for (it = intVector.begin(); it != intVector.end(); it++)
	{
		newVector.push_back(*it);
		newVector.push_back(*it);
	}

	// find last occurence of an item
	std::cout << *getLastOccurence(newVector, 5) << std::endl;

	std::cin.get();
	return 0;
}