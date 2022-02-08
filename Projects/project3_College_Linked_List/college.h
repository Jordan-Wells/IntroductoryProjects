/**
 *   @file: college.cc
 * @author: Jordan Wells
 *   @date: March 3rd, 2020
 *  @brief: Header file describing the course class and its member functions and variables
 *          
 */
#include "node.h"
#include "course.h"
#ifndef COLLEGE_H
#define COLLEGE_H

class College{
    public:
        College();
        ~College();
        College(College & newCollege);
        void add(course core);
        void set_name(std::string name);
        void display(std::ostream& outs);
        void save(std::ostream& outs);
        double gpa();
        double hours();
        void remove(std::string core);
        void load(std::istream& ins);
        College& operator = (College &rhs);
        
    private:
    std::string fName;
    node * head;
};
#endif



