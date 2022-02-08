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