#pragma once
#include "Action.h"
class NewGameAction : public Action
{

public:
	NewGameAction(ApplicationManager* pApp);

	void NewGameAction::ReadActionParameters();

	virtual void Execute();

	virtual ~NewGameAction();
};