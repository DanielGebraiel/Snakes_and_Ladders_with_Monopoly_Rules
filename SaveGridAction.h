#pragma once

#include "Action.h"
#include "GameObject.h"
#include <fstream>
#include <string>
using namespace std;

class SaveGridAction : public Action
{
	string fileName;

public:
	SaveGridAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~SaveGridAction();
};

