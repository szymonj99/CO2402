#pragma once

#include <iostream>
#include <string>

class CStudent
{
private:
	float m_Mark;
	std::string m_Name;

public:
	CStudent();
	CStudent(const std::string& NAME, const float MARK);
	void EnterName();
	void EnterMark();
	void OutputName();
	void OutputMark();
};