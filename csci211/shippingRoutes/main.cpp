#include <iostream>
#include <vector>
#include "stree.h"

using namespace std;


int main()
{
    Stree shippingTree;

    string command;
    while(cin >> command)
    {
         if(command == "insert")
        {

            string parent;
            string value;
            int dist;

            cin >> parent;
            cin >> value;
            cin >> dist;
            bool returnCheck;

            returnCheck = shippingTree.insertNode(parent, value, dist);

            if(!returnCheck)
            {
                cerr << "Error: could not insert " <<  parent << ", " <<  value << endl;
            }
        }
        else if(command =="remove")
        {
            string value;
            cin >> value;

            bool returnCheck;
            returnCheck = shippingTree.deleteNode(value);
            if(!returnCheck)
            {
                cerr << "Error: could not remove " << value << endl;
            }
        }
        else if(command == "lookup")
        {
            string value;

            cin >> value;

            vector<string> outputVec;
            vector<int> dist;
            outputVec = shippingTree.lookup(value, dist);

            if(outputVec[0] == "Failed")
            {
                cerr << "Error: " << value <<" not in tree" << endl;
            }
            else
            {
                cout << outputVec[0] << ": ";
                cout << outputVec[1];
                if(dist[0] != 0)
                {
                    cout << "(" << dist[0] <<")";
                }
                cout << ", " << outputVec[2];
                if(dist[1] != 0)
                {
                    cout << "(" << dist[1] <<")";
                }
                cout << ", " << outputVec[3];
                if(dist[2] != 0)
                {
                    cout << "(" << dist[2] <<")";
                }
                cout << endl;
            }

        }
        else if(command == "path")
        {
            string p1;
            string p2;

            cin>>p1;
            cin>>p2;

            vector<string> path = shippingTree.path(p1, p2);

            if(path[0] == "Failed")
            {
                cerr << "Error: no path between " <<  p1 << " and " << p2 << endl;
            }
            else
            {
                for(int a = 0; a < path.size()-1; a++)
                {
                    cout << path[a] << " --> ";
                }

                cout << path[path.size()-1] <<endl;
            }

        }
        else if(command =="distance")
        {
            string s1;
            string s2;
            cin >> s1;
            cin >> s2;
            int dist;
            bool workCheck;
            workCheck = shippingTree.distNodes(s1,s2,dist);
            if(!workCheck)
            {
                cerr << "Error: no path between " << s1 << " and " << s2 << endl;
            }
            else
            {
                string miles = "miles";
                if(dist == 1) miles = "mile";
                cout << s1 << " to " << s2 << " is " << dist <<" "<< miles << endl;
            }

        }
        else if(command == "countChild")
        {
            int a = 0;
            int b = 0;
            int c = 0;
            shippingTree.countChild(a,b,c);
            cout << "Zero = " << a << endl;
            cout << "One = " << b << endl;
            cout << "two = " << c << endl;
        }
        else
        {
            cerr << "Error: <" << command << "> is not a valid command" << endl;
            string yolo;
            getline(cin, yolo);
        }
    }

    return 0;
}
