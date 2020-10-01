#pragma once

// Definition for a simple counter
class CCounter
{
private:
	int m_Amount; // stores the current count value
	int m_Top; // top value reached

public:
	CCounter();
	CCounter(const int number);
	void Set(const int number); // set count to the value of number
	int  Get() const; 		// get the current value of amount
	void Increment();  	// increment count by 1 (trivial)
	void Decrement();	// Decrement the counter by 1
	void AssignAmountToTop(); // Assign the amount value to the top value and reset the amount value
	void DisplayAmount();
	void DisplayTop();
	void WriteSentence();
};