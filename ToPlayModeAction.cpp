#include "ToPlayModeAction.h"
#include "Grid.h"

ToPlayModeAction::ToPlayModeAction(ApplicationManager* pApp): Action(pApp)
{

}

void ToPlayModeAction::ReadActionParameters()
{
	//EMPTY
}

void ToPlayModeAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreatePlayModeToolBar();
	pOut->ClearStatusBar();
}

ToPlayModeAction :: ~ToPlayModeAction()
{

}