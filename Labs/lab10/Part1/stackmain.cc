/**********************************************************************
	Lab Assignment 9 - working with a stack
	It's sometimes tricky to set up the loop that reads the
expression from the keyboard, so I am giving that to you. You have to
fill in the rest of the main.
	John Dolan Fall 2016
			Ohio University
			Home of the Bobcats
**********************************************************************/
#include <stack>
#include <iostream>
#include<cstdlib>
#include "calc_useful.h"
using namespace std;


int main(){
    char c;
    char tmp;
    int onenum, twonum;
    int count;
    bool continu = true;
	// declare an STL stack called nums right here:
    stack<int> nums;
    
    while(continu==true){
        cout<<"Please enter your expression:\n";
        c = cin.get(); // priming read for the sentinel loop.
        while(c != '\n'){
 	        if(isdigit(c)){
	            cin.putback(c);
	            cin>>onenum;
	            nums.push(onenum);
	        }
	        else if(isop(c)){
		        if(!nums.empty()){
			        //pop two  numbers from the stack
                    int x = nums.top();
                    nums.pop();
                    if(!nums.empty()){
                        int y = nums.top();
                        nums.pop();
                        // evaluate them using the evaluate from stack_useful
                        int z = evaluate(y, x, c);
			        // push result onto the stack
                        nums.push(z);
                    }
                    else{
                        cout << "Not enough numbers to complete operation. Please try again." << endl;
                        return -1;
                    }
			    }
			    else{
				    cout<<"Error:";
				    cout<<" Expression contains non-number or operation characters. Please try again.\n"; // what did this error tell us about the user's expression?
        			return -1;
			    }

		    }
	
	        c = cin.get(); // reading at the bottom of the sentinel loop
        } // bottom of the loop that reads a single expression from the keyboard

	  // output the final result from the top of the stack
      // but only after you check to make sure there's something on the stack
        if(nums.empty()){
            cout << "Error: Empty stack" << endl;
        }
        else{
            int x = nums.top();
            nums.pop();
            if(nums.empty())
            cout << x << endl;
            else
            cout << "Error: Too many numbers in stack. \n";
        }
        cout << "Enter another equation?(y or n)";
        cin>> tmp;
        if(tmp=='y' || tmp=='Y'){
            continu=true;
            while(!nums.empty()){
                nums.pop();
            }
            cin.ignore(200, '\n');
            cin.clear();
        }
	    
        else
	    continu=false;

        
    }
    
    return 0;
}