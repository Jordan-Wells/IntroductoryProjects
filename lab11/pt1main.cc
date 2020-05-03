#include <iostream>

int counting(int n);


int main(){
	int x;
	for(int j=0; j<3; ++j){ // loop to do three test runs in 1 run                                             
	    std::cout << "Enter a number: ";
        std::cin>>x;
	    std::cout<<"The even numbers counting to there:\n";
	    counting(x);
	}
     // main for Part Two will go here
    return 0;
}

int counting(int n){
    if(n % 2 == 1){
        n = n - 1;
    }
    if(n - 2 >= 0){
        counting(n - 2);
        std::cout << n << std::endl;
    }
    
    return n;
}