#ifndef SHAPE_H
#define SHAPE_H

#include "grid.h"

class Shape
{
    public:
        virtual void draw(Grid &grid) = 0;  // this is a pure virtual function
        virtual ~Shape();
    protected:
        int xLoc;
        int yLoc;
    private:
};

#endif // SHAPE_H
