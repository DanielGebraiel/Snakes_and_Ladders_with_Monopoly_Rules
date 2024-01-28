#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
	check = false;
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	//////////////////////TODO: Make the needed validations on the read parameters
	if (startPos.HCell() == endPos.HCell() && startPos.VCell() > endPos.VCell())
	{
		if (startPos.GetCellNum() != 1 && endPos.GetCellNum() != 99)
		{
			check = true;
		}
	}

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	
	// Create a Ladder object with the parameters read from the user
	if (check == true)
	{
		bool added = false;
		Ladder* pLadder = new Ladder(startPos, endPos);

		if (pGrid->isOverlapping(pLadder) == true)
		{
			pGrid->PrintErrorMessage("Error: Ladder is overlapping with another ladder or snake ! Click to continue ...");
			return;
		}
		else
		{
			// Add the card object to the GameObject of its Cell:
			added = pGrid->AddObjectToCell(pLadder);
		}

		// if the GameObject cannot be added
		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}
		// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

		pGrid->GetOutput()->PrintMessage("Ladder has been drawn successfully");
	}
	else
	{
		pGrid->GetOutput()->PrintMessage("Error! Can not draw ladder!");
	}
}
