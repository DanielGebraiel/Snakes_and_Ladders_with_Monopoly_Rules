#include "CardEight.h"
//default constructor
CardEight::CardEight(const CellPosition& pos) :Card(pos)
{
	//Setting the card number
	cardNumber = 8;
}

CardEight::CardEight() : Card(CellPosition(0))
{
	cardNumber = 8;
}

CardEight::CardEight(const CellPosition& pos, int walletAmountInput) : Card(pos)
{
	walletAmount = walletAmountInput;
	cardNumber = 8;
}

void CardEight::ReadCardParameters(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	//In design mode: it gives the player the option to pay a specific amount in order not to remain in prison for three turns
	pOut->PrintMessage("Please enter the amount to decrement from the player wallet:");
	int decrementAmount = -1;
	//Checking if the amount of decrement is positive or not
	while (decrementAmount <= 0)
	{
		decrementAmount = pIn->GetInteger(pOut);
		if (decrementAmount <= 0)
		{
			pOut->PrintMessage("Error! Please enter a positive number:");
		}
	}
	//setting the decrement amount
	walletAmount = decrementAmount;

	pOut->ClearStatusBar();
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	//calling the "Apply function from base class "card"
	Card::Apply(pGrid, pPlayer);

	//The option in play mode
	pGrid->GetOutput()->PrintMessage("Do you want to pay (p) to get out of prison or not play for 3 turns(t)?");
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	//if the player wants to pay instead of remaining in prison
	if (pIn->GetSrting(pOut) == "p")
	{
		pPlayer->SetWallet(pPlayer->GetWallet() - walletAmount);
	}
	//if not:
	else
	{
		//setting the number of unplayable turns:
		pOut->ClearStatusBar();
		return pPlayer->SetunplayableTurns(pPlayer->GetunplayableTurns() + 3);

	}

}

void CardEight::Save(GameObjectType GameObject, ofstream& savedFile)
{
	if (GameObject != CardObject)
		return;

	savedFile << cardNumber << " " << position.GetCellNum() << " " << walletAmount << endl;
}

void CardEight::Load(ifstream& savedFile)
{
	int cardPos;
	savedFile >> cardPos;
	CellPosition cardCell(cardPos);
	int decrementAmount;
	savedFile >> decrementAmount;
	SetCardPosition(cardPos);
	walletAmount = decrementAmount;
}

Card* CardEight::GetCopy()
{
	return new CardEight(position, walletAmount);
}
//default destructor
CardEight::~CardEight(void)
{
}