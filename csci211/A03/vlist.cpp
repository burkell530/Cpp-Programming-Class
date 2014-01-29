#include "vlist.h"
#include <iostream>
#include "video.h"
#include <new>


using namespace std;




vlist::vlist()
{
     head = NULL;
     numVid = 0;
}

void vlist::insertVideo(video* p_video)
{
    if(isInList(p_video->getTitle()))
    {
        cerr << "Could not insert video <" << p_video->getTitle() << ">, already in list" << endl;
        return;
    }

    if (head==NULL || head->ptrVid->getTitle()> p_video->getTitle())
    {
        head = new Node(p_video, head);
        numVid++;
        return;
    }


    Node* ptr = head;

    while(ptr->ptrNext != NULL&&ptr->ptrNext->ptrVid->getTitle() < p_video->getTitle())
    {
        ptr=ptr->ptrNext;
    }

    ptr->ptrNext = new Node(p_video,ptr->ptrNext);
    numVid++;
    return;



    //if(!isInList(p_video -> getTitle()))
}

void vlist::print()
{
    Node* ptr = head;

    while(ptr != NULL)
    {
        ptr -> ptrVid -> print();
        ptr = ptr -> ptrNext;
    }
}

bool vlist::isInList(string p_title)
{
    Node* ptr = head;
    bool onList = false;

    while(ptr != NULL && !onList)
    {
        if( p_title == ptr -> ptrVid -> getTitle())
        {
            ptr -> ptrVid -> print();
            onList = true;
        }
        else
            ptr = ptr -> ptrNext;
    }

return onList;

}

void vlist::lookup(string p_title)
{
    Node* ptr = head;
    bool found = false;

    while(ptr != NULL && !found)
    {
        if( p_title == ptr -> ptrVid -> getTitle())
        {
            ptr -> ptrVid -> print();
            found = true;
        }
        else
            ptr = ptr -> ptrNext;
    }

     if(!found)
        cerr << "Title <" << p_title << "> not in list." << endl;
}


void vlist::removeVideo(string p_title)
{
    Node* ptr = head;
    bool found = false;
    bool toContinue = true;
    Node* ptrTemp = NULL;

     if(head == NULL)
            toContinue = false;


    if(head != NULL && head -> ptrVid -> getTitle() == p_title )
    {

        ptrTemp = head;

        head = head -> ptrNext;
        delete ptrTemp -> ptrVid;
        delete ptrTemp;
        numVid--;

        found = true;
        toContinue = false;


    }



    while(toContinue)
    {

           if(ptr -> ptrNext != NULL && ptr -> ptrNext -> ptrVid -> getTitle() == p_title)
           {
            found = true;
            toContinue = false;

            ptrTemp = ptr -> ptrNext;

            ptr -> ptrNext = ptr -> ptrNext -> ptrNext;

            delete ptrTemp -> ptrVid;
            delete ptrTemp;
            numVid = numVid - 1;

           }

           else
           {
               ptr = ptr -> ptrNext;

               if(ptr == NULL)
               {
                   toContinue = false;
               }
           }
    }
if(!found)
        cerr <<"Title <" << p_title << "> not in list, could not delete." << endl;




}

void vlist::length()
{
    int length = 0;
    Node* ptr = head;
    while(ptr != NULL)
    {
        ptr = ptr -> ptrNext;
        length++;
    }

    cout << length << endl;
}



/*
void vlist::lookup(string p_title)
{
    Node* ptr = head;
    bool found = false;

    while(ptr!=NULL && found == false)
    {
        if (ptr->ptrVid -> getTitle() == p_title)
        {
            ptr->ptrVid ->print();
            found = true;
        }

        else
            ptr = ptr->ptrNext;


    }

    if(!found)
        cout << "No Videos Found" <<endl;

}
*/

void vlist::printByRating()
{
    video vidArray[numVid] = new video[];

    for(int a = 0; a<numVid; a++)
    {
        if(head==NULL)
        {
            return;
        }
        Node* ptr=head;
        vidArray[a] = *(ptr->ptrVid);
        cout<<"debug1";
        ptr = ptr -> ptrNext;
        vidArray[a].print();

    }



 return;
}

void vlist::printByLength()
{


 return;
}

vlist::~vlist()
{

}





