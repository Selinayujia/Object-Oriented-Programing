//
//  Noble.h
//  hw06
//
//  Created by Selina on 20/03/2018.
//  Copyright © 2018 Selina. All rights reserved.
//

#ifndef Noble_h
#define Noble_h
#include <string>
#include <vector>
#include <iostream>
namespace WarriorCraft
{
    class Warrior;
    class Noble
    {
        friend std::ostream& operator<<(std::ostream& os, const Noble& nob);
        public:
        Noble (const std::string& name);   //initialize nobel
        std::string get_name() const;
        int get_strength() const;
        void after_win_battle(int rival_strength);    // after win the battle the strength of warriors will be
        void die_in_battle();              // set all the warrior's strength to zero after losing a battle
        bool hire(Warrior& warrior);               //make the warrior to point to the Nobel after hire
        bool fire(Warrior& warrior);//cancel the the pointer from warrior to a nobel
        void someoneflee(Warrior& warrior);
        void battle( Noble& nob);        //battle between the army of Nobles
        
        private:
        std::string name;
        std::vector<Warrior*> army;
        int strength=0;
        bool death= false;
        
    };
    

}

#endif /* Noble_h */
