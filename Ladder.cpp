#include "Ladder.h"
#include "Snake.h"
#include "Player.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{

	if (startCellPos.HCell() == endCellPos.HCell() && startCellPos.VCell() > endCellPos.VCell())
	{
		this->endCellPos = endCellPos;
	}
	//////////////////////////TODO: Do the needed validation
}

Ladder :: Ladder() : GameObject(CellPosition(0))
{
	endCellPos = CellPosition(0);
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///////////////////////TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	int x, y;

	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->GetOutput()->PrintMessage("You have reached a ladder. Click to continue ...");
	pGrid->GetInput()->GetPointClicked(x, y);
	pGrid->GetOutput()->ClearStatusBar();
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	if (pGrid->Get_Object(endCellPos))
	{
		pGrid->Get_Object(endCellPos)->Apply(pGrid, pPlayer);
		pPlayer->SetTurnCount(pPlayer->GetTurnCount() - 1);
	}
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

void Ladder::Save(GameObjectType gameObject, ofstream &savedFile)
{
	if (gameObject != LadderObject)
		return;

	savedFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
}

void Ladder :: Load(ifstream& savedFile)
{
	int start, end;
	savedFile >> start >> end;
	CellPosition startCell(start);
	CellPosition endCell(end);
	position = startCell;
	endCellPos = endCell;
}

bool Ladder::isOverlapping(GameObject* newObj)
{
	Ladder* pLadder;
	pLadder = dynamic_cast<Ladder*>(newObj);
	if (pLadder)
	{
		if (pLadder->GetEndPosition().HCell() == GetEndPosition().HCell())
		{
			if (pLadder->GetEndPosition().VCell() <= position.VCell())
			{
				if (GetEndPosition().VCell() <= pLadder->GetPosition().VCell())
					return true;
			}
		}
	}
	Snake* pSnake;
	pSnake = dynamic_cast<Snake*>(newObj);
	if (pSnake)
	{
		if (GetEndPosition().HCell() == pSnake->GetEndPosition().HCell())
		{
			if (GetEndPosition().VCell() == pSnake->GetPosition().VCell())
				return true;
		}
	}
	return false;
}

Ladder::~Ladder()
{
}