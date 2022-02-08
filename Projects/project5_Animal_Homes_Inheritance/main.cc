/**************************************************************************
	 This is the main function that allow for the reading of a file containing
     information pertaining to certain child classes of the home class.
     This function also allows for the addition and subtraction of homes
     to this list which is then exported to a file representing the user.
	    Jordan Wells				April 1st, 2020
************************************************************************/

#include "child.h"
#include <list>
#include <iterator>
#include <fstream>
int menu();
int main(){
    char c = 0;
    bool exit = false;
    Home * current;
    std::list<Home *> houses;
    std::list<Home *>::iterator it;
    std::string filename;
    std::ifstream ins;
    std::cout << "Enter username: ";
    std::cin >> filename;
    filename += ".txt";
    ins.open(filename);
    if(!ins.fail()){
        while(ins >> c){
            if(isalpha(c)){
                if(c == 'C'){
                    current = new Coot;
                    current -> make(ins);
                    houses.push_back(current);
                    
                }
                else if(c == 'B'){
                    current = new Bee;
                    current -> make(ins);
                    houses.push_back(current);
                    
                }
                else if(c == 'E'){
                    current = new Beaver;
                    current -> make(ins);
                    houses.push_back(current);
                    
                }
                else if(c == 'G'){
                    current = new Groundhog;
                    current -> make(ins);
                    houses.push_back(current);
                    
                }
                else if(c == 'T'){
                    current = new TrapdoorSpider;
                    current -> make(ins);
                    houses.push_back(current);
                    
                }
                else if(c == 'W'){
                    current = new Weaver;
                    current -> make(ins);
                    houses.push_back(current);
                    
                }
                
            }
            else{
                std::cout << c;
            }
            while(!isalpha(ins.peek()) && !ins.eof()){
                ins.ignore();
            }
        }
    }
    ins.close();
    while(!exit){
        int choice = menu();
        switch (choice)
        {
        case 1:
            current = new Coot;
            current -> make(std::cin);
            houses.push_back(current);
            
            break;

        case 2:
            current = new Bee;
            current -> make(std::cin);
            houses.push_back(current);
            
            break;

        case 3:
            current = new Beaver;
            current -> make(std::cin);
            houses.push_back(current);
            
            break;

        case 4:
            current = new Groundhog;
            current -> make(std::cin);
            houses.push_back(current);
            
            break;

        case 5:
            current = new TrapdoorSpider;
            current -> make(std::cin);
            houses.push_back(current);
            
            break;

        case 6:
            current = new Weaver;
            current -> make(std::cin);
            houses.push_back(current);
            
            break;

        case 7:
            for(it = houses.begin(); it != houses.end(); ++it){
                (*it) ->put (std::cout);
                std::cout << std::endl;
            }
            break;
        case 8:
            exit = true;
            break;
        }
    }
    std::ofstream outs;
    outs.open(filename);
    for(it = houses.begin(); it != houses.end(); ++it){
        (*it) -> put(outs);
    }
    outs.close();
    return 0;
}

int menu(){
    int choice = 0;
    std::cout << "Enter Choice: " << std::endl;
    std::cout << "(1) Coot\n(2) Bee\n(3) Beaver\n(4) Groundhog\n(5) Trapdoor Spider\n(6) Weaver\n(7) View list\n(8) Exit\n";
    std::cin >> choice;
    return choice;
}