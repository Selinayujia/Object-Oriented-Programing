//
//  Rational.cpp
//  rec08
//
//  Created by Selina on 23/03/2018.
//  Copyright © 2018 Selina. All rights reserved.
//

#include <stdio.h>
#include "Rational.h"
using namespace std;
namespace CS2124
{

    ostream& operator<<(ostream& os, const Rational& ration)
    {
            os<<ration.num<<"/"<<ration.deno<<endl;
            return os;
    }
    istream& operator>>(istream& is, Rational& ration)
        {
            int anum;
            int adeno;
            char slash;
            is>>anum>>slash>>adeno;
            int com_div;
            com_div= ration.greatestCommonDivisor(anum, adeno);
            ration.num=anum/com_div;
            ration.deno=adeno/com_div;
            
            return is;
        }
        
    
    
        Rational::Rational(int num,int deno):num(num),deno(deno)
        {
            int com_div= this->greatestCommonDivisor(num, deno);
            this->num=num/com_div;
            this->deno=deno/com_div;
        }
        Rational&  Rational::operator+=(const Rational& added)
        {
            int denos=this->deno*added.deno;
            int f_num=this->num*added.deno;
            int s_num=this->deno*added.num;
            int com_div= this->greatestCommonDivisor(f_num+s_num, denos);
            this->num=(f_num+s_num)/com_div;
            this->deno=denos/com_div;
            return *this;
            
        }
        Rational&  Rational::operator++()
        {
            num+=deno;
            return *this;
        }
        Rational Rational::operator++(int)
        {
            Rational result=*this;
            num+=deno;
            return result;
        }
        int  Rational::greatestCommonDivisor(int x, int y) {
            while (y != 0) {
                int temp = x % y;
                x = y;
                y = temp;
            }
            return x;
        }
        Rational::operator bool()const
        {
            return num!=0;
        }
        

    
    
    Rational operator+(const Rational& lhs,const Rational& rhs)
    {
        Rational result=lhs;
        result+=rhs;
        return result;
    }
    
    bool operator==(const Rational& lhs,const Rational& rhs)
    {
        return lhs.deno==rhs.deno&&lhs.num==rhs.num;
    }
    
    bool operator!=(const Rational& lhs,const Rational& rhs)
    {
        return !(lhs==rhs);
    }
    
    Rational& operator--(Rational& rhs)
    {
        return rhs+=-1;
    }
    Rational operator--(Rational& rhs, int)
    {
        Rational result= rhs;
        rhs+=1;
        return result;
    }

}
