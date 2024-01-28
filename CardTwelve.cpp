#include "CardTwelve.h"

CardTwelve::CardTwelve(const CellPosition& pos) : Card(pos), CardNine(pos), CardTen(pos), CardEleven(pos) // sets the cell position of the card and inherit from them all to get the owner
{
	Card::cardNumber = 12; // set the inherited cardNumber data member with the card number (12 here)
}

CardTwelve::CardTwelve() : Card(CellPosition(0)), CardNine(CellPosition(0)), CardTen(CellPosition(0)), CardEleven(CellPosition(0))
{
	Card::cardNumber = 12;
}

//default destructor
CardTwelve::~CardTwelve(void)
{
}

void CardTwelve::ReadCardParameters(Grid* pGrid)
{
	//empty
	//No parameters needed from the user
}
//function to get the most expensive station
Card* CardTwelve::MaxStation(Grid* pGrid, Player* pPlayer)
{
	int max = 0;
	//initializing a card member to get from it the player number
	Card* owner = NULL;

	if (OwnerOne != NULL && OwnerOne->GetPlayerNumber() == pPlayer->GetPlayerNumber())
	{
		//comparing the card prices of stations which each owner has to get the max
		if (CardNine::CardPrice > max)
		{
			max = CardNine::CardPrice;
			owner = new CardNine(pPlayer->GetCell()->GetCellPosition());

		}
	}
	if (OwnerTwo != NULL && OwnerTwo->GetPlayerNumber() == pPlayer->GetPlayerNumber())
	{
		if (CardTen::CardPrice > max)
		{
			max = CardTen::CardPrice;
			owner = new CardTen(pPlayer->GetCell()->GetCellPosition());
		}
	}
	if (OwnerThree != NULL && OwnerThree->GetPlayerNumber() == pPlayer->GetPlayerNumber())
	{
		if (CardEleven::CardPrice > max)
		{
			max = CardEleven::CardPrice;
			owner = new CardEleven(pPlayer->GetCell()->GetCellPosition());
		}
	}
	return owner;
	//owner!=null
}


void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)

{
	Card::Apply(pGrid, pPlayer);

	pGrid->AdvanceCurrentPlayer();
	int min = pGrid->GetCurrentPlayer()->GetWallet();
	Player* minPlayer = pGrid->GetCurrentPlayer();
	for (int i = 0; i < 2; i++)
	{
		pGrid->AdvanceCurrentPlayer();
		if (pGrid->GetCurrentPlayer()->GetWallet() < min)
		{
			min = pGrid->GetCurrentPlayer()->GetWallet();
			minPlayer = pGrid->GetCurrentPlayer();
		}
	}
	Card* MaxOwner = MaxStation(pGrid, pPlayer);
	if (MaxOwner != NULL && MaxOwner->GetCardNumber() == 9)
	{
		CardNine::setOwner(minPlayer);
	}
	if (MaxOwner != NULL && MaxOwner->GetCardNumber() == 10)
	{
		CardTen::setOwner(minPlayer);
	}
	if (MaxOwner != NULL && MaxOwner->GetCardNumber() == 11)
	{
		CardEleven::setOwner(minPlayer);
	}
	pGrid->AdvanceCurrentPlayer();
}

void CardTwelve::Save(GameObjectType GameObject, ofstream& savedFile)
{
	if (GameObject != CardObject)
		return;

	savedFile << Card :: cardNumber << " " << Card :: position.GetCellNum() << endl;
}

void CardTwelve::Load(ifstream& savedFile)
{
	int cardPos;
	savedFile >> cardPos;
	CellPosition cardCell(cardPos);
	Card :: SetCardPosition(cardCell);
}

Card* CardTwelve::GetCopy()
{
	return new CardTwelve(Card :: position);
}