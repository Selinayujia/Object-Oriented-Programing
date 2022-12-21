//
//  Rational.h
//  rec08
//
//  Created by Selina on 23/03/2018.
//  Copyright © 2018 Selina. All rights reserved.
//

#ifndef Rational_h
#define Rational_h
#include <iostream>
namespace CS2124
{
    class Rational
    {
        friend bool operator==(const Rational& lhs,const Rational& rhs);
        friend std::ostream& operator<<(std::ostream& os, const Rational& ration);
        friend std::istream& operator>>(std::istream& is, Rational& ration);
        
        public:
   
        Rational(int num = 0,int deno = 1);

        Rational& operator+=(const Rational& added);
        Rational& operator++();
        Rational operator++(int);
        int greatestCommonDivisor(int x, int y);
        explicit operator bool()const;
        
        private:
        int num;
        int deno;
    };
    
    Rational operator+(const Rational& lhs,const Rational& rhs);
    
    bool operator==(const Rational& lhs,const Rational& rhs);
    bool operator!=(const Rational& lhs,const Rational& rhs);
    
    Rational& operator--(Rational& rhs);
    Rational operator--(Rational& rhs, int);
    


}

#endif /* Rational_h */
