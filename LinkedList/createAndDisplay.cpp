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

void SortedInsert(struct Node *p, int x){
    struct Node *t,*q = NULL;
    t = new struct Node;
    t->data = x;
    t->next = NULL;

    if (first == NULL)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first){
            t->next = p;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int Delete(struct Node *p, int index){
    struct Node *q = NULL;
    int x,i;

    if (index < 1){
        return -1;
    }
    if (index == 1){
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    } else
    {
        for (i = 0; i < index - 1; i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
    
}

int isSorted(struct Node *p){
    int x = -65536;

    while (p != NULL)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

int main(){
    int A[] = {10,20,30,40,50};
    Create(A,5);
    Display(first);
    cout << endl;
    Delete(first,3);
    Display(first);
    cout << endl;
    return 0;
}