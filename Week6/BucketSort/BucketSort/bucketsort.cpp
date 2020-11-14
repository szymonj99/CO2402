#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// constant for the maximum size of the unsorted array and for each of the buckets.
constexpr int_fast32_t SIZE = 10;
constexpr std::pair<int_fast32_t, int_fast32_t> bucket1Range = std::make_pair<int_fast32_t, int_fast32_t>(1, 10);
constexpr std::pair<int_fast32_t, int_fast32_t> bucket2Range = std::make_pair<int_fast32_t, int_fast32_t>(11, 20);
constexpr std::pair<int_fast32_t, int_fast32_t> bucket3Range = std::make_pair<int_fast32_t, int_fast32_t>(21, 30);

static int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

class Bucket
{
private:
	std::pair<int_fast32_t, int_fast32_t> range = std::make_pair<int_fast32_t, int_fast32_t>(0, 0);
	int_fast32_t top = 0;
	int_fast32_t items[SIZE]; // The bucket acts as a stack

public:
	Bucket(const int_fast32_t bottom, const int_fast32_t top)
	{
		range.first = bottom;
		range.second = top;
	}
	Bucket(const std::pair<int_fast32_t, int_fast32_t>& new_range)
	{
		range = new_range;
	}

	void push(int_fast32_t item)
	{
		if (this->top < SIZE)
		{
			items[top] = item;
			top++;
		}
		else
		{
			std::cout << "Error: Bucket Stack Size reached: " << SIZE << "\n";
		}
	}

	int_fast32_t pop()
	{
		if (top > 0)
		{
			int_fast32_t temp_item = items[top];
			items[top] = NULL;
			return temp_item;
		}
		else
		{
			std::cout << "Error: No more items in bucket to pop.\n";
			return std::numeric_limits<int_fast32_t>::lowest();
		}
	}

	int_fast32_t getRangeBottom() const
	{
		return range.first;
	}
	int_fast32_t getRangeTop() const
	{
		return range.second;
	}

	int_fast32_t getTop()
	{
		return top;
	}

	int_fast32_t getItem(const int_fast32_t index) const
	{
		return items[index];
	}

	void doSort()
	{
		std::qsort(items, top, sizeof(items[0]), compare);
	}
};


class BucketSort
{
private:
	std::vector<Bucket*> buckets;
public:
	void addItem(const int_fast32_t item);
	void displayBuckets();
	BucketSort(const std::vector<Bucket*>& buckets);
	void doSort();
};

BucketSort::BucketSort(const std::vector<Bucket*>& buckets)
{
	this->buckets = buckets;
}

void BucketSort::addItem(const int_fast32_t item)
{
	for (Bucket* bucket : buckets)
	{
		if (item >= bucket->getRangeBottom() && item <= bucket->getRangeTop())
		{
			bucket->push(item);
		}
	}
}

// Displays all of the items currently on the stack in order from the bottom of the stack
// to the top of the stack.
void BucketSort::displayBuckets()
{
	for (Bucket* bucket : buckets)
	{
		for (int_fast32_t index = 0; index < bucket->getTop(); index++)
		{
			std::cout << bucket->getItem(index) << " ";
		}
		std::cout << "\n";
	}
}

void BucketSort::doSort()
{
	for (Bucket* bucket : buckets)
	{
		bucket->doSort();
	}
}

int main()
{
	// Create buckets, then use them to create BucketSort object.
	Bucket* bucket1 = new Bucket(1, 10);
	Bucket* bucket2 = new Bucket(11, 20);
	Bucket* bucket3 = new Bucket(21, 30);
	std::vector<Bucket*> buckets{ bucket1, bucket2, bucket3 };
	BucketSort* myBucket = new BucketSort(buckets);

	// This a fudge to deal with the fact that we're avoiding constructors for the time being.
	// However, it works well enough.
	int_fast32_t data[SIZE] = { 4, 13, 23, 12, 7, 28, 9, 15, 2, 21 };

	for (const int_fast32_t item : data)
	{
		myBucket->addItem(item);
	}

	myBucket->doSort();
	myBucket->displayBuckets();

	std::cout << "Program finished executing. Press Enter to exit.\n";
	std::cin.get();
	return 0;
}
