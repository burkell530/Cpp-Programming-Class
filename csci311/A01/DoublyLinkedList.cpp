
/** A Doubly linked list, meant to hold type string.  Variables are head, current and tail but are private.
 *
 * Written By: Seth Van Grinsven
 * Date: 1/26/2014
 * Class: Csci-311
 *
 */





#include "DoublyLinkedList.h"
#include <string>
#include <iostream>
using namespace std;


// Destructor.  Dissasembles the linked list.
DoublyLinkedList::~DoublyLinkedList()
{
    //dtor
    Node* ptr = head;
    while(ptr && ptr->ptrNext)
    {
        ptr = ptr->ptrNext;
        delete ptr->ptrPrev;
    }
    delete ptr;
    head = NULL;
    tail = NULL;
    current = NULL;
}

/** A function to determine if the dll is empty.
 *
 * Returns Bool, True if empty, otherwise false;
 *
 */

bool DoublyLinkedList::empty()
{
    if(head == NULL) return true;
    else return false;
}

/** Appends song to end of list.  Changes current to last song
 *
 * Input: Song Name (string)
 *
 * Returns: void
 *
 */

void DoublyLinkedList::append(std::string& name)
{

    //if playlist is empty
    if(empty())
    {
        //cout << "Empty, Creating First Node" << endl;
        current = tail = head = new Node(name,NULL, NULL);
    }

    //everywhere else
    else
    {
        //Adds to end of list
       tail -> ptrNext = new Node(name, NULL, tail);
       current = tail = tail -> ptrNext;
    }
    return;
}

/** inserts the song before the current and changes the current to the song
 *
 * input: Song name (string)
 *
 * returns: void
 *
 */

void DoublyLinkedList::insertBefore(std::string& name)
{
    //if playlist is empty
    if(empty()) current = tail = head = new Node(name,NULL, NULL);

    //if current is first in playlist.
    else if(head == current) current = head = head -> ptrPrev = new Node(name, head, NULL);

    //if current song is anywhere but first or empty list
    else
    {
        Node* temp = current->ptrPrev;
        current = temp ->ptrNext = current-> ptrPrev = new Node(name, current, temp);
    }

    return;
}

/** A function to insert song after the current and changes the current to the song
 *
 * input: Song name (string)
 *
 * output: void
 *
 */

void DoublyLinkedList::insertAfter(std::string& name)
{
    //if playlist is empty
    if(empty()) current = tail = head = new Node(name,NULL, NULL);
    //if song is the end
    else if(tail == current) append(name);
    //anywhere else
    else
    {
        Node* temp = current->ptrNext;
        current = temp ->ptrPrev = current->ptrNext = new Node(name,temp, current);
    }
    return;
}

/** Removes song from the list.  Does nothing if song not found
 *
 * input: Song Name (String)
 *
 * output (void)
 *
 */

void DoublyLinkedList::remove(std::string& name)
{
    // No song return;
    if(!find(name)) return;

    //cout << "Song Found, Attempting to Remove" << endl;
    //one song and on list.
    if(head == tail)
    {
        //cout << "Removing first Song" << endl;
        delete head;
        head = NULL;
        tail = NULL;
        current = NULL;
    }
    //if song at front of list >1
    else if(*(head -> songName) == name)
    {
        Node* temp = head;
        current = head = temp->ptrNext;
        //sets ptrPrev
        head -> ptrPrev = NULL;
        delete temp;

    }
    //Not empty, Not at Front
    else
    {
        //finds the first instance of the song in playlist, sets to PTR
        Node* ptr = head;
        while(*(ptr -> songName) != name)
        {
            ptr = ptr->ptrNext;
        }
        //at end of list
        if(ptr == tail)
        {
            ptr = ptr->ptrPrev;
            ptr->ptrNext = NULL;
            delete tail;
            current = tail = ptr;
        }
        //in middle of list
        else
        {
            current = ptr->ptrPrev->ptrNext = ptr->ptrNext;
            ptr->ptrNext->ptrPrev = ptr->ptrPrev;
            delete ptr;

        }
    }
    return;
}


/** gets song name of current
 *
 * input: none
 *
 * returns: song name (string)
 *
 */

std::string& DoublyLinkedList::getData()
{

    return *(current -> songName);
}


/**  Checks if the song is in the list.
 *
 *  input: song name (String)
 *
 *  output: returns true if song is in list, else false
 *
 */

bool DoublyLinkedList::find(std::string& name)
{
    //cout << "Looking for Song: " << name << endl;
    bool b = false;
    Node* ptr = head;
    while(ptr && !b)
    {
        if(*(ptr->songName) == name)
        {
            current = ptr;
            b=true;
        }
        ptr = ptr -> ptrNext;
    }

    return b;
}

/**< Sets current song to begin of list > */
void DoublyLinkedList::begin()
{
    current = head;
    return;
}


/**< Sets current song to end of list > */
void DoublyLinkedList::end()
{
    current = tail;
    return;
}

/**< Changes current to next song if there is one, returns false if at end */
bool DoublyLinkedList::next()
{
    if(!(current->ptrNext))
        return false;
    else current = current -> ptrNext;
        return true;

}

/**< Changes current song to previous, returns false if no song before current */
bool DoublyLinkedList::prev()
{
    if(!(current->ptrPrev))
        return false;
    else
        current = current ->ptrPrev;
        return true;
}
