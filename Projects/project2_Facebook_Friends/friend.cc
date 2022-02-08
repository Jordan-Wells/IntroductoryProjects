#include "friend.h"
#include "date.h"


/**
*   Function:   Friend
*               The constructor of class Friend
*   @return none
*/
Friend::Friend(){
    name = "N/A";
}

/**
*   Function:   get_name
*               Returns the name associated with this friend object
*   @return name - name associated with friend object
*/
std::string Friend::get_name()const{
    return name;
}

/**
*   Function:   get_birthday
*               Returns the Date object that is associated with this Friend object
*   @return bday - the Date object assigned to this Friend object
*/
Date Friend::get_bday()const{
    return bday;
}

/**
*   Function:   ==
*               Compares if this friend object is equal to another Friend object
*   @param other - a Friend to which the value of this friend will be compared to
*   @return bool - True or false value depending on whether the member variables of equal
*/
bool Friend::operator == (const Friend& other)const{
    return bday == other.bday && name == other.name;
}

/**
*   Function:   !=
*               Compares a Friend object to this friend object to see if they are different objects
*   @param other - Ta Friend to which the value of this friend will be compared to
*   @return bool - True or false value based off whether these objects are equal
*/
bool Friend::operator != (const Friend& other)const{
    return !(bday == other.bday && name == other.name);
}

/**
*   Function:   input
*               Receives input from some istream object to put data in to member variable of this Friend object
*   @param ins - The stream from which the data is read
*   @return none
*/
void Friend::input(std::istream& ins){
    while(ins.peek() == '\n' || ins.peek() == '\r' || isspace(ins.peek())){
        ins.ignore(1);
    }
    if(!isspace(ins.peek()) && ins.peek() != '\n' && ins.peek() != '\r'){
        getline(ins, name);
        ins >> bday;
    }
    
    
    
}

/**
*   Function:   output
*               Outputs data from this Friend object
*   @param outs - stream to which data is read
*   @return none
*/
void Friend::output(std::ostream& outs)const{
    outs << name << std::endl << bday << std::endl;
}

/**
*   Function:   >>
*               Inputs data from a some istream object to a Friend object 
*   @param ins - Stream from which data is being read
*   @param f -  Friend object to which data will be read to
*   @return ins - object that the data was read from
*/
std::istream& operator >>(std::istream& ins,Friend& f){
    f.input(ins); 
    return ins;

}
/**
*   Function:   <<
*               Outputs data from a Friend object to some ostream obejct
*   @param outs - stream to which data from Friend is being read in to
*   @param f - Friend object from which data is being read
*   @return outs - ofile that has the data from Friend read in to it
*/
std::ostream& operator <<(std::ostream& outs,const Friend& f){
    f.output(outs);
    return outs;
}
