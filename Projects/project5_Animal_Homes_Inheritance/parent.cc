/**************************************************************************
	 This file implements the parent make and put functions that
     allow for the calling of the children input and output functions
     to store or create new objects.
	    Jordan Wells				April 1st, 2020
************************************************************************/

#include "parent.h"

void Home::make(std::istream & ins){
    input(ins);
}
void Home::put(std::ostream & outs){
    output(outs);
}