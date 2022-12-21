//
//  Protecter.cpp
//  hw07
//
//  Created by Selina on 01/04/2018.
//  Copyright © 2018 Selina. All rights reserved.
//

#include <stdio.h>
#include "Noble.h"
#include "Protecter.h"
#include <string>
#include <vector>
#include <iostream>
namespace WarriorCraft
{
    
    Protecter::Protecter(const std::string& name, int strength):name(name),strength(strength){};
    std::string Protecter::getName() const
    {
        return name;
    }
    std::string Protecter::getMasterName()const
    {
        return master->getName();
    }
    int Protecter::getStrength()const
    {
        return strength;
    }
    void Protecter::setStrength(int newStrength)
    {
        strength=newStrength;
    }
    bool Protecter::hireStatu()const
    {
        return hired;
    }
    void Protecter::setMaster(Lord* lord)
    {
        master=lord;
    }
    
    void Protecter::quit()
    {
        master->armyFlee(*this);
        std::cout<<name<<", flees in terror, abandoning his lord, "<<getMasterName()<<std::endl;
        master=nullptr;
    }
    
    
    Wizard:: Wizard(const std::string& name, int strength):Protecter(name,strength){};
    
    void Wizard::ProtecterSound() const
    {
        std::cout<<"POOF"<<std::endl;
    }
    
    
    Warrior::Warrior(const std::string& name, int strength):Protecter(name,strength){};
    
    
    
    Archer::Archer(const std::string& name, int strength):Warrior(name,strength){};
    void Archer::ProtecterSound()const
    {
        std::cout<<"TWANG! "<<this->getName()<<" says: Take that in the name of my lord, "<<this->getMasterName()<<std::endl;
    }
    Swordsman::Swordsman(const std::string& name, int strength):Warrior(name,strength){};
    void Swordsman::ProtecterSound()const
    {
        std::cout<< "CLANG! "<<this->getName()<<" says: Take that in the name of my lord, "<<this->getMasterName()<<std::endl;
    }

}
