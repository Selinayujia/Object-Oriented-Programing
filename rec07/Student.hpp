//
//  Student.hpp
//  rec7
//
//  Created by Selina on 09/03/2018.
//  Copyright © 2018 Selina. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp


#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
namespace BrooklynPoly{
    class Course;
    class Student
    {
        friend std::ostream& operator<<(std::ostream& os, const Student& stu);
        std::string student_name;
        std::vector<Course*> classes;
        public:
        Student(const std::string& name):student_name(name){};
        const std::string& get_name() const;
        void add_class(Course* course);
        void dropCourse(const std::string& course_name);
        
    };
    
}
#endif /* Student_hpp */
