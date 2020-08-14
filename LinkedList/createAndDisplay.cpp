#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first = NULL;
struct Node *last = NULL;

void Create(int A[],int n){
    int i;
    first = new struct Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < 5; i++){
        struct Node *t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p){
    while (p!=0)
    {
        cout << p->data << " ";
        p = p->next;
    }

}

void Display1(struct Node *p){
    if (p!=NULL)
    {
        Display1(p->next);
        cout << p->data << endl;
        
    }
}

void Insert(struct Node *p, int index, int key){
    int i;
    if (index < 0){
        return;
    }
    struct Node *t = new struct Node;
    t->data = key;

    if(index == 0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    } 
}

void InsertLast(struct Node *p, int x){
    struct Node *q = new struct Node;
    q->data = x;
    q->next = NULL;

    if (first == NULL){
        first = last = q;
    }
    else
    {
        last->next = q;
        last = q;    
    }
    
}

int main(){
    int A[] = {1,2,3,4,5};
    InsertLast(first,2);
    InsertLast(first,3);
    InsertLast(first,4);
    Display(first);
    cout << endl;
    return 0;
}