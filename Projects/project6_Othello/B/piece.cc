
/**************************************************************************
	 This is the implentation of the piece class which holds the data that
     is essential for the othello class to work properly. This includes 
     the is_empty function to test for a pieces ownership, a get_owner
     function which allows for the access of the private owner member 
     variable, the flip function which is used to change ownership, the reset 
     function which is used when a new game is set, and the set_owner function
     whichis used when a spot that was not previously occupied is taken.
	    Jordan Wells				April 21st, 2020
************************************************************************/
#include "piece.h"

piece::piece(){
    empty = 1; 
    owner = 0;
}

bool piece::is_empty() const{
    return empty;
}
int piece::get_owner() const{
    return owner;
}
void piece::flip(){
    if(!empty){
        if(owner == 1)
            owner = 2;
        else if(owner == 2)
            owner = 1;
    }
    return;
}
void piece::reset(){
    empty = true;
    owner = 0; 
    return;
}
void piece::set_owner(int newOwner){
    empty = 0;
    owner = newOwner;
    return;
}