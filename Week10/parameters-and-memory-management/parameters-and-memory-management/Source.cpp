#include <iostream>
#include <string>
#include <memory>

class CTest
{
public:
	CTest() {}
	CTest(int d)
	{
		mData = d;
	}

	void CallByReference(int* d)
	{
		mData = *d;
	}
	void CallUsingReferenceParameter(int& d)
	{
		mData = d;
	}
	void CallByCopy(int d)
	{
		mData = d;
	}

private:
	int mData;
};

class CMemoryManager
{
public:
	void* allocate(size_t size, uint32_t line)
	{
		mCount++;
		std::cout << line << "\n";
		return malloc(size);
	}
	
	void deallocate(void* ptr, uint32_t line)
	{
		mCount--;
		std::cout << line << "\n";
		free(ptr);
	}

private:
	int mCount;
};

int main()
{
	CTest* test = new CTest(5);
	int i = 4;
	test->CallByCopy(i);
	test->CallByReference(&i);
	test->CallUsingReferenceParameter(i);

	CMemoryManager memoryManager;

	CTest* test2 = static_cast<CTest*>(memoryManager.allocate(sizeof(CTest), __LINE__));
	CTest* test3 = static_cast<CTest*>(memoryManager.allocate(sizeof(CTest), __LINE__));

	memoryManager.deallocate(test2, __LINE__);
	memoryManager.deallocate(test3, __LINE__);

	std::cin.get();
	return 0;
}