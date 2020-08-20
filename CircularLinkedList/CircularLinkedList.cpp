#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class CircularLinkedList{
    private:
        Node *head;
    public:
        CircularLinkedList(){head = NULL;};
        CircularLinkedList(int A[],int n);
        ~CircularLinkedList(){
            Node *p = head;
            while (head)
            {
                head = head->next;
                delete p;
                p = head;
            }
        };
        void Display();
        void Insert(int position, int x);
        int Length();
};

int CircularLinkedList::Length(){
    Node *p = head;
    int length = 0;
    do{
        length++;
        p = p->next;
    } while (p != head);
    return length;
}

CircularLinkedList::CircularLinkedList(int A[],int n){
    int i;
    Node *t,*last;

    head = new Node;
    head->data = A[0];
    head->next = head;
    last = head;

    for (i = 1; i < n; i++){
        t = new Node;
        t->data = A[i];
        // One way of linking
        // t->next = last->next;
        // last->next = t;
        // last = t;
        t->next = head;
        last->next = t;
        last = t;
    }
};

void CircularLinkedList::Display(){
    Node *p = head;
    do{
        cout << p->data << " ";
        p = p->next;
    } while(p != head);
    cout << endl;
};

void CircularLinkedList::Insert(int position, int x){
    int i;
    Node *p = head;
    Node *t = new Node;

    if (position < 0 && position > Length()){
        return;
    }
    if (position == 0){
        t->data = x;
        if (head == NULL){
            head = t;
            t->next = head;
        } else {
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }  
    } else {
        for (i = 0; i < position - 1; i++)
            p = p->next;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int main(){
    int A[] = {1,2,3,4,5};
    CircularLinkedList p(A,5);
    p.Insert(0,10);
    p.Display();
    return 0;
}