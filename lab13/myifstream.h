#ifndef CPP_2022_MYIFSTREAM_H
#define CPP_2022_MYIFSTREAM_H

#include <iostream>
#include <fstream>
#include <istream>
#include <string>

using namespace std;

class myifstream : public ifstream {
public:
    explicit myifstream(const string &filename);
    long filesize();
    char operator[](int index);

};


#endif //CPP_2022_MYIFSTREAM_H
