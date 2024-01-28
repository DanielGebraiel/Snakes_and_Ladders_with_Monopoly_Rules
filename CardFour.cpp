#include "CardFour.h"
CardFour::CardFour(const CellPosition& pos) :Card(pos)
{
	cardNumber = 4;// set the inherited cardNumber data member with the card number.
}

CardFour::CardFour() : Card(CellPosition(0))
{
	cardNumber = 4;
}

void CardFour::ReadCardParameters(Grid* pGrid)
{
	//Empty.
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);//Call Apply() of the base class Card to print the message that you reached this card number.

	pPlayer->SetunplayableTurns(pPlayer->GetunplayableTurns() + 1);//Make the player cant't play one turn. 
}

void CardFour::Save(GameObjectType GameObject, ofstream& savedFile)
{
	if (GameObject != CardObject)
		return;

	savedFile << cardNumber << " " << position.GetCellNum() << endl;
}

void CardFour::Load(ifstream& savedFile)
{
	int cardPos;
	savedFile >> cardPos;
	CellPosition cardCell(cardPos);
	SetCardPosition(cardCell);
}

Card* CardFour::GetCopy()
{
	return new CardFour(position);
}

CardFour::~CardFour(void)
{
	// Distractor.
}