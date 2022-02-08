/**************************************************************************
	 These are the child classes of the Home class. Each of the respective
    children in this class were chosen based off of their relatively
    unique housing characteristics. Each class will have a description
    of these unique patterns and its influence on the class attributes.
	 Each child class is complete with an input and output function that
    takes a stream as its argument and then uses this stream to output
    orinput the variable data.
	    Jordan Wells				April 1st, 2020
************************************************************************/

#ifndef CHILD_H
#define CHILD_H
#include "parent.h"


/*
 Horned Coots are a bird species that build their habitats by piling pebbles
in to the bottom of lakes and other bodies of water. Through this process,
they can create land masses that way up to 1.5 tons. After they construct
their artificial islands, they finish their project by covering the surface
with flora species they find throught their environment.
*/
class Coot: public Home{
    public:
    Coot(){
        weight = 0;
        eggs = 0;
        flora = "";
        aquaticEnvironment = "";
    }
     void input(std::istream &ins);
     void output(std::ostream & outs);
    private:
     int weight;
     int eggs;
     std::string flora;
     std::string aquaticEnvironment;
};

/*
 Bees are a species known for their intricate soical networks, and for
their interesting housing techique. They create these hives by chewing on wax
until it becomes soft and then bonding large quatities of it together in order
to form individual hexagonal honeycombs. The collection of these honeycombs is what
forms their nest. Scout bees are the ones who discover the location in which they
will build their nest, and worker bees are mostly responisble for the construction
of these sites.
*/
class Bee: public Home{
    public:
     Bee(){
         workers = 0;
         scouts = 0;
         honeycombs = 0;
         location = "";
     }
     void input(std::istream &ins);
     void output(std::ostream & outs);
    private:
     int workers;
     int scouts;
     int honeycombs;
     std::string location;
};


/*
 Beavers are another very well-known species that have an interesting method
of constructing their homes. To begin, beavers start piling logs and sticks around a
waterway which becomes the entrance to their home. After the construction phase ends,
they begin fortifying their home by packing mud on top of the sticks that form the 
structure. Each year they complete this process, further fortifying their home:
In my project, for each year it is fortified, the fortificationLevel value increases
If the water is too shallow to protect their home, beavers often form dams
across the water way in order to further their homes defense. This is represented
by a boolean value in my project.
*/
class Beaver: public Home{
    public:
     Beaver(){
         volume = 0;
         fortificationLevel = 0;
         woodType = "";
         waterway = "";
         dam = false;
     }
     void input(std::istream &ins);
     void output(std::ostream & outs);
    private:
     int volume;
     int fortificationLevel;
     std::string woodType;
     std::string waterway;
     bool dam;

};
/*
 Groundhogs form their homes by excavating massive amounts of soil, totaling up to
5,500 lbs. In these homes, their are multiple chambers which serve many functions
for the lifestyle of the groundhogs occupying it: These include, sleeping chambers,
restrooms, nuseries, and the creation of many escape routes for the security of the 
occupants
*/
class Groundhog: public Home{
    public:
     Groundhog(){
         escapeRoutes = 0;
         nuseries = 0;
         sleepingChambers = 0;
         restRooms = 0;
     }
     void input(std::istream &ins);
     void output(std::ostream & outs);
    private:
     int escapeRoutes;
     int nuseries;
     int sleepingChambers;
     int restRooms;
};

/*
 Trapdoor Spiders are a species of spider that build homes in a way that differs greatly
from that of a typical spider. Rather than building webs, they create burrows in the ground.
These burrows are completed with a door that is hinged on one side with silk. This
allows the spider to open and shut the door with ease. To hide their existence from the
outside world, they cover the door with plant debris to act as camoflage. As intruders approaches the door,
the spider opens the door and runs forward, capturing its prey while it is off guard.
*/
class TrapdoorSpider: public Home{
    public:
     TrapdoorSpider(){
         depth = 0;
         inhabitants = 0;
         camoflage = "";
         doorType = "";
     }
     void input(std::istream &ins);
     void output(std::ostream & outs);
    private:
     int depth;
     int inhabitants;
     std::string camoflage;
     std::string doorType;
};

/*
 Sociable weavers are a species of bird that form series of interconnected nests
that can house up to 200 adult weavers as well as their children. The connected
nest has the outside appearance of a haystack, but the inside has many passageways
connecting the nests distributed through it and exit points distributed through out.
All of the birds living their work together to maintain and protect the nest.
*/
class Weaver: public Home{
    public:
     Weaver(){
         nests = 0;
         birds = 0;
         decor = "";
         twig = "";
         tree = "";
     }
     void input(std::istream &ins);
     void output(std::ostream & outs);
    private:
     int nests;
     int birds;
     std::string decor;
     std::string twig;
     std::string tree;
};

#endif