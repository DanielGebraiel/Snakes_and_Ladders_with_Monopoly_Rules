#include "ApplicationManager.h"

#include "Grid.h"
#include "AddLadderAction.h"
#include "AddSnakeAction.h"
#include "AddCardAction.h"
#include "CopyCardAction.h"
#include "CutCardAction.h"
#include "PasteCardAction.h"
#include "SaveGridAction.h"
#include "OpenGridAction.h"
#include "ToPlayModeAction.h"
#include "RollDiceAction.h"
#include "NewGameAction.h"
#include "DeleteGameObject.h"
#include "InputDiceValueAction.h"
#include "ToDesignModeAction.h"

///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_LADDER:
		pAct = new AddLadderAction(this);
		break;

	case ADD_CARD:
		// create an object of AddCardAction here
		pAct = new AddCardAction(this);
		break;

	case COPY_CARD:
		// create an object of CopyCardAction here
		pAct = new CopyCardAction(this);
		break;

	case CUT_CARD:
		// create an object of CutCardAction here
		pAct = new CutCardAction(this);
		break;

	case PASTE_CARD:
		// create an object of PasteCardAction here
		pAct = new PasteCardAction(this);
		break;

	case ADD_SNAKE:
		// create an object of AddSnakeAction here
		pAct = new AddSnakeAction(this);
		break;

	case DELETE_GAME_OBJECT:
		// create an object of DeleteGameObject here
		pAct = new DeleteGameObject(this);
		break;

	case SAVE_GRID:
		//create an object of SaveGrid here
		pAct = new SaveGridAction(this);
		break;

	case OPEN_GRID:
		//create an object of OpenGrid here
		pAct = new OpenGridAction(this);
		break;

	case EXIT:
		break;

	case TO_PLAY_MODE:
		// create an object of ToPlayModeAction here
		pAct = new ToPlayModeAction(this);
		break;

	case NEW_GAME:
		// create an object of NewGame here
		pAct = new NewGameAction(this);
		break;

	case ROLL_DICE:
		// create an object of RollDiceAction here
		pAct = new RollDiceAction(this);
		break;

	case INPUT_DICE_VALUE:
		// create an object of RollDiceAction here
		pAct = new InputDiceValueAction(this);
		break;

	case SWITCH_TO_DESIGN_MODE:
		// create an object of ToDesignMode here
		pAct = new ToDesignModeAction(this);
		break;

		

		///TODO: Add a case for EACH Action type in the Design mode or Play mode



	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
