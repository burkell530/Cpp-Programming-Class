

#include "video.h"
#include <iostream>

using namespace std;

video::video(std::string title, std::string url, std::string comment, float length, int rating)
{
    m_title = title;
    m_url = url;
    m_comment = comment;
    m_rating = rating;
    m_length = length;
}



void video::print()
{
      cout << m_title << ", ";
      cout << m_url << ", ";
      cout << m_comment << ", ";
      cout << m_length << ", ";

      for(int a = m_rating; a>0;a--)
      {
      cout << "*";
      }

      cout<< endl;

}


bool video::longer(video *a)
{
      return m_length > a->m_length;
}

bool video::better(video *a)
{
      return m_rating < a->m_rating;
}

bool video::titleSort(video *a)
{
      return m_title > a->m_title;
}
std::string video::getTitle()
{
    return m_title;
}

float video::getLength()
{
    return m_length;
}

int video::getRating()
{
    return m_rating;
}
video::~video()
{
    //dtor
}
