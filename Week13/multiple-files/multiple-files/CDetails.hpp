#pragma once

#include <string>

class CDetails
{
private:
	std::string mName;
	int mAge;

public:
	CDetails(std::string& name, int age );
	void SetDetails(std::string& name, int age );
	void GetDetails(std::string& name, int &age );
};