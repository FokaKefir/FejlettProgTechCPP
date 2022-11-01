#include "Video.h"

Video::Video(const string &id, const string &title, double length, const string &uploader, long uploaded) :
    id(id), title(title), length(length), uploader(uploader), uploaded(uploaded) {}

const string &Video::getId() const {
    return this->id;
}

const string &Video::getTitle() const {
    return this->title;
}

double Video::getLength() const {
    return this->length;
}

const string &Video::getUploader() const {
    return this->uploader;
}

long Video::getUploaded() const {
    return this->uploaded;
}

ostream &operator<<(ostream &os, const Video &video) {
    os << video.id << " " << video.title << " " << video.length << " " << video.uploader << " " << video.uploaded << endl;
    return os;
}


