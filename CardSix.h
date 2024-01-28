#pragma once
#include "Card.h"


class CardSix : public Card
{
	int destinationCellNumber;
public:
	CardSix(const CellPosition& pos);
	CardSix(const CellPosition& pos, int savedDestinationCellNumber);
	CardSix();
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(GameObjectType GameObject, ofstream& savedFile);
	virtual void Load(ifstream& savedFile);
	virtual Card* GetCopy();
	~CardSix(void);
};