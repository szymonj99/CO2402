#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <deque>
#include <algorithm>
#include <random>
#include <chrono>

struct SCoords
{
	int32_t mX, mY;	
	SCoords(const int32_t x, const int32_t y)
	{
		mX = x;
		mY = y;
	}

	bool operator <(const SCoords& second) const
	{
		return mX < second.mX;
	}

private:
	SCoords() {};
};

void DoSomething(SCoords* ptr)
{
	std::cout << ptr->mX << " " << ptr->mY << std::endl;
}

int main()
{
	std::unique_ptr<SCoords> myPtr(new SCoords(3, 9)); // C++11 style

	std::unique_ptr<SCoords> myPtr2 = std::make_unique<SCoords>(30, 90);

	std::deque<std::unique_ptr<SCoords>> allCoords;

	std::srand(0);

	for (int32_t i = 0; i < 10; i++)
	{
		allCoords.push_back(std::make_unique<SCoords>(SCoords(std::rand() % 50, std::rand() % 100)));
		DoSomething(allCoords.back().get());
	}

	std::sort(allCoords.begin(), allCoords.end());

	std::cin.get();
	return 0;
}