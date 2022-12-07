#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void stringToUpper(string &str) {
    for (char &ch : str) {
        ch = ::toupper(ch);
    }
}

void stringClear(string &str) {
    for (char &ch : str) {
        if (!('A' <= ch && ch <= 'Z')) {
            ch = ' ';
        }
    }
}

int main() {

    map<string, set<int>> index;

    ifstream fin("in.txt");
    if (!fin) {
        cout << "Error" << endl;
        return 1;
    }
    string line;
    while (getline(fin, line)) {
        if (line.empty())
            break;
        stringToUpper(line);
        index.insert({line, set<int>()});
    }

    int n = 0;
    while (getline(fin, line)) {
        n++;
        stringToUpper(line);
        stringClear(line);

        stringstream ss(line);
        while (!ss.eof()) {
            string word;
            ss >> word;
            auto it = index.find(word);
            if (it != index.end()) {
                it->second.insert(n);
            }
        }
    }

    for (auto const &it : index) {
        cout << it.first << ": ";
        set<int> lines = it.second;
        //for (auto const &el : it.second) {
        //    cout << el << " ";
        //}
        //cout << endl;
        bool first = true;
        for (int i = 1; i <= n; ++i) {
            if (lines.contains(i)) {
                if (!lines.contains(i - 1) and !lines.contains(i + 1)) {
                    if (first) {
                        first = false;
                    } else {
                        cout << ", ";
                    }
                    cout << i;
                } else if(!lines.contains(i - 1) and lines.contains(i + 1)) {
                    if (first) {
                        first = false;
                    } else {
                        cout << ", ";
                    }
                    cout << i;
                } else if (lines.contains(i - 1) and !lines.contains(i + 1)) {
                    cout << "-" << i;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
