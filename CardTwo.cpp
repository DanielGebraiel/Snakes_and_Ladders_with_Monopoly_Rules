#include "CardTwo.h"
#include "Ladder.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos)
{
	cardNumber = 2;// set the inherited cardNumber data member with the card number
}

CardTwo::CardTwo() : Card(CellPosition(0))
{
	cardNumber = 2;
}

CardTwo ::~CardTwo()
{
	//Empty Distractor 
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
	//Empty
}
void CardTwo::Apply(Grid* pGrid, Player* pPlayer)

{
	Card::Apply(pGrid, pPlayer); //Call Apply() of the base class Card to print the message that you reached this card number
	Ladder* next = pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition()); //make possition of the next ladder
	if (next == NULL)
		return;
	int diff = (next->GetPosition().GetCellNum()) - (pPlayer->GetCell()->GetCellPosition().GetCellNum()); //The Diffrince between player and the ladder

	pGrid->GetCurrentPlayer()->Move(pGrid, diff); //Make player move the ladder

	pPlayer->SetTurnCount((pPlayer->GetTurnCount()) - 1); //Corrects the play count
}

void CardTwo::Save(GameObjectType GameObject, ofstream& savedFile)
{
	if (GameObject != CardObject)
		return;

	savedFile << cardNumber << " " << position.GetCellNum() << endl;
}

void CardTwo::Load(ifstream& savedFile)
{
	int cardPos;
	savedFile >> cardPos;
	CellPosition cardCell(cardPos);
	SetCardPosition(cardCell);
}

Card* CardTwo :: GetCopy()
{
	return new CardTwo(position);
}