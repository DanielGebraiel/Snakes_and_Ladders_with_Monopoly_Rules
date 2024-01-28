#include "DeleteGameObject.h"
#include "Grid.h"

DeleteGameObject::DeleteGameObject(ApplicationManager* pApp) : Action(pApp)
{
	//EMPTY
}

void DeleteGameObject :: ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Please choose a game object to delete:");
	selectedCell = pIn->GetCellClicked();
}

void DeleteGameObject::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	ReadActionParameters();

	bool check = pGrid->RemoveObjectFromCell(selectedCell);
	if (check == 1)
		pGrid->GetOutput()->PrintMessage("Object removed successfully");
	else
		pGrid->GetOutput()->PrintMessage("Error! No Game Object");
}

DeleteGameObject :: ~DeleteGameObject()
{

}