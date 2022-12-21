//
//  Noble.cpp
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
    Noble::Noble(const std::string& name,int strength):name(name),strength(strength){};
    
int Noble::getTotalStrength() const
{
    return strength;
}

bool Noble::checkStatus() const
{
    return death==false;
}
void Noble::changeStatus()
{
    death=true;
}
std::string Noble::getName()const
{
    return name;
}
void Noble::setStrength(int num)
{
    if(num==-1)
    {
        strength=0;
        death=true;
    }
    strength=num;
}
void Noble::battle(Noble& enermy)
{
    std::cout<<name<<' '<<"battles"<<' '<<enermy.getName()<<std::endl;
    if (checkStatus()==false || enermy.checkStatus()==false)     //if any of the two died
    {
        if (checkStatus()==false && enermy.checkStatus())
        {
            
            std::cout<<"He's dead, "<<enermy.getName()<<std::endl;
        }
        else if (checkStatus()&& enermy.checkStatus()==false)
        {
            std::cout<<"He's dead, "<<name <<std::endl;
        }
        else //both death
        {
            std::cout<<"Oh, NO! They're both dead! Yuck!"<<std::endl;
        }
        
    }
    
    else    //both are alive
    {
        if(strength < enermy.getTotalStrength())
        {
            enermy.setStrength(getTotalStrength());
            setStrength();
           std::cout<<enermy.getName()<<' '<<"defeats"<<' '<<name<<std::endl;
            
            
        }
        else if(strength > enermy.getTotalStrength())
        {
            setStrength(enermy.getTotalStrength());
            enermy.setStrength();
            std::cout<<name<<' '<<"defeats"<<' '<<enermy.getName()<<std::endl;
        }
        
        else // strengthes are the same
        {
            setStrength();
            enermy.setStrength();
            std::cout<<"Mutual Annihilation: "<<name;
            std::cout<<' '<<"and"<<' '<<enermy.getName()<<" die at each other's hands"<<std::endl;
            
        }
    }
}

/////////////////////////////////////////


Lord::Lord(const std::string& name):Noble(name){};

void Lord::setStrength(int enermyStrength)
{
    ////speak before strength lessen
    for(size_t i =0; i<army.size();++i)
    {
        army[i]->ProtecterSound();
    }
    
    if (enermyStrength==-1)
    {
        Noble::setStrength();
    }
    else
    {
        float ratio= float (enermyStrength)/float(this->getTotalStrength());
        int finalStrength=0;
        for(size_t i =0; i<army.size();++i)
        {
            int newStrength=(army[i]->getStrength())*ratio;
            army[i]->setStrength(newStrength);
            finalStrength+=newStrength;
        }
        Noble::setStrength(finalStrength);
    }
}
bool Lord::hires(Protecter& guard)
{
    //also make a collection of warrior pointer for Noble
    if( checkStatus() && guard.hireStatu()==false)
    {
        Protecter* ptr= &guard;
        army.push_back(ptr);
        guard.setMaster(this);
        Noble::setStrength(getTotalStrength()+guard.getStrength());
        return true;
    }
    else if (checkStatus()==false)
    {
        std::cout<<"Ghost cannot hire !"<<std::endl;
        return false;
    }
    else //warrior already has a host
    {
        std::cout<<"The warrior was hired by other!"<<std::endl;
        return false;
    }
    
    
    
}
bool Lord::fires(Protecter& guard)
{
    if( checkStatus())
    {
        Protecter* ptr= &guard;
        bool found=false;
        for(size_t i =0; i<army.size();++i)
        {
            if (army[i]==ptr)
            {
                found=true;
                for(size_t ind=i; ind<army.size()-1;++ind)
                    army[ind]=army[ind+1];
                army.pop_back();                        //delete the last dupulicated one
                std::cout<<guard.getName();
                std::cout<<" ,you are fired! --";
                std::cout<< getName()<<std::endl;
                
            }
        }
        if (found==false)
        {
            std::cout<<"The warrior wasn't hired by you!"<<std::endl;
            return false;
        }
        guard.setMaster(nullptr);
        Noble::setStrength(getTotalStrength()-guard.getStrength());
        return true;
    }
    else
    {
        std::cout<<"Ghost cannot fire !"<<std::endl;
        return false;
    }
}
void Lord::armyFlee(Protecter& guard)
{
    Protecter* ptr= &guard;
    for(size_t i =0; i<army.size();++i)
    {
        if (army[i]==ptr)
        {
            for(size_t ind=i; ind<army.size()-1;++ind)
                army[ind]=army[ind+1];
                army.pop_back();                        //delete the last dupulicated one
            
        }
    }
    this->Noble::setStrength(getTotalStrength()-guard.getStrength());
}
////////////////


PersonWithStrengthToFight::PersonWithStrengthToFight(const std::string& name, int strength):Noble(name,strength){};

void PersonWithStrengthToFight::setStrength(int enermyStrength)
{
    if (enermyStrength==-1)
    {
        Noble::setStrength();
    }
    else
    {
        float ratio= float (enermyStrength)/float(getTotalStrength());
        int newStrength=(getTotalStrength()*ratio);
        Noble::setStrength(newStrength);
    }
    
}
}
