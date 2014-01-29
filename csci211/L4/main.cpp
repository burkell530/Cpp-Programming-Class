#include <iostream>
#include "list.h"
using namespace std;

int main()
{
    list intlist;
    int temp;


    while(cin>>temp)
    {
        intlist.insertEnd(temp);
    }

    intlist.print();
    intlist.sum();






    return 0;
}

