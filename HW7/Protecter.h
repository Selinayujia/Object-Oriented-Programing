//
//  Protecter.h
//  hw07
//
//  Created by Selina on 01/04/2018.
//  Copyright © 2018 Selina. All rights reserved.
//

#ifndef Protecter_h
#define Protecter_h
#include <string>
#include<vector>
#include <iostream>
namespace WarriorCraft
{
class Noble;
class Protecter
{
public:
    Protecter(const std::string& name, int strength);
    virtual void ProtecterSound()const=0;
    void setMaster(Lord* lord);
    std::string getName() const;
    std::string getMasterName()const;
    int getStrength()const;
    void setStrength(int newStrength);
    bool hireStatu()const;
    void quit();

   
private:
    std::string name;
    int strength;
    Lord* master=nullptr;
    bool hired=false;
    bool death=false;
};

class Wizard:public Protecter
{
public:
    Wizard(const std::string& name, int strength);
    void ProtecterSound()const;
private:
    
};
class Warrior:public Protecter
{
public:
    Warrior(const std::string& name, int strength);
   

};
class Archer:public Warrior
{
public:
    Archer(const std::string& name, int strength);
    void ProtecterSound()const;
private:
    
};
class Swordsman:public Warrior
{
public:
    Swordsman(const std::string& name, int strength);
    void ProtecterSound()const;
private:
    
};



}
#endif /* Protecter_h */
