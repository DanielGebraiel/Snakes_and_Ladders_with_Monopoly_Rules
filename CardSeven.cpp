#include "CardSeven.h"


CardSeven::CardSeven(const CellPosition& pos) : Card(pos)
{
	cardNumber = 7;
}

CardSeven::CardSeven() : Card(CellPosition(0))
{
	cardNumber = 7;
}

CardSeven::~CardSeven(void)
{
}

void CardSeven :: ReadCardParameters(Grid* pGrid)
{
	//empty
	//There is no parameters asked from the user
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	//calling the "Apply" function from base class "Card"
	Card::Apply(pGrid, pPlayer);

	int cellNum = this->GetPosition().GetCellNum();
	Player* newPlayer = pGrid->GetCurrentPlayer();

	//Get the first player after the current player:
	//1-initializing First cell number with a number greater than any cell number

	int First = 100;
	for (int i = 0; i < 3; i++)
	{
		//2-check which player is the first one after the current player and setting it
		pGrid->AdvanceCurrentPlayer();
		int current = pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition().GetCellNum();
		//3-if the current player is the first one after the player who got the card
		if (current > cellNum && current < First)
		{
			First = current;
		}
	}
	pGrid->AdvanceCurrentPlayer();
	for (int i = 0; i < 3; i++)
	{
		pGrid->AdvanceCurrentPlayer();
		//Updating the cell position of the player to restart the game (Go to the first cell) 
		if (pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition().GetCellNum() == First)
		{
			pGrid->GetCurrentPlayer()->Restart(pGrid, 7);
		}
	}
	pGrid->AdvanceCurrentPlayer();
}

void CardSeven::Save(GameObjectType GameObject, ofstream& savedFile)
{
	if (GameObject != CardObject)
		return;

	savedFile << cardNumber << " " << position.GetCellNum() << endl;
}

void CardSeven::Load(ifstream& savedFile)
{
	int cardPos;
	savedFile >> cardPos;
	CellPosition cardCell(cardPos);
	SetCardPosition(cardCell);
}

Card* CardSeven::GetCopy()
{
	return new CardSeven(position);
}