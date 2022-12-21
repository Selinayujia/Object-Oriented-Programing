//
//  Noble.cpp
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

ostream& operator<<(ostream& os, const Noble& nob)
{
    
    os<<nob.name << " has an army of "<<nob.army.size()<<endl;
    for(size_t i=0;i<nob.army.size();++i)
    {
        os<<"\t"<<nob.army[i]->get_name()<<" : "<<nob.army[i]->get_strength()<<endl;
    }
    return os;
}
Noble::Noble (const string& name):name(name){}   //initialize nobel
string Noble::get_name() const
{
    return name;
}
int Noble::get_strength() const
{
    return strength;
}
void Noble::after_win_battle(int rival_strength)    // after win the battle the strength of warriors will be
{                                               //rendered to total rival strength /total strength before
    float ratio= float (rival_strength)/float(strength);
    
    for(size_t i =0; i<army.size();++i)
    {
        int n_s=(army[i]->get_strength())*ratio;
        army[i]->set_strength(n_s);
    }
}
void Noble::die_in_battle()              // set all the warrior's strength to zero after losing a battle
{
    strength=0;
    death=true;
    for(size_t i =0; i<army.size();++i)
    {
        army[i]->set_strength(0);
    }
}
bool Noble::hire(Warrior& warrior)               //make the warrior to point to the Nobel after hire
{                                                    //also make a collection of warrior pointer for Noble
    if( death==false && warrior.view_host()==nullptr)
    {
        Warrior* wptr= &warrior;
        army.push_back(wptr);
        warrior.get_host(this);
        strength+=warrior.get_strength();
        return true;
    }
    else if (death==true)
    {
        cout<<"Ghost cannot hire !"<<endl;
        return false;
    }
    else //warrior already has a host
    {
        cout<<"The warrior was hired by other!"<<endl;
        return false;
    }
}
bool Noble::fire(Warrior& warrior)                          //cancel the the pointer from warrior to a nobel
{                                                       //remove a warrior from the Noble army
    if( death==false && warrior.view_host()==this)
    {
        
        Warrior* wptr= &warrior;
        for(size_t i =0; i<army.size();++i)
        {
            if (army[i]==wptr)
            {
                Warrior* temp=army[i];
                army[i]=army[army.size()-1];
                army[army.size()-1]=temp;
                army.pop_back();
                
                
                cout<<warrior.get_name();
                cout<<" ,you are fired! --";
                cout<< name<<endl;
                
            }
        }
        warrior.get_host(nullptr);
        strength-=warrior.get_strength();
        return true;
    }
    else if (death==true)
    {
        cout<<"Ghost cannot fire !"<<endl;
        
        
    }
    else //warrior is not belong to this nobel
    {
        cout<<"The warrior wasn't hired by you!"<<endl;
        
    }
    return false;
}

void Noble::someoneflee(Warrior& warrior)
{
    Warrior* wptr= &warrior;
    for(size_t i =0; i<army.size();++i)
    {
        if (army[i]==wptr)
        {
            Warrior* temp=army[i];
            army[i]=army[army.size()-1];
            army[army.size()-1]=temp;
            army.pop_back();
            
        }
    }
    strength-=warrior.get_strength();
}

void Noble::battle(Noble& nob)         //battle between the army of Nobles
{
    
    if (strength==0 || nob.get_strength()==0)     //if any of the two died
    {
        
        cout<<name<<' '<<"battles"<<' '<<nob.get_name()<<endl;
        if (strength==0 && nob.get_strength()!=0)
        {
            
            cout<<"He's dead, "<<nob.get_name()<<endl;
        }
        else if (strength!=0 && nob.get_strength()==0)
        {
            cout<<"He's dead, "<<name <<endl;
        }
        else //(strength_of_host==0 && strength_of_rival==0)
        {
            cout<<"Oh, NO! They're both dead! Yuck!"<<endl;
        }
        
    }
    
    else    //both are alive
    {
        cout<<name<<' '<<"battles"<<' '<<nob.get_name()<<endl;
        if(strength < nob.get_strength())
        {
            nob.after_win_battle(strength);
            this->die_in_battle();
            cout<<nob.get_name()<<' '<<"defeats"<<' '<<name<<endl;
            
            
        }
        else if(strength > nob.get_strength())
        {
            this->after_win_battle(nob.strength);
            nob.die_in_battle();
            cout<<name<<' '<<"defeats"<<' '<<nob.get_name()<<endl;
        }
        
        else // strengthes are the same
        {
            this->die_in_battle();
            nob.die_in_battle();
            cout<<"Mutual Annihilation: "<<name;
            cout<<' '<<"and"<<' '<<nob.get_name()<<" die at each other's hands"<<endl;
            
        }
    }
}
}

