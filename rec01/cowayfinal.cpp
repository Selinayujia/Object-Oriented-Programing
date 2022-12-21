//
//  main.cpp
//  1
//
//  Created by Selina on 27/01/2018.
//  Copyright © 2018 Selina. All rights reserved.
//

#include <iostream>

//
//  main.cpp
//  coway
//
//  Created by Selina on 26/01/2018.
//  Copyright © 2018 Selina. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> coway()
{
    ifstream ifs("life.txt");
    if (!ifs) {
        cout<<"Failed to open file"<<endl;
        
    }
    string line;
    vector<string> net;
    
    while (getline(ifs, line))
    {
        net.push_back(line);
        
    }
    ifs.close();
    vector<string> newnet;
    for(string s:net)
    {
        newnet.push_back(s);
    }
    for (size_t i=0;i< net.size();++i)
    {
        for (size_t j=0; j<net[i].size(); ++j)
        {
            
            if ((i==0 &&j==0) ||(i==0 && j==net[i].size()-1 )||(i==net.size()-1&&j==0 )||(i==net.size()-1)||(j==net[i].size()-1 ))
            {
                if( (i==0 &&j==0) && net[i][j]=='-' )
                {
                    if((net[i+1][j]=='*')&&(net[i+1][j+1]=='*')&&(net[i][j+1]=='*'))
                    {
                        newnet[i][j]='*';
                    }
                }
                if ((i==0 &&j==net[i].size()-1 )&&net[i][j]=='-' )
                {
                    if((net[i+1][j]=='*')&&(net[i+1][j-1]=='*')&&(net[i][j-1]=='*'))
                    {
                        newnet[i][j]='*';
                    }
                }
                if ((i==net.size()-1&&j==0 )&& net[i][j]=='-' )
                {
                    if((net[i-1][j]=='*')&&(net[i-1][j+1]=='*')&&(net[i][j+1]=='*'))
                    {
                        newnet[i][j]='*';
                    }
                }
                if ((i==net.size()-1&&j==net[i].size()-1 )&&net[i][j]=='-' )
                {
                    if((net[i-1][j-1]=='*')&&(net[i-1][j]=='*')&&(net[i][j-1]=='*'))
                    {
                        newnet[i][j]='*';
                    }
                }
            }
            
            else if( (i==0)||(i==net.size()-1)||(j==0)||(j==net[i].size()-1))
            {
                if((i==0)||(i==net.size()-1))
                {
                    int counter=0;
                    if (net[i][j-1]=='*' )
                    {
                        counter+=1;
                    }
                    if  (net[i][j+1]=='*')
                    {
                        counter+=1;
                    }
                    if(i==0)
                    {
                        for(size_t loopinx=j-1;loopinx<j+2;++loopinx)
                        {
                            if(net[i+1][loopinx]=='*')
                            {
                                counter+=1;
                            }
                        }
                    }
                    if(i==net.size()-1)
                    {
                        for(size_t loopinx=j-1;loopinx<j+2;++loopinx)
                        {
                            if(net[i-1][loopinx]=='*')
                            {
                                counter+=1;
                            }
                        }
                    }
                    if (counter>3 && net[i][j]=='*')
                    {
                        newnet[i][j]='-';
                    }
                    if (counter<2 && net[i][j]=='*')
                    {
                        newnet[i][j]='-';
                    }
                    if ((counter==3 && net[i][j]=='-'))
                    {
                        newnet[i][j]='*';
                    }
                    
                }
                else
                {
                    int counter=0;
                    if (net[i-1][j]=='*' )
                    {
                        counter+=1;
                    }
                    if  (net[i+1][j]=='*')
                    {
                        counter+=1;
                    }
                    if(j==0)
                    {
                        for(size_t loopinx=i-1;loopinx<i+2;++loopinx)
                        {
                            if(net[loopinx][j+1]=='*')
                            {
                                counter+=1;
                            }
                        }
                    }
                    if(j==net[i].size()-1)
                    {
                        for(size_t loopinx=i-1;loopinx<i+2;++loopinx)
                        {
                            if(net[loopinx][j-1]=='*')
                            {
                                counter+=1;
                            }
                        }
                    }
                    if (counter>3 && net[i][j]=='*')
                    {
                        newnet[i][j]='-';
                    }
                    if (counter<2 && net[i][j]=='*')
                    {
                        newnet[i][j]='-';
                    }
                    if ((counter==3 && net[i][j]=='-'))
                    {
                        newnet[i][j]='*';
                    }
                }  //else
            } //elseif
            
            else
            {
                int counter =0;
                if(net[i][j-1]=='*')
                {
                    counter+=1;
                }
                if(net[i][j+1]=='*')
                {
                    counter+=1;
                }
                
                for(size_t loopinx=j-1;loopinx<j+2;++loopinx)
                {
                    if(net[i-1][loopinx]=='*')
                    {
                        counter+=1;
                    }
                }
                for(size_t loopinx=j-1;loopinx<j+2;++loopinx)
                {
                    if(net[i+1][loopinx]=='*')
                    {
                        counter+=1;
                    }
                }
                if (counter>3 && net[i][j]=='*')
                {
                    newnet[i][j]='-';
                }
                if (counter<2 && net[i][j]=='*')
                {
                    newnet[i][j]='-';
                }
                if ((counter==3 && net[i][j]=='-'))
                {
                    newnet[i][j]='*';
                }
                
            }
            
        }
        
    }
    
    
    
    
    
    return newnet;
    
}




int main()
{
    vector<string> result=coway();
    for (size_t i=0;i<result.size();++i)
    {
        cout<<result[i]<<"\n"<<endl;
    }
    
}

