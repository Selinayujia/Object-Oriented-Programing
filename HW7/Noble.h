//
//  Noble.h
//  hw07
//
//  Created by Selina on 01/04/2018.
//  Copyright © 2018 Selina. All rights reserved.
//

#ifndef Noble_h
#define Noble_h
#include <string>
#include<vector>
#include <iostream>
namespace WarriorCraft
{
class Protecter;
class Noble
{
public:
    Noble(const std::string& name,int strength=0);
    int getTotalStrength()const;
    std::string getName()const;
    bool checkStatus()const;
    void changeStatus();
    void battle(Noble& enermy);
    
protected:
    virtual void setStrength(int num=-1)=0;
    
private:
    std::string name;
    bool death=false;
    int strength=0;
};
class Lord:public Noble
{
public:
    Lord(const std::string& name);
    void setStrength(int enermyStrength=-1);
    bool hires(Protecter& guard);
    bool fires(Protecter& guard);
    void armyFlee(Protecter& guard);
    
private:
    std::vector<Protecter*> army;
};
class PersonWithStrengthToFight:public Noble
{
public:
    PersonWithStrengthToFight(const std::string& name, int strength);
    void setStrength(int enermyStrength=-1);
    
};

}
#endif /* Noble_h */
