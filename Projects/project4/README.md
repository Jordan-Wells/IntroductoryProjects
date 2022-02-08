# Project Outline Given by Professor
In our upcoming projects we will find a lot of use for an extremely versatile container, one that can hold anything without size limitations and easily change its size to fit the requirements of the moment. This list will be similar to the sequence class that we created for Project Two, but it will be implemented differently and the iterator access will be done as an external iterator. This list will also be implemented as a template, allowing it to hold any type of data. This will be our universal list.

Our list will be a doubly linked list. In a doubly linked list each node has a pointer pointing to the next node and another one pointing to the previous node. (The “node” after the last item is NULL and the “node” previous to the first one is NULL as well.) This will require the definition of a different node class from what’s in the book (p. 324). So you should start your project by making a Dnode class for nodes appropriate for use in a double linked list. Make this class template so it can hold any kind of data. You will need functions to access next, previous,  and data as well as functions to set_next, set_previous and set_data. You should provide a constructor that uses default arguments that will set the pointers to NULL.

Now using, this node class, develop a template list class. You will need pointers for head and tail, and these may initially be the only private variables that you need. Your class will have functions for front_insert, rear_insert, front_remove, and rear_remove. Remember to program incrementally. To help you with this I have written a file called main1.cc. When you first open this file you will see that everything has been commented out, except the default constructor for the Dlist class. So begin by writing just the Dnode class, and then a list class with just a default constructor. Compile and run. Then uncomment the next block of code and write the implementation for the functions that are called in that block. (Note that STL classes don’t have “show_all” functions, but I find it very useful to have one as you develop the class.) Continue this progress, compiling and running for each block as you uncomment it. If you get a crash go back and fix it before going on. (Compile with g++ -g main1.cc)

The list is holding dynamic memory (although the node class does not). This means that the default forms of the “Big 3” do not work correctly so you will need to define a Big 3 for this class. The destructor is much the same as one for a singly linked list, but the other two are different because in copying the list you must remember to maintain both pointers. Work carefully and use drawings. A minor misstep and can lead to major seg faults on down the road. There is code that does some testing of these in the main1 file as well.

The last thing that you will develop in this process is a bidirectional, external iterator. You will need to make an additional class for this, a class which will closely parallel the node_iterator class in the book. (p. 330). You will then alter the list class to include begin, end, r_begin, and r_end functions (book: p. 338) , and finally adding insert_before and insert_after functions that will each take an iterator and an item to be item to be added, and a remove function that takes an external iterator as its argument.

	
The Application – Color Squares

As many of you may know colors on a computer are frequently represented as a hexadecimal number, such as cc0099. (Hexadecimal numbers are base 16 numbers and consists of the digits 0 – f.) This number is actually three numbers, with the first two digits representing the intensity of red, the second two the amount of green and the third pair blue. There are 256 possible values for each color. (A total of 16,777,216 different colors can be represented in this way with 000000 being black and ffffff being white.) 

I have developed a small class to store color swatches, much like something used in a paint store. Each “swatch” consists of a hexadecimal number representing the color, and two decimal numbers representing the dimensions of the swatch in millimeters. This class is in ~jdolan/cs2401/projects/project4. I have also provided a data file listing a whole collection of these swatches called swatches.txt. There are also a couple of executables that will convert these numbers in viewable html files, as well as the application for the program, main2.cc. (This part will compile with g++ -g swatch.cc main2.cc)

This application reads data from the aforementioned data file, and place the predominantly green colors at the start of the list, and the predominantly red colors at the back of the list, and the predominantly blue colors at the spot immediately following the centermost spot in the list.

It then

•	Makes a copy of the list using either your copy constructor or your overloaded assignment operator

•	Removes the front, back and centermost swatch from the copy.

•	Outputs the original list frontwards

•	Outputs the copy frontwards.

•	Outputs the original list backwards.

•	Destroys the original list by alternating between removal of the first item and the last item, outputting each item as it is removed.

•	Outputs the copy backwards.

Notice that there is no user interaction in this application. It simply runs the test and stops, outputting the results to the screen, one “swatch” per line with two or more blank lines between each of the outputs. Although it is not required you can see the colors by :

•	Redirect the output of your program to a file: a.out > result

•	Run either: p1p2_mkhtml result OR: labs_mkhtml result depending on what machine you’re on.

•	This will create a .html file which you can transfer to your local machine via winscp or something similar, if you are not in lab, and which you can then open by double-clicking
