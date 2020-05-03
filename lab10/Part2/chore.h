#ifndef CHORE_H
#define CHORE_H
#include <iostream>
#include <string>
class Chore{
    public:
     friend bool operator < (const Chore left,const Chore right);
     void input(){
         std::cout << "Enter Description: ";
         getline(std::cin,desc);
         std::cout << "Enter Priority: ";
         std::cin >> priority;
     }
     void output(){
         std::cout << "\'" << desc << "\' " << priority << std::endl;
     }
    private:
     std::string desc;
     int priority;

     
};
bool operator < (const Chore left,const Chore right){
    return left.priority < right.priority;
}
#endif