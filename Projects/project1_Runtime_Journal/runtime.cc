/**
 *   @file: runtime.cc
 * @author: Jordan Wells
 *   @date: January 28th, 2020
 *  @brief: Implements the functions of the class Runtime, allowing user to do operations on Runtime objects, and input/output
 *          
 */
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "runtime.h"


Runtime::Runtime(){
    MyTime rtime(0, 0, 0);
	double distance = 0;
}

Runtime Runtime::operator +(const Runtime& rhs)const{
    Runtime tmp;
    tmp.distance = distance + rhs.distance;
    tmp.rtime = rtime + rhs.rtime;
    return tmp;
}

Runtime Runtime::operator -(const Runtime& rhs)const{
    Runtime tmp;
    tmp.distance = distance - rhs.distance;
    tmp.rtime = rtime - rhs.rtime;
    return tmp;
}

Runtime Runtime::operator *(const double& rhs) const{
    Runtime tmp;
    tmp.distance = distance * rhs;
    tmp.rtime = rtime * (int)rhs;
    return tmp;
}

Runtime Runtime::operator /(const double& rhs) const{
    Runtime tmp;
    tmp.distance = distance / rhs;
    tmp.rtime = rtime / rhs;
    return tmp;
}

	// Full equality means time and distance are the same
bool Runtime::operator == (const Runtime& rhs)const{
    return (rtime == rhs.rtime && distance == rhs.distance);
}

bool Runtime::operator != (const Runtime& rhs)const{
    return !(rtime == rhs.rtime && distance == rhs.distance);
}


	// Equality of doubles can be problematic - this returns true if they are
	// within a tenth of a mile
bool Runtime::distance_equal(double d) const{
    return distance == distance;
}

 	// Input - Output
void Runtime::input(std::istream& ins){
    char junk;
    ins >> rtime;
    ins.get(junk);
    ins >> distance;
}

void Runtime::output(std::ostream& outs)const{
    outs << rtime.get_hours() << ':' << std::setw(2) << std::setfill('0') << rtime.get_minutes();
    outs <<':' << std::setw(2) << std::setfill('0') << rtime.get_seconds() << " ";
    outs << std::fixed << std::showpoint << std::setprecision(2) << distance;
}

Runtime operator *(const double& lhs, const Runtime& rhs){
    Runtime tmp;
    tmp = rhs * lhs;
    return tmp;
}

std::ostream& operator <<(std::ostream& outs, const Runtime& rhs){
    rhs.output(outs);
    return outs;
}
std::istream& operator >>(std::istream& ins, Runtime& rhs){
    rhs.input(ins);
    return ins;
}
