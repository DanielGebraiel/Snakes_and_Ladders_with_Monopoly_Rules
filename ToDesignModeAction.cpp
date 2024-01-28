#include "ToDesignModeAction.h"
#include "Grid.h"

ToDesignModeAction::ToDesignModeAction(ApplicationManager* pApp) : Action(pApp)
{

}

void ToDesignModeAction::ReadActionParameters()
{
	//EMPTY
}

void ToDesignModeAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreateDesignModeToolBar();
	pOut->ClearStatusBar();
}

ToDesignModeAction :: ~ToDesignModeAction()
{

}