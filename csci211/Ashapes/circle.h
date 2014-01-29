#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "grid.h"

class Circle:public Shape
{
    public:
        Circle(int, int);
        void draw(Grid &);
        virtual ~Circle();
    protected:
    private:
};

#endif // CIRCLE_H
