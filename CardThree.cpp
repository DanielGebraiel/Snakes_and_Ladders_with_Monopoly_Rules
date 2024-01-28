#include "CardThree.h"
#include"RollDiceAction.h"


CardThree::CardThree(const CellPosition& pos) :Card(pos)
{
	cardNumber = 3;
}

CardThree::CardThree() : Card(CellPosition(0))
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number
}

void CardThree::ReadCardParameters()
{
}
void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer); //Call Apply() of the base class Card to print the message that you reached this card number

	//Advances the player for three times to return back to the play who just played
	pGrid->AdvanceCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();
	pGrid->GetOutput()->PrintMessage("You get an Extra dice roll! Click on roll dice to play again");
}

void CardThree::Save(GameObjectType GameObject, ofstream& savedFile)
{
	if (GameObject != CardObject)
		return;

	savedFile <<cardNumber << " " << position.GetCellNum() << endl;
}

void CardThree :: Load(ifstream& savedFile)
{
	int cardPos;
	savedFile >> cardPos;
	CellPosition cardCell(cardPos);
	SetCardPosition(cardCell);
}

Card* CardThree::GetCopy()
{
	return new CardThree(position);
}

CardThree::~CardThree(void)
{
	//Empty Distractor
}
