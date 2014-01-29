#include "pqueue.h"
#include <iostream>

using namespace std;

Pqueue::Pqueue()
{
    head = NULL;
    length =0;
}

int Pqueue::prioPeek()
{
    return head->prio;
}

//IS EMPTY FUNCTION

bool Pqueue::isEmpty()
{
    if (length == 0) return true;
    else return false;
}

int Pqueue::empty()
{


    return (length==0);
    /*
    if(head == NULL)    return 0;

    for(Node * ptr = head, int counter = 0; ptr -> ptrNext; ptr = ptr -> ptrNext, counter++);

    return counter;
    */
}


Cust* Pqueue::dequeue()
{
    bool work = true;
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

void Pqueue::enqueue(Cust* p_ptrCust,int p_prio)
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


Pqueue::~Pqueue()
{
    while(head!=NULL)
    {
        Node* ptr = head;
        head = head->ptrNext;
        delete ptr->ptrCust;
        delete ptr;
    }
}
