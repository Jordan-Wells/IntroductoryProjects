#include "othello.h"
#include <iostream>
#include <iomanip>
#include "colors.h"

Othello::Othello(){
    piece newPiece;
    for(size_t i = 0; i < 8; ++i){
        for(size_t j = 0; j < 8; ++j){
            board[i][j] = newPiece; 
        }
    }
}


void Othello::make_move(const std::string& move){
    int row = toupper(move[0]) - 'A';
    int column = move[1] - '0' - 1;
    
    if(next_mover() == COMPUTER){
        board[row][column].set_owner(2);
    }
    else if(next_mover() == HUMAN){
        board[row][column].set_owner(1);
    }
    game::make_move(move);

    return;
}
        // Restart the game from the beginning:
void Othello::restart( ){
    for(size_t i = 0; i < 8; ++i){
        for(size_t j = 0; j < 8; ++j){
            board[i][j].reset();
        }
    }
    game::restart();
    return;
}
        // Return a pointer to a copy of myself:
game* Othello::clone( ) const{
    // game * current;
    // current = this;
    return NULL;
}
        // Compute all the moves that the next player can make:
void Othello::compute_moves(std::queue<std::string>& moves) const{

    return;
}
    	// Display the status of the current game:
void Othello::display_status( ) const{
    
    for(size_t i = 0; i < 8; ++i){
        std::cout << GREEN << std::setfill('-') << std::setw(17) << "-" << std::endl;
        for(size_t j = 0; j < 8; ++j){
            std::cout << GREEN << "|";
            if(board[i][j].is_empty()){
                std::cout << " ";
            }
            else if(board[i][j].get_owner() == 1){
                std::cout << BLUE << "O";
            }
            else if(board[i][j].get_owner() == 2){
                std::cout << RED << "O";
            }
        }
        std::cout << GREEN << "|" << std::endl;
    }
    std::cout << GREEN << std::setfill('-') << std::setw(17) << "-" << std::endl;
    return;
}
    	// Evaluate a board position:
	// NOTE: positive values are good for the computer.
int Othello::evaluate( ) const{
    return 0;
}
    	// Return true if the current game is finished:
bool Othello::is_game_over( ) const{
    for(size_t i = 0; i < 8; ++i){
        for(size_t j = 0; j < 8; ++j){
            if(board[i][j].is_empty()){
                return false;
            }
        }
    }
    return true;
}
    	// Return true if the given move is legal for the next player:
bool Othello::is_legal(const std::string& move) const{
    size_t a = 0;
    char x = move[a];
    while(!isalpha(x)){
        a++;
        x = move[a];
    }
    int row = toupper(x) - 'A';
    int column = move[a + 1] - '1';
    if(row > 7 || row < 0)
        return false;

    if(column >= 8 || column < 0)
        return false;
    
    if(!board[row][column].is_empty())
        return false;
    
    if(isalnum(move[a+2]))
        return false;

    return true;
}