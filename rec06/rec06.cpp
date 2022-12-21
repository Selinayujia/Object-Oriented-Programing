/*
 Recitation 06
 CS2124
 
 Focus: Dynamic arrays and copy control.
 */

#include <string>
#include <iostream>
using namespace std;

class Position {
    public:
    Position(const string& aTitle, double aSalary)
    : title(aTitle), salary(aSalary) {}
    const string& getTitle() const { return title; }
    double getSalary() const { return salary; }
    void changeSalaryTo(double d) { salary = d; }
    void display(ostream& os = cout) const {
        os << '[' << title << ',' << salary << ']';
    }
    private:
    string title;
    double salary;
}; // class Position

class Entry {
    public:
    Entry(const string& aName, unsigned aRoom, unsigned aPhone,
          Position& aPosition)
    : name(aName), room(aRoom), phone(aPhone), pos(&aPosition) {
    }
    void display(ostream& os = cout) const {
        os << name << ' ' << room << ' ' << phone << ", ";
        pos->display(os);
    }
    const string& getName() const { return name; }
    const unsigned& getPhone() const { return phone;}
    private:
    string name;
    unsigned room;
    unsigned phone;
    Position* pos;
}; // class Entry

class Directory {
    public:
    friend ostream& operator<<(ostream& os, const Directory& direc)
    {
        Entry** en=direc.entries;
        for (size_t i =0; i<direc.size; ++i)
        {
            en[i]->display(os);
        }
        return os;
        
    }
    
    Directory()
    {
        size=0;
        capacity=1;
        entries=new Entry*[capacity];
    };
    
    Directory(const Directory& rhs)
    {
        size=rhs.size;
        capacity=rhs.capacity;
        entries= new Entry* [capacity];
        for(size_t i=0;i<size;++i)
        {
            Entry* en= new Entry(*rhs.entries[i]);
            entries[i]=en;
        }
        
        
    }
    ~Directory()
    {
        for(size_t i=0;i<size;++i)
        {
            delete entries[i];
        }
        delete[] entries;
        
    }
    Directory& operator=(const Directory& rhs)
    {
        if(this != &rhs)
        {
            delete[] entries;
        
        size=rhs.size;
        capacity=rhs.capacity;
        entries=new Entry*[capacity];
        for(size_t i=0;i<size;++i)
        {
            Entry* en= new Entry(*rhs.entries[i]);
            entries[i]=en;
        }
        }
        return *this;
    }
    

    
    
    void add(const string& name, unsigned room, unsigned ph, Position& pos) {
        if (size == capacity)
        {
            Entry** old_entries= entries;
            entries= new Entry* [capacity*2 ];
            capacity *=2;
            for(size_t i=0;i<size;++i)
            {
                entries[i]=old_entries[i];
            }
            delete[] old_entries;
            entries[size] = new Entry(name, room, ph, pos);
            ++size;
            
        }
        else
        {
            entries[size] = new Entry(name, room, ph, pos);
            ++size;
        }

        
        
    } // add
    
    void display(ostream& os = cout) const {
        for (size_t i = 0; i < size; ++i) {
            entries[i]->display(os);
            os << endl;
        }
    }
    unsigned operator[](const string& name) const  //getter x=v[i].....
    {
        for(size_t i=0;i<size;++i)
        {
            if(entries[i]->getName()==name)
            {
                return entries[i]->getPhone();
            }
        }
        return 0;
    }
    
    private:
    Entry** entries = nullptr;
    size_t size = 0;
    size_t capacity = 0;
}; // class Directory

void doNothing(Directory dir) { dir.display(); }

int main() {
    
    // Note that the Postion objects are NOT on the heap.
    Position boss("Boss", 3141.59);
    Position pointyHair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);
    
    // Create a Directory
    Directory d;
    d.add("Marilyn", 123, 4567, boss);
    d.display();
    
    Directory d2 = d;    // What function is being used??
    d2.add("Gallagher", 111, 2222, techie);
    d2.add("Carmack", 314, 1592, techie);
    d2.display();
    
    cout << "Calling doNothing\n";
    doNothing(d2);
    cout << "Back from doNothing\n";
    
    Directory d3;
    d3 = d2;
    
    // Should display 1592
    cout << d2["Carmack"] << endl;
    
} // main

