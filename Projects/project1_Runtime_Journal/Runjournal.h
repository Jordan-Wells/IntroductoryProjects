/**
 *   @file: Runjournal.cc
 * @author: Jordan Wells
 *   @date: January 28th, 2020
 *  @brief: Defines the Runjournal class and its member functions/variables.
 *          
 */
#include "runtime.h"
#ifndef RUNJOURNAL_H
#define RUNJOURNAL_H

class Runjournal{
    public:
     static const size_t CAPACITY = 200;

     Runjournal();
     
     void record(Runtime newRun);
     
     void display();
    
     void find_remove(Runtime target);

     void distance_view(double distance);

     void time_sort();
   
     void distance_sort();
   
     MyTime total_time();
    
     double total_distance();
   
     MyTime average_pace();

     void save(std::ostream& outs)const;
    
    private:
     Runtime allRuns[CAPACITY];

     size_t track;
     
};
#endif