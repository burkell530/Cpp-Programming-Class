#include "square.h"

Square::Square(int p_x, int p_y, int p_size)
{
    xLoc = p_x;
    yLoc = p_y;
    size = p_size;
    //ctor
}

Square::~Square()
{
    //dtor
}

void Square::draw(Grid &p_grid)
{
    for(int a = 0; a < size; a++)
    {
        for(int b =0; b< size; b++)
        {
            if(a == 0 || a == size-1)
                p_grid.setChar(xLoc+a,yLoc+b,'*');
            else if(b == 0 || b == size-1)
                p_grid.setChar(xLoc+a,yLoc+b,'*');
        }
    }
}
