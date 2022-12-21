//
//  main.cpp
//  hw3
//
//  Created by Selina on 04/02/2018.
//  Copyright © 2018 Selina. All rights reserved.
//
// I am Selina Zhang, nyu id N11659385 and net id yz4184. This is a game of medieval times. The world is filled with warriors. Naturally what warriors like to do is fight.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Warrior
{
    class Weapon       // private class weapon
    {
    public:
        Weapon(const string& name,int strength) : name(name), strength(strength) //weapon constructor
        {
        }
        
        string get_name()     //get name of the weapon
        {
            return name;
        }
        
        int get_strength()   //get strength of the weapon
        {
            return strength;
        }
        
        void modify_strength(int s)   //modify the strength of the weapon
        {
            strength=s;
        }
        
    private:                //private data field of the weapon
        string name;
        int strength;
        
    };
public:
    Warrior(const string&name,const string& wname,int strength):name(name),aweapon(wname,strength)
    {
    }                   // constructor of the warrior class
    
    string get_name()   // get name of the warrior
    {
        return name;
    }
    
    string get_weapon_name()         //get name of the weapon that warrior has
    {
        return aweapon.get_name();
    }
    int get_weapon_strength()       //get name of the weapon strength that warrior has
    {
        return aweapon.get_strength();
    }
    void after_battle(int strength)              //set the strength of warrior's weapon zero
    {
        aweapon.modify_strength(strength);
    }
    
private:               //private data field of warrior class
    
    string name;
    Weapon aweapon;
    
    
};

void print_status(vector<Warrior>& army);
void battle(const string& host,const string& rival,vector<Warrior>& army);



int main()
{
    ifstream ifs ("warriors.txt");            // read file
    if(!ifs)
    {
        cout<<"Fail to open file"<<endl;
        exit(0);
    }
    string command;
    int strength = 0;
    string name;
    string weapon_name;
    string rival;
    vector <Warrior> army;
    
    
    while(ifs >> command)    //get the command from every line
    {
        if (command=="Warrior")
        {
            ifs >> name >> weapon_name>>strength;
            Warrior awarrior(name,weapon_name,strength);
            army.push_back(awarrior);
        }
        else if(command=="Status")
        {
            print_status(army);
        }
        else //command is battle
        {
            ifs >> name >> rival;
            
            battle(name, rival, army);
        }
    }
    
    ifs.close();
}
void print_status(vector<Warrior>& army)     //while command is status, print warriors' status
{
    size_t army_size=army.size();
    cout << "There are: " << army_size << ' ' << "warriors" << endl;
    for( size_t i=0;i<army.size();++i)
    {
        string name=army[i].get_name();
        string weapon_name=army[i].get_weapon_name();
        int strength=army[i].get_weapon_strength();
        cout <<"Warrior: "<< name <<','
        <<" weapon: "<<weapon_name<<','
        <<" strength: " <<strength<<endl;
        
    }
    
}

void battle(const string& host,const string& rival,vector<Warrior>& army) //while command is battle, battle
{
    int strength_of_host=0;
    int strength_of_rival=0;
    size_t index_of_host=0;
    size_t index_of_rival=0;
    
    
    for(size_t i=0;i<army.size();++i)      //get the strength of specific warriors,
    {                                       //and get the index for modifying
        if(army[i].get_name()==host)
        {
            strength_of_host=army[i].get_weapon_strength();
            index_of_host=i;
            
        }
        if(army[i].get_name()==rival)
        {
            strength_of_rival=army[i].get_weapon_strength();
            index_of_rival=i;
            
        }
    }
    if (strength_of_host==0 || strength_of_rival==0)     //if any of the two died
    {
        
        
        if(strength_of_host==0 && strength_of_rival!=0)
        {
            cout<<"He's dead, "<<rival<<endl;
        }
        else if (strength_of_host!=0 && strength_of_rival==0)
        {
            cout<<"He's dead, "<<host<<endl;
        }
        else //(strength_of_host==0 && strength_of_rival==0)
        {
            cout<<"Oh, NO! They're both dead! Yuck!"<<endl;
        }
        
    }
    
    else    //both are alive
    {
        if(strength_of_rival > strength_of_host)
        {
            
            cout<<host<<' '<<"battles"<<' '<<rival<<endl;
            cout<<rival<<' '<<"defeats"<<' '<<host<<endl;
            army[index_of_host].after_battle(0);
            army[index_of_host].after_battle(strength_of_rival-strength_of_host);
            
        }
        else if(strength_of_host > strength_of_rival)
        {
            
            cout<<host<<' '<<"battles"<<' '<<rival<<endl;
            cout<<host<<' '<<"defeats"<<' '<<rival<<endl;
            army[index_of_rival].after_battle(0);
            army[index_of_host].after_battle(strength_of_host-strength_of_rival);
        }
        else // strengthes are the same
        {
            cout<<host<<' '<<"battles"<<' '<<rival<<endl;
            cout<<"Mutual Annihilation: "<<host<<' '<<"and"<<' '<<rival<<" die at each other's hands"<<endl;
            
            army[index_of_host].after_battle(0);
            
            army[index_of_rival].after_battle(0);
            
        }
    }
}


