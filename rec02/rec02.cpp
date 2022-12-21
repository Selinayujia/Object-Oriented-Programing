//
//  main.cpp
//  rec02
//
//  Created by Selina on 02/02/2018.
//  Copyright © 2018 Selina. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct Hydrocarbon{int carbon;int hydrogen;vector<string>names;};

size_t exist_yet(int c, int h,const vector<Hydrocarbon>& CH);
int largestCarbon(const vector<Hydrocarbon>& CH);
void print(int range, const vector<Hydrocarbon>& hydrocollection);


int main()
{
    ifstream ifs("Chemistry_formula.txt");
    if (!ifs)  //prevent the failing open file
    {
        cout<<"Failed to open file"<<endl;
    }
    string name;
    char c;
    char h;
    int carbon_num;
    int hydro_num;
    
    vector<Hydrocarbon> hydrocollection;
    while (ifs >> name >> c >> carbon_num >> h >> hydro_num)
    {
        
        size_t potential_index;
        
        potential_index= exist_yet (carbon_num,hydro_num,hydrocollection);
        
        if(potential_index==-1)
        {
            Hydrocarbon aCH;
            aCH.carbon=carbon_num;
            aCH.hydrogen=hydro_num;
            aCH.names.push_back(name);
            hydrocollection.push_back(aCH);
            
        }
        else
        {
            hydrocollection[potential_index].names.push_back(name);
        }
    }
    ifs.close();
    int range= largestCarbon(hydrocollection);
    print (range,hydrocollection);
    
    
    
}



void print(int range, const vector<Hydrocarbon>& hydrocollection)
{
    for(int index=0;index<=range;++index)
    {
        for(size_t ind=0;ind<hydrocollection.size();++ind)
        {
            if(hydrocollection[ind].carbon==index)
            {
                cout<<'C'<<hydrocollection[ind].carbon<<'H'<<hydrocollection[ind].hydrogen<<' ';
                for (const string& aCH: hydrocollection[ind].names)
                {
                    cout<<aCH<<' ';
                }
                cout<<endl;
            }
        }
    }
    
}

int largestCarbon(const vector<Hydrocarbon>& CH)
{
    int range=0;
    for(size_t index=0;index<CH.size();++index)
    {
        if(CH[index].carbon>range)
        {
            range=CH[index].carbon;
        }
    }
    return range;
}


size_t exist_yet(int c, int h,const vector<Hydrocarbon>& CH)
{
    
    for (int index=0;index<CH.size();++index)
    {
       
        if(CH[index].carbon==c && CH[index].hydrogen==h)
        {
         
            return index;
        }
    }
    return -1;
}

