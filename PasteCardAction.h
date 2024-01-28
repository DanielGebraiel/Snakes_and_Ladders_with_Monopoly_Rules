#pragma once

#include "Action.h"
#include "CellPosition.h"

class PasteCardAction : public Action
{
	CellPosition clickedCell;

public:
	PasteCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~PasteCardAction();
};