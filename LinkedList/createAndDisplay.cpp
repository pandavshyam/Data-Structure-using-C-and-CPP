#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first = NULL;
struct Node *second = NULL;
struct Node *third = NULL;

void Create(int A[],int n){
    int i;
    struct Node *last;
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

void Create1(int A[],int n){
    int i;
    struct Node *last;
    second = new struct Node;
    second->data = A[0];
    second->next = NULL;
    last = second;

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
    struct Node *last;
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

void DeleteDuplicate(struct Node *p){
    struct Node *q = first->next;

    while (q != NULL){
        if (p->data != q->data){
            p = q;
            q = q->next;
        }
        else{
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

// Reverse using New Array
// Changing only data of the node, not the links
void Reverse1(struct Node *p){
    struct Node *q = p;
    int *A, i = 0;

    A = new int[5];

    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    i--;
    q = p;

    while (q != NULL)
    {
        q->data = A[i];
        i--;
        q = q->next;
    }
    delete[] A;
    
}

// Reverse Linked List using Sliding Pointer
void Reverse2(struct Node *p){
    struct Node *q = NULL, *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// Reverse Linked List using Recursion
void Reverse3(struct Node *q, struct Node *p){
    if (p)
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

void Merge(struct Node *p, struct Node *q){
    struct Node *last;
    if (p->data < q->data){
        third = last = p;
        p = p->next;
        last->next = NULL;
    } else {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }

    while (p!=NULL && q!=NULL)
    {
        if (p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        } else {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p!=NULL) last->next = p;
    if (q!=NULL) last->next = q;
}

int main(){
    int A[] = {10,20,30,40,50};
    int B[] = {5,15,25,35,45};
    Create(A,5);
    Create1(B,5);
    Display(first);
    cout << endl;
    Display(second);
    cout << endl;
    Merge(first,second);
    Display(third);
    cout << endl;
    return 0;
}