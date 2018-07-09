/*
ID: wissben
TASK: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::reverse
#include <vector>       // std::vector

using namespace std;

ofstream fout("namenum.out");
ifstream fin("namenum.in");
ifstream dic("dict.txt");
string name;
bool found = false;

vector<int> intDec(unsigned long long int n) {
    vector<int> res;
    while (n > 0) {
        res.push_back(n % 10);
        n /= 10;
    }
    std::reverse(res.begin(), res.end());
    return res;
}


/* LANG can be C++11 or C++14 for those more recent releases */
int compareMyType(const void *a, const void *b) {
    if (*(string *) a < *(string *) b) return -1;
    if (*(string *) a == *(string *) b) return 0;
    if (*(string *) a > *(string *) b) return 1;
}

void possib(string s, vector<string> *res, char **digit, vector<int> number, int indexNum, string *dict, int cpt) {
    if (s.length() == number.size() - 1) {
        //cout << s << endl;
        string tmp;
        tmp = s;
        s += digit[number[indexNum]][0];
        if (bsearch(&s, dict, cpt, sizeof(string), compareMyType)) {
            fout << s << endl;
            found = true;
        }
        s = tmp;
        s += digit[number[indexNum]][1];
        if (bsearch(&s, dict, cpt, sizeof(string), compareMyType)) {
            fout << s << endl;
            found = true;
        }
        s = tmp;
        s += digit[number[indexNum]][2];
        if (bsearch(&s, dict, cpt, sizeof(string), compareMyType)) {
            fout << s << endl;
            found = true;
        }
        return;

    } else {
        possib(s + digit[number[indexNum]][0], res, digit, number, indexNum + 1, dict, cpt);
        possib(s + digit[number[indexNum]][1], res, digit, number, indexNum + 1, dict, cpt);
        possib(s + digit[number[indexNum]][2], res, digit, number, indexNum + 1, dict, cpt);
    }
}


int main1() {
    unsigned long long int N;
    char **digit = new char *[10];
    char A = 'A';
    for (int i = 2; i < 10; i++) {
        digit[i] = new char;
        for (int j = 0; j < 3; j++) {
            if (A == 'Q') {
                A++;
            }
            digit[i][j] = A;
            A++;
        }
    }
    fin >> N;
    vector<int> number = intDec(N);
    //printVec2(number);
    vector<string> outcome;
//    vector<string> dict;
    string *dict = new string[4700];
    string s = "";
    int maxSizeNames = 0;
    int cpt = 0;
    while (dic >> name) {
        if (name.size() > maxSizeNames) {
            maxSizeNames = name.size();
        }
        dict[cpt] = name;
        cpt++;
    }
    dic.close();
    if (number.size() > maxSizeNames)
        fout << "NONE" << endl;
    else {
        possib(s, &outcome, digit, number, 0, dict, cpt);
        if (!found)
            fout << "NONE" << endl;
    }

    return 0;
}

