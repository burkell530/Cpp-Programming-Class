#include <iostream>

using namespace std;


int main()
{
    int counter = 0;
    int i = 0;
    counter++;
    int n = 10;

    counter++;

    while(i<n)
    {

        counter++;
        for(int k = i+1; k<n-1; k++)
        {
            counter++;
            counter++;
        }
        counter++;
        for(int u = 0; u <= n-1; u++)
        {
            counter++;
            counter++;
        }
        counter++;
        i++;
    }

cout << "counter: " << counter << endl;

}
