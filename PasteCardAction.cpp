#pragma once

#include "PasteCardAction.h"
#include "Grid.h"
#include "Card.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
	//EMPTY
}

void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Please choose a card to paste to:");
	clickedCell = pIn->GetCellClicked();
}

void PasteCardAction :: Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	ReadActionParameters();

	if (clickedCell.IsValidCell())
	{
		Card* copiedCard = pGrid->GetClipboard();
		copiedCard->SetCardPosition(clickedCell);
		pGrid->AddObjectToCell(copiedCard);
		pOut->PrintMessage("Card pasted successfully!");
	}
	else
	{
		pOut->PrintMessage("Error! invalid position to paste card");
	}
}

PasteCardAction :: ~PasteCardAction()
{

}