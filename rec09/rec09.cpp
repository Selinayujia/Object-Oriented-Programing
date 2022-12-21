//
//  main.cpp
//  rec09
//
//  Created by Selina on 30/03/2018.
//  Copyright © 2018 Selina. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class PrintedMaterial {
    friend ostream& operator<<(ostream& os, const PrintedMaterial& pm)
    {
        pm.displayNumPages();
        

        return os;
    }
    
public:
    PrintedMaterial(unsigned pagenumber):pagenumber(pagenumber){}
    virtual void displayNumPages() const=0;

protected:
private:
    unsigned pagenumber;
};

void PrintedMaterial::displayNumPages() const
{
    cout<<pagenumber;
}

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned pagenumber):PrintedMaterial(pagenumber){}
    void displayNumPages() const
    {
        this->PrintedMaterial::displayNumPages();
    }
protected:
private:
    
};

class Book : public PrintedMaterial {
public:
    void displayNumPages() const
    {
         this->PrintedMaterial::displayNumPages();
    }
    
    Book(unsigned pagenumber):PrintedMaterial(pagenumber){}
//    virtual void displayNumPages()const =0;
protected:
private:
};

class TextBook : public Book {
public:
    TextBook(unsigned pagenumber, unsigned numOfIndexPages):Book(pagenumber),numOfIndexPages(numOfIndexPages){}
        void displayNumPages() const
        {
            cout<<"Page number: ";
            this->PrintedMaterial::displayNumPages();
            cout << "Index of page: "<<numOfIndexPages<<endl;
        }
protected:
    
private:
    unsigned numOfIndexPages;

};

class Novel : public Book {
public:
    Novel(unsigned pagenumber):Book(pagenumber){}
    
protected:
private:

};

// tester/modeler code
int main()
{
//    PrintedMaterial p(123);
    TextBook t(2110,123);
    Novel n(5340);
    Magazine m(231);
//    t.displayNumPages();
//    m.displayNumPages();
//    n.displayNumPages();
//    cout<<t;
//    cout<<m;
//    cout<<n;
//    PrintedMaterial pm = t; // like putting a t into a vector of PrintedMaterials
//    pm.displayNumPages();
    
//
//    vector<PrintedMaterial> pM;
//    pM.push_back(t);
//    pM.push_back(m);
//    pM[0].displayNumPages();
//    pM[1].displayNumPages();
    
    vector<PrintedMaterial*> pM;
    pM.push_back(&t);
    pM.push_back(&m);
    pM[0]->displayNumPages();
    pM[1]->displayNumPages();
    
//    Magazine x=p;
//    Magazine* x=&p;
    
    
}
