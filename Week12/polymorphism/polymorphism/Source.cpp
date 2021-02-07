#include <string>
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

class CTest
{
public:
	virtual void WriteMessage();
};

void CTest::WriteMessage()
{
	std::cout << "Message from base class." << std::endl;
}

class CMessage1 : public CTest
{
public:
	void WriteMessage()
	{
		std::cout << "Message from 1." << std::endl;
	}
};

class CMessage2 : public CTest
{
public:
	void WriteMessage()
	{
		std::cout << "Message from 2." << std::endl;
	}
};

class CAccount
{
private:
	float mfBalance;

public:
	void Deposit(float amount);
	void ChangeBalance(float amount);
	float GetBalance();
	virtual void Withdrawal(float amount);
	virtual void Interest();
};

void CAccount::Deposit(float amount)
{
	mfBalance += amount;
}

void CAccount::ChangeBalance(float amount)
{
	mfBalance = amount;
}

float CAccount::GetBalance()
{
	return mfBalance;
}

class CCurrentAccount : public CAccount
{
private:
	const float mkfWithdrawLimit = 5000.0f;
	float mfWithdrawnMoney = 0.0f;
	const float mkfInterest = 0.05f; // 5% interest rate

public:
	void Withdrawal(float amount)
	{
		if (mfWithdrawnMoney + amount < mkfWithdrawLimit)
		{
			mfWithdrawnMoney += amount;
			ChangeBalance(amount);
		}
	}

	void Interest()
	{
		if (GetBalance() < 0.0f)
		{
			ChangeBalance(GetBalance() - (GetBalance() * mkfInterest));
		}
	}
};

class CDepositAccount : public CAccount
{
private:
	const float mkfInterest = 0.03f; // 3% interest rate

public:
	void Withdrawal(float amount)
	{
		if (GetBalance() - amount > 0.0f)
		{
			ChangeBalance(GetBalance() - amount);
		}
		else
		{
			ChangeBalance(0.0f);
		}
	}

	void Interest()
	{
		if (GetBalance() > 0.0f)
		{
			ChangeBalance(GetBalance() + (GetBalance() * mkfInterest));
		}
	}
};

int main()
{
	CTest* pMessages[4];
	pMessages[0] = new CMessage1;
	pMessages[1] = new CMessage2;
	pMessages[2] = new CMessage1;
	pMessages[3] = new CMessage2;

	for (CTest* message : pMessages)
	{
		message->WriteMessage();
	}

	free(pMessages[0]);
	pMessages[0] = nullptr;
	free(pMessages[1]);
	pMessages[1] = nullptr;
	free(pMessages[2]);
	pMessages[2] = nullptr;
	free(pMessages[3]);
	pMessages[3] = nullptr;

	_CrtDumpMemoryLeaks();

	return 0;
}