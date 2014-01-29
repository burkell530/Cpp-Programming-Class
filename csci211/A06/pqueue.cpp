#include "pqueue.h"
#include <iostream>

using namespace std;

pqueue::pqueue()
{
    head = NULL;
    length =0;
}

int pqueue::prioPeek()
{
    return head->prio;
}

//IS EMPTY FUNCTION

bool pqueue::isEmpty()
{
    if (getLength() == 0) return true;
    else return false;
}

int pqueue::getLength()
{

    return length;
    /*
    if(head == NULL)    return 0;

    for(Node * ptr = head, int counter = 0; ptr -> ptrNext; ptr = ptr -> ptrNext, counter++);

    return counter;
    */
}


Cust* pqueue::dequeue(bool &work)
{
    work = true;
    if(length == 0)
    {
        work = false;
        cout << "Dequeue Failed" << endl;
        return NULL;
    }
    Cust* custReturn = head -> ptrCust;

    Node* ptr = head;
    head = head -> ptrNext;
    delete ptr;
    length--;
    return custReturn;
}

void pqueue::enqueue(int p_prio, Cust* p_ptrCust)
{
    if(length == 0 || p_prio < head -> prio)
    {
        head = new Node(p_prio, p_ptrCust, head);
        length++;
        return;
    }

    Node* ptr = head;
    while(ptr -> ptrNext &&  p_prio >= ptr -> ptrNext -> prio) ptr = ptr->ptrNext;
    //Do Nothing For Loop, MOVES PTR

    ptr -> ptrNext = new Node(p_prio, p_ptrCust, ptr ->ptrNext);

    length++;
    return;
}


pqueue::~pqueue()
{
    while(head!=NULL)
    {
        Node* ptr = head;
        head = head->ptrNext;
        delete ptr->ptrCust;
        delete ptr;
    }
}
