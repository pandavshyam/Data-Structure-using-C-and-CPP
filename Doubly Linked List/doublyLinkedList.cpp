#include <iostream>
using namespace std;

class Node
{
public:
    Node *previous;
    int data;
    Node *next;
};

class DoublyLinkedList
{
private:
    Node *first;
public:
    DoublyLinkedList();
    DoublyLinkedList(int A[], int n);
    void Display();
    int Length();
    void Insert(int position, int x);
    int Delete(int position);
    void Reverse();
    void Reverse1();
    ~DoublyLinkedList();
};

DoublyLinkedList::DoublyLinkedList(){
    first = NULL;
}

DoublyLinkedList::DoublyLinkedList(int A[], int n){
    Node *last, *t;
    int i;

    first = new Node;
    first->data = A[0];
    first->previous = NULL;
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++){
        t = new Node;
        t->data = A[i];
        
        t->next = last->next;
        t->previous = last;
        last->next = t;
        last = t;
    }
}

void DoublyLinkedList::Display(){
    Node *p = first;

    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int DoublyLinkedList::Length(){
    Node *p = first;
    int len = 0;

    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void DoublyLinkedList::Insert(int position, int x){
    Node *p = first, *t;
    int i;

    if (position < 0 && position > Length()){
        return;
    }

    t = new Node;

    if (position == 0){
        t->data = x;
        t->previous = NULL;
        t->next = first;
        first->previous = t;
        first = t;
    } else{
        for (i = 0; i < position - 1; i++){
            p = p->next;
        }
        t->data = x;
        t->next = p->next;
        t->previous = p;
        if (p->next)
            p->next->previous = t;
        p->next = t;
        
    }
    
}

int DoublyLinkedList::Delete(int position){
    if (position < 1 || position > Length()){
        return -1;
    }
    int x,i;
    Node *p = first;
    if (position == 1){
        first = first->next;
        if (first)
            first->previous = NULL;
        x = p->data;
        delete p;
    } else {
        for (i = 0; i < position - 1; i++)
            p = p->next;
        p->previous->next = p->next;
        if (p->next)
            p->next->previous = p->previous;
        x = p->data;
        delete p;
    }
    return x;
}

void DoublyLinkedList::Reverse(){
    Node *p = first;

    while (p->next != NULL){p = p->next;}

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->previous;
    }
    cout << endl;
}

void DoublyLinkedList::Reverse1(){
    Node *p = first, *temp;
    while (p)
    {
        temp = p->next;
        p->next = p->previous;
        p->previous = temp;
        p = p->previous;
        if (p!= NULL && p->next == NULL){
            first = p;
        }
    }   
}

DoublyLinkedList::~DoublyLinkedList(){
    Node *q = first;

    while (first)
    {
        first = first->next;
        delete q;
        q = first;
    }
}


int main(){
    int A[] = {10,20,30,40,50};
    DoublyLinkedList dll(A,5);
    dll.Reverse1();
    dll.Display();
    // cout << dll.Length() << endl;
    return 0;
}