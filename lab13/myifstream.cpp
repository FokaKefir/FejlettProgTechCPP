#include "myifstream.h"

myifstream::myifstream(const string &filename) : ifstream(filename){

}

long myifstream::filesize() {
    long pos = this->tellg();
    this->seekg(0, end);
    long ret = this->tellg();
    this->seekg(pos);
    return ret;
}

char myifstream::operator[](int index) {
    this->seekg(index);
    return get();
}
