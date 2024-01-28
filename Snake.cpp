#include "Snake.h"
#include "Ladder.h"
#include "Player.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{

	if (startCellPos.HCell() == endCellPos.HCell() && startCellPos.VCell() < endCellPos.VCell())
	{
		this->endCellPos = endCellPos;
	}
	//////////////////////////TODO: Do the needed validation
}

Snake::Snake() : GameObject(CellPosition(0))
{
	endCellPos = CellPosition(0);
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///////////////////////TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	int x, y;

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a snake. Click to continue ..." and wait mouse click
	pGrid->GetOutput()->PrintMessage("You have reached a snake. Click to continue ...");
	pGrid->GetInput()->GetPointClicked(x, y);
	pGrid->GetOutput()->ClearStatusBar();
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	if (pGrid->Get_Object(endCellPos))
	{
		pGrid->Get_Object(endCellPos)->Apply(pGrid, pPlayer);
		pPlayer->SetTurnCount(pPlayer->GetTurnCount() - 1);
	}
	// 2- Apply the snake's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

void Snake::Save(GameObjectType GameObject, ofstream &savedFile)
{
	if (GameObject != SnakeObject)
		return;

	savedFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
}

void Snake :: Load(ifstream& savedFile)
{
	int start, end;
	savedFile >> start >> end;
	CellPosition startCell(start);
	CellPosition endCell(end);
	position = startCell;
	endCellPos = endCell;
}

bool Snake::isOverlapping(GameObject* newObj)
{
	Snake* pSnake;
	pSnake = dynamic_cast<Snake*>(newObj);
	if (pSnake)
	{
		if (pSnake->GetEndPosition().HCell() == GetEndPosition().HCell())
		{
			if (pSnake->GetPosition().VCell() <= GetEndPosition().VCell())
			{
				if (GetPosition().VCell() <= pSnake->GetEndPosition().VCell())
					return true;
			}
		}
	}
	Ladder* pLadder;
	pLadder = dynamic_cast<Ladder*>(newObj);
	if (pLadder)
	{
		if (GetEndPosition().HCell() == pLadder->GetEndPosition().HCell())
		{
			if (GetEndPosition().VCell() == pLadder->GetPosition().VCell())
				return true;
		}
	}
	return false;
}

Snake::~Snake()
{
}
