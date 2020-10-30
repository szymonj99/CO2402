#include <iostream>
#include <memory> // Unique pointer
#include <string>

constexpr int SIZE = 20;

class Stack
{
private:
	int top = 0;
	std::string data[SIZE];

public:
	Stack();
	Stack(const Stack* STACK);
	void push( std::string newData );
	void pop( std::string &oldData );
	const bool isEmpty() const;
	const bool isFull() const;
	void displayStack() const;
	const int getLength() const;
	void displayReverseStack() const;
	const int countData(const std::string& searchString) const;
	const int findData(const std::string& searchString) const;
	void displayN(const int N) const;
	const bool findN(const int N, std::string& foundString) const;
	const bool allSame() const;
	void copyStack(Stack* newStack) const;
};

// Default constructor
Stack::Stack()
{
	top = 0;
}

// Copy the contents of the parameter stack to the current stack
Stack::Stack(const Stack* STACK)
{
	for (int i = 0; i < STACK->getLength(); i++)
	{
		this->data[i] = STACK->data[i];
	}
}

// pushes data onto the stack, increments top.
// input: string newData. The data to be pushed onto the top of the stack.
void Stack::push( std::string newData )
{
	if( !isFull() )
	{
		data[top] = newData;
		++top;
	}
	else
	{
		std::cout << "stack full" << std::endl;
	}
}

// pops data from the stack, decrements top.
// output: string &newData (reference parameter). The data to be popped from the top of the stack.
void Stack::pop( std::string &oldData )
{
	if( !isEmpty() )
	{
		--top;
		oldData = data[top];
	}
	else
	{
		std::cout << "stack empty" << std::endl;
		oldData = "";
	}
}

// Checks to see whether the array is full.
// Returns: true if the array is full, false if the array is not full.
const bool Stack::isFull() const
{
	if ( top >= SIZE )
	{
		return true;
	}
	return false;
}

// Checks to see whether the array is empty.
// Returns: true if the array is empty, false if the array is not empty.
const bool Stack::isEmpty() const
{
	if ( top <= 0 )
	{
		return true;
	}
	return false;
}

// Displays all of the items currently on the stack in order from the bottom of the stack
// to the top of the stack.
void Stack::displayStack() const
{
	for( int i=0; i<top; ++i)
	{
		std::cout << data[i] << std::endl;
	}
}

// Get the length of the stack
const int Stack::getLength() const
{
	return top;
}

// Print the stack in reverse order
void Stack::displayReverseStack() const
{
	for (int i = top; i >= 0; i--)
	{
		std::cout << data[i] << std::endl;
	}
}

// Get the number of times the string is present in the stack
const int Stack::countData(const std::string& searchString) const
{
	int sum = 0;
	for (int i = 0; i < top; i++)
	{
		if (data[i] == searchString)
		{
			sum++;
		}
	}
	return sum;
}

// Find the index of the first occurence of string
const int Stack::findData(const std::string& searchString) const
{
	for (int i = 0; i < top; i++)
	{
		if (data[i] == searchString)
		{
			return i;
		}
	}
	return -1;
}

// Display nth element.
void Stack::displayN(const int N) const
{
	if (N <= top && N >= 1)
	{
		std::cout << data[N - 1] << std::endl;
	}
	else
	{
		std::cout << "out of bounds" << std::endl;
	}
}

//Find and return nth element.
// Returns true if element was found, false if it wasn't.
const bool Stack::findN(const int N, std::string& foundString) const
{
	if (N >= 1 && N <= top)
	{
		foundString = data[N - 1];
		return true;
	}
	else
	{
		return false;
	}
}

// Returns true if all items in the stack are the same
const bool Stack::allSame() const
{
	if (top == 1)
	{
		return true;
	}

	for (int i = top - 1; i > 0; i--)
	{
		if (data[i] != data[i - 1])
		{
			return false;
		}
	}
	return true;
}

// Copy the contents of the current stack to the new stack parameter
void Stack::copyStack(Stack* newStack) const
{
	for (int i = 0; i < this->getLength(); i++)
	{
		newStack->data[i] = this->data[i];
	}
}

int main()
{
	std::unique_ptr<Stack> myStack = std::make_unique<Stack>();

	myStack->push( "red" );
	myStack->push( "green" );
	myStack->push( "blue" );
	myStack->push("blue");

	myStack->displayStack();
	std::cout << std::endl;

	std::string storedData;
	myStack->pop( storedData );
	std::cout << "popped: " << storedData << std::endl;	// blue
	myStack->pop( storedData );
	std::cout << "popped: " << storedData << std::endl;	// green
	myStack->pop( storedData );
	std::cout << "popped: " << storedData << std::endl;	// red

	std::cin.get();
}