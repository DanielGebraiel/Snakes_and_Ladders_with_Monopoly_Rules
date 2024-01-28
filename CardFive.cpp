#include "CardFive.h"
CardFive::CardFive(const CellPosition& pos) :Card(pos)
{
	cardNumber = 5;
}

CardFive::CardFive() : Card(CellPosition(0))
{
	cardNumber = 5;
}

void CardFive::ReadCardParameters(Grid* pGrid)
{
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	int stepsBack = -pPlayer->GetJustRollDiceNum();
	CellPosition previousCell = position;
	previousCell.AddCellNum(stepsBack);
	pGrid->UpdatePlayerCell(pPlayer, previousCell);
}

void CardFive::Save(GameObjectType GameObject, ofstream& savedFile)
{
	if (GameObject != CardObject)
		return;

	savedFile << cardNumber << " " << position.GetCellNum() << endl;
}

void CardFive::Load(ifstream& savedFile)
{
	int cardPos;
	savedFile >> cardPos;
	CellPosition cardCell(cardPos);
	SetCardPosition(cardCell);
}

Card* CardFive::GetCopy()
{
	return new CardFive(position);
}

CardFive::~CardFive(void)
{
}