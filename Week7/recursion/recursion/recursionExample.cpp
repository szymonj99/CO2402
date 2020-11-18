#include <iostream>

class CRecursionExample
{
public:
	void Recurse( int amount );
};

void CRecursionExample::Recurse( int currentAmount )
{
	currentAmount++;

	if( currentAmount > 0 )
	{
		Recurse( currentAmount );
	}
	std::cout << currentAmount << std::endl;
}

int main()
{
	CRecursionExample* myRecursionExample = new CRecursionExample;

	myRecursionExample->Recurse( 4 );

	delete ( myRecursionExample );

	std::cin.get();
	return 0;
}