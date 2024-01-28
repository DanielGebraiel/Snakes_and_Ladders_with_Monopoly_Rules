#include "CardNine.h"

//Setting the static data members
int CardNine::CardPrice = -1;
int CardNine::StationFees = -1;
Player* CardNine::OwnerOne = NULL;
bool CardNine::FirstTime = true;
bool CardNine::firstTimeSave = true;
bool CardNine::firstTimeLoad = true;

//default constructor
CardNine::CardNine(const CellPosition& pos) : Card(pos) // sets the cell position of the card
{
	cardNumber = 9;

}

CardNine::CardNine(const CellPosition& pos, int CardPriceInput, int StationFeesInput): Card(pos)
{
	CardPrice = CardPriceInput;
	StationFees = StationFees;
	cardNumber = 9;
}

CardNine::CardNine() : Card(CellPosition(0))
{
	cardNumber = 9;
}

//default destructor
CardNine::~CardNine(void)
{
}
//Setting an owner so that we can use later in card 12
void  CardNine::setOwner(Player* player1)
{
	OwnerOne = player1;
}
Player* CardNine::GetOwner()
{
	return OwnerOne;
}

void CardNine::ReadCardParameters(Grid* pGrid)
{
	//if the player is entering the card price and the station fees for the first time to set them
	if (FirstTime == true)
	{
		Input* pIn = pGrid->GetInput();
		Output* pOut = pGrid->GetOutput();

		pOut->PrintMessage("New Card: Please enter the card price:");
		int Price, Fees;
		Price = -1;
		Fees = -1;

		//To check if the card price is positive
		while (Price <= 0)
		{
			Price = pIn->GetInteger(pOut);
			if (Price <= 0)
			{
				pOut->PrintMessage("Error! Please enter a positive number for the Card price:");
			}
		}

		//setting the card price
		CardPrice = Price;

		pOut->PrintMessage("New Card: Please enter the Station fees:");

		//Checking if the station fees is positive or not
		while (Fees <= 0)
		{
			Fees = pIn->GetInteger(pOut);
			if (Fees <= 0)
			{
				pOut->PrintMessage("Error! Please enter a positive number for the card fees:");
			}
		}

		//setting the station fees
		StationFees = Fees;

		// Clear the status bar

		pOut->ClearStatusBar();

		//setting the first time by false to avoid re-entering the price and fees
		FirstTime = false;
	}
}


void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{

	//Calling the "Apply" Function from the base class "Card"
	Card::Apply(pGrid, pPlayer);
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	//Setting the owner of CardNine by asking the current player if he wants to buy it
	if (OwnerOne == NULL)
	{
		pGrid->GetOutput()->PrintMessage("Do you want to buy this station (y/n)?");
		if (pIn->GetSrting(pOut) == "y")
		{
			//if he wants to buy it, then we must check if he has its price or not
			if (pPlayer->GetWallet() >= CardPrice)
			{

				//if he has its money, then OwnerOne is set to have the address of this player and then, its card price is deducted from the wallet
				CardNine::OwnerOne = pPlayer;
				OwnerOne->SetWallet(pPlayer->GetWallet() - CardPrice);
			}
			else
			{
				pOut->PrintMessage("You Don't Have Enough Monney");
			}
		}
	}
	else
	{
		//if any other player stops at this bought card
		if (pPlayer != OwnerOne)
		{
			//Then the owner will get the fees from the player who just stopped at that card
			OwnerOne->SetWallet(OwnerOne->GetWallet() + StationFees);

			//and the fees will be deducted from that player
			pPlayer->SetWallet(pPlayer->GetWallet() - StationFees);
		}
	}
}

void CardNine::Save(GameObjectType GameObject, ofstream& savedFile)
{
	if (GameObject != CardObject)
		return;

	if (firstTimeSave == true)
	{
		savedFile << cardNumber << " " << position.GetCellNum() << " " << CardPrice << " " << StationFees << endl;
		firstTimeSave = false;
	}
	else
	{
		savedFile << cardNumber << " " << position.GetCellNum() << endl;
	}
}

void CardNine::Load(ifstream& savedFile)
{
	if (firstTimeLoad == true)
	{
		int savedCellNumber;
		savedFile >> savedCellNumber;
		CellPosition savedCell(savedCellNumber);
		SetCardPosition(savedCell);
		savedFile >> CardPrice;
		savedFile >> StationFees;
		firstTimeLoad = false;
	}
	else
	{
		int savedCellNumber;
		savedFile >> savedCellNumber;
		CellPosition savedCell(savedCellNumber);
		SetCardPosition(savedCell);
	}

}

Card* CardNine :: GetCopy()
{
	return new CardNine(position,CardPrice, StationFees);
}