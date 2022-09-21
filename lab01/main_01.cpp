#include <iostream>
#include <cmath>
#include <utility>
#include <sstream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int countBits(int num);
void feladat1();

bool setBit(unsigned int& num, int order);
void feladat2();

double mean(double array[], int numElements);
void feladat3();

double stddev(double array[], int numElements);
void feladat4();

pair<double , double> max2(double array[], int numElements);
void feladat5();

double sumNumbersInString(string s);
void feladat6();

int countWords(string text);
void feladat7();

bool isCharacter(char c);
string code(string text);
void feladat8();

string capitalizeWords(string text);
void feladat9();

vector<pair<string, int>> countWordsFromFile(ifstream &fin);
string getNthMostCommonWord(vector<pair<string, int>> words, int n);
void extraFeladat();

int main() {
    extraFeladat();
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

double mean(double array[], int numElements) {
    if (numElements == 0)
        return NAN;

    double avg = 0;
    for (int i = 0; i < numElements; ++i) {
        avg += array[i];
    }
    return avg / (double) numElements;
}

void feladat3() {
    double array[] = {1, 2, 3, 4, 5};
    int n = 5;
    cout << mean(array, n);
}

double stddev(double array[], int numElements) {
    if (numElements == 0)
        return NAN;

    double sDev = 0.0;
    double meanNum = mean(array, numElements);
    for (int i = 0; i < numElements; ++i) {
        sDev += pow(array[i] - meanNum, 2);
    }

    return sqrt(sDev / numElements);
}

void feladat4() {
    double array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    cout << stddev(array, n);
}

pair<double, double> max2(double array[], int numElements) {
    if (numElements == 0)
        return pair<double, double>(NAN, NAN);
    else if (numElements == 1)
        return pair<double, double>(array[0], array[0]);

    pair<double, double> pr(array[0], array[1]);
    for (int i = 2; i < numElements; ++i) {
        if (array[i] > pr.second) {
            pr.first = pr.second;
            pr.second = array[i];
        } else if (array[i] > pr.first) {
            pr.first = array[i];
        }
    }
    return pr;
}

void feladat5() {
    double array[] = {1, 2, 3, 4, 5, 11, 7, 8, 9, 10};
    int n = 10;
    pair<double, double> pr = max2(array, n);
    cout << pr.first << " " << pr.second << endl;

}

double sumNumbersInString(string s) {
    int ind = 0;
    while (ind < s.size()) {
        if (!('0' <= s[ind] && s[ind] <= '9') && s[ind] != ' ' && s[ind] != '.')
            s.erase(ind, 1);
        else
            ind++;
    }

    double sum = 0.0;
    istringstream iss(s);
    double number;
    while(iss >> number){
        sum += number;
    }
    return sum;
}

void feladat6() {
    string s = "1.1 2 3 alma 4";
    cout << sumNumbersInString(s) << endl;
}

int countWords(string text) {
    int count = 0;
    istringstream iss(text);
    string word;
    while (iss >> word)
        count++;

    return count;
}

void feladat7() {
    string text = "Szia hello Laci vagyok 1 kecske";
    cout << countWords(text) << endl;
}

bool isCharacter(char c) {
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
        return true;
    return false;
}

string code(string text) {
    string codedText = "";
    for (int i = 0; i < text.size(); ++i) {
        if (isCharacter(text[i])) {
            if (text[i] == 'z')
                codedText.push_back('a');
            else if (text[i] == 'Z')
                codedText.push_back('A');
            else
                codedText.push_back(text[i] + 1);
        } else {
            codedText.push_back(text[i]);
        }
    }
    return codedText;
}

void feladat8() {
    string text = "alma&Szar";
    cout << code(text) << endl;
}

string capitalizeWords(string text) {
    string cText = "";
    if (isCharacter(text[0]))
        cText.push_back(toupper(text[0]));

    for (int i = 1; i < text.size(); ++i) {
        if (isCharacter(text[i]) && !isCharacter(text[i - 1]))
            cText.push_back(toupper(text[i]));
        else
            cText.push_back(tolower(text[i]));
    }

    return cText;
}

void feladat9() {
    string text;
    while (getline(cin, text)) {
        if (text.size() == 0)
            break;

        cout << capitalizeWords(text) << endl;
    }
}

vector<pair<string, int>> countWordsFromFile(ifstream &fin) {
    vector<pair<string, int>> wordsVec;
    map<string, int> wordsMap;
    string text;
    while (fin >> text) {
        if (!wordsMap.count(text))
            wordsMap[text] = 1;
        else
            wordsMap[text]++;
    }

    for (auto &it : wordsMap)
        wordsVec.push_back(it);

    return wordsVec;
}

bool cmp(pair<string, int>& a, pair<string, int>& b){
    return a.second > b.second;
}

string getNthMostCommonWord(vector<pair<string, int>> words, int n) {
    sort(words.begin(), words.end(), cmp);
    return words[n - 1].first;
}


void extraFeladat() {
    ifstream fin("bible.txt");
    if (!fin.is_open()) {
        cout << "File failed to open!";
        fin.close();
        return;
    }

    int n = 1;
    vector<pair<string, int>> words = countWordsFromFile(fin);
    cout << "The " << n << "th most common world is: " << getNthMostCommonWord(words, n) << endl;

    fin.close();
}


