#include <iostream>

using namespace std;

int countBits(int num);
void feladat1();

bool setBit(unsigned int& num, int order);
void feladat2();

double avgArray(double array[], int numElements);
void feladat3();

int main() {
    feladat3();
    return 0;
}

int countBits(int num) {
    int s = 0;
    while (num) {
        s += num & 1;
        num = num >> 1;
    }
    return s;
}

void feladat1() {
    for (int i = 0; i <= 127; ++i) {
        cout << i << " " << countBits(i) << endl;
    }
}

bool setBit(unsigned int &num, int order) {
    if (order < 0 || order > 31)
        return false;

    num = num | (1 << order);
    return true;
}

void feladat2() {
    for (int i = 0; i < 35; ++i) {
        unsigned int n = 0;
        if (setBit(n, i)) {
            cout << i << " ---> " << n << endl;
        } else {
            cout << "Impossible operation!" << endl;
        }
    }
}

double avgArray(double array[], int numElements) {
    double avg = 0;
    for (int i = 0; i < numElements; ++i) {
        avg += array[i];
    }
    return avg / (double) numElements;
}

void feladat3() {
    double array[] = {1, 2, 3, 4, 5};
    int n = 5;
    cout << avgArray(array, n);
}
