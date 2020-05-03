/**************************************************************************
	 This file is the implemetation of the Othello class which is a child
     of the game class. It include the virtual function implementations
     of the game class including how making a move is handled and how
     illegal moves are handled
	    Jordan Wells				April 21st, 2020
************************************************************************/
#include "othello.h"
#include <iostream>
#include <iomanip>
#include "colors.h"
#include <cstdlib>

Othello::Othello(){
    piece newPiece;
    for(size_t i = 0; i < 8; ++i){
        for(size_t j = 0; j < 8; ++j){
            board[i][j] = newPiece; 
        }
    }
    board[4][4].set_owner(1);
    board[4][5].set_owner(2);
    board[5][4].set_owner(2);
    board[5][5].set_owner(1);
}


void Othello::make_move(const std::string& move){
    if(move == "none"){
        game::make_move(move);
        return;
    }
    int row = toupper(move[0]) - 'A';
    int column = move[1] - '1';


    int i = 1;
    bool done = false;
    if(next_mover() == HUMAN){
        //right check
        if(board[row][column + 1].get_owner() == 2){
            while(!done){
                if(column + i >= 8 || board[row][column + i].is_empty()){
                    done = true;
                }
                else if(board[row][column + i].get_owner() == 1){
                    for(size_t j = column + 1; j < column + i; j++){
                        board[row][j].flip();
                    }
                    done = true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row][column - 1].get_owner() == 2){
            while(!done){
                if(column - i <= -1 || board[row][column - i].is_empty()){
                    done = true;
                }
                else if(board[row][column - i].get_owner() == 1){
                    for(size_t j = column - i + 1; j < column; j++){
                        board[row][j].flip();
                    }
                    done = true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row + 1][column].get_owner() == 2){
            while(!done){
                if(row + i >= 8 || board[row + i][column].is_empty()){
                    done = true;
                }
                else if(board[row + i][column].get_owner() == 1){
                    for(size_t j = row + 1; j < row + i; j++){
                        board[j][column].flip(); 
                    }
                    done = true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row - 1][column].get_owner() == 2){
            while(!done){
                if(row - i <= -1 || board[row - i][column].is_empty()){
                    done = true;
                }
                else if(board[row - i][column].get_owner() == 1){
                    for(size_t j = row - i + 1; j < row; j++){
                        board[j][column].flip();
                    }
                    done = true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row + 1][column + 1].get_owner() == 2){
            while(!done){
                if(row + i >= 8 || column + i >= 8 ||board[row + i][column + i].is_empty()){
                    done = true;
                }
                else if(board[row + i][column + i].get_owner() == 1){
                    for(size_t j = row + 1; j < row + i; j++){
                        for(size_t k = column + 1; k < column + i; k++){
                            if(j - row == k - column)
                                board[j][k].flip();
                        }
                    }
                    done = true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row - 1][column - 1].get_owner() == 2){
            while(!done){
                if(row - i <= -1 || column - i <= -1 || board[row - i][column - i].is_empty()){
                    done = true;
                }
                else if(board[row - i][column - i].get_owner() == 1){
                    for(size_t j = row - i + 1; j < row; j++){
                        for(size_t k = column - i + 1; k < column; k++){
                            if(row - j == column - k)
                                board[j][k].flip();
                        }
                    }
                    done = true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row - 1][column + 1].get_owner() == 2){
            while(!done){
                if(row - i <= -1 || column + i >= 8 || board[row - i][column + i].is_empty()){
                    done = true;
                }
                else if(board[row - i][column + i].get_owner() == 1){
                    int j = 1;
                    while(j < i){
                        board[row - j][column + j].flip();
                        j++;
                    }
                    done = true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row + 1][column - 1].get_owner() == 2){
            while(!done){
                if(row + i >= 8 || column - i <= -1 || board[row + i][column - i].is_empty()){
                    done = true;
                }
                else if(board[row + i][column - i].get_owner() == 1){
                    int j = 1;
                    while(j < i){
                        board[row + j][column - j].flip();
                        j++;
                    }
                    done = true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
    }
    if(next_mover() == COMPUTER){
        //right check
        if(board[row][column + 1].get_owner() == 1){
            while(!done){
                if(column + i >= 8 || board[row][column + i].is_empty()){
                    done = true;
                }
                else if(board[row][column + i].get_owner() == 2){
                    for(size_t j = column + 1; j < column + i; j++){
                            board[row][j].flip();
                    }
                    done = true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row][column - 1].get_owner() == 1){
            while(!done){
                if(column - i <= -1 || board[row][column - i].is_empty()){
                    done = true;
                }
                else if(board[row][column - i].get_owner() == 2){
                    for(size_t j = column - i + 1; j < column; j++){
                        board[row][j].flip();
                    }
                    done = true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row + 1][column].get_owner() == 1){
            while(!done){
                if(row + i >= 8 || board[row + i][column].is_empty()){
                    done = true;
                }
                else if(board[row + i][column].get_owner() == 2){
                    for(size_t j = row + 1; j < row + i; j++){
                        board[j][column].flip();
                    }
                    done = true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row - 1][column].get_owner() == 1){
            while(!done){
                if(row - i <= -1 || board[row - i][column].is_empty()){
                    done = true;
                }
                else if(board[row - i][column].get_owner() == 2){
                    for(size_t j = row - i + 1; j < row; j++){
                        board[j][column].flip();
                    }
                    done = true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row + 1][column + 1].get_owner() == 1){
            while(!done){
                if(row + i >= 8 || column + i >= 8 ||board[row + i][column + i].is_empty()){
                    done = true;
                }
                else if(board[row + i][column + i].get_owner() == 2){
                    for(size_t j = row + 1; j < row + i; j++){
                        for(size_t k = column + 1; k < column + i; k++){
                            if(j - row == k - column)
                                board[j][k].flip();
                        }
                    }
                    done = true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row - 1][column - 1].get_owner() == 1){
            while(!done){
                if(row - i <= -1 || column - i <= -1 || board[row - i][column - i].is_empty()){
                    done = true;
                }
                else if(board[row - i][column - i].get_owner() == 2){
                    for(size_t j = row - i + 1; j < row; j++){
                        for(size_t k = column - i + 1; k < column; k++){
                            if(row - j == column - k)
                                board[j][k].flip();
                        }
                    }
                    done = true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row - 1][column + 1].get_owner() == 1){
            while(!done){
                if(row - i <= -1 || column + i >= 8 || board[row - i][column + i].is_empty()){
                    done = true;
                }
                else if(board[row - i][column + i].get_owner() == 2){
                    int j = 1;
                    while(j < i){
                        board[row - j][column + j].flip();
                        j++;
                    }
                    done = true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row + 1][column - 1].get_owner() == 1){
            while(!done){
                if(row + i >= 8 || column - i <= -1 || board[row + i][column - i].is_empty()){
                    done = true;
                }
                else if(board[row + i][column - i].get_owner() == 2){
                    // for(size_t j = row + 1; j < row + i; j++){
                    //     for(size_t k = column - i + 1; k < column; k++){
                    //         if(j - row + i == column - k + 2)
                    //             board[j][k].flip();
                    //     }
                    // }
                    int j = 1;
                    while(j < i){
                        board[row + j][column - j].flip();
                        j++;
                    }
                    done = true;
                }
                i++;
            }
            i = 1;
            done = false;
        } 
    }

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
    board[3][3].set_owner(1);
    board[3][4].set_owner(2);
    board[4][3].set_owner(2);
    board[4][4].set_owner(1);
    return;
}
        // Return a pointer to a copy of myself:
game* Othello::clone( ) const{
   return new Othello(*this);
}
        // Compute all the moves that the next player can make:
void Othello::compute_moves(std::queue<std::string>& moves) const{
    string move = "  ";
    char row = 'A';
    char column = '1';
    while(row <= 'H'){
        while(column <= '7'){
            move[0] = row;
            move[1] = column;
            if(is_legal(move)){
                moves.push(move);
            }
            column++;
        }
        column = '1';
        row++;
    }
    return;
}
    	// Display the status of the current game:
void Othello::display_status( ) const{
    std::cout << BLUE << "HUMAN\t" << RED << "COMPUTER" << std::endl;
    std::cout <<"  ";
    for(size_t i = 1; i <= 8; i++){
        cout << GREEN << left << setw(4) << setfill(' ') << i; 
    }
    std::cout << std::endl;;
    for(size_t i = 0; i < 8; ++i){
        std::cout << GREEN << std::setfill('-') << std::setw(33) << "-" << std::endl;
        for(size_t j = 0; j < 8; ++j){
            std::cout << GREEN << "| ";
            if(board[i][j].is_empty()){
                std::cout << " ";
            }
            else if(board[i][j].get_owner() == 1){
                std::cout << BLUE << "O";
            }
            else if(board[i][j].get_owner() == 2){
                std::cout << RED << "O";
            }
            std::cout << " ";
        }
        std::cout << GREEN << "|"; 
        switch(i){
            case 0:
                std::cout << " A";
                break;
            case 1:
                std::cout << " B";
                break;
            case 2:
                std::cout << " C";
                break;
            case 3:
                std::cout << " D";
                break;
            case 4:
                std::cout << " E";
                break;
            case 5:
                std::cout << " F";
                break;
            case 6:
                std::cout << " G";
                break;
            case 7:
                std::cout << " H";
                break;
            

        }
        std::cout << std::endl;
    }
    std::cout << GREEN << std::setfill('-') << std::setw(17) << "-" << std::endl;
    return;
}
    	// Evaluate a board position:
	// NOTE: positive values are good for the computer.
int Othello::evaluate( ) const{
    size_t i = 0;
    int h = 0, c = 0;
    while(i < 8){
        size_t j = 0;
        while(j < 8){
            if(board[i][j].get_owner() == 2)
                c++;
            else if(board[i][j].get_owner() == 1)
                h++;
            j++;
        }
        i++;
    }
    return c - h;
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
    if( board[row + 1][column].is_empty() && board[row][column+1].is_empty()
        && board[row + 1][column + 1].is_empty() && board[row - 1][column].is_empty()
        && board[row][column - 1].is_empty() && board[row - 1][column - 1].is_empty()
        && board[row + 1][column - 1].is_empty() && board[row - 1][column + 1].is_empty())
        return false;
    if(isalnum(move[a+2]))
        return false;
    
    int i = 1;
    bool done = false;
    if(next_mover() == HUMAN){
        //right check
        if(board[row][column + 1].get_owner() == 2){
            while(!done){
                if(column + i >= 8 || board[row][column + i].is_empty()){
                    done = true;
                }
                else if(board[row][column + i].get_owner() == 1){
                    return true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row][column - 1].get_owner() == 2){
            while(!done){
                if(column - i <= -1 || board[row][column - i].is_empty()){
                    done = true;
                }
                else if(board[row][column - i].get_owner() == 1){
                    return true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row + 1][column].get_owner() == 2){
            while(!done){
                if(row + i >= 8 || board[row + i][column].is_empty()){
                    done = true;
                }
                else if(board[row + i][column].get_owner() == 1){
                    return true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row - 1][column].get_owner() == 2){
            while(!done){
                if(row - i <= -1 || board[row - i][column].is_empty()){
                    done = true;
                }
                else if(board[row - i][column].get_owner() == 1){
                    return true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row + 1][column + 1].get_owner() == 2){
            while(!done){
                if(row + i >= 8 || column + i >= 8 ||board[row + i][column + i].is_empty()){
                    done = true;
                }
                else if(board[row + i][column + i].get_owner() == 1){
                    return true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row - 1][column - 1].get_owner() == 2){
            while(!done){
                if(row - i <= -1 || column - i <= -1 || board[row - i][column - i].is_empty()){
                    done = true;
                }
                else if(board[row - i][column - i].get_owner() == 1){
                    return true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row - 1][column + 1].get_owner() == 2){
            while(!done){
                if(row - i <= -1 || column + i >= 8 || board[row - i][column + i].is_empty()){
                    done = true;
                }
                else if(board[row - i][column + i].get_owner() == 1){
                    return true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row + 1][column - 1].get_owner() == 2){
            while(!done){
                if(row + i >= 8 || column - i <= -1 || board[row + i][column - i].is_empty()){
                    done = true;
                }
                else if(board[row + i][column - i].get_owner() == 1){
                    return true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
    }
    if(next_mover() == COMPUTER){
        //right check
        if(board[row][column + 1].get_owner() == 1){
            while(!done){
                if(column + i >= 8 || board[row][column + i].is_empty()){
                    done = true;
                }
                else if(board[row][column + i].get_owner() == 2){
                    return true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row][column - 1].get_owner() == 1){
            while(!done){
                if(column - i <= -1 || board[row][column - i].is_empty()){
                    done = true;
                }
                else if(board[row][column - i].get_owner() == 2){
                    return true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row + 1][column].get_owner() == 1){
            while(!done){
                if(row + i >= 8 || board[row + i][column].is_empty()){
                    done = true;
                }
                else if(board[row + i][column].get_owner() == 2){
                    return true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row - 1][column].get_owner() == 1){
            while(!done){
                if(row - i <= -1 || board[row - i][column].is_empty()){
                    done = true;
                }
                else if(board[row - i][column].get_owner() == 2){
                    return true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row + 1][column + 1].get_owner() == 1){
            while(!done){
                if(row + i >= 8 || column + i >= 8 ||board[row + i][column + i].is_empty()){
                    done = true;
                }
                else if(board[row + i][column + i].get_owner() == 2){
                    return true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row - 1][column - 1].get_owner() == 1){
            while(!done){
                if(row - i <= -1 || column - i <= -1 || board[row - i][column - i].is_empty()){
                    done = true;
                }
                else if(board[row - i][column - i].get_owner() == 2){
                    return true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row - 1][column + 1].get_owner() == 1){
            while(!done){
                if(row - i <= -1 || column + i >= 8 || board[row - i][column + i].is_empty()){
                    done = true;
                }
                else if(board[row - i][column + i].get_owner() == 2){
                    return true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
        if(board[row + 1][column - 1].get_owner() == 1){
            while(!done){
                if(row + i >= 8 || column - i <= -1 || board[row + i][column - i].is_empty()){
                    done = true;
                }
                else if(board[row + i][column - i].get_owner() == 2){
                    return true;
                }
                i++;
            }
            i = 1;
            done = false;
        }
    }
    
    return false;
}