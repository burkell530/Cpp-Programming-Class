#ifndef KALLIST_H
#define KALLIST_H

#include <iostream>


class kalList
{
    public:
        kalList();
        void add(int p);
        int popTop();
        virtual ~kalList();
        int getLength() {return length;}
        void kalSort();
    protected:
    private:
        int length;
        class Node
        {
             public:
                 int value;
                 Node* ptrNext;
                 Node(int a)
                 {
                     value = a;
                     ptrNext = NULL;
                 }
        };

        Node* head;
        Node* tail;
};

#endif // KALLIST_H
