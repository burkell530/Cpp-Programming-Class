#include "point.h"
#include "grid.h"

Point::Point(int p_x, int p_y, char p_char)
{
    xLoc = p_x;
    yLoc = p_y;
    charLOL = p_char;
}

void Point::draw(Grid &p_grid)
{
    p_grid.setChar(xLoc, yLoc, charLOL);
}

Point::~Point()
{
    //dtor
}
