#include "Player.h"

#include "GameObject.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"

Player::Player(Cell* pCell, int playerNum) : stepCount(0), wallet(100), playerNum((playerNum >= 0 && playerNum <= MaxPlayerCount - 1) ? playerNum : -1)
{
	if (pCell->GetCellPosition().IsValidCell())
	{
		this->pCell = pCell;
	}
	this->turnCount = 0;
	//////////////// Make all the needed initialization or validations
	unplayableTurns = 0;
}

// ====== Setters and Getters ======

void Player::SetCell(Cell* cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;


	////////////// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

void Player::SetTurnCount(int TurnCount)
{
	turnCount = TurnCount;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

int Player::GetPlayerNumber() const
{
	return playerNum;
}
void Player::SetunplayableTurns(int numberInput)
{
	if (numberInput > 0)
		unplayableTurns = numberInput;

	else
		unplayableTurns = 0;

}

int Player::GetunplayableTurns()
{
	return unplayableTurns;
}

void Player::SetJustRollDiceNum(int DiceNum)
{
	justRolledDiceNum = DiceNum;
}

int Player::GetJustRollDiceNum()
{
	return justRolledDiceNum;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];
	Cell* pos = this->GetCell();
	pOut->DrawPlayer(pos->GetCellPosition(), playerNum, playerColor);

	///////////////TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	Cell* pos = this->GetCell();
	pOut->DrawPlayer(pos->GetCellPosition(), playerNum, cellColor);

	///////////////TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	turnCount++;
	if (unplayableTurns > 0)
	{
		pGrid->GetOutput()->PrintMessage("You Can't Play This Turn ! ");
		pGrid->UpdatePlayerCell(this, pCell->GetCellPosition());
		unplayableTurns--;
		pGrid->AdvanceCurrentPlayer();

		if (turnCount == 3)
		{
			turnCount = 0;
			return;
		}

	}
	else
	{
		// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
		if (turnCount == 3)
		{
			//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
			wallet += diceNumber * 10;
			turnCount = 0;
			return;
		}

		if (wallet < 1)
			return;

		// 3- Set the justRolledDiceNum with the passed diceNumber

		justRolledDiceNum = diceNumber;

		// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
		CellPosition pos = pCell->GetCellPosition();
		//    Using the appropriate function of CellPosition class to update "pos"
		pos.AddCellNum(justRolledDiceNum);
		stepCount += justRolledDiceNum;
		// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
		pGrid->UpdatePlayerCell(this, pos);

		//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

		// 6- Apply() the game object of the reached cell (if any)
		if (pCell->GetGameObject() != NULL)
			pCell->GetGameObject()->Apply(pGrid, this);

		// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
		if (pCell->GetCellPosition().GetCellNum() + diceNumber == 100)
		{
			pGrid->UpdatePlayerCell(this, 99);
			pGrid->SetEndGame(true);
			pGrid->GetOutput()->PrintMessage("Playernumber" + to_string(playerNum) + "YOU ARE WINNER  Click to continue");
		}
	}

}

void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}

void Player::Restart(Grid* pGrid, int number)
{

	CellPosition cellpos = cellpos.GetCellPositionFromNum(1);
	pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(), cellpos);
	if (number != 7)
	{
		wallet = 100;
		turnCount = 0;
		CardNine card9(CellPosition(1));
		CardTen card10(CellPosition(1));
		CardEleven card11(CellPosition(1));
		card10.setOwner(NULL);
		card11.setOwner(NULL);
		card9.setOwner(NULL);
	}
	string Playerinfo = "";
	pGrid->GetCurrentPlayer()->AppendPlayerInfo(Playerinfo);
}