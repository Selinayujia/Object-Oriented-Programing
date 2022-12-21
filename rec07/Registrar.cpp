//
//  Registrar.cpp
//  rec7
//
//  Created by Selina on 09/03/2018.
//  Copyright © 2018 Selina. All rights reserved.
//

#include "Registrar.hpp"
#include "Course.hpp"
#include "Student.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
namespace BrooklynPoly{
    ostream& operator<<(ostream& os, const Registrar& regi)
    {
        os<<"Courses:"<<endl;
        if(regi.all_courses.size()==0)
        {
            os<<"None"<<endl;
        }
        else
        {
            
            for(size_t i=0; i<regi.all_courses.size();++i)
            {
                cout<<*regi.all_courses[i]<<endl;
            }
        }
        os<<"Student:"<<endl;
        if(regi.all_students.size()==0)
        {
            os<<"None"<<endl;
        }
        else
        {
            for(size_t ind=0; ind<regi.all_students.size(); ++ind)
            {
                
                cout<<*regi.all_students[ind]<<endl;
                
            }
        }
        return os;
    }
    
    
    void Registrar::addCourse(const string& course_name)
    {
        Course* aCourse= new Course(course_name);
        all_courses.push_back(aCourse);
    }
    void Registrar::addStudent(const string& student_name)
    {
        Student* aStudent= new Student(student_name);
        all_students.push_back(aStudent);
        
    }
    void Registrar::enrollStudentInCourse(const string& student_name,const string& course_name)
    {
        bool if_student=false;
        for(size_t i=0; i<all_students.size();++i)
        {
            if(all_students[i]->get_name()==student_name)
            {
                if_student=true;
            }
        }
        if(if_student==false)
        {
            cout<<"No such student"<<endl;
        }
        else
        {
            bool if_class=false;
            for(size_t i=0; i<all_courses.size();++i)
            {
                if(all_courses[i]->get_name()==course_name)
                {
                    if_class=true;
                }
            }
            if(if_class==false)
            {
                cout<<"No such class"<<endl;
            }
            else
            {
                for(size_t i=0; i<all_students.size();++i)
                {
                    if(all_students[i]->get_name()==student_name)
                    {
                        for(size_t ind=0; ind<all_courses.size();++ind)
                        {
                            if(all_courses[ind]->get_name()==course_name)
                            {
                                all_students[i]->add_class(all_courses[ind]);
                                all_courses[ind]->add_student(all_students[i]);
                            }
                            
                        }
                    }
                }
            }
        }
        
        
        
    }
    
    void Registrar::cancelCourse(const string& course_name)
    {
        bool if_course=false;
        for(size_t ind=0; ind<all_courses.size();++ind)
        {
            if(all_courses[ind]->get_name()==course_name)
            {
                if_course=true;
            }
        }
        if(if_course==false)
        {
            cout<<"No such course!"<<endl;
        }
        else
        {
            
            
            for(size_t i=0; i<all_students.size();++i)
            {
                all_students[i]->dropCourse(course_name);
            }
            
            
            for(size_t ind=0; ind<all_courses.size();++ind)
            {
                if(all_courses[ind]->get_name()==course_name)
                {
                    Course* temp= all_courses[ind];
                    all_courses[ind]=all_courses[all_courses.size()-1];
                    all_courses[all_courses.size()-1]=temp;
                    delete all_courses[ind];
                    all_courses.pop_back();
                }
            }
        }
    }
    void Registrar::purge()
    {
        for(size_t i=0;i<all_courses.size();++i)
        {
            delete all_courses[i];
        }
        all_courses.clear();
        
        for(size_t i=0;i<all_students.size();++i)
        {
            delete all_students[i];
        }
        all_students.clear();
    }
}
