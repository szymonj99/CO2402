#pragma once

#include <iostream>
#include <string>
#include "Constants.h"

namespace Noughts
{
	enum class PlayerTurn
	{
		PLAYER_ONE,
		PLAYER_TWO,
	};

	struct Input
	{
		int uiX, uiY;		
	};

	class CNoughts
	{
	private:
		int m_Grid[Constants::SIZE][Constants::SIZE];
		PlayerTurn playerTurn = PlayerTurn::PLAYER_TWO;

	public:
		// Initialise the grid to 0.
		void Initialise();
		// Display the grid.
		void Grid() const;
		// Get the input from the player.
		const Input GetInput();
		// Try to insert the symbol at the X and Y coordinates. Returns false if player tries to put the symbol out of the scope of the grid or the place is taken.
		bool Insert(const int X, const int Y);
		// Get the symbol for the current player.
		const char GetPlayerSymbol();
		// Check horizontal lines for a win
		bool HorizontalWin();
		// Check vertical lines for a win
		bool VerticalWin();
		// Check diagonal lines for a win
		bool DiagonalWin();
		// Check if any of the players are winning
		bool Winning();
		// Check if the game is a draw
		bool Drawing();
		// Write to std::cout who's turn it is
		void OutputPlayerTurn();
		// Write to std::cout who the winning player is
		void OutputWinningPlayer();
		// Output to std::cout that the game is a draw
		void OutputDraw();
		// Change the current player
		void ChangePlayer();
	};
}