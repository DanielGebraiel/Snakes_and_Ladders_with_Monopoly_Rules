#pragma once

#include "Action.h"
#include "CellPosition.h"

class CutCardAction : public Action
{
	CellPosition cutCell;

public:
	CutCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~CutCardAction();
};