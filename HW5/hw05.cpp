//  main.cpp
//  hw6
//
//  Created by Selina on 19/02/2018.
//  Copyright © 2018 Selina. All rights reserved.
// I am Selina Zhang, nyu id N11659385 and net id yz4184. This is a game of medieval times. The world is filled with warriors. The warriors are hired or fired by Nobels. They will always fight for the Nobel till the death. If all warrior died then the Nobel is dead too.

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
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
    void set_strength(int str)
    {
        strength=str;
    }
    void get_host(Noble* const nob)
    {
        host=nob;
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
    
    void delete_army()
    {
        for(size_t i=0;i<army.size();++i)
        {
            delete army[i];
        }
        army.clear();
    }
    Warrior* get_Warrior(const string name)
    {
        for(size_t i =0; i<army.size();++i)
        {
            if (army[i]->get_name()==name)
            {
                return army[i];
            }
        }
        return nullptr;
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
        }
        else //warrior already has a host
        {
            cout<<"The warrior was hired by other!"<<endl;
        }
        return false;
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
    void battle( Noble& enermy)         //battle between the army of Nobles
    {
        
        if (strength==0 || enermy.get_strength()==0)     //if any of the two died
        {
            
            cout<<name<<' '<<"battles"<<' '<<enermy.get_name()<<endl;
            if (strength==0 && enermy.get_strength()!=0)
            {
                
                cout<<"He's dead, "<<enermy.get_name()<<endl;
            }
            else if (strength!=0 && enermy.get_strength()==0)
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
            cout<<name<<' '<<"battles"<<' '<<enermy.get_name()<<endl;
            if(strength < enermy.get_strength())
            {
                enermy.after_win_battle(strength);
                this->die_in_battle();
                cout<<enermy.get_name()<<' '<<"defeats"<<' '<<name<<endl;
                
                
            }
            else if(strength > enermy.get_strength())
            {
                this->after_win_battle(enermy.strength);
                enermy.die_in_battle();
                cout<<name<<' '<<"defeats"<<' '<<enermy.get_name()<<endl;
            }
            
            else // strengthes are the same
            {
                this->die_in_battle();
                enermy.die_in_battle();
                cout<<"Mutual Annihilation: "<<name;
                cout<<' '<<"and"<<' '<<enermy.get_name()<<" die at each other's hands"<<endl;
                
            }
        }
    }
    
    private:
    string name;
    vector<Warrior*> army;
    int strength=0;
    bool death= false;
    
};

size_t find_noble(const vector<Noble*>& nob, const string& n_name)  //find the corresponding noble in vector, remind if there is no such Noble
{
    size_t ind_n=-1;
    for(size_t i=0;i<nob.size();++i)
    {
        if(nob[i]->get_name()==n_name)
        {
            ind_n=i;
        }
        
    }
    if(ind_n==-1)
    {
        cout<<"There is no such noble named "<<n_name<<endl;
        
    }
    return ind_n;
    
    
}


size_t find_warrior(const vector<Warrior*>& warr, const string& w_name) //find the correspond warrior in vector, remind if
//there's no such warrior
{
    size_t ind_w=-1;
    for(size_t i=0;i<warr.size();++i)
    {
        if(warr[i]->get_name()==w_name)
        {
            ind_w=i;
        }
        
    }
    if (ind_w==-1)
    {
        cout<<"There is no such warrior named "<<w_name<<endl;
    }
    return ind_w;
}



int main()
{
    ifstream ifs("nobleWarriors.txt");    // input file
    if (!ifs)
    {
        cout<<"Fail to open file"<<endl; //prevent the failure of opening the file
        exit(0);
        
    }
    string command, n_name, w_name, host, rival;
    int strength;
    vector<Noble*> upr_class;
    vector<Warrior*>unemployed;
    
    while(ifs>>command)
    {
        if(command =="Noble")            //if it is a command of nobel, print in the format following with name
        {
            ifs >> n_name;
            size_t if_exist=-1;
            for(size_t i=0;i<upr_class.size();++i)
            {
                if(upr_class[i]->get_name()==n_name)
                {
                    if_exist=i;
                }
                
            }
            if(if_exist==-1)
            {
                
                Noble* n = new Noble(n_name);
                upr_class.push_back(n);
            }
            else
            {
                cout<<"The noble is already existed"<<endl;
            }
            
        }
        else if(command == "Warrior")      //if it is a command of warrior, print in the format following with name and strength
        {
            ifs >> w_name >> strength;
            size_t if_exist=-1;
            for(size_t i=0;i<unemployed.size();++i)
            {
                if(unemployed[i]->get_name()==w_name)
                {
                    if_exist=i;
                }
                
            }
            if(if_exist==-1)
            {
                
                Warrior* w = new Warrior(w_name,strength);
                unemployed.push_back(w);
            }
            else
            {
                cout<<"The warrior is already existed"<<endl;
            }
            
        }
        else if(command == "Hire") // if it is a command of hire, trigger hire method in Nobel class if noble and warrior are found
        {
            ifs >> n_name >> w_name;
            size_t ind_n= find_noble(upr_class, n_name);
            size_t ind_w= find_warrior(unemployed, w_name);
            if(ind_n != -1 && ind_w != -1)
            {
                upr_class[ind_n]->hire(*unemployed[ind_w]);
                for(size_t i=ind_w;i<unemployed.size()-1;++i)  //remove the hired warrior from an unemployed list
                {
                    unemployed[i]=unemployed[i+1];
                }
                unemployed.pop_back();
            }
            
        }
        else if(command == "Fire") //if is a command of hire, trigger fire method in Noble class if noble and warrior are found
        {
            ifs >> n_name >> w_name;
            size_t ind_n= find_noble(upr_class, n_name);
            if(ind_n != -1 )
            {
                Warrior* fired_w=upr_class[ind_n]->get_Warrior(w_name); //get the fired warrior from Noble class
                upr_class[ind_n]->fire(*fired_w);
                unemployed.push_back(fired_w);         //put the fired warrior back to unemployed list
                
            }
            
            
        }
        else if (command == "Battle")          // trigger the battle method in the Noble class
        {
            ifs >> host >> rival;
            size_t ind_h= find_noble(upr_class, host);
            size_t ind_r= find_noble(upr_class, rival);
            if(ind_h != -1 && ind_r != -1)
            {
                upr_class[ind_h]->battle(*upr_class[ind_r]);
            }
            
        }
        else if (command =="Status")     //display the Noble and unemplyed list
        {
            cout<<"Status"<<endl;
            cout<<"======"<<endl;
            cout<<"Nobles : ";
            if(upr_class.size()==0)
            {
                cout<<"None"<<endl;
            }
            for(const Noble* n: upr_class)
            {
                
                n->display();
            }
            
            cout<<"Unemployed Warriors: ";
            if(unemployed.size()==0)
            {
                cout<<"None"<<endl;
            }
            for(const Warrior* w: unemployed)
            {
                cout<<w->get_name()<<" : "<< w->get_strength()<< endl;
            }
            
        }
        else //command == "Clear"         delete the pointer point to heap
        {
            for(size_t i_n=0; i_n<upr_class.size();++i_n)
            {
                upr_class[i_n]->delete_army();
                delete upr_class[i_n];
            }
            upr_class.clear();
            
            for(size_t i_w=0; i_w<upr_class.size();++i_w)
            {
                delete unemployed[i_w];
            }
            unemployed.clear();
            
            
        }
        
    }
    ifs.close();   //close the file input
}
