#include "stree.h"
#include <vector>
#include <iostream>

using namespace std;

Stree::Stree()
{
    root = NULL;
}

bool Stree::distNodes(string p1, string p2, int &p_dist)
{
    p_dist = 0;

    if(root == NULL)
    {
        return false;
    }

    if(p1 == p2)
    {

        return true;
    }

    Node* ptr = findNode(root, p1);

    if(!ptr) return false;

    Node* ptr2 = NULL;
    if(ptr->ptrLeft)
    {
        ptr2 = findNode(ptr->ptrLeft,p2);
    }

    if(ptr->ptrRight && ptr2 == NULL)
    {
        ptr2 = findNode(ptr->ptrRight,p2);
    }

    if(!ptr2) return false;
    else
        findDist(ptr,ptr2,p_dist);

        return p_dist;

}

void Stree::findDist(Node* ptr1, Node* ptr2, int &p_dist)
{
    if(ptr1==ptr2)
    {
        return;
    }
    Node* ptr3 = findNode(ptr1->ptrLeft,ptr2->value);
    if(ptr3)
    {
        p_dist = p_dist = ptr1->ptrLeft->distance + p_dist;
        findDist(ptr1->ptrLeft, ptr2, p_dist);
    }
    else
    {
        p_dist = p_dist = ptr1->ptrRight->distance + p_dist;
        findDist(ptr1->ptrRight, ptr2, p_dist);
    }
}


void Stree::findPath(Node* p_ptr1,Node* p_ptr2, vector<string> &p_vec)
{
    Node* ptr1 = p_ptr1;
    Node* ptr2 = p_ptr2;
    p_vec.push_back(ptr1->value);


    if(ptr1==ptr2)
    {
        return;
    }
    Node* ptr3 = findNode(ptr1->ptrLeft,p_ptr2->value);
    if(ptr3)
    {
        findPath(ptr1->ptrLeft, ptr2, p_vec);
    }
    else
    {
        findPath(ptr1->ptrRight, ptr2, p_vec);
    }


}




bool Stree::deleteNode(string p_value)
{
    Node* ptr = findNode(root, p_value);

    if(ptr == NULL)
        return false;
    else
    {
        if(ptr == root)
        {
            root = NULL;
        }
        if(ptr->ptrParent && ptr -> ptrParent -> ptrRight == ptr)
        {
            ptr -> ptrParent -> ptrRight = NULL;
        }
        else if(ptr -> ptrParent && ptr -> ptrParent -> ptrLeft == ptr)
        {
            ptr -> ptrParent -> ptrLeft = NULL;
        }

        delete ptr;
        return true;
    }



}

vector<string> Stree::path(string p1, string p2)
{
    vector<string> returnVec;
    if(root == NULL)
    {
        returnVec.push_back("Failed");
        return returnVec;
    }
    if(p1 == p2)
    {
        returnVec.push_back("Failed");
        return returnVec;
    }

    Node* ptr = findNode(root, p1);

    if (ptr == NULL)
    {
        returnVec.push_back("Failed");
        return returnVec;
    }

    Node* ptr2 = NULL;
    Node* ptr3 = NULL;
    if(ptr->ptrLeft) ptr2 = findNode(ptr->ptrLeft, p2);

    if(ptr->ptrRight) ptr3 = findNode(ptr->ptrRight, p2);

    if(ptr2 || ptr3)
    {

        Node* ptr4;
        if(ptr2) ptr4 = ptr2;
        else ptr4 = ptr3;

        findPath(ptr, ptr4, returnVec);

    }
    else
    {
        returnVec.push_back("Failed");
        return returnVec;
    }

    return returnVec;
}
bool Stree::insert(string p_head, string p_value, int p_dist)
{
    return insertNode(p_head,p_value, p_dist);
}



bool Stree::insertNode(string p_head, string p_value, int p_dist)
{
    if(root == NULL)
    {

        root = new Node(p_head, 0, NULL, new Node(p_value,p_dist,NULL,NULL,NULL), NULL);
        root -> ptrLeft -> ptrParent = root;
        return true;
    }
    else
    {
        Node* temp2 = findNode(root, p_value);
        if(temp2) return false;


        Node* temp = findNode(root, p_head);
        if(temp == NULL) return false;
        if(temp -> ptrLeft != NULL&& temp->ptrRight != NULL) return false;




        if(temp -> ptrLeft == NULL)
        {

            temp ->ptrLeft = new Node(p_value, p_dist, temp, NULL, NULL);
            return true;
        }
        else if(temp -> ptrRight == NULL)
        {

            temp ->ptrRight = new Node(p_value, p_dist, temp, NULL, NULL);
            return true;
        }
    }







    return false;
}



vector<string> Stree::lookup(string p_value, vector<int> &dist)
{
    vector<string> returnVec;
    Node* ptr = findNode(root, p_value);
    if(ptr==NULL)
    {
        returnVec.push_back("Failed");
        dist.push_back(0);
        return returnVec;
    }
    else
    {
          returnVec.push_back(ptr->value);


          //parent
          if(ptr->ptrParent == NULL)
          {
              returnVec.push_back("none");
              dist.push_back(0);
          }
          else
          {
              returnVec.push_back(ptr->ptrParent->value);
              dist.push_back(ptr->distance);
          }
          //left
          if(ptr->ptrLeft== NULL)
          {
              returnVec.push_back("none");
              dist.push_back(0);

          }
          else
          {
              returnVec.push_back(ptr->ptrLeft->value);
              dist.push_back(ptr->ptrLeft->distance);
          }
          //right
          if(ptr->ptrRight == NULL)
          {
              returnVec.push_back("none");
              dist.push_back(0);
          }
          else
          {
              returnVec.push_back(ptr->ptrRight->value);
              dist.push_back(ptr->ptrRight->distance);
          }
          return returnVec;
    }
}


void Stree::countChild(int &zero, int &one, int &two, Node* cur)
{
    if(cur == NULL) return;
    else
    {
        if(cur->ptrLeft && cur ->ptrRight) two++;
        else if(!(cur->ptrLeft) && !(cur ->ptrRight)) zero++;
        else one++;
        countChild(zero, one, two, cur->ptrLeft);
        countChild(zero,one,two,cur->ptrRight);
        return;
    }
}

void Stree::countChild(int &a, int &b, int &c)
{
    countChild(a,b,c,root);
}

Stree::~Stree()
{
    //dtor
}
