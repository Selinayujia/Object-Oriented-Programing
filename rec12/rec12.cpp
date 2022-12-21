//
//  main.cpp
//  rec 12
//
//  Created by Selina on 20/04/2018.
//  Copyright © 2018 Selina. All rights reserved.
//

// Doubly linked list
//  Test code


#include <cstdlib>
#include <iostream>
using namespace std;

class List
{
  
friend ostream& operator<<(ostream& os, const List& list)
    {
        Node* cursor=list.head;
        os<<"[";
        while(cursor->next!=list.tail)
        {
            cursor=cursor->next;
            os<<cursor->data<<" ";
        }
        os<<"]";
        return os;
    }
public:
    struct Node;
    class iterator {
        friend class List;
        friend bool operator!=(const iterator& lhs, const iterator& rhs) {
            return lhs.p != rhs.p; // compare pointer that they hold
            //return *lhs.p != *rhs.p; // compare data
            //return &lhs != &rhs;   // are they the same iterator
        }
    public:
        iterator(Node* p) : p(p) {}
        iterator& operator++() {
            p=p->next;
            return *this;
        }
        int& operator*() { return p->data; }
        const int operator*() const { return p->data; }
    private:
        Node* p;
    };

    struct Node
    {
        Node(int data=0,Node* prev=nullptr,Node* next=nullptr):data(data),prev(prev),next(next){}
        int data;
        Node* prev;
        Node* next;
    };
    List()
    {
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->prev=head;
    }
    List(const List& list)
    {
        sizeoflist=0;
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->prev=head;
        Node* cursor= list.head->next;
        while(cursor!=list.tail)
        {
            push_back(cursor->data);
            cursor=cursor->next;
        }
    }
    ~List()
    {
        this->clear();
        delete head;
        delete tail;
    }
    
    List& operator=(List& rhs)
    {
        if(this!=&rhs)
        {
            this->clear();
            delete head;
            delete tail;
            sizeoflist=0;
            head=new Node();
            tail=new Node();
            head->next=tail;
            tail->prev=head;
            Node* cursor= rhs.head->next;
            while(cursor!=rhs.tail)
            {
                this->push_back(cursor->data);
                cursor=cursor->next;
            }
        }
        return *this;
    }
    int size() const
    {
        return sizeoflist;
    }
    
    int front() const
    {
        if(sizeoflist==0)
        {
            cout<<"empty list"<<endl;
            return -1;
            
        }
        return head->next->data;
    }
    int back() const
    {
        if(sizeoflist==0)
        {
            cout<<"empty list"<<endl;
            return -1;
        }
        return tail->prev->data;
    }
    void push_front(int num)
    {
        Node* newone=new Node(num,head,head->next);
        head->next->prev=newone;
        head->next=newone;
        sizeoflist++;
    }
    void push_back(int num)
    {
        Node* newone=new Node(num,tail->prev,tail);
        tail->prev->next=newone;
        tail->prev=newone;
        sizeoflist++;
    }
    void pop_front()
    {
        if (sizeoflist==0)
        {
            cout<<"empty list"<<endl;
        }
        else
        {
            Node* to_del= head->next;
            to_del->next->prev=head;
            head->next=to_del->next;
            delete to_del;
            sizeoflist--;
            
        }
    }
    void pop_back()
    {
        if (sizeoflist==0)
        {
             cout<<"empty list"<<endl;
        }
        else
        {
            Node* to_del= tail->prev;
            to_del->prev->next=tail;
            tail->prev=to_del->prev;
            delete to_del;
            sizeoflist--;
            
        }
    }
    iterator insert(iterator pos,int num)
    {
        Node* newone=new Node(num,pos.p->prev,pos.p);
        pos.p->prev->next=newone;
        pos.p->prev=newone;
        sizeoflist++;
        iterator result(newone);
        return result;
    }
    iterator erase(iterator pos)
    {
       
        Node* to_del=pos.p;
        to_del->prev->next=to_del->next;
        to_del->next->prev=to_del->prev;
        iterator result(to_del->next);
        delete to_del;
        sizeoflist--;
        return result;
            
        }
    void clear()
    {
        Node* cursor=head->next;
        while(cursor!=tail)
        {
            delete cursor;
            cursor=cursor->next;
        }
        head->next=tail;
        tail->prev=head;
        sizeoflist=0;
    }
    const int operator[](size_t index) const {
        if(index>sizeoflist-1)
        {
            cout<<"Index out of range!"<<endl;
            return -1;
        }
        
        Node* result= head->next;
        size_t count=0;
        while (count!=index)
        {
            result=result->next;
            count++;
        }
        return result->data;
    }
    int& operator[](size_t index) {
        if(index>sizeoflist-1)
        {
            cout<<"Index out of range!"<<endl;
            return head->data;
        }
        else
        {
        Node* result= head->next;
        size_t count=0;
        while (count!=index)
        {
            result=result->next;
            count++;
        }
        return result->data;
        }
        
    }
    
   
    
    iterator begin() {
        iterator result(head->next);
        return result;
    }
    iterator end() { return iterator(tail); }
    
    const iterator begin() const {
        iterator result(head->next);
        return result;
    }
    const iterator end() const { return iterator(tail); }
    
    
    
    
    
    
private:
    Node* head;
    Node* tail;
    int sizeoflist=0;
    

    
    
};

void printListInfo(List& myList) {
    cout << "size: " << myList.size()
    << ", front: " << myList.front()
    << ", back(): " << myList.back()
    << ", list: " << myList << endl;
}

// Task 8
void doNothing(List aList) {
    cout << "In doNothing\n";
    printListInfo(aList);
    cout << endl;
    cout << "Leaving doNothing\n";
}

int main() {
    
    // Task 1
    cout << "\n------Task One------\n";
    List myList;
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList.push_back(" << i*i << ");\n";
        myList.push_back(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_back\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_back();
    }
    cout << "===================\n";
    
    // Task2
    cout << "\n------Task Two------\n";
    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList2.push_front(" << i*i << ");\n";
        myList.push_front(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_front\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_front();
    }
    cout << "===================\n";

    // Task3
    cout << "\n------Task Three------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i*i);
    }
    printListInfo(myList);
    cout << "Now clear\n";
    myList.clear();
    cout << "Size: " << myList.size() << ", list: " << myList << endl;
    cout << "===================\n";

    // Task4
    cout << "\n------Task Four------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    cout << "Display elements with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Add one to each element with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
    cout << "And print it out again with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;

    // Task 5
    cout << "\n------Task Five------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    printListInfo(myList);
    cout << "Now display the elements in a ranged for\n";
    for (int x : myList) cout << x << ' ';
    cout << endl;
    cout << "And again using the iterator type directly:\n";
    for (List::iterator iter = myList.begin(); iter != myList.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    cout << "WOW!!! (I thought it was cool.)\n";

    // Task 6
    cout << "\n------Task Six------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Filling an empty list with insert at begin(): "
    << "i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
    printListInfo(myList);
    // ***Need test for insert other than begin/end***
    cout << "===================\n";

    // Task 7
    cout << "\n------Task Seven------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    cout << "Erasing the elements in the list, starting from the beginning\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.erase(myList.begin());
    }
    // ***Need test for erase other than begin/end***
    cout << "===================\n";

    // Task 8
    cout << "\n------Task Eight------\n";
    cout << "Copy control\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Calling doNothing(myList)\n";
    doNothing(myList);
    cout << "Back from doNothing(myList)\n";
    printListInfo(myList);

    cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
    List listTwo;
    for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
    printListInfo(listTwo);
    cout << "listTwo = myList\n";
    listTwo = myList;
    cout << "myList: ";
    printListInfo(myList);
    cout << "listTwo: ";
    printListInfo(listTwo);
    cout << "===================\n";
}
