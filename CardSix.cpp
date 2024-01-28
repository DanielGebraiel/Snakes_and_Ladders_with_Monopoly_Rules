#include "CardSix.h"
#include "Ladder.h"
#include "Snake.h"

CardSix::CardSix(const CellPosition& pos) : Card(pos)
{
	cardNumber = 6;
}

CardSix :: CardSix(const CellPosition& pos, int savedDestinationCellNumber) : Card(pos)
{
	cardNumber = 6;
	destinationCellNumber = savedDestinationCellNumber;
}

CardSix::CardSix() : Card(CellPosition(0))
{
	cardNumber = 6;
}

CardSix::~CardSix(void)
{
}

void CardSix::ReadCardParameters(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("New Card Six, Please enter your destination cell number");
	int newNumber = 0;
	while (newNumber < 1 || newNumber>99)
	{
		newNumber = pIn->GetInteger(pOut);
		if (newNumber < 1 || newNumber>99)
		{
			pOut->PrintMessage("Error! Please enter a valid cell number:");
		}
	}
	destinationCellNumber = newNumber;
	pOut->ClearStatusBar();
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	int initialCell = pPlayer->GetCell()->GetCellPosition().GetCellNum();
	int move = destinationCellNumber - initialCell;
	pPlayer->Move(pGrid, move);
	if (pPlayer->GetCell()->GetGameObject() == NULL)
	{
		pPlayer->SetTurnCount(pPlayer->GetTurnCount() - 1);
	}
}

void CardSix::Save(GameObjectType GameObject, ofstream& savedFile)
{
	if (GameObject != CardObject)
		return;

	savedFile << cardNumber << " " << position.GetCellNum() << " " << destinationCellNumber << endl;
}

void CardSix :: Load(ifstream& savedFile)
{
	int cardPos;
	savedFile >> cardPos;
	CellPosition cardCell(cardPos);
	SetCardPosition(cardPos);
	int cellDestinationPosition;
	savedFile >> cellDestinationPosition;
	destinationCellNumber = cellDestinationPosition;
}

Card* CardSix::GetCopy()
{
	return new CardSix(position, destinationCellNumber);
}