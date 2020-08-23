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
    dll.Insert(2,5);
    dll.Display();
    cout << dll.Length() << endl;
    return 0;
}
