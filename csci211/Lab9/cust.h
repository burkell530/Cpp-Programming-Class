#ifndef CUST_H
#define CUST_H

#include <iostream>
#include <fstream>



using namespace std;
class Cust
{



    public:
        Cust(string, string, int);
        Cust(string, int, int, bool);
        ~Cust();
        void printEnterStore(ofstream &,int);
        void printDoneShopping(ofstream &,int);
        void printEnteredCheckout(ofstream &,int, int);
        int printResult(ofstream &,int, int, int);
        void print(ostream&);




        //RETURNS
        bool isRobber() {return robber;}
        int getNumItems() {return numItems;}
        string getName() {return name;}

    private:
        bool robber;
        int numItems;
        string name;
        int arrivalTime;

};

#endif // CUST_H

