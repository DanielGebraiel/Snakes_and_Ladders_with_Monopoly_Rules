#include "SaveGridAction.h"
#include "Grid.h"
#include "GameObject.h"
SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{

}

void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Please enter the name of the file to save the grid:");
	fileName = pIn->GetSrting(pOut);
}

void SaveGridAction::Execute()
{
	ofstream savedFile;
	ReadActionParameters();
	savedFile.open(fileName);
	Grid* pGrid = pManager->GetGrid();

	int numOfLadders = pGrid->GetNumOfLadders();
	savedFile << numOfLadders << endl;
	pGrid->SaveAll(savedFile, LadderObject);

	int numOfSnakes = pGrid->GetNumOfSnakes();
	savedFile << numOfSnakes << endl;
	pGrid->SaveAll(savedFile, SnakeObject);

	int numOfCards = pGrid->GetNumOfCards();
	savedFile << numOfCards << endl;
	pGrid->SaveAll(savedFile, CardObject);

	savedFile.close();
	pGrid->GetOutput()->PrintMessage("Grid has been saved successfully");
}

SaveGridAction :: ~SaveGridAction()
{

}