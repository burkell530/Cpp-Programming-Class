#ifndef LIST_H
#define LIST_H


class list
{
    public:
        list();
        ~list();
       void add(int p_int);
       void print();
       void sum();
       void insertEnd(int p_int);
    protected:
    private:
        class Node
        {
            public:
                int value;
                Node* ptrNext;
                public:

                 Node(int p_int, Node* p_next)
                 {
                    value = p_int;
                    ptrNext = p_next;
                }

        };

        Node* head;
};

#endif // LIST_H
