/**
 *   @file: Runjournal.cc
 * @author: Jordan Wells
 *   @date: January 28th, 2020
 *  @brief: Implementation of the functions of the class Runjournal, allowing user to record values, display values,
 *          find/remove values, sort data, save data, and find important values of Runjournal objects.
 *          
 */
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Runjournal.h"


Runjournal::Runjournal(){
    /*
     *  Function:   RunJournal
     *              default constructor that initializes the values of allRuns
     *              array and track variable.
     *     
     *  @return - none
     */
    Runtime newRun;
    for(size_t i= 0 ; i < CAPACITY; i++ ){
        allRuns[i] = newRun;
    }
    track = 0;
}

void Runjournal::record(Runtime newRun){
    /*
     *  Function:   record
     *              records a new value to add to the array of allRuns Rutime
     *              object array.
     *
     *  @param newRun - Value to be added to Runtime array
     *  @return - none
     */
    allRuns[track] = newRun;
    track++;

}

void Runjournal::display(){
    /*
     *  Function:   display
     *              displays the values within the allRuns Runtime object array.
     *
     *  @return - none
     */
    for (size_t i = 0; i < track; i++){
        std::cout << std::fixed << std::showpoint << std::setprecision(2)<< allRuns[i] << std::endl;
    }
}

void Runjournal::find_remove(Runtime target){
    /*
     *  Function:   find_remove
     *              finds a targeted value within the allRuns array, and then
     *              allows the user to delete value.
     *
     *  @param target - value that is to be fund within the allRuns array
     *  @return - none
     */
    std::string ans;
    size_t i = 0;
    char remove;
    bool find = false;
    bool valid = false;
    while(!find && i < track){
        if(allRuns[i] == target){
            std::cout << allRuns[i] << std::endl;

            while(!valid){
                std::cout << "Would you like to remove this run?(Y/N): ";
                std::cin >> remove;
                if(remove == 'Y' || remove == 'y'){
                    for (size_t x = i; x < track; x++){
                        allRuns[x] = allRuns[x + 1];
                    }
                    track -= 1;
                    valid = true;
                }
                else if(remove == 'N' || remove == 'n'){
                    valid = true;
                }
                else{
                    std::cout << "Enter valid optiom (Y/N)" << std::endl;
                }
            }
            
            find = true;
        }
        else{
            i++;
        }
    }
}

void Runjournal::distance_view(double distance){
    /*
     *  Function:   distance_view
     *              displays all runs within allRuns array with a specified
     *              distance value.
     *
     *  @param distance - value that is being searhed for within the allRuns array
     *  @return - none
     */
    for(size_t i = 0; i < track; i++){
        if(allRuns[i].get_distance() == distance){
            std::cout << "Run " << i << ":\n" << allRuns[i] << std::endl;
        }
    }

}

void Runjournal::time_sort(){
    /*
     *  Function:   time_sort
     *              sorts the array of Runtime objects based off of the MyTime
     *              object values of these objects from least to greatest.
     * 
     *  @return - none
     */
    MyTime lowval(24, 59, 59);
    size_t lowind = 0;
    Runtime tmp;
    

    for(size_t i = 0; i < track; i++){
        lowval.Reset(24, 59, 59);
        for(size_t x = i; x < track; x++){
            if(allRuns[x].get_time() < lowval){
                lowval = allRuns[x].get_time();
                lowind = x;
            }
        }
        tmp = allRuns[i];
        allRuns[i] = allRuns[lowind];
        allRuns[lowind] = tmp;
    }
        
}   

void Runjournal::distance_sort(){
    /*
     *  Function:   distance_sort
     *              sorts the array of Runtime objects based off of the distance
     *              double values of these objects form least to greatest.
     *
     *  @return - none
     */
    size_t lowind = 0;
    double lowval = 99999.0;
    Runtime tmp;

    
    for(size_t i = 0; i < track; i++){
        lowval = 99999.0;
        for(size_t x = i; x < track; x++){
            if(allRuns[x].get_distance() < lowval){
                lowval = allRuns[x].get_distance();
                lowind = x;
            }
        }
        tmp = allRuns[i];
        allRuns[i] = allRuns[lowind];
        allRuns[lowind] = tmp;
    }
    
}

MyTime Runjournal::total_time(){
    /*
     *  Function:   total_time
     *              adds all of the MyTime objects of the Runtimes within the 
     *              Runtime array together.
     *
     *  @return - the value of all the MyTime objects added together
     */
    MyTime tmp;
    for(size_t i = 0; i < track; i++){
        tmp = tmp + allRuns[i].get_time();
    }
    return tmp;
}

double Runjournal::total_distance(){
    /*
     *  Function:   total_distance
     *              adds the distance values of all the Runtime objects
     *              within the allRuns Runtime array.
     *
     *  @return - the value of all the distances added together
     */
    double tmp;
    for(size_t i = 0; i < track; i++){
        tmp = tmp + allRuns[i].get_distance();
    }
    return tmp;
}

MyTime Runjournal::average_pace(){
    /*
     *  Function:   average_pace
     *              divides the value of the total_time function by the 
     *              value of the total_distance function to find the average pace
     * 
     *  @return - the time value of the total time divided by the total distance
     */
    MyTime average;
    average = total_time() / total_distance();
    return average;
}

void Runjournal::save(std::ostream& outs)const{
    /*
     *  Function:   save
     *              puts all the values from the allRuns Runtime array in to an
     *              output file
     *
     *  @return - none
     */
    for(size_t i = 0; i < track; i++){
        outs << allRuns[i] << std::endl;
    }
}
