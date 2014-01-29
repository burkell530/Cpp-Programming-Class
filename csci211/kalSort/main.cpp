#include "kalList.h"
#include <iostream>

using namespace std;

int main()
{

    kalList list;
    list.add(0);
    list.add(2);
    list.add(5);
    cout << "Length: "<<list.getLength() << endl;
    cout << list.popTop() << endl;
    cout << list.popTop() << endl;
    cout << list.popTop() << endl;
    cout << list.popTop() << endl;



    return 0;
}
