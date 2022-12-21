//
//  Course.hpp
//  rec7
//
//  Created by Selina on 09/03/2018.
//  Copyright © 2018 Selina. All rights reserved.
//

#ifndef Course_hpp
#define Course_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
namespace BrooklynPoly{
    class Student;
    class Course
    {
        friend std::ostream& operator<<(std::ostream& os, const Course& cour);
        std::string course_name;
        std::vector<Student*> students;
        public:
        Course(const \std::string& name):course_name(name){};
        const std::string& get_name() const;
        void add_student( Student* student);
        
        
    };
}

#endif /* Course_hpp */
