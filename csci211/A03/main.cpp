#include <iostream>
#include "video.h"
#include "vlist.h"

using namespace std;

int main()
{
    vlist videoList;


    string command;
    string title;
    string url;
    string comment;
    float length;
    int rating;

    video* vTemp;


    while (getline(cin,command))
    {
        if(command != "insert" && command != "length" && command != "remove" && command != "lookup" && command != "print" && command!="print_by_rating" && command!= "print_by_length")
        {
        cerr << "<" << command <<"> is not a legal command, giving up." << endl;
        return 1;
        }

        if(command == "insert")
        {
            getline(cin,title);
            getline(cin,url);
            getline(cin,comment);
            cin >> length;
            cin >> rating;
            cin.ignore();

           vTemp = new video(title,url,comment,length,rating);
           videoList.insertVideo(vTemp);
        }

        if(command == "remove")
        {
            getline(cin,title);
           videoList.removeVideo(title);
        }

        if(command == "print")
            videoList.print();

        if(command == "length")
            videoList.length();

        if(command == "lookup")
        {
            getline(cin,title);
            videoList.lookup(title);
        }

        if(command == "print_by_length")
            videoList.printByLength();

        if(command =="print_by_rating")
            videoList.printByRating();


    }






    return 0;

}
