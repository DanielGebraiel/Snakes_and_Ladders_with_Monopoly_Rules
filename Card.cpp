#include "Card.h"


Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
}

void Card::SetCardNumber(int cnum)
{
	if (cnum >= 1 && cnum <= 12)
		cardNumber = cnum; ////////////////// needs validation
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::SetCardPosition(CellPosition pos)
{
	if (pos.IsValidCell())
		position = pos;
}

void Card::Draw(Output* pOut) const
{

	/////////////////////TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position, cardNumber);

}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards don't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	int x, y;
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click
	if (pPlayer->GetCell()->HasCard())
	{
		pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
	}

}

void Card :: Save(GameObjectType GameObject, ofstream& savedFile)
{

}

void Card :: Load(ifstream& savedFile)
{
	
}

bool Card :: isOverlapping(GameObject* newObj)
{
	return false;
}

Card* Card::GetCopy()
{
	return new Card(position);
}

Card::~Card()
{
}