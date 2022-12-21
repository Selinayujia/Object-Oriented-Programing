//
//  main.cpp
//  rec11
//
//  Created by Selina on 13/04/2018.
//  Copyright © 2018 Selina. All rights reserved.
//
#include <iostream>
#include <cstdlib> // To allow NULL if no other includes
#include <vector>
#include<unordered_set>

using namespace std;

struct Node {
    Node(int data = 0, Node* next = NULL) : data(data), next(next) {}
    int data;
    Node* next;
    
};
void display(Node* a)
{
    if(a==nullptr)
    {
        cout<<"null"<<endl;
    }
    else
    {
        while(a)
        {
            cout<<a->data;
            a=a->next;
        }
        cout<<endl;
    }
}

void listInsertHead(Node*& headPtr, int entry) {
    headPtr = new Node(entry, headPtr);
}

// Should free up your nodes, of course...
void listClear(Node*& headPtr) {
    while (headPtr) {
        Node* next = headPtr->next;
        delete headPtr;
        headPtr = next;
    }
}

void listSplice(Node* headPtr, Node* posPtr)
{
    if(headPtr==nullptr)
    {
        return;
    }
    if(posPtr->next)
    {
        Node* restPart= posPtr->next;
        posPtr->next=headPtr;
        while(headPtr->next)
        {
            headPtr=headPtr->next;
        }
        headPtr->next=restPart;
    }
    else
    {
        posPtr->next=headPtr;
    }
    
}

Node* sublist(Node* parent, Node* child)
{
    Node* check=child;
    Node* result=nullptr;
    while(parent && check)
    {
        while(parent&& parent->data!=check->data)
        {
            parent=parent->next;
        }
        result=parent;
        if(!parent)
        {
            
            break;
        }
        
        else
        {
            bool find=true;
            while(check->next && parent->next)
            {
                check=check->next;
                parent=parent->next;
                if(check->data==parent->data)
                {
                    continue;
                }
                
                else
                {
                    find=false;
                
                    break;
                }
                
            }
            if(check->next==nullptr&& find)
            {
                return result;
            }
            parent=result->next;
            check=child;
        }
    }
    
    return nullptr;
}

// This might be useful for setting up test cases. Feel free to use it
// or not as you like. Example of using would be:
// Node* myList = listBuild({1, 4, 9, 16}); // builds a list of: 1 4 9 16
Node* listBuild(const vector<int>& vals) {
    Node* result = nullptr;
    for (size_t index = vals.size(); index > 0; --index) {
        listInsertHead(result, vals[index-1]);
    }
    return result;
    
}
bool sharelist(Node* first, Node* second)
{
     unordered_set<Node*> stuff;
    while(first)
    {
        stuff.insert(first);
        first=first->next;
    }
    while(second)
    {
        if(stuff.find(second) ==stuff.end())
        {
            second=second->next;
        }
        
            return second;
        
    }
    return nullptr;
    
    
    
}
int main()
{
    Node* parent=listBuild({ 1 ,2, 3, 2, 3, 2, 4, 5, 6});
    Node* child=listBuild({2,3,2,4});
    Node* result =sublist(parent, child);
    display(result);
    
    
//    Node a;
//    Node b(1,&a);
//    Node c(2,&b);
//    Node d(3,&c);
//
//    Node x(4,&b);
//    display(&d);
//    display(&x);
//    bool result=sharelist(&d, &x );
//    cout << boolalpha << result << endl;
//    if(result)
//    {
//        cout<<"Ture"<<endl;
//    }
    
}
    
    























