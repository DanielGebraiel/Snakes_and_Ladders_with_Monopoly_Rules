#pragma once

#include "Card.h"

// [ CardTwo ] Summary:
// Its Apply() Function: Moves the player forward to the start of the next ladder direct.
// Its Parameters: Empty.

class CardTwo : public Card
{

	//Doesn't Have Parameters.

public:

	CardTwo(const CellPosition& pos); // A Constructor takes card position.

	CardTwo(); // A default constructor

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardTwo which is: Empty.

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwo on the passed Player.
													  // By moves the player forward to the start of the next ladder.

	virtual void Save(GameObjectType GameObject, ofstream& savedFile);

	virtual void Load(ifstream& savedFile);

	virtual Card* GetCopy();

	virtual ~CardTwo();// Distructor.
};