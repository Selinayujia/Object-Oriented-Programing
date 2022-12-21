//
//  Warrior.cpp
//  hw06
//
//  Created by Selina on 20/03/2018.
//  Copyright © 2018 Selina. All rights reserved.
//

#include "Noble.h"
#include "Warrior.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
namespace WarriorCraft
{
Warrior::Warrior (const string& name, int strength):name(name), strength(strength){} //initialize the warrior

string Warrior::get_name() const
{
    return name;
}
int Warrior::get_strength() const
{
    return strength;
}
void Warrior::set_strength(int str)
{
    strength=str;
}
void Warrior::get_host(Noble* const nob)
{
    host=nob;
}
void Warrior::runaway()
{
    Warrior* awarrior=this;
    string host_name=host->get_name();
    host->someoneflee(*awarrior);
    host=nullptr;
    cout<<this->name<<" flees in terror, abandoning his lord, "<<host_name<<endl;
}
Noble* Warrior::view_host() const
{
    return host;
}
}

