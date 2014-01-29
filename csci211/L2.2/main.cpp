#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool allEven = true;
    int a;

    while(cin >> a)
    {
        if(a%2 != 0)
        {
            allEven = false;
        }
    }


    if( allEven == false)
    {
        cerr << "not all even" << endl;
        return 1;
    }
    else
    {
        cout << "all even" << endl;
        return 0;
    }
}
