/**
 *   @file: college.cc
 * @author: Jordan Wells
 *   @date: March 3rd, 2020
 *  @brief: Implementation of the college class header file that manipulates the objects within the College class including the name string and the node * linked list
 *          
 */
#include "college.h"
#include "course.h"
#include "node.h"
#include <fstream>
#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<string>

/**
*   Function:   College
*               The constructor of class College that saids its value to null
*   @return none
*/
College::College(){
    head = NULL;
}

/**
*   Function:   ~College
*               The destructer of class College that deletes all of its data
*   @return none
*/
College::~College(){
    node * now = head;
    node * next;
    if (now == NULL){
        return;
    }
    next = now -> link();
    if(next == NULL){
        delete now;
    }
    while(next != NULL){
        delete now;
        now = next;
        next = next -> link();
    }
    std::cout << "Thanks!" << std::endl;
}

/**
*   Function:   College
*               Copy constructer for class College that saves the data from another College object
*   @param newCollege - FBFriends object from which data is taken
*   @return none
*/
College::College(College &newCollege){
    fName = newCollege.fName;
    node * after;
    while (head != NULL){
        after = head -> link();
        delete head;
        head = after;

    }
    while(newCollege.head != NULL){
        head = newCollege.head;
        head = head -> link();
        newCollege.head = newCollege.head -> link();
        if(head == NULL){
            head = new node();
        }
    }
    
}

/**
*   Function:   add
*               Adds a new course object to the linked list contained within the College class object
*   @param core - new course object that is being added to the linked list
*   @return none
*/
void College::add(course core){
    node * coreNode = new node(core, NULL);
    //node * newNode = new node;
    if(head == NULL){
        head = new node(core, NULL);
        delete coreNode;
        return;
    }
    else{
        node * changeLink = head;
        node * compare = head -> link();
        // if(compare == NULL){
        //     compare -> set_data(core);
        //     compare -> set_link(newNode);
        //     return;
        // }
        if (changeLink -> data() > core ){
            head = coreNode;
            head -> set_link(changeLink);
            return;
        }
        else if(changeLink -> data() == core){
            head = coreNode;
            head -> set_link(changeLink);
            return;
        }
        while(changeLink -> link() != NULL){
            if (core > compare -> data()){
                changeLink = changeLink -> link();
                compare = compare -> link();
            }
            else if(compare -> data() == core){
                changeLink -> set_link(coreNode);
                coreNode -> set_link(compare);
                return;
            } 
            else{
                changeLink -> set_link(coreNode);
                coreNode -> set_link(compare);
                return;
            }
            
        }
        changeLink -> set_link(coreNode);
        coreNode -> set_link(compare);
        //compare -> set_link(NULL);
    }
    
}

/**
*   Function:   set_name
*               Changes the string name associated with the college class object
*   @param name - the new name that will be stored within the College class object
*   @return none
*/
void College::set_name(std::string name){
    fName = name; 
}

/**
*   Function:   display
*               Displays all course objects stored within the linked list within the college class
*   @param outs - stream to which the course objects data are displayed
*   @return none
*/
void College::display(std::ostream& outs){
    outs << fName << std::endl;
    node * cursor = head;
    while(cursor != NULL){
        outs << cursor -> data();
        cursor = cursor -> link();
    }
}

/**
*   Function:   save
*               Saves all the data from a college object's course data
*   @param outs - stream to which the information will be outputted
*   @return none
*/
void College::save(std::ostream& outs){
    outs << fName << std::endl;
    node * cursor = head;
    for(cursor = head; cursor != NULL; cursor = cursor -> link()){
        outs << cursor -> data().get_course_number() << std::endl;
        outs << cursor -> data().get_grade() << std::endl;
        outs << cursor -> data().get_number_grade() << std::endl;

    }
}

/**
*   Function:   gpa
*               Calculates the gpa from all of the course objects from within the college object
*   @return total / cursCount - total calculates the hours by the grade received in a class divided by the cursCount which calculates the total number of classes
*/
double College::gpa(){
    node * cursor = head;
    double cursCount = 0;
    double total = 0;
    while(cursor != NULL){
        cursCount = cursCount + static_cast<double>(cursor -> data().get_hours());
        total += (static_cast<double>(cursor -> data().get_number_grade()))*static_cast<double>((cursor -> data().get_hours()));
        cursor = cursor -> link();
    }
    return total / cursCount;
}

/**
*   Function:   hours
*               Total number of hours found within the course bojects of the college class's linked list
*   @return total - all of the hours found within the college class combined
*/
double College::hours(){
    node * cursor = head;
    double total = 0;
    while(cursor != NULL){
        total += (cursor -> data().get_hours());
        cursor = cursor -> link();
    }
    return total;
}

/**
*   Function:   remove
*               Course name that is to be removed from the linked list college's class
*   @param core - string that holds the name of a course that is to be removed from the linked list
*   @return none
*/
void College::remove(std::string const core){
    std::string upperCore = core;
    for(size_t i = 0; i < core.length(); i++){
        upperCore[i] = toupper(upperCore[i]);
    }
    node * removeLink = head;
    if(head == NULL){
        std::cout << "ERROR 404: Course not found" << std::endl;
        return;
    }
    else if(head -> data().get_course_number() == upperCore){
        head = head -> link();
        delete removeLink;
        return;
    }
    else{
        node * finder = head -> link();
        while(finder != NULL){
            if(finder -> data().get_course_number() != upperCore){
                finder = finder -> link();
                removeLink = removeLink -> link();
            }
            else{
                removeLink -> set_link(finder -> link());
                delete finder;
                return;
            }
            
        }
        std::cout << "ERROR 404: Course not found" << std::endl;
    }
}

/**
*   Function:   load
*               Saves all the data stored within an istream in to a college class object
*   @param ins - istream from which the data is loaded in to college
*   @return none
*/
void College::load(std::istream& ins){
    std::string named;
    course newCourse;
    getline(ins, named);
    fName = named;
    while(ins.peek() == '\n' || ins.peek() == '\r'|| isspace(ins.peek())){
        ins.ignore();
    }
    while(ins >> newCourse){
        if(ins.peek() == '\n' || ins.peek() == '\r'|| isspace(ins.peek())){
            while(ins.peek() == '\n' || ins.peek() == '\r'|| isspace(ins.peek())){
                ins.ignore();
            }
        }
        add(newCourse);
    }
}

/**
*   Function:   =
*               Assigns the data from one college object in to another
*   @param rhs - college object from which data is assigned
*   @return *this - the data stored within this course object
*/
College& College::operator = (College &rhs){
    if(this == &rhs) return *this;
    fName = rhs.fName;
    node * rmv;
    while(head != NULL){
        rmv = head;
        head = head -> link();
        delete rmv;
    }

    if (rhs.head == NULL){
        return *this;
    }
    else{
        node * added = rhs.head;
        node * adding = head;
        while(added != NULL){
            adding = added;
            adding = adding -> link();
            added = rhs.head -> link();

        }
        return *this;
    }


}