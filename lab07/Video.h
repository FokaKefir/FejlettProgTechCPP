#ifndef CPP_2022_VIDEO_H
#define CPP_2022_VIDEO_H

#include <string>
#include <ostream>

using namespace std;

class Video {
private:
    string id;
    string title;
    double length;
    string uploader;
    long uploaded;

public:
    Video(const string &id, const string &title, double length, const string &uploader, long uploaded);
    const string &getId() const;
    const string &getTitle() const;
    double getLength() const;
    const string &getUploader() const;
    long getUploaded() const;

    friend ostream &operator<<(ostream &os, const Video &video);

};


#endif //CPP_2022_VIDEO_H
