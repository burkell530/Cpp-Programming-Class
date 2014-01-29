#include "dstack.h"
#include <iostream>

using namespace std;

dstack::dstack()
{
    head = NULL;
}

//Returns true if empty
bool dstack::isEmpty()
{
    if(head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void dstack::push(double p_value)
{
    head = new Node(p_value,head);
    return;
}

double dstack::pop(bool &work)
{

    if(isEmpty())
    {
        work = false;
        return 0;
    }
    else
    {

        work = true;
        double Temp = head -> value;
        Node* ptr = head;
        head = head -> ptrNext;
        delete ptr;
        return Temp;
    }

}


int dstack::length()
{
    if(head==NULL)
        return 0;

    int length = 1;

    for(Node* ptr = head; ptr = ptr-> ptrNext; ptr)
    {
        length++;
    }

    return length;
}

dstack::~dstack()
{
   while(head!=NULL)
   {
       Node *ptr = head;
       head = head -> ptrNext;
       delete ptr;
   }
}


