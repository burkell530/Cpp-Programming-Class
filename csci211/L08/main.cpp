
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <cstdlib>

using namespace std;

void checkValid(string k)
{

    for(int a = 0; a < k.length(); a++)
    {

        if(isdigit(k[a]) == false)
        {
            cerr<< "Error: illegal integer." << endl;
            exit(1);
        }
    }

    return;
}



// in order to access the command line arguments, declare main() like this
int main(int argc, char *argv[])
{
    int sum = 0;

     for(int a = 1; a < argc; a++)
    {
        std::stringstream s_str( argv[a] );
        string temp;
        s_str >> temp;
        checkValid(temp);

    }


    for(int a = 1; a < argc; a++)
    {
        int temp = 0;
        std::stringstream s_str( argv[a] );

        s_str >> temp;

        sum = sum + temp;
    }

    cout << sum << endl;
    return 0;

}
