#include "cust.h"

#ifndef PQUEUE_H
#define PQUEUE_H


class pqueue
{

    public:
        pqueue();
        ~pqueue();

        void enqueue(int, Cust*);
        Cust* dequeue(bool &);
        bool isEmpty();
        int getLength();
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
