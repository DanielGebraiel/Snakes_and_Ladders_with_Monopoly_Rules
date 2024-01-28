#include "NewGameAction.h"
#include "Grid.h"
#include "Player.h"

NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{
}

void NewGameAction::ReadActionParameters()
{
	// no parameters to read from user
}

void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	for (int i = 0; i <= 3; i++)
	{
		pGrid->GetCurrentPlayer()->Restart(pGrid);
		pGrid->AdvanceCurrentPlayer();
	}
	int playernum = pGrid->GetCurrentPlayer()->GetPlayerNumber();
	for (int i = 4; i > playernum; i--)
	{
		pGrid->AdvanceCurrentPlayer();
	}
	pGrid->GetOutput()->ClearStatusBar();
}

NewGameAction:: ~NewGameAction()
{
}