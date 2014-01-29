#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"
#include "grid.h"


class Square : public Shape
{
    public:
        Square(int, int, int);
        void draw(Grid &);
        virtual ~Square();
    protected:
    private:
        int size;
};

#endif // SQUARE_H
