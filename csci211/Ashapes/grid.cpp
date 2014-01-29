#include "grid.h"
#include <iostream>

using namespace std;




Grid::Grid()
{
    height = 24;
    width = 60;
        gridArray = new char*[height];
        for(int i = 0; i<height; i++)
        gridArray[i] = new char[width];


    for(int a = 0; a < height; a++)
    {
            for(int b=0; b < width; b++)
            {
                gridArray[a][b] = ' ';
            }

    }
}

Grid::~Grid()
{
    //dtor
}

void Grid::setChar(int p_x, int p_y, char p_c)
{

    if(p_x < 0 || p_x >= width || p_y < 0 || p_y >= height)   return;
    else
        gridArray[p_y][p_x] = p_c;
    return;
}

void Grid::print()
{


    for(int a = 0; a < height; a++)
    {
        for(int b = 0; b < width; b++)
        {
            cout << gridArray[a][b];
        }

        cout << endl;
    }

}
