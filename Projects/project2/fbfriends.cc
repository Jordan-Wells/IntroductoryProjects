#include "fbfriends.h"
#include "friend.h"
#include "date.h"

/**
*   Function:   FBFriends
*               The constructor of class FBFriends
*   @return none
*/
FBFriends::FBFriends(){
    capacity = 6;
    current_index = 0;
    used = 0;    
    data = new Friend[capacity];
}
/**
*   Function:   ~FBFriend
*               The destructor of class FBFriends
*   @return none
*/
FBFriends::~FBFriends(){
    delete [] data;
}
/**
*   Function:   FBFriends
*               The constructor of class FBFriends that takes its data from another FBFriend object
*   @param other - FBFriends object from which data is taken
*   @return none
*/
FBFriends::FBFriends(const FBFriends& other){
    data = new Friend[other.capacity];

    std::copy(other.data, other.data + other.used, data);

    used = other.used;
    capacity = other.capacity;
}

/**
*   Function:   =
*               Sets data of this FBFreinds object equal to that of another class
*   @param other - FBFriends object that this object will be set equal to
*   @return none
*/
void FBFriends::operator = (const FBFriends& other){
    if(data != other.data){
        delete [] data;
        data = new Friend [other.capacity];
        used = other.used;
        capacity = other.capacity;
        current_index = 0;
        std::copy(other.data, other.data + other.used, data);
    }
    
}
/**
*   Function:   start
*               sets the current_index variable to the begininng of the array (0)
*   @return none
*/
void FBFriends::start(){
    current_index = 0;
}
/**
*   Function:   advance
*               Increases the internal iterator variable current_index
*   @return none
*/
void FBFriends::advance(){
    ++current_index;
}
/**
*   Function:   is_item
*               Checks to see if current_index of data applies to an actual Friend object with valid data
*   @return bool - True or false value depending on if it is a real object with data
*/
bool FBFriends::is_item(){
    if(current_index != used - 1){
        return true;
    }
    return false;
}
/**
*   Function:   current
*               Returns the data that is contained within the current data slot
*   @return data[current_index] - the data that corresponds to the current placement of the internal iterator
*/
Friend FBFriends::current(){ 
    return data[current_index];
}
/**
*   Function:   remove_current
*               Removes the data at the current placement of the internal iterator
*   @return none
*/
void FBFriends::remove_current(){
    Friend empty;
    data[current_index] = empty;
    
    for(size_t i = current_index; i < used; i++){
        data[i] = data[i +1];
    }
    --used;
}
/**
*   Function:   insert
*               Puts a Friend object in to the data array at the placement of the internal iterator
*   @param f - Friend object which is to be added to the data array
*   @return none
*/
void FBFriends::insert(const Friend& f){
    used++;
    if(used == capacity){
        resize();
    }
    for(size_t i = used; i > current_index; i--){
        data[i] = data[i - 1];
    }
    data[current_index] = f;

}
/**             attach
*               Puts a Friend object in to the data array at the placement after the internal iterator
*   @param f - Friend object which is to be added to the data array
*   @return none
*/
void FBFriends::attach(const Friend& f){
    if(used + 1 == capacity){
        resize();
    }
    data[used] = f;
    used++;
}
/**
*   Function:   show_all
*               Displays all of the values within the Friend object data array
*   @param outs - ostream object to which the data is displayed
*   @return none
*/
void FBFriends::show_all(std::ostream& outs)const{
    for(size_t i = 0; i < used; i++){
        outs << data[i];
    }
}
/**
*   Function:   bday_sort
*               Sorts the data array based off of the Date object associated with the Friend objects within the data array
*   @return none
*/
void FBFriends::bday_sort(){
    bool done = false;
    size_t i;
    Friend tmp;
    while(!done){
		done = true;
		for(i = used - 1; i > 0; --i){
	    	if(data[i].get_bday() < data[i - 1].get_bday()){
				done = false;
				tmp = data[i];
				data[i] = data[i-1];
				data[i-1] = tmp;
	    	}
		}
	}
}
/**
*   Function:   find_friend
*               finds a name associated with a Friend object within the data array
*   @param name - name to which the other names in the data array are to be compared
*   @return data[i]/x - data that matches the target name or x if the name is not found
*/
Friend FBFriends::find_friend(const std::string& name)const{
    for(size_t i = 0; i < used; i++){
        if(data[i].get_name() == name){
            return data[i];
        }
    }
    Friend x;
    return x;
}
/**
*   Function:   is_friend
*               Checks to see if the data in the array matches a Friend object
*   @param f - Friend object to which the Friend objects in the data array are being compared to
*   @return bool - true or false value depending on if the friend is within the list
*/
bool FBFriends::is_friend(const Friend& f) const{
    for(size_t i = 0; i < used; i++){
        if(data[i] == f){
            return true;
        }
    }
    return false;
}
/**
*   Function:   load
*               loads data from an istream object in to the Friend obejcts within the data array
*   @param ins - istream object from which the data is read
*   @return none
*/
void FBFriends::load(std::istream& ins){
    data[used].input(ins);
    used++;
    if(used == capacity){
        resize();
    }
    while(ins.eof() == false){
        if(ins.peek() == '\n' || ins.peek() == '\r' || isspace(ins.peek())){
            ins.ignore(1);
        }
        else{
            data[used].input(ins);
            if(data[used].get_name() != "N/A"){
                used++;
                if(used == capacity){
                    resize();
                }
            }
            
        }
        
    }
}
/**
*   Function:   save
*               saves the data from the Friend object data array in to a ostream object
*   @param outs - ostream object to which the data is loaded
*   @return none
*/
void FBFriends::save(std::ostream& outs){
    show_all(outs);
}
/**
*   Function:   resize
*               makes a new array with the same data as the previous data array with a larger capacity in order to store more objects
*   @return none
*/
void FBFriends::resize(){
    Friend * tmpptr;
    tmpptr = new Friend[capacity + 5];
    std::copy(data, data + used, tmpptr);
    delete [] data;
    data = tmpptr;
    capacity += 5;
}