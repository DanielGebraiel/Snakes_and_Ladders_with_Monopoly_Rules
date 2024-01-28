#include "CardOne.h"

CardOne::CardOne(const CellPosition & pos) : Card(pos) // sets the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}

CardOne::CardOne(const CellPosition& pos, int savedWalletAmount) :Card(pos)
{
	cardNumber = 1;
	walletAmount = savedWalletAmount;
}

CardOne::CardOne(): Card(CellPosition(0))
{
	cardNumber = 1;
}

CardOne::~CardOne(void)
{
}

void CardOne::ReadCardParameters(Grid * pGrid)
{
	int x, y;
	
	////////////TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input *pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	pOut->PrintMessage("New Card One: Please enter the amount to decrement from the player's wallet:");
	int decrementAmount = -1;
	while (decrementAmount <= 0)
	{
		decrementAmount = pIn->GetInteger(pOut);
		if (decrementAmount <= 0)
		{
			pOut->PrintMessage("Error! Please enter a positive number:");
		}
	}
	walletAmount = decrementAmount;
	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{
		
	/////////////TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	pPlayer->SetWallet(pPlayer->GetWallet() - walletAmount);

}

void CardOne::Save(GameObjectType GameObject, ofstream & savedFile)
{
	if (GameObject != CardObject)
		return;

	savedFile << cardNumber << " " << position.GetCellNum() << " " << walletAmount << endl;
}

void CardOne::Load(ifstream& savedFile)
{
	int cardPos;
	savedFile >> cardPos;
	CellPosition cardCell(cardPos);
	int decrementAmount;
	savedFile >> decrementAmount;
	SetCardPosition(cardPos);
	walletAmount = decrementAmount;
}

Card* CardOne::GetCopy()
{
	return new CardOne(position, walletAmount);
}