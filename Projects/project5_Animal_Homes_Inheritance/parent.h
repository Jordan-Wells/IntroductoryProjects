/**************************************************************************
     This class is the basis for the child classes it derives, its
     only function is to serve as a base for the creation of these children
	    Jordan Wells				April 1st, 2020
************************************************************************/

#ifndef PARENT_H
#define PARENT_H

#include <iostream>

class Home{
    public:
     virtual void input(std::istream &ins) = 0;
     virtual void output(std::ostream & outs) = 0;
     void make(std::istream & ins);
     void put(std::ostream & outs);
};

#endif