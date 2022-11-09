#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>


using namespace std;

void printIntVector(vector<int> vec);
void printStringVector(vector<string> vec);
void printDoubleVector(vector<double> vec);
void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();
void task9();

int main() {
    task9();
    return 0;
}

void printIntVector(vector<int> vec)  {
    for_each(vec.begin(), vec.end(), [](const int &n){
        cout << n << " ";
    });
    cout << endl;
}

void printStringVector(vector<string> vec) {
    for_each(vec.begin(), vec.end(), [](const string &str){
        cout << str << " ";
    });
    cout << endl;
}

void printDoubleVector(vector<double> vec) {
    for_each(vec.begin(), vec.end(), [](const double &n){
        cout << n << " ";
    });
    cout << endl;
}

void task1() {
    vector<string> fruits = {"melon", "strawberry", "apple", "banana", "walnut", "lemon"};
    auto x = find_if(fruits.begin(), fruits.end(), [](const string &fruit){
        return fruit.find("berry") != string::npos;
    });
    cout << *x;
}

void task2() {
    vector<int> nums1 = {1, 2, 3, 4, 5, 6};
    vector<int> nums2 = {2, 4, 6, 8};

    bool cond = all_of(nums2.begin(), nums2.end(), [](const int &num){
        return (num % 2 == 0);
    });
    cout << cond;
}

void task3() {
    vector<int> nums1 = {1, 2, 3, 4, 5, 6};
    for_each(nums1.begin(), nums1.end(), [](int &num){
        num *= 2;
    });
    printIntVector(nums1);
}

void task4() {
    vector<string> months = {
            "January", "February", "March", "April", "May", "June", "July",
            "August", "September", "October", "November", "December"
    };

    int s = count_if(months.begin(), months.end(), [](const string &month){
        return (month.length() == 5);
    });
    cout << s;
}

void task5() {
    vector<double> nums1 = {
            1.2, 6.7, 4.5, 2.4, 8.9, 3.56, 99.0
    };
    vector<double> nums2 = {
            1.2, 6.7, 4.5, 2.4, 8.9, 3.56, 99.0
    };

    sort(nums1.begin(), nums1.end(), greater<>());
    printDoubleVector(nums1);

    sort(nums2.begin(), nums2.end(), [](const double &a, const double &b){
        return a > b;
    });
    printDoubleVector(nums2);

}

void task6() {
    vector<pair<string, double>> months = {
            {"January", 23}, {"February", 32}, {"March", 23.4}, {"April", 12.2}, {"May", 23.4},
            {"June", 45.3}, {"July", 32.4},{"August", 12.3}, {"September", 21.2},
            {"October", 32.4}, {"November", 43}, {"December", 43}
    };

    sort(months.begin(), months.end(), [](const pair<string, double> &a, const pair<string, double> &b){
        return a.second < b.second;
    });

    for_each(months.begin(), months.end(), [](const pair<string, double> &a){
        cout << a.first << " " << a.second << "\n";
    });
}

void task7() {
    vector<double> nums1 = {
            1.2, -6.7, -4.5, 2.4, 8.9, -3.56, 99.0
    };

    sort(nums1.begin(), nums1.end(), [](const double &a, const double &b){
        return abs(a) > abs(b);
    });

    printDoubleVector(nums1);

}

void task8() {
    vector<string> months = {
            "January", "February", "March", "April", "May", "June", "July",
            "August", "September", "October", "November", "December"
    };

    for_each(months.begin(), months.end(), [](string &month){
        month[0] = tolower(month[0]);
    });

    printStringVector(months);
}

void task9() {
    const int n = 'z' - 'a' + 1;
    char abc[n];
    for (int i = 0; i < n; ++i) {
        abc[i] = i + 'a';
    }

    random_shuffle(abc, abc + n);

    int indexes[256] = {0};
    for (int i = 0; i < n; ++i) {
        char c = abc[i];
        char C = c - 'a' + 'A';
        indexes[c] = i;
        indexes[C] = i;
        cout << c << C;
    }

    vector<string> months = {
            "January", "February", "March", "April", "May", "June", "July",
            "August", "September", "October", "November", "December"
    };
    sort(months.begin(), months.end(), [&](const string &a, const string &b){
        return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), [&](char c1, char c2){
            return indexes[c1] < indexes[c2];
        });
    });
    cout << endl;
    printStringVector(months);
}

