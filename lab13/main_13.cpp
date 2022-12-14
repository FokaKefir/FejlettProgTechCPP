#include <iostream>
#include <queue>
#include "myifstream.h"

void task1() {

}

struct item {
    char c;
    int count;

    item(char c, int count) : c(c), count(count) {}

    friend bool operator<(item a, item b) {
        return a.count < b.count;
    }

};

void task2() {

}

int main() {
    int occ[256] = {0};
    myifstream f("huff.txt");
    for( int i=0; i <f.filesize(); ++i){
        occ[f[i]]++;
    }

    priority_queue<item> pq;
    for (int i = 0; i < 256; ++i) {
        if (occ[i] == 0 or i == ' ' or i == '\n')
            continue;

        pq.emplace(i, occ[i]);
    }

    while (!pq.empty()) {
        cout << pq.top().c << ": " << pq.top().count << endl;
        pq.pop();
    }
    cout << endl;

    return 0;

}