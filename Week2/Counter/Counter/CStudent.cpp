#include "CStudent.h"

CStudent::CStudent() {};

CStudent::CStudent(const std::string& NAME, const float MARK)
{
	m_Mark = MARK;
	m_Name = NAME;
}

void CStudent::EnterName()
{
	std::cout << "Enter name.\n";
	std::cin >> m_Name;
}

void CStudent::EnterMark()
{
	std::cout << "Enter new mark.\n";
	std::cin >> m_Mark;
}

void CStudent::OutputName()
{
	std::cout << "Student mark: " << m_Name << "\n";
}

void CStudent::OutputMark()
{
	std::cout << "Student mark: " << m_Mark << "\n";
}