# Project Outline Given by Professor
The idea of a sequence class is that the programmer can choose where an item is stored in the list, and that sequence, or order, of the items remains the same, even when things are deleted. In this particular project we are going to pass that capability on to the user allowing them to order their Facebook friends in any way they choose. (We’re just maintaining a list here, not working with your actual Facebook account, and you are allowed to have fictitious friends.) Of course, some people have hundreds of Facebook friends, while others have only a few, so we are going to implement this using a dynamic array.

Begin this project by copying the main.cc, date.h, date.cc, friend.h and fbfriends.h files that I have provided in ~jdolan/cs2401/projects/project2 and in Blackboard. First I have written a header file for you for a class called Friend. (Note that we can only call this class Friend if we use capitalization, since the word friend is reserved.) This class has have two private variables, one for the friend’s name and the other for their birthday, the later being of type Date, another class that I have given you. You are to write the implementation of this class, including overloaded insertion and extraction operators as well operators for = = and !=. Two friends are “equal” only if they have the same name and the same birthday. (Doctors’ offices do this because of the low probability that two people will have both the same name and the same birthday.)

Test this class by writing a main of your own that declares a two friends, lets you put the information into both, outputs them to the screen and compares them for equality.

Now, in the main that I have given you, you will find that the application allows

•	The addition of a new friend to the beginning of the list

•	The viewing of all the friends in the list

•	The ability to walk through the list, viewing one friend at a time

•	The ability to remove a friend from the list (de-friending someone)

•	The ability to insert a new friend at some spot in the middle of the list, which includes at the back end

•	The ability to sort all the friends by their birthdays

•	The ability to find a friend using their name

There is also a file backup mechanism. In this case it operates using the person’s username for the name of the file. {OVER}

 
I have given you the header file for the container class that makes all of this possible, fbfriends.h. You are to write the implementation of this as well. The private variables for this class consist of a pointer of type Friend and variables for capacity, used, and current_index. The constructor will begin by allocating a dynamic array of Friends capable of holding only five friends. (This will save on memory space for those users with few friends.) When the action of adding an additional friend to the list happens you should check if used == capacity, and if it does do a resize operation, that increases the size of the array by five.

This container also has an internal iterator, as the author illustrated in section 3.2 of the text, which will require that you write the functions

•	start

•	advance

•	is_item

•	current

•	remove_current

•	insert

•	attach

and you will find that these are implemented in the same way as they are in the text. You will also need to implement show_all – used mostly for testing purposes, bday_sort, find_friend, and is_friend.

Because this is a dynamic array you will need to write a resize function, and the Big 3 (destructor, copy constructor, and assignment operator). And because we’re providing file backup we will also have functions for load and save.
