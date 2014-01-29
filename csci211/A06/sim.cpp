#include <iostream>
#include <sstream>
#include <cstdlib>
#include "pqueue.h"
#include <fstream>

#ifndef SIM_H
#define SIM_H
class sim
{
    public:
        sim();
        ~sim();
        void run(ofstream &, ifstream &);
        void setCheckers(int p_checkers){numCheckers = p_checkers;}
        void setBreak(int p_length){breakLength = p_length;}
    protected:
    private:
        int time;
        int numCheckers;
        int breakLength;
};


using namespace std;


/********************************************//**
CHECK ARRAY OF STRINGS IS DIGIT

Return:
    True if all digit
    False if not all digit
 ***********************************************/

bool isDigit(string p_string)
{

    for(int a = 0; a < p_string.length(); a++)
    {

        if(!isdigit(p_string[a]))
            return false;
    }

    return true;
}






/********************************************//**
ERROR FUNCTION (OUTPUT)

Error Code:
1 - Invalid Command Line Arguments
2 - Could not Open Input File
3 - Could Not open Output File
4 - Invalid Number of Checkers
5 - Invalid Checker Break
************************************************/

void error(int p_errorNum, string p_name)
{

switch(p_errorNum)
    {
    case 0:
        cerr << "Error: invalid number of command line arguments." << endl;
        break;
    case 1:
        cerr << "Error: could not open input file <" << p_name << ">."<< endl;
        break;
    case 2:
        cerr << "Error: could not open output file <" << p_name << ".out>." << endl;
        break;
    case 3:
        cerr << "Error: invalid number of checkers specified." << endl;
        break;
    case 4:
        cerr << "Error: invalid checker break duration specified." << endl;
        break;
    }

    exit(1);

}

void error(int p)
{
    error(p, "NULL");
}






int main(int argc, char* argv[])
{


    if(argc !=5) error(0);

    if(!isDigit(argv[1])) error(3);
    if(!isDigit(argv[2])) error(4);

        istringstream temp;
        temp.str(argv[1]);
        int numCheckers;
        temp >> numCheckers;

        temp.clear();
        temp.str(argv[2]);
        int breakLength;
        temp >> breakLength;



        ifstream inFile;
        inFile.open(argv[3]);

        if(!inFile)
        {
            error(1, argv[3]);
        }

        ofstream outFile;
        outFile.open(argv[4]);

        if(!outFile)
        {
            error(2,argv[4]);
        }




        sim simulation;
        simulation.setBreak(breakLength);
        simulation.setCheckers(numCheckers);
        simulation.run(outFile, inFile);

    return 0;
}

struct Checker
{
    int currentMoney;
    int timeLeftBreak;
    int timeLeftCheckout;
    Cust* currentCustomer;
    bool open;
};


using namespace std;

sim::sim()
{
    time = 0;
    numCheckers = 0;
    breakLength = 0;

}

sim::~sim()
{
    //dtor
}

void sim::run(ofstream &outputStream, ifstream &inputStream)
{

    int numOfCusts = 0;
    bool workCheck = false;

    Checker checker[numCheckers];

    for(int a = 0; a < numCheckers; a++)
    {
        checker[a].currentMoney = 500;
        checker[a].open = true;
        checker[a].timeLeftBreak = 0;
        checker[a].timeLeftCheckout = 0;
    }

    pqueue arrivalQueue;
    pqueue shoppingQueue;
    pqueue checkoutQueue;

    string inName, inType;
    int inArrival, inNumItems;
    while(inputStream >> inName)
    {
        inputStream >> inType;
        inputStream >> inArrival;
        inputStream >> inNumItems;


        Cust *tempCust = new Cust(inName, inType, inNumItems);
        arrivalQueue.enqueue(inArrival,tempCust);
        numOfCusts++;

        // Cust tempCust(inName, inType, inArrival, inNumItems);

    }
    Cust *custPTR;
    int totalTime;
    if(numOfCusts > 0) totalTime = 1;
    else totalTime = 0;

    /********************************************//**
            SIMULATION IS DONE HERE
    ***********************************************/

    for(int time = 1; numOfCusts>0; time++,totalTime++)
    {

        /********************************************//**
                        ARRIVAL QUEUE
         ***********************************************/

        while(arrivalQueue.getLength()!=0 && arrivalQueue.prioPeek() == time)
        {
            custPTR = arrivalQueue.dequeue(workCheck);
            if(!workCheck) cerr << "ERROR!!!" << endl;
            custPTR -> printEnterStore(outputStream, time);
            shoppingQueue.enqueue(time + custPTR->getNumItems()*3,custPTR);

        }

        /********************************************//**
                         SHOPPING QUEUE
          ***********************************************/

        while(shoppingQueue.getLength()!=0 && shoppingQueue.prioPeek() == time)
        {
            custPTR = shoppingQueue.dequeue(workCheck);
            if(!workCheck) cerr << "ERROR!!!" << endl;
            custPTR -> printDoneShopping(outputStream, time);
            checkoutQueue.enqueue(0,custPTR);
        }

        /********************************************//**
                        CHECKER QUEUE
        ***********************************************/

        for(int a = 0; a < numCheckers; a++)
        {
            if(!checker[a].open)
            {
                if(checker[a].timeLeftCheckout > 0)
                {
                    checker[a].timeLeftCheckout--;

                    //CHECKS IF FINISHED
                    if(checker[a].timeLeftCheckout == 0)
                    {
                        checker[a].currentMoney = checker[a].currentCustomer -> printResult(outputStream,time,a,checker[a].currentMoney);
                        numOfCusts--;

                            //IF ROBBER GOES ON BREAK
                         if(checker[a].currentCustomer -> isRobber()) checker[a].timeLeftBreak = breakLength;

                         checker[a].currentCustomer = NULL;

                    }

                }
                else if(checker[a].timeLeftBreak > 0)
                {
                    checker[a].timeLeftBreak--;

                }


                if(checker[a].timeLeftBreak == 0 && checker[a].timeLeftCheckout == 0)
                {
                    checker[a].open=true;
                }
            }
        }

        for(int a = 0; a < numCheckers; a++)
            {

            if(checker[a].open)
            {
                if(checkoutQueue.getLength() > 0)
                {
                    custPTR = checkoutQueue.dequeue(workCheck);
                    if(!workCheck) cerr << "ERROR!!!" << endl;

                    custPTR -> printEnteredCheckout(outputStream,time,a);

                    checker[a].currentCustomer = custPTR;
                    checker[a].open = false;


                    if(custPTR -> isRobber()) checker[a].timeLeftCheckout = 7;
                    else checker[a].timeLeftCheckout = (custPTR -> getNumItems()) * 2;
                }
            }

        }


    }
    /********************************************//**
            SIMULATION ENDS
    ***********************************************/

    for(int a = 0; a < numCheckers; a++)
        outputStream << "registers[" << a << "] = $" << checker[a].currentMoney << endl;

    outputStream << "time = " << totalTime << endl;



}



#endif // SIM_H
