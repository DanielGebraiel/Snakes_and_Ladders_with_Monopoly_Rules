#pragma once

#include "Action.h"

class ToDesignModeAction : public Action
{

	// No parameters for this action

public:
	ToDesignModeAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~ToDesignModeAction();
};