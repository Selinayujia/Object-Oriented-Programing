//
//  Student.cpp
//  rec7
//
//  Created by Selina on 09/03/2018.
//  Copyright © 2018 Selina. All rights reserved.
//

#include "Student.hpp"
#include "Course.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
namespace BrooklynPoly {
    
ostream& operator<<(ostream& os, const Student& stu)
{
    os<<"Student: "<<stu.get_name()<<endl;
    os<<"Course for this student: ";
    if(stu.classes.size()==0)
    {
        os<<"None"<<endl;
    }
    for(size_t i=0;i<stu.classes.size();++i)
    {
        os<<stu.classes[i]->get_name()<<' ';
    }
    os<<endl;
    return os;
    
}
    const string& Student:: get_name() const
    {
        return student_name;
    }
    
    void Student::dropCourse(const string& course_name)
    {
        for(size_t i=0; i<classes.size();++i)
        {
            if(classes[i]->get_name()==course_name)
            {
                Course* temp= classes[i];
                classes[i]=classes[classes.size()-1];
                classes[classes.size()-1]=temp;
                classes.pop_back();
            }
        }
        
        
    }
    
    
    void Student:: add_class(Course* course)
    {
        classes.push_back(course);
    }
    

}
