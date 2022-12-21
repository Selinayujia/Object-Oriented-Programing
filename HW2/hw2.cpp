//
//  main.cpp
//  hw2
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
struct Warrior{string name; int strength;};
void print_status(vector<Warrior> army);
void battle(string host, string rival, vector<Warrior>& army);


int main()
{
    ifstream ifs ("warriors.txt");
    if(!ifs)
    {
        cout<<"Fail to open file"<<endl;
        exit(0);
    }
    string command;
    int strength = 0;
    string name;
    string rival;
    vector <Warrior> army;
    
    
    while(ifs >> command)    //get the command from every line
    {
        if (command=="Warrior")
        {
            ifs >> name >> strength;
            Warrior awarrior;
            awarrior.name=name;
            awarrior.strength=strength;
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

void print_status(vector<Warrior> army)     //while command is status, print warriors' status
{
    size_t army_size=army.size();
    cout << "There are: " << army_size << ' ' << "warriors" << endl;
    for( const Warrior& awarrior: army)
    {
        cout << "Warrior: " << awarrior.name <<','
        << " strength: " <<awarrior.strength<<endl;
    }

}

void battle(string host,string rival,vector<Warrior>& army) //while command is battle, battle
{
    int strength_of_host=0;
    int strength_of_rival=0;
    size_t index_of_host=0;
    size_t index_of_rival=0;
    
    
    for(size_t i=0;i<army.size();++i)      //get the strength of specific warriors,
    {                                       //and get the index for modifying
        if(army[i].name==host)
        {
            strength_of_host=army[i].strength;
            index_of_host=i;
           
        }
        if(army[i].name==rival)
        {
            strength_of_rival=army[i].strength;
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
            army[index_of_host].strength=0;
            
        }
        else if(strength_of_host > strength_of_rival)
        {
            cout<<host<<' '<<"battles"<<' '<<rival<<endl;
            cout<<host<<' '<<"defeats"<<' '<<rival<<endl;
            army[index_of_rival].strength=0;
        }
        else // strengthes are the same
        {
            cout<<host<<' '<<"battles"<<' '<<rival<<endl;
            cout<<"Mutual Annihilation: "<<host<<' '<<"and"<<' '<<rival<<" die at each other's hands"<<endl;

            army[index_of_host].strength=0;
           
            army[index_of_rival].strength=0;
            
        }
    }
}

