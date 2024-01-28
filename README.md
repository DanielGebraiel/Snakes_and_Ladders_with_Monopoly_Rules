
# Snakes & Ladders with Monopoly Rules

-This is an innovative game that combines two very interesting and entertaining games into an even better one!

-Play with your friends, climb ladders and avoid snakes as you try to beat them to reach the final square similar to snakes and ladders but with the twist of adding event cards in some squares to make the game more interesting

-This Game has 2 modes: Design and Play
## Play Mode

- Up to 4 players can play this game
- Players take turn in rolling the dice to reach the final destination
- Players have an amount of coins that they use to aid them to reach the final square
- There is an option to reset the game
- If there is a specefic feature that players need to test, they can specify the dice number

## Design Mode

- This is where players can unleash their creativity to make any board that they wish
- Players can add vertical ladders & snakes
- Players can add cards out of the 12 available cards and choose their properties
- Design mode is made easier by features such as copy, cut & paste
- Players also can save their boards and load it at any time
- Their is also the ability that players can load any board they would like as long as it has a specefic file format
## Cards

- Card1:
Decrements the value of the passing player’s wallet by a value specified when creating the grid.
Input data in design mode:
Value to decrement  

- Card2:
Moves the player forward to the start of the next ladder in the grid.
If no ladders ahead, do nothing.

- Card3 and Card4:
Card3 gives the player an extra dice roll.
Card4 prevents the player from rolling the next turn.
Both the extra dice roll or the canceled dice roll count normally towards recharging the wallet turn (both increment the count of player turns).

- Card5:
Moves the player backward with the same number of steps that he just rolled.
If he reaches a ladder, a snake, or a card at the end of moving, take it.

- Card6:
Instructs the player to go to a specific cell.
If the destination cell contains a ladder, snake, or card, take it.
Input data in design mode: Cell to move to. 

- Card7:
• Restarts the game for the first player whose cell is after the current player in the grid. Restarting the game for a player makes him go to cell number 1.

- Card8:
This card is a prison. When a player stops at a Card8 cell, the player should choose either to pay specific amount of coins to go out of the prison, or stay in prison and not playing for 3 turns.
Input data in design mode: The amount of coins needed to go out of the prison

- Cards [from 9 to 11]:
Gives the player the option to buy this cell and all cells containing a card with the same number. For example, if a player chooses to buy a cell with Card10, he will own all cells having a Card10. \
-This cell is considered a station for a specific price. \
-This specific price is deducted from the player’s wallet in case he chooses to buy the cell. \
-Whenever another player stops at a cell owned by another player, he has to pay fees to the player who owns the cell. \
-The price of the cell and the fees are taken as input during grid design. \
-Input data in design mode is only taken if it is the first time to insert a card with the same number. For example, user will insert price and fees of Card10 only once. \
-Input data in design mode: \
i. Card price\
ii. Fees to pay by passing players 
- Card12:
• This card moves the ownership of the most expensive station that the current user owns from the current user to the player that has the least amount of coins in his wallet.
## File Format

#Comments start with hashtag such as this one

3 #Number Of ladders\
13 68 #Starting Position, Ending Position\
38 60 #Starting Position, Ending Position\
42 86 #Starting Position, Ending Position\
2 #Number of Snakes\
73 51 #Starting Position, Ending Position\
92 37 #Starting Position, Ending Position\
5 #Number Of Cards\
1 4 20 #CardNum, Card location, Card properties\
3 7 #CardNum, Card location\
7 33 #CardNum, Card location\
6 63 44 #CardNum, Card location, Card properties\
5 78 #CardNum, Card location

## Screenshots

- Design Mode
![App Screenshot](https://github.com/DanielGebraiel/Snakes_-_Ladders_with_Monopoly_Rules/blob/main/screenshots/designMode.png)

- Play Mode
![App Screenshot](https://github.com/DanielGebraiel/Snakes_-_Ladders_with_Monopoly_Rules/blob/main/screenshots/playMode.png)

- Landing on Card
![App Screenshot](https://github.com/DanielGebraiel/Snakes_-_Ladders_with_Monopoly_Rules/blob/main/screenshots/usingCard1.png)

![App Screenshot](https://github.com/DanielGebraiel/Snakes_-_Ladders_with_Monopoly_Rules/blob/main/screenshots/usingCard2.png)


## Lessons Learned

- OOP in C++ and Class hierarchy
- How to store and load data using files
- How to create a simple GUI using CMU graphics Library

