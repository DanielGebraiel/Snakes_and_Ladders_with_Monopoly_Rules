#pragma once
#include"Card.h"
class CardThree :public Card
{
	// [ CardThree ] Summary:
	// Its Apply() Function: Get Extra Dice Roll.
	// Its Parameters: Empty

public:
	CardThree(const CellPosition& pos); // A Constructor takes card position.
	CardThree();
	virtual void ReadCardParameters(); // Reads the parameters of CardThree which is: Empty.
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player.
													  // By  Get Extra Dice Roll.
	virtual void Save(GameObjectType GameObject, ofstream & savedFile);
	virtual void Load(ifstream& savedFile);
	virtual Card* GetCopy();
	virtual ~CardThree(void); // Distractor
};