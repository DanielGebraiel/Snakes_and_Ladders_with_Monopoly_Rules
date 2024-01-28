#include "Card.h"

//This card restarts the game for the first player whose cell is after the current player in the grid.

class CardSeven : public Card
{

public:
	CardSeven(const CellPosition& pos);
	CardSeven();
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(GameObjectType GameObject, ofstream& savedFile);
	virtual void Load(ifstream& savedFile);
	virtual Card* GetCopy();
	~CardSeven(void);
};