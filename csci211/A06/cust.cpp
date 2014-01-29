#include "cust.h"
#include <fstream>
#include <iostream>

using namespace std;


Cust::Cust(string p_name, string p_type, int p_numItems)
{
    name = p_name;

    if(p_type == "robber") robber = true;
    else robber = false;

    numItems = p_numItems;
}
void Cust::printEnterStore(ofstream &output,int p_time)
{
    output << p_time << ": " << name << " entered store" << endl;
    return;
}
void Cust::printDoneShopping(ofstream &output,int p_time)
{
    output << p_time << ": " << name << " done shopping" << endl;
    return;
}
void Cust::printEnteredCheckout(ofstream &output,int p_time, int p_checkerNum)
{
    output << p_time << ": " << name << " started checkout with checker " << p_checkerNum << endl;
    return;
}
int Cust::printResult(ofstream &output,int p_time, int p_checkerNum, int p_checkerMoney)
{
    string item = " item";
    if(numItems>1) item = " items";

    int money = p_checkerMoney;

    if(robber)
        //37: Maggie stole $500 and 1 item from checker 1
        {
            money = 0;
            output << p_time << ": " << name << " stole $" << p_checkerMoney << " and " << numItems << item << " from checker " << p_checkerNum << endl;
        }
    else
        //120: Bart paid $115 for 23 items to checker 0
        {
            money = money + numItems * 5;
            output << p_time << ": " << name << " paid $" << numItems * 5<< " for " << numItems << item << " to checker "  << p_checkerNum << endl;
        }
    return money;
}



Cust::~Cust()
{
    //dtor
}
