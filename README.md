# Reversi

Download and Installation : - 
  
  •	Download the Code from Github
  
  •	Run make command to compile the source code
  
  •	Run ./reversi to run the executable
  
  •	After the completion of the game play, check the savedgames folder to view your saved files.



Description : Implementation of Reversi board game into its technical equivalent using C++/C. The interface of the game is User Vs User.



So what is Reversi? 

Reversi is a strategy board game for two players, played on an 8×8 uncheckered board. There are sixty-four identical game pieces called tiles, which are a diamond symbol on one side and a spade symbol on the other. Players take turns placing tiles on the board with their assigned symbol. During a play, a player can make a move in the horizontal or the vertical direction crossing over the tiles occupied by the symbol of the opponent. The object of the game is to have the majority of the tiles turned to display your symbol when the last playable empty square is filled.



Rules to implemented in the workings of the game : -

1)	Objective: To have maximum occupied tiles.

2)	Each player gets 25 chances each to create a majority of his/her tiles on the board.

3)	Only horizontal and vertical moves are allowed.

4)	Rules for valid initial co-ordinates:- The tile whose initial co-ordinate is entered should already be occupied by the  current player.

5)	Rules for valid final co-ordinates:- The tile whose co-ordinate is entered should be an empty tile. There should atleast be one opponent's tile and no empty tiles between the initial and final co-ordinates.

6)	The player whose, tiles comprise the majority of the board at the end of 25 moves or earlier (in case of unavailability of      moves for the other player, wins the game)

7)	The player who wins the toss will go first

8) A player can forfeit the game by entering 0 0 as the initial co-ordinates.



Features Incorporated : -

•	Random Event – Conduction of toss among the 2 players to decide who would have the first chance. 

•	File Input/Output – Storing the game-play moves in a new directory called ‘savedgames’ for future reference of the games previously played.

•	Dynamic Memory Management using Data Structures – Implementation of ‘vector’ (STL) for storing the game moves and creating the reversi game board.


