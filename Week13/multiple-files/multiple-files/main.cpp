#include <iostream>
#include <string>

#include "CDetails.hpp"

int main()
{
	std::string personName = "fred";
	CDetails* person = new CDetails(personName, 32);

	std::string name;
	int age;
	person->GetDetails( name, age );
	std::cout << name << " " << age << std::endl;
	delete person;

	std::cin.get();
}