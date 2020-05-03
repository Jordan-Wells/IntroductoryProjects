#ifndef DLIST_H
#define DLIST_H
#include "iterator.h"
template <class L>
class dlist{
    public:
     typedef node_iterator<L> iterator;
     dlist();
     ~dlist();
     dlist(dlist<L> & rhs); 
     dlist<L>& operator = (dlist<L> & list);
     void front_insert(L data);
     void rear_insert(L data);
     void front_remove();
     void rear_remove(); 
     iterator begin(){
        return iterator(head);
     }
     iterator end(){
        return iterator(tail -> next());
     }
     iterator r_begin(){
         return iterator(tail);
     }
     iterator r_end(){
         return iterator(head -> prev());
     }
     void insert_before(iterator spot, L data);
     void insert_after(iterator spot, L data);
     void remove(iterator spot);
     int size();
     void show(){
         Dnode<L> * cursor = head;
         while(cursor != NULL){
             std::cout << cursor -> data() << " ";
             cursor = cursor -> next();
         }
     }
     void reverse_show(){
         Dnode<L> * cursor = tail;
         while(cursor != NULL){
             std::cout << cursor -> data() << " ";
             cursor = cursor -> prev();
         }
     }

    private:
     Dnode<L> * head;
     Dnode<L> * tail;
};
#include "dlist.template"
#endif