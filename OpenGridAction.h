#pragma once

#include "Action.h"
#include <fstream>
#include <string>
using namespace std;

class OpenGridAction : public Action
{
	string fileName;

public:
	OpenGridAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~OpenGridAction();
};