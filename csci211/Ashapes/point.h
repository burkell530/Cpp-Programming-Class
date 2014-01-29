#ifndef POINT_H
#define POINT_H

#include "shape.h"
#include "grid.h"
class Point:public Shape
{
    public:
        Point(int, int, char);
        void draw(Grid &);
        virtual ~Point();
    protected:
    private:

    char charLOL;
};

#endif // POINT_H
