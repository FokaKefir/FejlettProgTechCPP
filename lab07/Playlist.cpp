#include "Playlist.h"

Playlist::Playlist(int capacity) : capacity(capacity) {
    this->title = "";
    this->count = 0;
    this->list = new Video*[this->capacity];
}

Playlist::Playlist(const Playlist &copy) {
    this->title = copy.title;
    this->capacity = copy.capacity;
    this->list = new Video*[this->capacity];
    this->count = copy.count;
    for (int i = 0; i < this->count; ++i) {
        this->list[i] = copy.list[i];
    }
}

Playlist::Playlist(Playlist &&move) noexcept {
    this->title = move.title;
    this->capacity = move.capacity;
    this->count = move.count;
    this->list = move.list;
    move.list = nullptr;
    move.count = 0;
}


Playlist::~Playlist() {
    //for (int i = 0; i < this->count; ++i) {
    //    delete list[i];
    //}
    delete[] list;
}

const string &Playlist::getTitle() const {
    return this->title;
}

void Playlist::setTitle(const string &title) {
    this->title = title;
}

int Playlist::videos() const {
    return count;
}

void Playlist::append(Video *video) {
    if (count < capacity) {
        this->list[count] = video;
        this->count++;
    }
}

void Playlist::sort(bool less(const Video *a, const Video *b)) {
    std::sort(list, list + count, less);
}

Video *Playlist::operator[](int index) {
    if (index >= count or index < 0)
        return nullptr;
    return list[index];
}

const Video *Playlist::operator[](int index) const {
    if (index >= count or index < 0)
        return nullptr;
    return list[index];
}

Playlist &Playlist::operator=(const Playlist &copy) {
    delete[] list;
    this->title = copy.title;
    this->capacity = copy.capacity;
    this->count = copy.count;
    this->list = new Video*[this->capacity];
    for (int i = 0; i < this->count; ++i) {
        this->list[i] = copy.list[i];
    }
    return *this;
}

Playlist &Playlist::operator=(Playlist &&move) noexcept {
    delete[] list;
    this->title = move.title;
    this->capacity = move.capacity;
    this->count = move.count;
    this->list = move.list;
    move.list = nullptr;
    move.count = 0;
    return *this;
}

Playlist operator+(const Playlist &a, const Playlist &b) {
    Playlist playlist(a.capacity + b.capacity);
    playlist.title = a.title + " and " + b.title;
    playlist.count = 0;
    for (int i = 0; i < a.count; ++i) {
        playlist.append(a.list[i]);
    }
    for (int i = 0; i < b.count; ++i) {
        playlist.append(b.list[i]);
    }
    return playlist;
}

ostream &operator<<(ostream &os, const Playlist &playlist) {
    os << playlist.title << ":\n";
    for (int i = 0; i < playlist.count; ++i) {
        os << *(playlist[i]);
    }
    return os;
}

