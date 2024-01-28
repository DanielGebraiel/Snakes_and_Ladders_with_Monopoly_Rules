#include "CutCardAction.h"
#include "Grid.h"
#include "Card.h"
CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
	//EMPTY
}

void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Please choose a card to cut:");
	cutCell = pIn->GetCellClicked();
}

void CutCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	ReadActionParameters();

	Card* pCard = pGrid->GetCard(cutCell);
	if (pCard)
	{
		pGrid->SetClipboard(pCard->GetCopy());
		pGrid->RemoveObjectFromCell(cutCell);
		pOut->PrintMessage("Card has been cut to clipboard successfully!");
	}
	else
	{
		pGrid->GetOutput()->PrintMessage("Error! There is no card here");
	}
}

CutCardAction :: ~CutCardAction()
{

}