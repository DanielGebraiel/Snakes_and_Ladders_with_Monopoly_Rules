#pragma once
#include "Card.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include"Player.h"
//This card moves the ownership of the most expensive station that the current user owns from the current user to the player that has the least amount of coins in his wallet.
//To get the owner we should inherit from cards nine to eleven
class CardTwelve :
    public Card, public CardNine, public CardTen, public CardEleven
{

public:
    CardTwelve(const CellPosition& pos);

    CardTwelve();

    virtual void ReadCardParameters(Grid* pGrid);

    virtual void Apply(Grid* pGrid, Player* pPlayer);

    Card* MaxStation(Grid* pGrid, Player* pPlayer);

    void Save(GameObjectType GameObject, ofstream& savedFile);

    virtual void Load(ifstream& savedFile);

    virtual Card* GetCopy();

    virtual ~CardTwelve();
};