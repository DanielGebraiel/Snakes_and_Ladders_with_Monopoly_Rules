#include "CopyCardAction.h"
#include "Grid.h"
#include "Card.h"
CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
	//EMPTY
}

void CopyCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Please choose a card to copy:");
	copiedCell = pIn->GetCellClicked();
}

void CopyCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	ReadActionParameters();

	Card* pCard = pGrid->GetCard(copiedCell);
	if (pCard)
	{
		pGrid->SetClipboard(pCard->GetCopy());
		pOut->PrintMessage("Card has been copied to clipboard successfully!");
	}
	else
	{
		pGrid->GetOutput()->PrintMessage("Error! There is no card here");
	}
}

CopyCardAction :: ~CopyCardAction()
{

}