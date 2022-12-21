//
//  Warrior.h
//  hw06
//
//  Created by Selina on 20/03/2018.
//  Copyright © 2018 Selina. All rights reserved.
//

#ifndef Warrior_h
#define Warrior_h

#include <string>
#include <vector>
#include <iostream>
namespace WarriorCraft
{
    class Noble;
    class Warrior
    {
        public:
        
        Warrior(const std::string& name, int strength); //initialize the warrior
        std::string get_name() const;
        int get_strength() const;
        void set_strength(int str);
        void get_host(Noble* const nob);
        void runaway();
        Noble* view_host() const;
        
        private:
        std::string name;
        int strength;
        Noble* host=nullptr;
        
    };

    
}

#endif /* Warrior_h */
