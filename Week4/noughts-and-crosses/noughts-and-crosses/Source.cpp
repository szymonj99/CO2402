#include <memory> // std::unique_ptr
#include "CNoughts.h"

int main()
{
	static std::unique_ptr<Noughts::CNoughts> Game = std::make_unique<Noughts::CNoughts>();

	Game.get()->Initialise();
	Game.get()->Grid();

	// While the game is not over, keep playing
	while (!Game.get()->Winning() || !Game.get()->Drawing())
	{
		// Clear screen
		std::cout << "\x1B[2J\x1B[H";

		Game.get()->Grid();

		// Change before asking for input to start off asking for player one, as the game is initialised with player two.
		// This fixes a bug where the wrong player is shown at the end of the game in the case of a win
		// And saves CPU cycles in comparison to:
		// if (!Game.get()->Winning() || !Game.get()->Drawing())
		// {
		//	 Game.get()->ChangePlayer();
		// }
		Game.get()->ChangePlayer();
		Game.get()->OutputPlayerTurn();
		Noughts::Input userInput = Game.get()->GetInput();
		while (!Game.get()->Insert(userInput.uiX, userInput.uiY))
		{
			userInput = Game.get()->GetInput();
		}
	}

	Game.get()->Drawing() ? Game.get()->OutputDraw() : Game.get()->OutputWinningPlayer();

	std::cin.get();

	return 0;
}