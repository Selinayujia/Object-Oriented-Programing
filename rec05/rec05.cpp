//
//  main.cpp
//  rec05
//
//  Created by Selina on 23/02/2018.
//  Copyright © 2018 Selina. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Section;
class LabWorker;


class Section
{
    

    class TimeSlot
    {
    public:
        friend ostream& operator<<(ostream& os, const TimeSlot& t)
        {
            string time_note=" ";
            int t_twl = t.get_time();
            if(t_twl>=12)
            {
                if( t_twl > 12)
                {
                    t_twl=t_twl-12;
                }
                time_note = "pm";
            }
            else
            {
                time_note = "am";
            }
            os << " Time slot: [Day: "<< t.get_day() <<" , Start time: "<< t_twl << time_note << ']';
            return os;
        }
    

        TimeSlot(string d_of_w, int time):d_of_w(d_of_w),time(time){}
        
        string get_day() const
        {
            return d_of_w;
        }
        
        int get_time() const
        {
            return time;
        }
        
    private:
        string d_of_w;
        int time;
        
    };
    
   
    
    class Student
    {
    public:
        friend ostream& operator<<(ostream& os, const Student& s)
        {
            os<<"Name: "<<s.get_name()<<" , Grade: ";
            for (size_t i =0; i<s.get_grade().size(); ++i)
            {
                os<<s.get_grade()[i]<<' ';
            }
            return os;
            
        }
        Student(string name):s_name(name)
        {
            for(size_t i=0; i<14; ++i)
            {
                score.push_back(-1);
            }
        }
        
    
        
        string get_name() const
        {
            return s_name;
        }
        
        vector<int> get_grade() const
        {
            return score;
        }
        void change_grade(size_t week, int g)
        {
            score[week-1]= g;
        }
        
        void set_scores(const vector<int>& n_score)
        {
            score=n_score;
        }
        
    private:
        string s_name;
        vector<int> score;
        
    };
    

    
    string name;
    TimeSlot time;
    vector<Student*> sec_class;
    
public:
  
    Section(string name, string d_of_w, int time):name(name),time(d_of_w, time){}
    Section(const Section &before):name(before.name),time(before.get_day(), before.get_time())
    {
        vector<Student*> old_sec= before.get_sec_class();
        for(size_t i=0;i<old_sec.size();++i)
        {
            
            string new_name= old_sec[i]->get_name();
            vector<int> scores= old_sec[i]->get_grade();
            Student* s= new Student(name);
            s->set_scores(scores);
            sec_class.push_back(s);
            
        }
        
    }
    ~Section()
    {
        cout<<"Section "<<name<<" is being deleted"<<endl;
        for(size_t i=0; i<sec_class.size();++i)
        {
            cout<<"Deleting "<<sec_class[i]->get_name()<<endl;
            delete sec_class[i];
            
        }
        
        sec_class.clear();
    }
    
    void display() const
    
    {
        cout<<"Section: "<<name<< time<< "Students: "<<endl;
        for (size_t i =0; i<sec_class.size(); ++i)
        {
            cout<<*sec_class[i]<<endl;
        }
    }
        
    string get_name() const
    {
        return name;
    }
    string get_day() const
    {
        return time.get_day();
    }
    int get_time() const
    {
        return time.get_time();
    }
    
    vector<Student*> get_sec_class() const
    {
        return sec_class;
    }
    void set_student_grade(const string& name, int grade, int week)
    {
        for(size_t i =0; i<sec_class.size(); ++i)
        {
            if(sec_class[i]->get_name()==name)
            {
                sec_class[i]->change_grade(week, grade);
            }
        }
    }
    void addStudent(const string& name)
    {
        Student* s = new Student(name);
        sec_class.push_back(s);
        
    }
};


class LabWorker
{

public:
    LabWorker(string name):name(name){}
   
    void display() const
    {
        if (sec!=nullptr)
        {
            cout << name << " has " ;
            sec->display();
            cout << endl;
        }
        else
        {
            cout << name << " does not have a section"<<endl;
        }
    
    }
    
    
    void addSection(Section& sect)
    {
        sec = &sect;
    }
    
    void addGrade(const string& name, int grade, int week)
    {
        sec->set_student_grade(name, grade, week);
    }
    
private:
    string name;
    Section* sec=nullptr;
    
};



void doNothing(Section sec) { sec.display(); }

int main() {
    
    cout << "Test 1: Defining a section\n";
    Section secA2("A2", "Tuesday", 16);
    secA2.display();
    
    cout << "\nTest 2: Adding students to a section\n";
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    secA2.display();
    
    cout << "\nTest 3: Defining a lab worker.\n";
    LabWorker moe( "Moe" );
    moe.display();
    
    cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection( secA2 );
    moe.display();
    
    cout << "\nTest 5: Adding a second section and lab worker.\n";
    LabWorker jane( "Jane" );
    Section secB3( "B3", "Thursday", 11 );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    jane.addSection( secB3 );
    jane.display();
    
    cout << "\nTest 6: Adding some grades for week one\n";
    moe.addGrade("John", 17, 1);
    moe.addGrade("Paul", 19, 1);
    moe.addGrade("George", 16, 1);
    moe.addGrade("Ringo", 7, 1);
    moe.display();
    
    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    moe.addGrade("John", 15, 3);
    moe.addGrade("Paul", 20, 3);
    moe.addGrade("Ringo", 0, 3);
    moe.addGrade("George", 16, 3);
    moe.display();
    
    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all those students (or rather their records?)\n";
    
    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, then make sure the following call works\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n";
    
} // main
