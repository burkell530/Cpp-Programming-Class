/** The .h file for DoublyLinkedList.cpp.  Contains the Node class, as well as the constructor function code, as well
 * as other function declarations
 *
 * Written By: Seth Van Grinsven
 * Date: 1/26/14
 * Class: csci311
 *
 */

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <string>


class DoublyLinkedList
{
    public:
        DoublyLinkedList()
        {
            head = NULL;
            current = NULL;
            tail = NULL;
        }
        ~DoublyLinkedList();

          bool empty();
          void append(std::string &);
          void insertBefore(std::string &);
          void insertAfter(std::string &);
          void remove(std::string &);
          void begin();
          void end();
          bool next();
          bool prev();
          bool find(std::string &);
          std::string& getData();
    protected:
    private:

        /**< Node Class for the DLL.  Contains constructor,  */
        class Node
        {
            public:
                Node(std::string& name)
                {
                Node(name, NULL, NULL);
                }

                /**< Constructor of input type String, Node*, Node* */
                Node(std::string& name, Node* next, Node* prev)
                {


                songName = new std::string();
                *songName = name;
                ptrNext = next;
                ptrPrev = prev;
                }

                /**< Destructor */
                ~Node(){
                    delete songName;
                    songName = NULL;
                    ptrNext = NULL;
                    ptrPrev = NULL;
                }

                /**< Variables for Class Node */
                Node* ptrNext;
                Node* ptrPrev;
                std::string* songName;
        };

        /**< Variables for class DLL */
        Node* head;
        Node* current;
        Node* tail;
};

#endif // DOUBLYLINKEDLIST_H
