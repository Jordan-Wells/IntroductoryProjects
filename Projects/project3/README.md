# Project Outline Given by Professor
For this project I have written a node class that is pretty much identical to the one that appears in Chapter 5 of your text. And for the data type I have written a little class that stores information about a single college course.   And I have written a main that will allow a uniform program interface to facilitate my grading. You can copy these on your prime account with the command 

cp /home/jdolan/cs2401/projects/project3/*  .   

or you can download them from Blackboard. (The test.cc file that you find in this directory is just a little file I wrote to make sure that everything compiles and that the input and output are working – you can delete it after you take a quick look at it. You will need the other three files.

For this project we will be writing another container class. This one will be built with a linked list constructed using the node-class nodes that I have given you. Now with the first container class that we wrote the order of the items did not matter, and could be changed by the class itself if it was convenient. The second container that we wrote was a sequence. Items stayed in whatever order the programmer had chosen to use in putting them into the container with the internal iterator. But there are also containers where the order is maintained by the container itself. Where there is only a single insert function, and it always puts items into the container at the spot where they would go in an ordered list of those items. Such lists can only be used to store data types and classes that have comparison operators.

So your assignment is to create a class that will have, as private variables, a string for the students name and a pointer to the head of a linked list which is built from the nodes that I have provided. The list will have the following capabilities:

•	The ability to add an additional course to the list – the course will be inserted to the correct spot alphabetically by the list class itself (not by the application program)

•	The ability to display all the courses taken on the screen.

•	The ability to remove a course with a function that takes the name of the course as a parameter

•	The ability to return the total hours taken 

•	The ability to return the student’s  GPA. To do this you pass through the list obtaining the point value of each course by multiplying number_grade * hours and accumulating these “points” into a single sum, which is then divided by the total hours that the studet has taken.
{OVER}
 
The main that I have written will offer the user a chance to do each of these functions, plus a testing of the copy constructor which is done by making a copy of the list, allowing the user to delete a course from the copy, and then allowing the copy to go out of scope.
Even though you are only testing one of the Big 3 you are expected you are expected to write all three.
There will also be a file-backup of all the data. The program should load the student’s name (which will be the first thing in the file) and list of courses when it starts up and save the altered list to the same file when it is exiting. Again, we will ask for the student’s username to determine the name of this file. If no file exists the program since the student may be in their first semester of college.

