//
//  Registrar.hpp
//  rec7
//
//  Created by Selina on 09/03/2018.
//  Copyright © 2018 Selina. All rights reserved.
//

#ifndef Registrar_hpp
#define Registrar_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
namespace BrooklynPoly{
    class Course;
    class Student;
class Registrar
{
    friend std::ostream& operator<<(std::ostream& os, const Registrar& regi);
    std::vector<Course*>all_courses;
    std::vector<Student*>all_students;
    public:
    Registrar(){};
    void addCourse(const std::string& course_name);
    void addStudent(const std::string& student_name);
    void enrollStudentInCourse(const std::string& student_name, const std::string& course_name);
    void cancelCourse(const std::string& course_name);
    void purge();
    
    
};
}

#endif /* Registrar_hpp */
