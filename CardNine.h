#pragma once

#include "Card.h"

class CardNine : public Card
{
protected:
	//defining static members
	static int CardPrice;
	static int StationFees;
	static Player* Owner;
	static bool FirstTime;
	static Player* OwnerOne;
	static bool firstTimeSave;
	static bool firstTimeLoad;


public:
	CardNine(const CellPosition& pos); // A Constructor takes card position

	CardNine(const CellPosition& pos, int CardPriceInput, int StationFeesInput);

	CardNine();

	void setOwner(Player* player1);
	Player* CardNine::GetOwner();

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(GameObjectType GameObject, ofstream& savedFile);

	virtual void Load(ifstream& savedFile);

	virtual Card* GetCopy();

	virtual ~CardNine(); // A Virtual Destructor
};