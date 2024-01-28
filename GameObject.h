#pragma once

#include "Grid.h"
#include <fstream>

// Base Class for All Game Objects ( ladders, snakes and cards )
enum GameObjectType
{
	LadderObject,
	SnakeObject,
	CardObject
};

class GameObject
{

protected:

	CellPosition position; // The current cell position of the GameObject
	
public:

	GameObject(const CellPosition & pos); // Constructor for initializing data members
	
	CellPosition GetPosition() const;     // A Getter for position

	// ============ Virtual Functions ============

	virtual void Draw(Output* pOut) const = 0;	 // Draws the game object in the window in his position cell 
											     // (drawing depends on GameObject Type, so virtual)

	virtual void Apply(Grid* pGrid, Player* pPlayer) = 0;  // Applys the effect of the GameObject on the passed Player
	                                                       // (The effect depends on the GameObject type, so virtual)
	                                                       // For example, applying a ladder is by moving player up, and so on

	virtual void Save(GameObjectType object, ofstream &savedFile) = 0; // Saves the GameObject parameters to the file

	virtual void Load(ifstream & savedFile) = 0; // Loads and Reads the GameObject parameters from the file

	virtual bool isOverlapping(GameObject* newObj)=0;

	// The following functions are examples of what should be supported by the GameObject class
	// They should be overridden by each inherited class

	// Decide the parameters that you should pass to each function	
	

	virtual ~GameObject(); // Virtual destructor
};