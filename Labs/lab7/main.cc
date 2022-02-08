/*********************************************************************
     Lab Assignment 6: This is another lab assignment in working with 
     linked lists. We will be using a struct node, for its simplicity,
     and working with non-member functions here. The main point is to 
     work with the logic of a linked list. Do not be afraid to make 
     drawings on scrap paper.
     The prototypes for the functions that you are to implement are
     included. You should uncomment them when you are ready to write 
     the implementation.
           John Dolan				Spring 2014
*********************************************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct node{
     int data;
     node * link;
};


// These are the three I have written for you
void build_list(node* & head);  // note that we are passing by reference
void show_list(const node* head);
int size(const node* head);
void dup_fix(node* & head);
void split_list(node * & head, int split, node * & lessThan, node * & moreThan);

//These are the two that you are to write, as described in the 
//instructions page.
/* void remove_repeats(node*& head);
   void split_list(const node* original, node*& lesser, 
		node*& greater,int split_value);
*/


int main(){
    int start, stop;
    int split;
    char x;
    node* head = NULL;
    node *lesser;
    node * greater;

    start = time(NULL);
    build_list(head);
    
    stop = time(NULL);
    show_list(head);
    cout << "Fix(y/n)? ";
    cin >> x;
    if (x == 'y'){
         dup_fix(head);
         show_list(head);
    }
    cout << "Enter value from which to split the list: ";
    cin >> split;
    split_list(head, split, lesser, greater);
    show_list(lesser);
    show_list(greater);


//     cout<<"Time to build list = "<<stop - start <<"seconds.\n";
//     start = time(NULL);
//     show_list(head);
//     stop = time(NULL);
//     cout<<"Time to print list = "<<stop - start<<"seconds.\n";
//     cout<<"Size of the list = "<<size(head)<<endl;


return 0;
}

// builds a linked list of 2000 random integers, all in the 1 to 500 range
void build_list(node*& head){
     node* cursor;
     head = new node;
     head->data = rand()%500 + 1;
     cursor = head;
     for(int i = 0; i < 2000; ++i){
	cursor->link = new node;
        cursor = cursor->link;
        cursor->data = rand()%500 + 1;
     }
     cursor->link = NULL;
}

// outputs the contents of a linked list to the screen
void show_list(const node* head){
      const node * cursor = head;
      while(cursor !=  NULL){
   	cout<<cursor->data<<"  ";
	cursor = cursor->link;
      }
     cout<<endl;
}

// returns the number of nodes in a linked list
int size(const node* head){
	const node* cursor = head;
	int count = 0;
	while(cursor != NULL){
  	    count++;
	    cursor = cursor->link;
	}
	return count;
}

void dup_fix(node* & head){
     node * first;
     node * rmv;
     node * before;
     node * hold;
     if (head == NULL || head -> link == NULL){
          return;
     }
     first = head;
     before = head;
     rmv = head -> link;
     hold = rmv;
     while(first != NULL){
          while(rmv != NULL){
               if(rmv -> data == first -> data){
                    before -> link = rmv -> link;
                    hold = before;
                    delete rmv;
               }
               else{
                    before = before -> link;
               }
               rmv = hold -> link;
               hold = rmv;
          }
          first = first -> link;
          before = first;
          rmv = first-> link;
          hold = rmv;
     }
     return;
}

void split_list(node * & head, int split, node * & lessThan, node * & moreThan){
     cout << "Please enter a value between 1 - 500 to split your list: ";
     cin >> split;
     node * holdSame;
     while(head != NULL){
          if(split > head -> data){
               lessThan = head;
               head = head -> link;
               lessThan -> link = NULL;
          }
          else if (split < head -> data){
               moreThan = head;
               head = head -> link;
               moreThan -> link = NULL;
          }
          else{
               holdSame = head;
               head = head -> link;
               delete holdSame;
          }
     }
     
}