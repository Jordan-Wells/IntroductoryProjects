/**************************************************************************
	 These are the implementations of the functions held with in the
     children classes of the the home class.
	    Jordan Wells				April 1st, 2020
************************************************************************/

#include "child.h"
#include <fstream>
void Coot::input(std::istream &ins){
    if(&ins == &std::cin){
        std::cout << "Enter Island Weight: ";
        ins >> weight;
        std::cout << "Enter number of eggs: ";
        ins >> eggs;
        ins.ignore(1);
        std::cout << "Enter flora type: ";
        getline(ins,flora);
        std::cout << "Enter body of water: ";
        getline(ins, aquaticEnvironment);
    }
    else{
        ins.ignore(1);
        std::string tmp;
        getline(ins, tmp);
        weight = std::stoi(tmp);
        getline(ins, tmp);
        eggs = std::stoi(tmp);
        getline(ins, flora);
        getline(ins, aquaticEnvironment);   
    }

}
void Coot::output(std::ostream & outs){
    if(&outs == &std::cout){
        outs << "Animal: Coot" << std::endl;
        outs << "Weight: " << weight << std::endl;
        outs << "Eggs: " << eggs << std::endl;
        outs << "Flora: " << flora << std::endl;
        outs << "Environment: " << aquaticEnvironment << std::endl;
    }
    else{
        outs << "C" << std::endl << weight << std:: endl;
        outs << eggs << std:: endl;
        outs << flora << std:: endl;
        outs << aquaticEnvironment << std:: endl;
    }
}
void Bee::input(std::istream &ins){
    if(&ins == &std::cin){
        std::cout << "Enter number of workers: ";
        ins >> workers;
        std::cout << "Enter number of scouts: ";
        ins >> scouts;
        std::cout << "Enter number of honeycombs: ";
        ins >> honeycombs;
        ins.ignore(1);
        std::cout << "Enter location of hive: ";
        getline(ins, location);
    }
    else{
        ins.ignore(1);
        std::string tmp;
        getline(ins, tmp);
        workers = std::stoi(tmp);
        getline(ins, tmp);
        scouts = std::stoi(tmp);
        getline(ins, tmp);
        honeycombs = std::stoi(tmp);
        getline(ins, location);   
    }
}
void Bee::output(std::ostream & outs){
    if(&outs == &std::cout){
        outs << "Animal: Bee" << std::endl;
        outs << "Workers: " << workers << std::endl;
        outs << "Scouts: " << scouts << std::endl;
        outs << "HoneyCombs: " << honeycombs << std::endl;
        outs << "Location: " << location << std::endl;
    }
    else{
        outs << "B" << std::endl << workers << std:: endl;
        outs << scouts << std:: endl;
        outs << honeycombs << std:: endl;
        outs << location << std:: endl;
    }
}
void Beaver::input(std::istream &ins){
    if(&ins == &std::cin){
        std::cout << "Enter chamber volume: ";
        ins >> volume;
        std::cout << "Enter number of years of fortification: ";
        ins >> fortificationLevel;
        ins.ignore(1);
        std::cout << "Enter type of wood: ";
        getline(ins, woodType);
        std::cout << "Enter body of water: ";
        getline(ins, waterway);
        std::cout << "Is there a dam? (true/false) (1/0): ";
        ins >> dam;
    }
    else{
        ins.ignore(1);
        std::string tmp;
        getline(ins, tmp);
        volume = std::stoi(tmp);
        getline(ins, tmp);
        fortificationLevel = std::stoi(tmp);
        getline(ins, woodType);
        getline(ins, waterway);   
        ins >> dam;
    }
}
void Beaver::output(std::ostream  & outs){
    if(&outs == &std::cout){
        outs << "Animal: Beaver" << std::endl;
        outs << "Volume: " << volume << std::endl;
        outs << "Years of fortification: " << fortificationLevel << std::endl;
        outs << "Wood: " << woodType << std::endl;
        outs << "Body of Water: " << waterway << std::endl;
        outs << "Dam?: ";
        if(dam){
            outs << "True" << std::endl;
        }
        else{
            outs << "False" << std::endl;
        }
    }
    else{
        outs << "E" << std::endl << volume << std:: endl;
        outs << fortificationLevel << std:: endl;
        outs << woodType << std:: endl;
        outs << waterway << std:: endl;
        outs << dam << std::endl;
    }
}
void Groundhog::input(std::istream &ins){
    if(&ins == &std::cin){
        std::cout << "Enter number of escape routes: ";
        ins >> escapeRoutes;
        std::cout << "Enter number of nuseries: ";
        ins >> nuseries;
        std::cout << "Enter number of sleeping chambers: ";
        ins >> sleepingChambers;
        std::cout << "Enter number of restrooms: ";
        ins >> restRooms;
    }
    else{
        ins.ignore(1);
        std::string tmp;
        getline(ins, tmp);
        escapeRoutes = std::stoi(tmp);
        getline(ins, tmp);
        nuseries = std::stoi(tmp);
        getline(ins, tmp);
        sleepingChambers = std::stoi(tmp);
        getline(ins, tmp);
        restRooms = std::stoi(tmp);
    }
}
void Groundhog::output(std::ostream & outs){
    if(&outs == &std::cout){
        outs << "Animal: Groundhog" << std::endl;
        outs << "Number of escape routes: " << escapeRoutes << std::endl;
        outs << "Number of nuseries: " << nuseries << std::endl;
        outs << "Number of sleeping chambers: " << sleepingChambers << std::endl;
        outs << "Number of restrooms: " << restRooms << std::endl;
    }
    else{
        outs << "G" << std::endl << escapeRoutes << std:: endl;
        outs << nuseries << std:: endl;
        outs << sleepingChambers << std:: endl;
        outs << restRooms << std:: endl;
    }
}
void TrapdoorSpider::input(std::istream &ins){
    if(&ins == &std::cin){
        std::cout << "Enter depth (in centimeters): ";
        ins >> depth;
        std::cout << "Enter number of inhabitants: ";
        ins >> inhabitants;
        ins.ignore(1);
        std::cout << "Enter type of camoflage: ";
        getline(ins,camoflage);
        std::cout << "Enter type of door: ";
        getline(ins,doorType);
    }
    else{
        ins.ignore(1);
        std::string tmp;
        getline(ins, tmp);
        depth = std::stoi(tmp);
        getline(ins, tmp);
        inhabitants = std::stoi(tmp);
        getline(ins, camoflage);
        getline(ins, doorType);
    }
}
void TrapdoorSpider::output(std::ostream & outs){
    if(&outs == &std::cout){
        outs << "Animal: Trapdoor Spider" << std::endl;
        outs << "Burrow Depth: " << depth << std::endl;
        outs << "Inhabitants: " << inhabitants << std::endl;
        outs << "Camoflage: " << camoflage << std::endl;
        outs << "Type of Door: " << doorType << std::endl;
    }
    else{
        outs << "T" << std::endl << depth << std:: endl;
        outs << inhabitants << std:: endl;
        outs << camoflage << std:: endl;
        outs << doorType << std:: endl;
    }
}
void Weaver::input(std::istream &ins){
    if(&ins == &std::cin){
        std::cout << "Enter number of nests: ";
        ins >> nests;
        std::cout << "Enter number of birds: ";
        ins >> birds;
        ins.ignore(1);
        std::cout << "Enter nest decor: ";
        getline(ins, decor);
        std::cout << "Enter type of twigs: ";
        getline(ins,twig);
        std::cout << "Enter type of tree: ";
        getline(ins,tree);
    }
    else{
        ins.ignore(1);
        std::string tmp;
        getline(ins, tmp);
        nests = std::stoi(tmp);
        getline(ins, tmp);
        birds = std::stoi(tmp);
        getline(ins, decor);
        getline(ins, twig);
        getline(ins, tree);
    }
}
void Weaver::output(std::ostream & outs){
    if(&outs == &std::cout){
        outs << "Animal: Weaver" << std::endl;
        outs << "Number of nests: " << nests << std::endl;
        outs << "Number of birds: " << birds << std::endl;
        outs << "Decor: " << decor << std::endl;
        outs << "Twig type: " << twig<< std::endl;
        outs << "Tree type: " << tree<< std::endl;
    }
    else{
        outs << "W" << std::endl << nests << std:: endl;
        outs << birds << std:: endl;
        outs << decor << std:: endl;
        outs << twig << std:: endl;
        outs << tree << std:: endl;
    }
}