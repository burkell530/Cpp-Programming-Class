#ifndef VIDEO_H
#define VIDEO_H
#include <string>

class video
{
    public:
        video(std::string title, std::string url, std::string comment, float length, int rating);
        ~video();
       void print();

       int getRating();
       float getLength();
       std::string getTitle();
       bool longer(video *a);
       bool better(video *a);
       bool titleSort(video *a);


    protected:
    private:
        std::string m_title;
        std::string m_url;
        std::string m_comment;
        float m_length;
        int m_rating;
};

#endif // VIDEO_H
