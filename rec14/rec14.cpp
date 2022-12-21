//
//  main.cpp
//  rec14
//
//  Created by Selina on 2018/5/4.
//  Copyright © 2018 Selina. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <exception>
using namespace std;


struct Node {
public:
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    // accessors
    int getData() const { return data; }
    Node* getNext() { return next; }
    // mutators
    void setData(int data) { this->data = data; }
    void setNext(Node* next) { this->next = next; }
private:
    int data;
    Node* next;
};

struct TNode {
    TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
    int data;
    TNode *left, *right;
};


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
    //while (headPtr->next != nullptr) {
    Node* p = headPtr;
    //while (headPtr != nullptr) {
    //while (p != nullptr) {
    while (p) {
        // cout << headPtr->data << ' ';
        // headPtr = headPtr->next;
        cout << p->getData() << ' ';
        p = p->getNext();
    }
    cout << endl;
}

bool ifEvenBinaryOne(int input) //first task
{
    if(input==0)
    {
        return true;
    }
    else
    {
        if(input%2==0)
        {
            bool result=ifEvenBinaryOne(input/2);
            return result;
        }
        else
        {
            bool result=ifEvenBinaryOne(input/2);
            return !result;
        }
    }
    
}

Node* combineTwoList(Node* left, Node* right) //task two
{
    if(left==nullptr && right==nullptr)
    {
        return nullptr;
    }
    else if(left==nullptr )
    {
        Node* result= new Node(right->getData());
        right=right->getNext();
        result->setNext(combineTwoList(left, right));
        return result;
        
    }
    else if( right==nullptr)
    {
        Node* result= new Node(left->getData());
        left=left->getNext();
        result->setNext(combineTwoList(left, right));
        return result;
        
    }
    else //both are not nullptr
    {
        Node* result= new Node(left->getData()+right->getData());
        left=left->getNext();
        right=right->getNext();
        result->setNext(combineTwoList(left, right));
        return result;
    }
    
}
int max(TNode* root) {
    if(!root) throw invalid_argument("Empty Tree");
    if(!root->left && !root->right)
    {
        return root->data;
        
    }
    else if(!root->left && root->right)
    {
        int right_result=max(root->right);
        if(root->data>=right_result) return root->data;
        else return right_result;
    }
    else if(root->left && !root->right)
    {
        int left_result= max(root->left);
        if (left_result>=root->data) return left_result;
        else return root->data;
    }
    else
    {
        int left_result= max(root->left);
        int right_result=max(root->right);
        if(root->data>=left_result && root->data>=right_result) return root->data;
        else if (left_result>=root->data && left_result>=right_result) return left_result;
        else return right_result;
        
    }
   
}

bool palindrome(char input[], int length)
{
    if(length==1)
    {
        return true;
    }
    if(length==2)
    {
        return input[0]==input[1];
    }
    else
    {
        if(input[0]==input[length-1])
        {
            return palindrome(++input,length-2 );
        }
        return false;
    }
    

}

int towers(int num, char a, char b, char c)
{
    if(num==0) return 0;
    int count=towers(num-1, a, c, b);
    count+=1;
    count+=towers(num-1, c, b, a);
    return count;
    
}
void mystery(int n) {
    if (n > 1) {
        cout << 'a';
        mystery(n/2);
        cout << 'b';
        mystery(n/2);
    }
    cout << 'c';
}

int main()
{
    cout<<boolalpha;
    cout<<ifEvenBinaryOne(5)<<endl;
    
    Node* start=new Node(3);
    listAddTail(start, 6);
    listAddTail(start, 5);
    listAddTail(start, 8);
    
    Node* anotherStart=new Node(7);
    listAddTail(anotherStart, 6);
    listAddTail(anotherStart, 1);
    
    Node* result= combineTwoList(start, anotherStart);
    listDisplay(result);
    
    TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
    cout << max(&f) << endl;
    try {
        cout << max(&e) << "\n";
    } catch (...) {
        cerr << "Empty Tree!\n";
    }
    

    char s[] = "racecar";
    if (palindrome(s, 7)) { cout << "Yes!\n"; }
    cout<<towers(1, 'a', 'b', 'c')<<endl;
    cout<<towers(2, 'a', 'b', 'c')<<endl;
    cout<<towers(3, 'a', 'b', 'c')<<endl;
    cout<<towers(4, 'a', 'b', 'c')<<endl;
    mystery(4);
   
};
