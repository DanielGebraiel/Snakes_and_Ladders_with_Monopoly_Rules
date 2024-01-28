#pragma once

#include "Action.h"

class InputDiceValueAction : public Action
{

	int diceValue;

public:
	InputDiceValueAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~InputDiceValueAction();
};

