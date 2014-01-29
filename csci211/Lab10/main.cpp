#include <iostream>

using namespace std;

bool equalStrings(char[], char[]);
int largest_in_array(int[], int);
bool isInt(char[]);
bool is_array_sorted(int[], int);

int main()
{
    int label[5] = {1,2,2,4,5};


    cout << "Is Sorted: " << is_array_sorted(label,5) << endl;;



}

bool equalStrings(char p_s1[], char p_s2[])
{
    if(p_s1[0] == NULL && p_s2[0] == NULL)
    {
        return true;
    }

    else if((p_s1[0] == NULL && p_s2[0] != NULL) || (p_s1[0] != NULL && p_s2[0] == NULL))
        return false;

    else
        return equalStrings(p_s1+1, p_s2+1);

}

int largest_in_array(int values[], int size)
{
   if(size == 1)
    return values[0];

   if(values[0] > largest_in_array(values+1, size-1))
    return values[0];

   else
    return largest_in_array(values+1, size-1);

}

bool isInt(char str[])
{
    if(str[0] == NULL)
        return true;
    else if(isdigit(str[0]))
        return isInt(str+1);
    else
        return false;

}

bool is_array_sorted(int values[], int size)
{
    if(size<2)
        return true;
    if(size == 2)
    return values[0] <= values[1];

    else if(values[0] > values[1])
        return false;
    else
        return is_array_sorted(values+1,size-1);

}
