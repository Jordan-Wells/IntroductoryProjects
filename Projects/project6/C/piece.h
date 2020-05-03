/**************************************************************************
	 This is the header file for the piece class which includes
     the empty boolean which is used for testing occupancy and the owner
     integer which is used to tell which player currently possesses a piece
	    Jordan Wells				April 21st, 2020
************************************************************************/

#ifndef PIECE_H
#define PIECE_H

class piece{
    public:
     piece();

     bool is_empty() const;
     int get_owner() const;
     void flip();
     void reset();
     void set_owner(int newOwner);

    private:
     bool empty;
     int owner;

};

#endif