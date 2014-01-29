#include "triangle.h"
#include "grid.h"
Triangle::Triangle(int p_x, int p_y)
{
   xLoc = p_x;
   yLoc = p_y;
}

void Triangle::draw(Grid &p_grid)
{
    p_grid.setChar(xLoc+2, yLoc, '+');
    p_grid.setChar(xLoc, yLoc+2, '+');
    p_grid.setChar(xLoc+1, yLoc+1, '+');

    p_grid.setChar(xLoc+3, yLoc+1, '+');
    p_grid.setChar(xLoc+4, yLoc+2, '+');

    p_grid.setChar(xLoc+1, yLoc+2, '+');
    p_grid.setChar(xLoc+2, yLoc+2, '+');
    p_grid.setChar(xLoc+3, yLoc+2, '+');



}

Triangle::~Triangle()
{
    //dtor
}
