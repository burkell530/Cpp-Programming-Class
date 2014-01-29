#include "video.h"

#ifndef VLIST_H
#define VLIST_H


class vlist
{
    public:
        bool isInList(std::string p_title);
        void print();
        void insertVideo(video *p_vid);
        void length();
        void lookup(std::string p_title);
        void removeVideo(std::string p_title);
        void printByLength();
        void printByRating();


        ~vlist();
        vlist();



    protected:
    private:

        class Node
        {
            public:
               video* ptrVid;
               Node* ptrNext;
               Node(video* p_video, Node* p_next)
                {
                    ptrVid = p_video;
                    ptrNext = p_next;
                }

        };
        int numVid;
        Node* head;

};

#endif // VLIST_H
