#ifndef DSTACK_H
#define DSTACK_H

using namespace std;
#include <string>



class dstack
{
    public:
        dstack();
        void push(double);
        double pop(bool &);
        bool isEmpty();
        ~dstack();
        int length();
    protected:
    private:

        class Node
        {
            public:
                Node* ptrNext;
                double value;
                Node(double p_value,Node* p_next)
                {
                    value = p_value;
                    ptrNext = p_next;
                }
        };
        Node* head;
};

#endif // DSTACK_H
