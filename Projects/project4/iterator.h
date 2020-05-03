#ifndef ITERATOR_H
#define ITERATOR_H
#include "dnode.h"

template <class L>
class dlist;
template<class L>
class node_iterator{
    public:
    friend class dlist<L>;
    node_iterator(Dnode<L>* initial = NULL) { 
        current = initial; 
    }
    const L & operator *() { 
    //     L co = current -> data();
    //     const L cor = co;
        return current -> data(); 
    } 
    node_iterator& operator ++(){
        current = current-> next();
        return *this; 
    }
    node_iterator operator ++(int){
        node_iterator original(current); 
        current = current-> next(); 
        return original;
    }
    node_iterator& operator --(){
        current = current-> prev();
        return *this; 
    }
    node_iterator operator --(int){
        node_iterator original(current); 
        current = current-> prev(); 
        return original;
    }
    bool operator ==(const node_iterator other) const{ 
        return current == other.current; 
    }
    bool operator !=(const node_iterator other) const{ 
        return current != other.current; 
    } 
    Dnode<L> * now(){
        return current;
    }
    private:
    Dnode<L> * current;
};

#endif