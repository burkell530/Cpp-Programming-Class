#include <iostream>
#include "dstack.h"
#include <stdio.h>
#include <ctype.h>
#include <cmath>
#include <cstdlib>

using namespace std;

void error()
{
    cerr << "Error: Invalid expression." << endl;
    exit(1);
}

bool endValue(dstack &dStack)
{

    bool properInput;
    double answer;
    answer = dStack.pop(properInput);


    if(properInput)
    {
        double temp = dStack.pop(properInput);

        if(properInput == false)
        {
            cout << answer << endl;
            return true;
        }

        else
        {
            return false;
        }

    }

    return false;

}




/*
RETURNS:
0 - INVALID
1 - WHITESPACE
2 - OPERAND
3 - OPERATOR
4 - EOF
5 - SQRT
6 - SIN
7 - COS
8 - AVE
*/


int checkChar(char c)
{
    char operators[5] ={'+','-','*','/','^'};
    char operands[11] ={'0','1','2','3','4','5','6','7','8','9','.'};
    char whiteSpace[3] = {' ','\n','\t'};


    for(int a = 0; a < 3; a++)
    {
        if(whiteSpace[a] == c)
        {
            return 1;
        }
    }

    for(int a = 0; a < 5; a++)
    {
        if(operators[a] == c)
        {
            return 3;
        }
    }

    for(int a = 0; a < 11; a++)
    {
        if(operands[a] == c)
        {
            return 2;
        }
    }

    if(c == 's')
    {
        cin.ignore();
        c=cin.peek();

        if(c=='i')
        {
            cin.ignore();
            c=cin.peek();

            if(c== 'n')
            {
                cin.ignore();
                return 6;
            }
        }

        else if(c=='q')
        {
            cin.ignore();
            c=cin.peek();

            if(c== 'r')
            {
                cin.ignore();
                 c=cin.peek();
                 if(c=='t')
                 {
                    cin.ignore();
                    return 5;
                 }
            }
        }

        return 0;
    }


     if(c == 'a')
    {
        cin.ignore();
        c=cin.peek();

        if(c=='v')
        {
            cin.ignore();
            c=cin.peek();

            if(c== 'e.')
            {
                cin.ignore();
                return 8;
            }
        }

        return 0;
    }

     if(c == 'c')
    {
        cin.ignore();
        c=cin.peek();

        if(c=='o')
        {
            cin.ignore();
            c=cin.peek();

            if(c== 's')
            {
                cin.ignore();
                return 7;
            }
        }

        return 0;
    }

    return 0;
}



//OPERATION
bool operation(char p_Char, dstack &p_Stack)
{
    bool errorCheck = true;
    double valueTwo = p_Stack.pop(errorCheck);
    double valueOne = p_Stack.pop(errorCheck);
    double valueEnd;

    if (errorCheck == false) return false;


    switch(p_Char)
    {
        case '+':
            valueEnd = valueOne + valueTwo;
            break;
        case '-':
            valueEnd = valueOne - valueTwo;
            break;
        case '/':
            if(valueTwo == 0) return false;
            valueEnd = valueOne / valueTwo;
            break;
        case '*':
            valueEnd = valueOne * valueTwo;
            break;
        case '^':
            valueEnd = pow(valueOne, valueTwo);
            break;
    }
    p_Stack.push(valueEnd);

    return true;
}


//OPERATONS EXTRA CREDIT
void operationEC(int a, dstack &dStack)
{

    double myDouble;
    bool work = true;

    switch(a)
    {
        /*
        0 - SQRT
        1 - SIN
        2 - COS
        3 - AVG
        */
        case 0:

            myDouble = dStack.pop(work);
            if(!work) error();
            dStack.push(sqrt(myDouble));
            break;
        case 1:
            myDouble = dStack.pop(work);
            if(!work) error();
            dStack.push(sin(myDouble*(M_PI/180)));
            break;

        case 2:
            myDouble = dStack.pop(work);
            if(!work) error();
            dStack.push(cos(myDouble*(M_PI/180)));
            break;
        case 3:
            double tempSum = 0;
            int length = dStack.length();
            for(int k = 0; k < length;k++)
            {
            tempSum = tempSum + dStack.pop(work);
            if(!work) error();
            }

            dStack.push(tempSum/length);
            break;
    }

    return;



}


int main()
{
    dstack dStack;
    bool toContinue = true;
    double tempValue;
    char c;






    while((c = cin.peek()) && toContinue)
    {
        if(cin.peek()==EOF || c == '=') // CHANGE TO EOF
        {
            bool answer = endValue(dStack);
            toContinue = false;

            if(answer)
                return 0;
            else
            {
                error();
            }
        }

        switch (checkChar(c))
        {
            //ERROR
            case 0:
                error();
            //WSpace
            case 1:
                cin.ignore();
                break;
            //NUMBER
            case 2:
                cin >> tempValue;
                dStack.push(tempValue);
                if(!cin.good())
                {
                    error();
                }
                break;
            //OPERATOR (NON EC)
            case 3:
                toContinue = operation(c, dStack);
                cin.ignore();
                break;
            case 5: operationEC(0, dStack); break;
            case 6: operationEC(1, dStack); break;
            case 7: operationEC(2, dStack); break;
            case 8: operationEC(3, dStack); break;

        }
    }




    error();
    return 1;
}
