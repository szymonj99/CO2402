#include "CDetails.hpp"

CDetails::CDetails(std::string& name, int age )
{
	mName = name;
	mAge = age;
}

void CDetails::SetDetails(std::string& name, int age )
{
	mName = name;
	mAge = age;
}

void CDetails::GetDetails(std::string& name, int &age )
{
	name = mName;
	age = mAge;
}

