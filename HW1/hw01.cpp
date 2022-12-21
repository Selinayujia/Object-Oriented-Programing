//
//  main.cpp
//  hw1
//
//  Created by Selina on 29/01/2018.
//  Copyright © 2018 Selina. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
char decypher(char c,int rotation)
{
    int cha=int(c)-rotation;
    if (cha<('a'))  //prevent the ascii number is smaller than the range of lower case alphabet
    {
        cha='z'-'a'+cha+1;
    }
    c=cha;
    
    return c;
}
void modifystr(string& str,int rotation)  //modified the string from input directly
{
    for(size_t index=0;index<str.size();++index)
    {
        if (int(str[index])>='a'&&int(str[index])<='z') //use the ascii number to identify the lowercases to decypher
        {
            str[index]=decypher(str[index],rotation);
        }
    }
}
int main()
{
    ifstream ifs("encrypted.txt");
    if (!ifs)  //prevent the failing open file
    {
        cout<<"Failed to open file"<<endl;
    }
    string line;
    vector<string> txt;
    
    while (getline(ifs, line))   //put every line read from file to a vector
    {
        txt.push_back(line);
    }
    ifs.close();
    int num_of_rotat=0;
    stringstream geek(txt[0]);
    geek >> num_of_rotat;         //read the first line of file to know the rotation number, change it to integer
    
    for(size_t index=1;index<txt.size();++index)
    {
        modifystr(txt[index],num_of_rotat);
        
    }
    reverse(begin(txt),end(txt));  //reverse the order of text
    for (size_t index=0;index<txt.size()-1;++index)
    {
        cout<<txt[index]<<"\n"<<endl;
    }
}

