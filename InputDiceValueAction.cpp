#include "InputDiceValueAction.h"

#include "Grid.h"
#include "Player.h"

InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp) : Action(pApp)
{
	diceValue = 0;
}

void InputDiceValueAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Please enter a number from 1 to 6");
	int inputValue = pIn->GetInteger(pOut);
	if (inputValue >= 1 && inputValue <= 6)
		diceValue = inputValue;
}

void InputDiceValueAction::Execute()
{

	//TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	ReadActionParameters();
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	Grid* pGrid = pManager->GetGrid();
	if (pGrid->GetEndGame() == true)
	{

	}
	// -- If not ended, do the following --:
	else
	{
		//2- Check if the user has entered a proper dice value and then exits if so, else the player moves with the entererd dice value
		if (diceValue == 0)
		{
			pGrid->GetOutput()->PrintMessage("Sorry! You entered an invalid number");
			return;
		}

		// 3- Get the "current" player from pGrid
		Player* currentPlayer = pGrid->GetCurrentPlayer();
		// 4- Move the currentPlayer using function Move of class player
		currentPlayer->Move(pGrid, diceValue);
		// 5- Advance the current player number of pGrid
		pGrid->AdvanceCurrentPlayer();

		// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
	}
}

InputDiceValueAction::~InputDiceValueAction()
{
}
