#ifndef GRID_H
#define GRID_H


class Grid
{
    public:
        Grid();
        virtual ~Grid();
        void print();
        void setChar(int, int, char);
    protected:
    private:
    int height;
    int width;
      char** gridArray;
};

#endif // GRID_H
