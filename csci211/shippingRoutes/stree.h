#ifndef STREE_H
#define STREE_H

#include <vector>
#include <string>

class Stree
{
    public:
        Stree();
        void countChild(int &, int &, int &);
        bool insert(std::string p_orgin ,std::string p_dest, int p_dis);
        bool insertNode(std::string p_orgin ,std::string p_dest, int p_dis);
        bool deleteNode(std::string p_value);
        std::vector<std::string> lookup(std::string p_value, std::vector<int>&);
        std::vector<std::string> path(std::string p_start, std::string p_end);
        bool distNodes(std::string p_one, std::string p_two, int&);

        ~Stree();
    protected:
    private:

        class Node
        {
            public:
                std::string value;
                Node* ptrParent;
                Node* ptrLeft;
                Node* ptrRight;
                int distance;


                Node(std::string p_value,int p_distance, Node* p_ptrParent, Node* p_ptrLeft, Node* p_ptrRight)
                {
                    value = p_value;
                    distance = p_distance;
                    ptrParent = p_ptrParent;
                    ptrLeft = p_ptrLeft;
                    ptrRight = p_ptrRight;
                }

                ~Node()
                {
                    delete ptrLeft;
                    delete ptrRight;
                    ptrLeft = NULL;
                    ptrRight = NULL;
                    ptrParent = NULL;
                }
        };

        Node* root;

        Node* findNode(Node* p_current, std::string p_target)
        {
              Node* temp = NULL;
                if(p_current->value == p_target)  temp = p_current;
                else
                {
                      if(p_current -> ptrLeft == NULL && p_current -> ptrRight == NULL) temp == NULL;
                      if(p_current -> ptrLeft != NULL) temp = findNode(p_current->ptrLeft, p_target);
                      if(temp == NULL && p_current -> ptrRight != NULL) temp = findNode(p_current->ptrRight, p_target);
                }

                return temp;
        };

        void countChild(int &, int &, int &, Node*);

        void findPath(Node * ,Node *, std::vector<std::string> &);
        void findDist(Node * ,Node *, int&);
};

#endif // STREE_H
