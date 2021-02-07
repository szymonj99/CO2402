#include <iostream>
#include <memory>
#include <vector>
#include <string>

class ModuleMarks
{
private:
	std::string Name = "";
	float Mark = 0.0f;

public:
	ModuleMarks(const std::string& name, float mark)
	{
		Name = name;
		Mark = mark;
	}

	const bool setModule(const std::string& name, float mark)
	{
		Name = name;
		Mark = mark;
		return true;
	}

	const bool displayModule() const
	{
		std::cout << "Name: " + Name + " Mark: " + std::to_string(Mark) + "\n";
		return true;
	}
};

class BankAccount
{
public: 
	std::string Name = "";
	float Balance = 0.0f;

	BankAccount(const std::string& name, const float balance)
	{
		Name = name;
		Balance = balance;
	}

	void PrintDetails()
	{
		std::cout << "Name: " + Name + " Balance: " + std::to_string(Balance) << std::endl;
	}
};

void flattenArray(int32_t* arrayPtr, int32_t size)
{
	int32_t* ptr;
	ptr = arrayPtr;

	for (int32_t i = 0; i < size; i++)
	{
		*ptr = 0;
		ptr++;
	}
}

void displayArray(int32_t* arrayPtr, int32_t size)
{
	int32_t* ptr;
	ptr = arrayPtr;

	for (int32_t i = 0; i < size; i++)
	{
		std::cout << *ptr << ", ";
		ptr++;
	}
	std::cout << std::endl;
}

int main()
{
	BankAccount* account = new BankAccount("Bob Jones", 75.3f);

	account->PrintDetails();

	delete(account);

	int32_t myArray[]{ 3,7,4,9 };

	displayArray(myArray, sizeof(myArray) / sizeof(myArray[0]));
	flattenArray(myArray, sizeof(myArray) / sizeof(myArray[0]));
	displayArray(myArray, sizeof(myArray) / sizeof(myArray[0]));

	std::vector<ModuleMarks*> moduleMarks;
	moduleMarks.reserve(4);

	const std::string moduleNamesArray[]{ "Science", "Biology", "Computer Science", "Engineering" };
	const float moduleMarksArray[]{ 50.0f, 70.0f, 80.0f, 90.0f };

	for (int32_t i = 0; i < 4; i++)
	{
		moduleMarks.push_back(new ModuleMarks(moduleNamesArray[i], moduleMarksArray[i]));
		moduleMarks.at(i)->displayModule();
	}

	moduleMarks.emplace_back("Test", 50.0f);
	moduleMarks.at(4)->displayModule();

	std::cin.get();
	return 0;
}