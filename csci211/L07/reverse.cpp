#include <iostream>
#include "dstack.h"

using namespace std;

int main()
{
    dstack dStack;

    double myDouble;
    while(cin >> myDouble)
    {
        dStack.push(myDouble);
    }

    bool work = true;

    while(work)
    {
        myDouble = dStack.pop(work);

        if(work)
            cout << myDouble << endl;
    }




    return 0;
}
