#pragma once

#include"Card.h"

class CardFour :public Card
{
	// [ CardFour ] Summary:
	// Its Apply() Function: Make prevents the player from rolling the next turn.
	// Its Parameters: Empty.

public:

	CardFour(const CellPosition& pos);// A Constructor takes card position.

	CardFour();

	virtual void ReadCardParameters(Grid* pGrid);// Reads the parameters of CardFour which is: Empty.

	virtual void Apply(Grid* pGrid, Player* pPlayer);// Applies the effect of CardFour on the passed Player.
													  // By prevents the player from rolling the next turn.

	virtual void Save(GameObjectType GameObject, ofstream& savedFile);

	virtual void Load(ifstream& savedFile);

	virtual Card* GetCopy();

	virtual ~CardFour(void);//destructor 
};