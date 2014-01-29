#include "cust.h"

#ifndef PQUEUE_H
#define PQUEUE_H


class Pqueue
{

    public:
        Pqueue();
        ~Pqueue();

        void enqueue(Cust*, int);
        Cust* dequeue();
        bool isEmpty();
        int empty();
        int prioPeek();


    protected:
    private:
        class Node
        {
            public:
                Cust* ptrCust;
                int prio;
                Node* ptrNext;

                Node(int p_prio, Cust* p_cust, Node* p_next)
                {
                    ptrCust = p_cust;
                    prio = p_prio;
                    ptrNext = p_next;
                }

        };

        Node* head;
        int length;
};

#endif // PQEUEU_H
