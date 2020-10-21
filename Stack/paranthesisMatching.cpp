#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
};

class SinglyLinkedList
{
private:
    Node *top;
    Node *t = new Node();

public:
    SinglyLinkedList();
    void Push(char x);
    char pop();
    int isBalanced(char *p);
    void Display();
};

SinglyLinkedList::SinglyLinkedList()
{
    Node *top = NULL;
}

void SinglyLinkedList::Push(char x)
{
    if (t == NULL)
    {
        cout << "Stack is Full";
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char SinglyLinkedList::pop()
{
    if (top == NULL)
    {
        cout << "Stack is empty";
        return 0;
    }
    else
    {
        Node *p = top;
        top = top->next;
        char x = p->data;
        // delete p;
        return x;
    }
}

int SinglyLinkedList::isBalanced(char *p)
{
    int i;
    for (i = 0; p[i] != '\0'; i++)
    {
        if (p[i] == '(')
            Push(p[i]);
        else if (p[i] == ')')
        {
            if (top == NULL)
                return 0;
            pop();
        }
    }
    if (top == NULL)
        return 1;
    else
        return 0;
}

void SinglyLinkedList::Display()
{
    Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    char *p = "((a+b))";
    SinglyLinkedList obj;
    cout << obj.isBalanced(p) << endl;
    return 0;
}
