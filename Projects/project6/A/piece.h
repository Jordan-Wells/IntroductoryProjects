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