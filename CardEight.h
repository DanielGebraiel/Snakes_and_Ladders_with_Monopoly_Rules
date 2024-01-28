#pragma once
#include"Card.h"

//This card is a prison

class CardEight :public Card
{
	int walletAmount;
public:
	CardEight(const CellPosition& pos);
	CardEight(const CellPosition& pos, int walletAmountInput);
	CardEight();
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardEight(void);
	virtual void Save(GameObjectType GameObject, ofstream& savedFile);
	virtual void Load(ifstream& savedFile);
	virtual Card* GetCopy();
};