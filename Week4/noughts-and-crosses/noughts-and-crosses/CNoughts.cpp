#include "CNoughts.h"

void Noughts::CNoughts::Initialise()
{
	for (auto& outer : m_Grid)
	{
		for (auto& inner : outer)
		{
			inner = Constants::DEFAULT_CHAR;
		}
	}
}

void Noughts::CNoughts::Grid() const
{
	for (auto& outer : m_Grid)
	{
		for (auto& inner : outer)
		{
			std::cout << static_cast<char>(inner) << " ";	
		}
		std::cout << "\n";
	}
	std::cout << std::endl; // Clear output buffer
}

bool Noughts::CNoughts::Insert(const int X, const int Y)
{
	const char cSymbol = GetPlayerSymbol();
	// We are checking the Contants values outside of this function already.
	//if (X - 1 > Constants::WIDTH || Y - 1 > Constants::HEIGHT || m_Grid[X - 1][Y - 1] != 0)
	if (m_Grid[X - 1][Y - 1] != Constants::DEFAULT_CHAR)
	{
		return false;
	}
	m_Grid[X - 1][Y - 1] = cSymbol;
	return true;
}

const Noughts::Input Noughts::CNoughts::GetInput()
{
	int uiX, uiY; // User input X and user input Y.
	do
	{
		std::cout << "Input the the X and Y location, separated by space." << std::endl;
		std::cin >> uiY >> uiX; // Scan in reverse order, to follow the X and Y as the grid is stored in reverse order.
	}
	while (uiX > Constants::SIZE || uiX < 1 || uiY > Constants::SIZE || uiY < 1);
	return { uiX, uiY };
}

const char Noughts::CNoughts::GetPlayerSymbol()
{
	return playerTurn == PlayerTurn::PLAYER_ONE ? Constants::PLAYER_ONE : Constants::PLAYER_TWO;
}

bool Noughts::CNoughts::HorizontalWin()
{
	// Tripwire
	bool won = true;

	const char cSymbol = GetPlayerSymbol();

	// Check the horizontal lines.
	for (int row = 0; row < Constants::SIZE; row++)
	{
		won = true;
		for (int column = 0; column < Constants::SIZE; column++)
		{
			if (m_Grid[row][column] != cSymbol)
			{
				won = false;
				break;
			}
		}
		if (won)
		{
			return won;
		}
	}
	//for (const auto& row : m_Grid)
	//{
	//	for (const auto column : row)
	//	{
	//		if (column != cSymbol)
	//		{
	//			won = false;
	//			break;
	//		}
	//	}
	//}
	return won;
}

bool Noughts::CNoughts::VerticalWin()
{
	// Tripwire
	bool won = true;

	const char cSymbol = GetPlayerSymbol();

	// Check Vertical lines
	// For every char in first row, check all chars below current position
	for (int row = 0; row < Constants::SIZE; row++)
	{
		for (int column = 0; column < Constants::SIZE; column++)
		{
			if (m_Grid[row][column] != cSymbol)
			{
				won = false;
				break;
			}
		}
		if (won)
		{
			break;
		}
	}
	return won;
}

bool Noughts::CNoughts::DiagonalWin()
{
	// Tripwire
	bool won = true;

	const char cSymbol = GetPlayerSymbol();

	// Check diagonal lines.
	// Top left corner to bottom right corner
	for (int i = 0; i < Constants::SIZE; i++)
	{
		if (m_Grid[i][i] != cSymbol)
		{
			won = false;
			break;
		}
		if (won)
		{
			break;
		}
	}

	if (won)
	{
		return won;
	}

	// Bottom left corner to top right corner
	for (int i = 0; i < Constants::SIZE; i++)
	{
		if (m_Grid[Constants::SIZE - i - 1][i] != cSymbol)
		{
			won = false;
			break;
		}
		if (won)
		{
			break;
		}
	}
	return won;
}

bool Noughts::CNoughts::Winning()
{
	return (HorizontalWin() || VerticalWin() || DiagonalWin());	
}

bool Noughts::CNoughts::Drawing()
{
	bool drawing = true;
	for (const auto& outer : m_Grid)
	{
		for (const auto& inner : outer)
		{
			if (inner == Constants::DEFAULT_CHAR)
			{
				drawing = false;
				break;
			}
		}
		if (!drawing)
		{
			break;
		}
	}
	return drawing;
}

void Noughts::CNoughts::OutputPlayerTurn()
{
	playerTurn == PlayerTurn::PLAYER_ONE ? std::cout << "Player One's turn." << std::endl : std::cout << "Player Two's turn." << std::endl;
}

void Noughts::CNoughts::OutputWinningPlayer()
{
	playerTurn == PlayerTurn::PLAYER_ONE ? std::cout << "Player One won." << std::endl : std::cout << "Player Two won." << std::endl;
}

void Noughts::CNoughts::OutputDraw()
{
	std::cout << "The game ended with a draw." << std::endl;
}

void Noughts::CNoughts::ChangePlayer()
{
	playerTurn == PlayerTurn::PLAYER_ONE ? playerTurn = PlayerTurn::PLAYER_TWO : playerTurn = PlayerTurn::PLAYER_ONE;
}