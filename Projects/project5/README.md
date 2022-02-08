# Project Outline Given by Professor
Now that spring is here, all the animals are out shopping for new homes. We have been commissioned to write the software for Animal Home Construction Inc.® a company which will be offering many types of animal homes this fall.

What makes this project unique is that due to the different needs of different animals the homes must have different attributes. The attributes that describe a bear's cave are not really the same as those that describe an eagles nest. Yet we would like to have a single container that holds all of these homes. (Can you say “Polymorphism?”)

The key here is to derive all the different types of homes from a single parent class. The parent class exists primarily just to be a parent. Then by using pointers of the parent class and virtual functions we can dynamically allocate each home as it is ordered and insert it into a container that has been instantiated to hold pointers of the parent class.

For a container you should use the list class from the STL. You will be using an iterator for output, and the container will not order the list by any comparison, so a list is a good choice. You will have at least five child classes, each of which will have input and output functions, and no other functions. The application program will present the user with a menu, giving him, or her, a choice of what kind of animal they would like to order a home for. Then it will ask them to input the information for that home. That home will then be put into the container. At any time the user can also ask to see a printout of all the homes ordered thus far. (You will be using the list iterator for this.)

Since our software is frequently shut-down at night we need to keep a permanent record of all the homes in the list, so there should be a mechanism that writes the homes out to a file. When the program begins running it should look for the file and begin by inserting all the homes that it finds there into the container. Your submission should include a datafile that allows the program to do this.

In some ways this project is simple. The child classes contain little more than a default constructor and virtual input and output functions that work with that child's particular member variables, and you are not required to implement the container. But it does demonstrate a powerful programming tool and some profound features of C++. (And don't procrastinate too much because the file I/O can be tricky.) Also variety and imagination in the creation of the child classes is a critical grading criterion. Do not be lazy. 

Included with your project submission should be a UML class diagram for the project, generated through the ArgoUML© software, and saved as a .zargo file. This is worth five out of the fifty points for the overall project. 

Your Blackboard submission of this project should include all the files that I need to compile and run the program as well as a sample data file of some homes your clients have order. It is due at 11:59 p.m. on Tuesday, April 7th.	
