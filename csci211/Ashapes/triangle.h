#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include "grid.h"
class Triangle:public Shape
{
    public:
        Triangle(int, int);
        void draw(Grid &);
        virtual ~Triangle();
    protected:
    private:
};

#endif // TRIANGLE_H
