#include <iostream>
using namespace std;

//class Node {
struct Node {
    //public:
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    // // accessors    
    // int getData() const { return data; }
    // Node* getNext() { return next; }
    // // mutators
    // void setData(int data) { this->data = data; }
    // void setNext(Node* next) { this->next = next; }
    //private:
    int data;
    Node* next;
};

/*
  display
  add, remove
  length
  find
  equality
  duplicate
  clear
 */

void listDisplay(Node* headPtr) {
    //while (headPtr->next != nullptr) {
    Node* p = headPtr;
    //while (headPtr != nullptr) {
    //while (p != nullptr) {
    while (p) {
        // cout << headPtr->data << ' ';
        // headPtr = headPtr->next;
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

int listLength(Node* headPtr) {
//int listLength(const Node* headPtr) {
    Node* p = headPtr;
    //const Node* p = headPtr;
    int count = 0;
    while (p != nullptr) {
        ++count;
        p = p->next;
    }
    return count;
}

void listAddTail(Node* headPtr, int data) {
    Node* last = headPtr;
    //while (last != nullptr) {
    while (last->next != nullptr) {
        // if (last->next == nullptr)
        //     break;
        // else 
            last = last->next;
    }
    last->next = new Node(data);
}

int main() {
    Node* myList = nullptr;

    //myList = new Node(17);
    listAddTail(myList, 17);

    //myList->setNext(new Node(28));
    myList->next = new Node(28);

    //cout << myList->data << ' ' << myList->next->data << endl;
    listDisplay(myList);
}
