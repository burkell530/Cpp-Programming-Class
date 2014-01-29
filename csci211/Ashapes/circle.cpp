#include "circle.h"
#include "grid.h"

Circle::Circle(int p_x, int p_y)
{
    xLoc = p_x;
    yLoc = p_y;
}

void Circle::draw(Grid &p_grid)
{
    p_grid.setChar(xLoc + 1, yLoc, 'o');
    p_grid.setChar(xLoc + 2, yLoc, 'o');
    p_grid.setChar(xLoc, yLoc + 1, 'o');
    p_grid.setChar(xLoc, yLoc + 2, 'o');

    p_grid.setChar(xLoc+3, yLoc + 1, 'o');
    p_grid.setChar(xLoc+3, yLoc + 2, 'o');

    p_grid.setChar(xLoc+1, yLoc + 3, 'o');
    p_grid.setChar(xLoc+2, yLoc + 3, 'o');

}

Circle::~Circle()
{
    //dtor
}
