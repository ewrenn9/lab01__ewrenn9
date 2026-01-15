// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    //IMPLEMENT THIS
    if(source.head==nullptr){
        head=nullptr;
        tail=nullptr;
        return;
    }
    head = new Node();
    Node* curr= head;
    Node* track = source.head;
    while(track->next != nullptr){
        curr->info = track->info;
        curr -> next = new Node();
        curr=curr->next;
        track=track->next;
    }
    curr->info =track->info;
    curr->next =nullptr;
    tail = curr;


}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS
    while(head!=nullptr){
        Node* temp=head;
        head=head->next;
        delete temp;
    }
}


// return sum of values in list
int IntList::sum() const {
    int sum=0;
    Node* curr=head;
    while(curr!=nullptr){
        sum+=curr->info;
        curr=curr->next;
    }
    return sum; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr=head;
    while(curr!=nullptr){
        if(curr->info==value){
            return true;
        }
        curr=curr->next;
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if(head==nullptr){
        return 0;
    }
    int max = head->info;
    Node* curr=head->next;
    while(curr!=nullptr){
        if(max<curr->info){
            max=curr->info;
        }
        curr=curr->next;
    }
    return max; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if(count()==0){
        return 0;
    }
    double s=sum();
    
    return s/count(); // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    // IMPLEMENT
    Node* n=new Node();
    n->next=head;
    n->info=value;
    head=n;
}

// append value at end of list
void IntList::push_back(int value) {
    // IMPLEMENT
    Node *n = new Node();
    n->next=nullptr;
    n->info = value;
    if(head!=nullptr){
    tail->next=n;
    tail = n; 
    }
    else{
        head=n;
        tail=n;
    }
 
}

// return count of values
int IntList::count() const {
   int n=0;
   Node* curr=head;
   while(curr!=nullptr){
    n++;
    curr=curr->next;
   }
   return n;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    if(this == &source){
        return *this;
    }
    while(head!=nullptr){
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    
    tail=nullptr;
    if(source.head==nullptr){
        return *this;
    }
    Node* curr=source.head;
    while(curr!=nullptr){
        this->push_back(curr->info);
        curr=curr->next;
    }
    return *this;
    
    

}

// constructor sets up empty list
IntList::IntList(){ 
    //IMPLEMENT THIS 
    head = nullptr;
    tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

