//
//  polynomial.h
//  hw11
//
//  Created by Selina on 2018/5/2.
//  Copyright © 2018 Selina. All rights reserved.
//

#ifndef polynomial_h
#define polynomial_h
#include <vector>
#include <iostream>

struct Node {
public:
    Node(int data = 0, Node* next = nullptr);
    int getData() const;
    Node* getNext();
    void setData(int data);
    void setNext(Node* next);
private:
    int data;
    Node* next;
};

class Polynomial
{
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly);
    friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
public:
    Polynomial(std::vector<int> input);
    Polynomial();
    Polynomial(const Polynomial& rhs);
    ~Polynomial();
    Polynomial& operator=(const Polynomial& rhs);
    Polynomial& operator+=(const Polynomial& rhs);
    int evaluate(int input);
private:
    int degree;
    Node* headptr;
};



int listLength(Node* headPtr);
void listAddTail(Node* headPtr, int data);
void listDisplay(Node* headPtr);
void display(Node* headptr, int counter=-1);
Polynomial operator+(const Polynomial& lhs,const Polynomial& rhs);
bool operator!=(const Polynomial& lhs, const Polynomial& rhs);
void doNothing(Polynomial temp);

#endif /* polynomial_h */
