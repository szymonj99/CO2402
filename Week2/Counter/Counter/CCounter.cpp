// CO2402: Advanced C++
// Week 3: Introduction to classes, the counter class

#include <iostream>
#include "CCounter.h"

CCounter::CCounter() {};

CCounter::CCounter(const int NUMBER)
{
	m_Amount = NUMBER;
	m_Top = NUMBER;
}

// Set counter to the value of NUMBER
void CCounter::Set( const int NUMBER )
{
    m_Amount = NUMBER;
}

 // Get the current value of the counter
int CCounter::Get() const
{
    return m_Amount;
}

// Increment the counter by 1 (trivial)
void CCounter::Increment()
{
    m_Amount++;
}

// Decrement the counter by 1
void CCounter::Decrement()
{
	m_Amount--;
}

// Assign the amount value to the top value and reset the amount value
void CCounter::AssignAmountToTop()
{
	m_Top = m_Amount;
	m_Amount = 0;
}

void CCounter::DisplayAmount()
{
	std::cout << m_Amount << "\n";
}

void CCounter::DisplayTop()
{
	std::cout << m_Top << "\n";
}

void CCounter::WriteSentence()
{
	std::cout << "The rain in Spain\n";
	m_Amount++;
}