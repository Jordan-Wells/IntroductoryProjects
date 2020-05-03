#ifndef DNODE_H
#define DNODE_H

template<class L>
class Dnode{
    public:
     Dnode();
     Dnode(L * data);
     L & data();
     Dnode * next();
     Dnode * prev();

     void set_data(L data);
     void set_next(Dnode * data);
     void set_prev(Dnode * data);


    private:
     L current;
     Dnode * nextField;
     Dnode * prevField;
};
#include "dnode.template"
#endif