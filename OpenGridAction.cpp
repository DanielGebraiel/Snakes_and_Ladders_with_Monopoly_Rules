#include "OpenGridAction.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "Grid.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"

OpenGridAction::OpenGridAction(ApplicationManager* pApp) : Action(pApp)
{

}

void OpenGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Please enter the name of the file of the grid you wish to open:");
	fileName = pIn->GetSrting(pOut);
}

void OpenGridAction::Execute()
{
	ifstream savedFile;
	ReadActionParameters();
	savedFile.open(fileName);
	Grid* pGrid = pManager->GetGrid();

	if (savedFile.is_open())
	{
		Input* pIn = pGrid->GetInput();
		Output* pOut = pGrid->GetOutput();

		GameObject* pGameObject;
		
		pGrid->ClearAll();

		for (int i = 0; i <= 3; i++)
		{
			pGrid->GetCurrentPlayer()->Restart(pGrid);
			pGrid->AdvanceCurrentPlayer();
		}
		int playernum = pGrid->GetCurrentPlayer()->GetPlayerNumber();
		for (int i = 4; i > playernum; i--)
		{
			pGrid->AdvanceCurrentPlayer();
		}
		pGrid->GetOutput()->ClearStatusBar();

		int numOfLadders;
		savedFile >> numOfLadders;
		for (int i = 0; i < numOfLadders; ++i)
		{
			pGameObject = new Ladder();
			pGameObject->Load(savedFile);
			pGrid->AddObjectToCell(pGameObject);
		}

		int numOfSankes;
		savedFile >> numOfSankes;
		for (int i = 0; i < numOfSankes; ++i)
		{
			pGameObject = new Snake();
			pGameObject->Load(savedFile);
			pGrid->AddObjectToCell(pGameObject);
		}

		int numOfCards;
		savedFile >> numOfCards;
		int currentCardNumber;

		for (int i = 0; i < numOfCards; ++i)
		{
			savedFile >> currentCardNumber;

			switch (currentCardNumber)
			{
			case 1:
				pGameObject = new CardOne();
				pGameObject->Load(savedFile);
				pGrid->AddObjectToCell(pGameObject);
				break;

			case 2:
				pGameObject = new CardTwo();
				pGameObject->Load(savedFile);
				pGrid->AddObjectToCell(pGameObject);
				break;

			case 3:
				pGameObject = new CardThree();
				pGameObject->Load(savedFile);
				pGrid->AddObjectToCell(pGameObject);
				break;

			case 4:
				pGameObject = new CardFour();
				pGameObject->Load(savedFile);
				pGrid->AddObjectToCell(pGameObject);
				break;

			case 5:
				pGameObject = new CardFive();
				pGameObject->Load(savedFile);
				pGrid->AddObjectToCell(pGameObject);
				break;

			case 6:
				pGameObject = new CardSix();
				pGameObject->Load(savedFile);
				pGrid->AddObjectToCell(pGameObject);
				break;

			case 7:
				pGameObject = new CardSeven();
				pGameObject->Load(savedFile);
				pGrid->AddObjectToCell(pGameObject);
				break;

			case 8:
				pGameObject = new CardEight();
				pGameObject->Load(savedFile);
				pGrid->AddObjectToCell(pGameObject);
				break;

			case 9:
				pGameObject = new CardNine();
				pGameObject->Load(savedFile);
				pGrid->AddObjectToCell(pGameObject);
				break;

			case 10:
				pGameObject = new CardTen();
				pGameObject->Load(savedFile);
				pGrid->AddObjectToCell(pGameObject);
				break;

			case 11:
				pGameObject = new CardEleven();
				pGameObject->Load(savedFile);
				pGrid->AddObjectToCell(pGameObject);
				break;

		//	case 12:
			//	pGameObject = new CardTwelve();
			//	pGameObject->Load(savedFile);
			//	pGrid->AddObjectToCell(pGameObject);
			//	break;
			}
		}

		pOut->PrintMessage("File has been loaded successfully!");
	}
	else
	{
		pGrid->PrintErrorMessage("Error! File not Found");
	}
}

OpenGridAction :: ~OpenGridAction()
{

}