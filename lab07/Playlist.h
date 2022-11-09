#ifndef CPP_2022_PLAYLIST_H
#define CPP_2022_PLAYLIST_H

#include "Video.h"
#include <algorithm>

using namespace std;

class Playlist {
private:
    string title;
    Video **list;
    int capacity;
    int count;

public:
    Playlist(int capacity = 200);
    Playlist(const Playlist &copy);
    Playlist(Playlist &&move) noexcept;
    ~Playlist();

    const string &getTitle() const;
    void setTitle(const string &title);

    int videos() const;
    void append(Video *video);
    void sort(bool less(const Video *a, const Video *b));

    Video* operator[](int index);
    const Video* operator[](int index) const;

    Playlist &operator=(const Playlist &copy);
    Playlist &operator=(Playlist &&move) noexcept;

    friend Playlist operator+(const Playlist &a, const Playlist &b);
    friend ostream &operator<<(ostream &os, const Playlist &playlist);
};


#endif //CPP_2022_PLAYLIST_H
