#pragma once

#include "Card.h"
//This card is a station

class CardTen : public Card
{
protected:
	//defining static members
	static int CardPrice;
	static int StationFees;
	static bool FirstTime;
	static Player* OwnerTwo;
	static bool firstTimeSave;
	static bool firstTimeLoad;

public:

	CardTen(const CellPosition& pos); // A Constructor takes card position

	CardTen(const CellPosition& pos, int CardPriceInput, int StationFeesInput);

	CardTen();

	virtual void Save(GameObjectType GameObject, ofstream& savedFile);

	virtual void Load(ifstream& savedFile);

	virtual Card* GetCopy();

	void setOwner(Player* p);
	Player* CardTen::GetOwner();

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);



	virtual ~CardTen(); // A Virtual Destructor
};