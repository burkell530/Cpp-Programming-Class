#include "kalList.h"

kalList::kalList()
{
    length = 0;
    head = NULL;
    tail = NULL;

}

int kalList::popTop()
{
    int val = -1;
    if(head == NULL) return val;


    Node* temp = head;
    val = head -> value;
    head = head->ptrNext;

    delete temp;

    if(head == NULL) tail = NULL;

    length--;
    return val;
}

void kalList::add(int p)
{
    if(head == NULL)
    {
        head = new Node(p);
        tail = head;
    }

    tail -> ptrNext = new Node(p);
    length++;



}

void kalList::kalSort()
{

}

kalList::~kalList()
{
    //dtor
}
