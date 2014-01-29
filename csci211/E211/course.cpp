#include "course.h"
#include <iostream>

#include <string>


Course::Course(std::string className, int number, int time)
{
    m_class = className;
    m_number = number;
    m_time = time;
}

void Course::print()
{
    std::cout << m_class << " " << m_number << " at " << m_time << std::endl;

}
Course::~Course()
{
    //dtor
}
