//
//  polynomial.cpp
//  hw08
//
//  Created by Selina on 2018/5/2.
//  Copyright © 2018 Selina. All rights reserved.
//

#include <stdio.h>
#include "polynomial.h"
#include <vector>
#include <iostream>
using namespace std;
class Polynomial;


Node::Node(int data, Node* next) : data(data), next(next) {}
int Node::getData() const { return data; }
Node* Node::getNext() { return next; }
void Node::setData(int data) { this->data = data; }
void Node::setNext(Node* next) { this->next = next; }



Polynomial::Polynomial(vector<int> input)
{
    
    degree=int(input.size()-1);
    headptr=new Node();
    int counter= degree;
    while (counter>=0)
    {
        listAddTail(headptr, input[counter]);
        counter--;
    }
}
Polynomial::Polynomial()
{
    degree=0;
    headptr=new Node();
}
Polynomial::Polynomial(const Polynomial& rhs)
{
    degree=rhs.degree;
    Node* start_node=rhs.headptr->getNext();
    headptr=new Node();
    int counter= degree;
    while (counter>=0)
    {
        listAddTail(headptr,start_node->getData());
        counter--;
        start_node=start_node->getNext();
    }
};
Polynomial::~Polynomial()
{
    while(headptr!=nullptr)
    {
        delete headptr;
        headptr=headptr->getNext();
    }
}
Polynomial& Polynomial::operator=(const Polynomial& rhs)
{
    if(this!=&rhs)
    {
        while(headptr!=nullptr)
        {
            delete headptr;
            headptr=headptr->getNext();
        }
        degree=rhs.degree;
        Node* start_node=rhs.headptr->getNext();
        headptr=new Node();
        int counter= degree;
        while (counter>=0)
        {
            listAddTail(headptr,start_node->getData());
            counter--;
            start_node=start_node->getNext();
        }
    }
    return *this;
}
Polynomial& Polynomial::operator+=(const Polynomial& rhs)
{
    Node* p1=headptr;
    Node* p2=rhs.headptr;
    while(p1!=nullptr&&p2!=nullptr)
    {
        p1->setData(p1->getData()+p2->getData());
        p1=p1->getNext();
        p2=p2->getNext();
    }
    if(rhs.degree>degree)
    {
        while(p2!=nullptr)
        {
            listAddTail(headptr, p2->getData());
            p2=p2->getNext();
        }
    }
    return *this;
}
int Polynomial::evaluate(int input)
{
    bool first=true;
    int multi=input;
    int result=0;
    Node* p=headptr;
    while(p->getNext()!=nullptr)
    {
        p=p->getNext();
        if (first)
        {
            result+=p->getData();
            first=false;
        }
        else
        {
            result+=p->getData()*multi;
            multi*=input;
        }
    }
    return result;
}



int listLength(Node* headPtr) {
    Node* p = headPtr;
    int count = 0;
    while (p != nullptr) {
        ++count;
        p = p->getNext();
    }
    return count;
}

void listAddTail(Node* headPtr, int data) {
    Node* last = headPtr;
    while (last->getNext()!=nullptr) {
        last = last->getNext();
    }
    last->setNext(new Node(data));
}
void listDisplay(Node* headPtr) {
    
    Node* p = headPtr;
    while (p)
    {
        cout << p->getData() << ' ';
        p = p->getNext();
    }
    cout << endl;
}

void display(Node* headptr, int counter)
{
    if(headptr==nullptr)
    {
        return;
    }
    else
    {
        if(headptr->getNext()==nullptr&&counter==-1)
        {
            cout<<"0";
            return;
        }
        Node* next_ptr=headptr->getNext();
        display(next_ptr,counter+1);
        if(headptr->getData()!=0)
        {
            if (counter==0)
            {
                cout<<headptr->getData();
            }
            else
            {
                if(headptr->getData()==1|| counter==1)
                {
                    if (headptr->getData()==1)
                    {
                        cout<<"x";
                    }
                    else
                    {
                        cout<<headptr->getData()<<"x";
                    }
                    if(counter==1)
                    {
                        cout<<"+";
                    }
                    else
                    {
                        cout<<"^"<<counter<<"+";
                    }
                    return;
                }
                cout<<headptr->getData()<<"x^"<<counter<<"+";
                
            }
        }
    }
}
ostream& operator<<(ostream& os, const Polynomial& poly)
{
    //Node* realStart=poly.headptr->getNext();
    display(poly.headptr);
    return os;
}
bool operator==(const Polynomial& lhs, const Polynomial& rhs)
{
    if(lhs.degree!=rhs.degree)
    {
        return false;
    }
    else
    {
        Node* p1=lhs.headptr->getNext();
        Node* p2=rhs.headptr->getNext();
        while(p1!=nullptr && p2!=nullptr)
        {
            if(p1->getData()!=p2->getData())
            {
                return false;
            }
            p1=p1->getNext();
            p2=p2->getNext();
        }
    }
    return true;
}
Polynomial operator+(const Polynomial& lhs,const Polynomial& rhs)
{
    Polynomial result=lhs;
    result+=rhs;
    return result;
}

bool operator!=(const Polynomial& lhs, const Polynomial& rhs)
{
    return (!operator==(lhs,rhs));
}


void doNothing(Polynomial temp) {}


