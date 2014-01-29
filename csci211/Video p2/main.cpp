#include <iostream>
#include <string>
#include "video.h"

using namespace std;

int main()
{
    //video pointer array
    video *videos[100];

    //all variables
    std::string title;
    std::string url;
    std::string comments;
    float length;
    int rating;

    std::string sortType;
    std::string temp;

    //get sort type
    getline(cin,sortType);

    //check for valid sort type
    if(!(sortType == "rating" || sortType == "length" || sortType == "title"))
    {
        cerr << sortType + " is not a legal sorting method, giving up." << endl;
        return 1;
    }

//temp to count videos
    int numVideos = 0;

//grabs the inputs and stores them in a new video
    while(cin >> title)
    {
        //Error over 100 videos
        if(numVideos == 100)
        {
        cerr << "Too many videos, giving up." << endl;
        return 1;
        }

    getline(cin,temp);
    title = title + temp;


    getline(cin, url);
    getline(cin, comments);
    cin >> length;
    cin >> rating;
    cin.ignore();

    videos[numVideos] = new video(title,url,comments,length,rating);
    numVideos++;
    }

    //SORTING
    //bubble sort by length
    if(sortType == "length")
    {
        for (int last = numVideos -1; last > 0; last--)
            for (int cur = 0; cur < last; cur++)
                if (videos[cur]->longer(videos[cur+1]))
                    swap(videos[cur], videos[cur+1]);  // since videos is an array of pointers you can simply swap the addresses at the cur and cur+1 locations.
    }
    //bubble sort by rating
    else if(sortType == "rating")
    {
        for (int last = numVideos -1; last > 0; last--)
            for (int cur = 0; cur < last; cur++)
                if (videos[cur]->better(videos[cur+1]))
                    swap(videos[cur], videos[cur+1]);
    }
    //bubble sort by title
    else if(sortType == "title")
    {
        for (int last = numVideos -1; last > 0; last--)
            for (int cur = 0; cur < last; cur++)
                if (videos[cur]->titleSort(videos[cur+1]))
                    swap(videos[cur], videos[cur+1]);
    }

    //print out video array
    for(int a = 0; a<numVideos; a++)
    {
        videos[a] -> print();
    }

    //End of main
    return 0;
}
