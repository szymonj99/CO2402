#include "CCounter.h"
#include "CStudent.h"

int main()
{
	//std::unique_ptr<CCounter> myCount;
	CCounter* myCount = new CCounter; // declare object of type CCounter

	myCount->Set(6);
	for (unsigned int i = myCount->Get(); i < 10; i++)
	{
		myCount->Increment();
	}
	myCount->DisplayAmount();
	delete (myCount);

	CStudent* myStudent = new CStudent;

	myStudent->EnterName();
	myStudent->EnterMark();

	myStudent->OutputName();
	myStudent->OutputMark();

	delete(myStudent);

	std::cin.get();
}