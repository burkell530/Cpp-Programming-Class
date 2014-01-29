#include <iostream>
using namespace std;

int main()
{

}


bool treeSum(int targetLevel)
{
if(targetLevel =< 0) return false;
int curLevel = 1;
int sum = 0;
treeSum(root, targetLevel, curLevel, sum)
return true;
}

treeSum(Node* cur, int targetLevel, int &curLevel, int &sum)
{
    if(cur == NULL)
    {
        curLevel--;
        return;
    }
    if(curLevel == targetLevel)
    {
        curLevel--;
        sum = sum + cur->value;
        return;
    }
    else
    {
        treeSum(cur->ptrLeft, targetLevel, curLevel++, sum)
        treeSum(cur->ptrRight, targetLevel, curLevel++, sum)
    }
}

int* values tree.dump()
{
    int* array = new int[tree.size()];
    iter = 0;
    fillArray(array,iter, root)
}

void fillArray(int* array, int& iter, Node* cur)
{
    if(!cur) return

    *(array+iter) = value;
    iter++;
    fillArray(array, iter, cur->ptrLeft);
    fillArray(array, iter, cur->preRight);

}




