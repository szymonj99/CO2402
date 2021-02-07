#include <string>
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

struct SEmployee
{
	std::string mName;
	int32_t mID;

	SEmployee() {};
	SEmployee(std::string& name, int32_t id)
	{
		mName = name;
		mID = id;
	}
};

class CPayRoll
{
private:
	SEmployee* mpEmployeeDetails;

public:
	CPayRoll() {};
	CPayRoll(std::string& name, int32_t id);
	~CPayRoll();
	void SetDetails(std::string& name, int32_t id);
	void GetDetails(std::string& name, int32_t& id);
};

CPayRoll::CPayRoll(std::string& name, int32_t id)
{
	mpEmployeeDetails = new SEmployee(name, id);
}

CPayRoll::~CPayRoll()
{
	free(mpEmployeeDetails);
	mpEmployeeDetails = nullptr;
}

void CPayRoll::SetDetails(std::string& name, int32_t id)
{
	if (mpEmployeeDetails == nullptr)
	{
		mpEmployeeDetails = new SEmployee(name, id);
	}
	else
	{
		mpEmployeeDetails->mName = name;
		mpEmployeeDetails->mID = id;
	}	
}

void CPayRoll::GetDetails(std::string& name, int32_t& id)
{
	name = mpEmployeeDetails->mName;
	id = mpEmployeeDetails->mID;
}

class CHourlyPaid : public CPayRoll
{
private:
	float mpHoursWorked;
	float mpHourlyRate;

public:
	CHourlyPaid() {};
	CHourlyPaid(std::string& name, int32_t id)
	{
		SetDetails(name, id);
	}
	void SetHours(float hoursWorked, float hourlyRate)
	{
		mpHoursWorked = hoursWorked;
		mpHourlyRate = hourlyRate;
	}
	float Pay()
	{
		return mpHourlyRate * mpHoursWorked;
	}
};

class CStoreArray
{
private:
	int32_t* mpArrayPointer;

public:
	CStoreArray()
	{
		const int32_t kSize = 4;
		const int32_t kMultiplier = 2;
		int32_t* arr = new int32_t[kSize];
		for (int32_t i = 0; i < kSize; i++)
		{
			arr[i] = i * kMultiplier;
		}
		mpArrayPointer = arr;
	}
	CStoreArray(int32_t* ptr)
	{
		mpArrayPointer = ptr;
	}
	void DisplayArray()
	{
		for (size_t i = 0; i < sizeof(mpArrayPointer); i++)
		{
			std::cout << mpArrayPointer[i] << " ";
		}
		std::cout << std::endl;
	}
	~CStoreArray()
	{
		free(mpArrayPointer);
		mpArrayPointer = nullptr;
	}
};

class CMonthlyPaid : public CPayRoll
{
private:
	float mpSalary;
public:
	CMonthlyPaid() {};
	CMonthlyPaid(std::string& name, int32_t id, float salary)
	{
		SetDetails(name, id);
		mpSalary = salary;
	}
	void SetSalary(float salary)
	{
		mpSalary = salary;
	}
	float Pay()
	{
		const int32_t kMonths = 12;
		return mpSalary / kMonths;
	}
};

class CBook
{
private:
	std::string mpTitle;
	std::string mpAuthor;

public:
	CBook() {};
	CBook(std::string& title, std::string& author)
	{
		mpTitle = title;
		mpAuthor = author;
	}
	void SetDetails(std::string& title, std::string& author)
	{
		mpTitle = title;
		mpAuthor = author;
	}
	void GetDetails(std::string& title, std::string& author)
	{
		title = mpTitle;
		author = mpAuthor;
	}
};

class CBookSeries : public CBook
{
private:
	std::string mpSeriesTitle;
	std::string mpSeriesEditor;

public:
	CBookSeries() {};
	CBookSeries(std::string& series, std::string& editor, std::string& title, std::string& author)
	{
		SetDetails(title, author);
		mpSeriesEditor = editor;
		mpSeriesTitle = series;
	}
	void GetSeriesDetails(std::string& series, std::string& editor, std::string& title, std::string& author)
	{
		GetDetails(title, author);
		series = mpSeriesTitle;
		editor = mpSeriesEditor;
	}
}

int main()
{
	{
		CStoreArray* ar = new CStoreArray;
		ar->DisplayArray();
	}
	_CrtDumpMemoryLeaks();
	return 0;
}