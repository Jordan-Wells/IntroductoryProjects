#ifndef OTHELLO_H
#define OTHELLO_H
#include "game.h"
#include "piece.h"
#include "colors.h"
using namespace main_savitch_14;
class Othello: public game{
    public:
     Othello();
     void make_move(const std::string& move);
        // Restart the game from the beginning:
     void restart( );
        // Return a pointer to a copy of myself:
     game* clone( ) const;
        // Compute all the moves that the next player can make:
     void compute_moves(std::queue<std::string>& moves) const;
    	// Display the status of the current game:
     void display_status( ) const;
    	// Evaluate a board position:
	// NOTE: positive values are good for the computer.
     int evaluate( ) const;
    	// Return true if the current game is finished:
     bool is_game_over( ) const;
    	// Return true if the given move is legal for the next player:
     bool is_legal(const std::string& move) const;

    private:
     piece board[8][8];

};

#endif