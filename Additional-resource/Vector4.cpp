/*
  Vector Class
  Demonstrates:
     Good example of copy control
     Dynamic arrays and pointer arithmetic
     Square bracket operator
     Implementation of an important data structure
  Sec C
 */
#include <iostream>
using namespace std;

class Elephant {};

template <typename Fred>
class Vector {
public:
    class Iterator {
        friend bool operator!=(const Iterator& lhs, const Iterator& rhs) {
            return lhs.p != rhs.p; // compare pointer that they hold
            //return *lhs.p != *rhs.p; // compare data
            //return &lhs != &rhs;   // are they the same iterator
        }
    public:
        Iterator(Fred* p) : p(p) {}
        Iterator& operator++() { 
            ++p; 
            return *this;
        }
        Fred& operator*() { return *p; }
        const Fred& operator*() const { return *p; }
    private:
        Fred* p;
    };

    
    // default constructor
    Vector() : data(nullptr), theSize(0), theCapacity(0)  {}
    explicit Vector(size_t howMany, Fred val=Fred())
    {
        theSize = howMany;
        theCapacity = howMany;
        data = new Fred[howMany];
        for (size_t i = 0; i < theSize; ++i) {
            data[i] = val;
        }
    }

    // Copy control
    ~Vector() {
        delete [] data;
    }
    Vector(const Vector& rhs) {
        theSize = rhs.theSize;
        theCapacity = rhs.theCapacity;
        data = new Fred[theCapacity];
        for (size_t i = 0; i < theSize; ++i) {
            data[i] = rhs.data[i];
        }
    }
    // lhs = rhs
    Vector& operator=(const Vector& rhs) {
        if (this != &rhs) {
            // Free up the old (destructor)
            delete [] data;
            // Allocate new
            data = new Fred[rhs.theCapacity];
            // Copy all the stuff
            theSize = rhs.theSize;
            theCapacity = rhs.theCapacity;
            for (size_t i = 0; i < theSize; ++i) {
                data[i] = rhs.data[i];
            }
        }
        // Return ourselves
        return *this;
    }


    void push_back(int val) {
        if (theSize == theCapacity) {
            if (data == nullptr) {
                data = new Fred[1];
                theCapacity = 1;
            } else {
                int* oldData = data;
                data = new Fred[2*theCapacity];
                for (size_t i = 0; i < theSize; ++i) {
                    data[i] = oldData[i];
                }
                delete [] oldData;
                theCapacity *= 2;
            }
        }
        data[theSize] = val;
        ++theSize;
    }

    size_t size() const { return theSize; }
    void pop_back() { --theSize; }

    void clear() { theSize = 0; };


    // Square brackets?
    const Fred& operator[](size_t index) const {
        return data[index];
    }
    Fred& operator[](size_t index) {
        return data[index];
    }
    
    Iterator begin() { 
        Iterator result(data);
        return result; 
    }
    Iterator end() { return Iterator(data + theSize); }

    const Iterator begin() const { 
        Iterator result(data);
        return result; 
    }
    const Iterator end() const { return Iterator(data + theSize); }

private:
    Fred* data;
    size_t theSize;
    size_t theCapacity;
};


void printVector(const Vector<int>& vec) {
    //*vec.begin() = 17; // const version won't allow this.
    for (int val : vec) {
        cout << val << ' ';
    }
    cout << endl;
}

template <typename Mary>
void printVector(const Vector<Mary>& vec) {
    for (const Mary& val : vec) {
        cout << val << ' ';
    }
    cout << endl;
}


int main() {

    // Not templated.  Our Vector class can only hold ints.
    Vector<int> v;  

    v.push_back(17);
    v.push_back(42);
    v.push_back(6);
    v.push_back(28);
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
        //cout << v.operator[](i) << endl;
    }
    cout << endl;
    
    v[0] = 100;

    //    v[0];
    //Vector v2(v);
    Vector<int> v2 = v;
    for (size_t i = 0; i < v2.size(); ++i) {
        cout << v2[i] << ' ';
    }
    cout << endl;

    Vector<int> v3;
    v3 = v;

    //v3 = 17;
    v3 = Vector<int>(17);

    // Won't compile without further stuff
    cout << "===============\n";
    cout << "Ranged for on vector:\n";
    for (int val : v2) {
        cout << val << ' ';
    }
    cout << endl;

    for (Vector<int>::Iterator iter = v2.begin(); iter != v2.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;

    cout << "===============\n";
    cout << "Passing vector by const-ref and printing:\n";
    printVector(v2);

    Vector<Elephant> ve;
    //printVector(ve);

    //sort(v2.begin(), v2.end());
}

