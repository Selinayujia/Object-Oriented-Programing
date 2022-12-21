//
//  main.cpp
//  hw4
//
//  Created by Selina on 19/02/2018.
//  Copyright © 2018 Selina. All rights reserved.
// I am Selina Zhang, nyu id N11659385 and net id yz4184. This is a game of medieval times. The world is filled with warriors. The warriors are hired or fired by Nobels. They will always fight for the Nobel till the death. If all warrior died then the Nobel is dead too.

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Warrior;
class Noble;

class Warrior
{
public:
    
    Warrior(const string& name, int strength):name(name), strength(strength){} //initialize the warrior
    
    string get_name() const
    {
        return name;
    }
    int get_strength() const
    {
        return strength;
    }
    void set_strength(int s)
    {
        strength=s;
    }
    void get_host(Noble* const n)
    {
        host=n;
    }
    Noble* view_host() const
    {
        return host;
    }
private:
    string name;
    int strength;
    Noble* host=nullptr;

};

class Noble
{
public:
    Noble (const string& name):name(name){}   //initialize nobel
    string get_name() const
    {
        return name;
    }
    int get_strength() const
    {
        return strength;
    }
    void after_win_battle(int rival_strength)    // after win the battle the strength of warriors will be
    {                                               //rendered to total rival strength /total strength before
        float ratio= float (rival_strength)/float(strength);
        
        for(size_t i =0; i<army.size();++i)
        {
            int n_s=(army[i]->get_strength())*ratio;
            army[i]->set_strength(n_s);
        }
    }
    void die_in_battle()              // set all the warrior's strength to zero after losing a battle
    {
        strength=0;
        death=true;
        for(size_t i =0; i<army.size();++i)
        {
            army[i]->set_strength(0);
        }
    }
    bool hire(Warrior& warrior)               //make the warrior to point to the Nobel after hire
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
    bool fire(Warrior& warrior)                          //cancel the the pointer from warrior to a nobel
    {                                                       //remove a warrior from the Noble army
        if( death==false && warrior.view_host()==this)
        {
          
            Warrior* wptr= &warrior;
            for(size_t i =0; i<army.size();++i)
            {
                if (army[i]==wptr)
                {
                    for(size_t ind=i; ind<army.size()-1;++ind)     //after find the warrior to fire, make every
                        army[ind]=army[ind+1];                    //warrior in the back reassign forward and
                    army.pop_back();                        //delete the last dupulicated one
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
    void display()  const     //dispaly Noble's army
    {
        cout<< name << " has an army of "<<army.size()<<endl;
        for(size_t i=0;i<army.size();++i)
        {
            cout<<"\t"<<army[i]->get_name()<<" : "<<army[i]->get_strength()<<endl;
        }
        
    }
    void battle( Noble& n)         //battle between the army of Nobles
    {
        
        if (strength==0 || n.get_strength()==0)     //if any of the two died
        {
            
            cout<<name<<' '<<"battles"<<' '<<n.get_name()<<endl;
            if (strength==0 && n.get_strength()!=0)
            {
                
                cout<<"He's dead, "<<n.get_name()<<endl;
            }
            else if (strength!=0 && n.get_strength()==0)
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
            cout<<name<<' '<<"battles"<<' '<<n.get_name()<<endl;
            if(strength < n.get_strength())
            {
                n.after_win_battle(strength);
                this->die_in_battle();
                cout<<n.get_name()<<' '<<"defeats"<<' '<<name<<endl;
                
                
            }
            else if(strength > n.get_strength())
            {
                this->after_win_battle(n.strength);
                n.die_in_battle();
                cout<<name<<' '<<"defeats"<<' '<<n.get_name()<<endl;
            }
            
            else // strengthes are the same
            {
                this->die_in_battle();
                n.die_in_battle();
                cout<<"Mutual Annihilation: "<<name;
                cout<<' '<<"and"<<' '<<n.get_name()<<" die at each other's hands"<<endl;
                
            }
        }
    }
    
private:
    string name;
    vector<Warrior*> army;
    int strength=0;
    bool death= false;
    
};


int main() {
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");
    
    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);
    
    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);
    
    jim.display();
    lance.display();
    art.display();
    linus.display();
    billie.display();
    
    art.fire(cheetah);
    art.display();
    
    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);
    
}

