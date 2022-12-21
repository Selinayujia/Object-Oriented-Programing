//
//  Course.cpp
//  rec7
//
//  Created by Selina on 09/03/2018.
//  Copyright © 2018 Selina. All rights reserved.
//

#include "Course.hpp"
#include "Student.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
namespace BrooklynPoly {

    ostream& operator<<(ostream& os, const Course& cour)
    {
        os<<"Course: "<<cour.get_name()<<endl;
        os<<"Student in this course: ";
        if(cour.students.size()==0)
        {
            os<<"None"<<endl;
        }
        for(size_t i=0;i<cour.students.size();++i)
        {
            os<<cour.students[i]->get_name()<<' ';
        }
        os<<endl;
        return os;
    }
    const string& Course:: get_name() const
    {
        return course_name;
    }
    
    void Course:: add_student(Student* student)
    {
        students.push_back(student);
    }

}

