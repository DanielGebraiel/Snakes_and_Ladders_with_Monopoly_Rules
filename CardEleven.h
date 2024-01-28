#pragma once

#include "Card.h"

//This card is a station
class CardEleven : public Card
{
protected:
	//defining static members
	static int CardPrice;
	static int StationFees;
	static Player* Owner;
	static bool FirstTime;
	static Player* OwnerThree;
	static bool firstTimeSave;
	static bool firstTimeLoad;

public:

	CardEleven(const CellPosition& pos); // A Constructor takes card position

	CardEleven(const CellPosition& pos, int CardPriceInput, int StationFeesInput);

	CardEleven();

	void setOwner(Player* p);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(GameObjectType GameObject, ofstream& savedFile);

	virtual void Load(ifstream& savedFile);

	virtual Card* GetCopy();

	virtual ~CardEleven(); // A Virtual Destructor
};