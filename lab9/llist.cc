/************************************************************************
     This is the implementation file for the LList class which is a 
container based on a doubly linked other. The student is required to 
write the rearview function as well as the copy constructor. Note that 
the copy constructor will not be able to use the add function to produce 
a true copy because of the strange behavior of the add function, which 
treats all numbers divisible by five differently than other numbers.
	John Dolan		Ohio University		Spring 2018
************************************************************************/
#include<iostream>
#include "llist.h"
using namespace std;

void LList::frontview()const{
    node* cursor = head;
    while (cursor != NULL){
	cout<<cursor->data() <<"  ";
	cursor = cursor->next();
    }
}

// The student is required to write the implementation of this function
void LList::rearview()const{
	node * cursor = tail;
	while (cursor != NULL){
		cout << cursor -> data() << "  ";
		cursor = cursor -> previous();
	}
}

LList::LList(const LList & other){
	nodecount = other.nodecount; 
	tail = head = new node; 
	node * changeHead = head; 
	node * change = other.head; 
	//node * prev; 
	if(change != NULL){ 
		if(changeHead == NULL){ 
			changeHead = new node; 
		} 
		changeHead -> set_data(change -> data()); 
		tail = changeHead; 
		change = change -> next(); 
	} 
	while(change != NULL){ 
		changeHead -> set_next(new node(change -> data(), changeHead)); 
		change = change -> next(); 
		tail = changeHead = changeHead -> next();
	}
}


void LList::add_item(int item){
    if(head == NULL) {
		head=tail=new node(item);
		nodecount++;
    }
    else if(item%5 == 0 && nodecount > 3){
		int i = 0;
		node* cursor=head; 
		while(i < nodecount/2){ 
	    	cursor = cursor->next(); 
	    	i++; 
		}
		node * data = new node (item, cursor -> previous(), cursor);
		cursor -> previous() ->set_next(data);
		nodecount++; 
    }
    else{ 
		tail->set_next(new node(item, tail));
		tail = tail->next();
		nodecount++;
    } 
}

LList::~LList(){
   node* rmptr;
   while(head != NULL){
		rmptr=head;
		head = head->next();
		delete rmptr;
   }
}