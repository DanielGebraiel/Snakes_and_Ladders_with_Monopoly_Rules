#pragma once
#include"Card.h"
class CardFive :public Card
{
public:
	CardFive(const CellPosition& pos);
	CardFive();
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void Save(GameObjectType GameObject, ofstream& savedFile);
	virtual void Load(ifstream& savedFile);
	virtual Card* GetCopy();
	virtual ~CardFive(void);
};