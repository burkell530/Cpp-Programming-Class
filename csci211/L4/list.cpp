#include "list.h"
#include <iostream>

using namespace std;

list::list()
{
    head = NULL;
    //ctor
}

void list::add(int p_int)
{
    head = new Node(p_int,head);

    return;
}

void list::insertEnd(int p_int)
{

    Node* ptr = head;
    if(head == NULL)
    {
        add(p_int);
    }
    else
    {
        while (ptr ->ptrNext != NULL)
        {
            ptr = ptr->ptrNext;
        }

        ptr->ptrNext = new Node(p_int, ptr -> ptrNext);

    }

    return;
}

void list::sum()
{
    Node* ptr = head;

    int sum = 0;


    while(ptr!=NULL)
    {
        sum = ptr->value + sum;
        ptr = ptr -> ptrNext;
    }

    cout <<"sum = " <<sum <<  endl;

}

void list::print()
{
    Node* ptr = head;

    while(ptr != NULL)
    {
        cout << ptr -> value << endl;
        ptr = ptr -> ptrNext;
    }
    return;

}

list::~list()
{
    //dtor
}
