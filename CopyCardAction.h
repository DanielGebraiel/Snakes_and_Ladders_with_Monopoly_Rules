#pragma once

#include "Action.h"
#include "CellPosition.h"

class CopyCardAction : public Action
{
	CellPosition copiedCell;

public:
	CopyCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~CopyCardAction();
};