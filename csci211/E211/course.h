#ifndef COURSE_H
#define COURSE_H

#include <string>


class Course
{
    public:
        Course(std::string className, int number, int time);
        ~Course();
        void print();
    protected:
    private:
        std::string m_class;
        int m_number;
        int m_time;
};

#endif // COURSE_H
