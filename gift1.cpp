/*
ID: wissben
TASK: gift1
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include<cstdlib>

#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
using namespace std;
#define _GLIBCXX_USE_C99 1


int main() {
    ofstream fout("gift1.out");
    vector<string> gift2;
    ifstream fin("gift1.in");
    map<string, int> vec;
    int NP;
    fin >> NP;
    string tmp;
    for (int i = 0; i < NP; ++i) {
        fin >> tmp;
        gift2.push_back(tmp);
        vec[tmp] = 0;
    }
    while (fin >> tmp != NULL) {
        vector<string> infos;
        string giver = tmp;
        fin >> tmp;
        infos.push_back(tmp);
        fin >> tmp;
        infos.push_back(tmp);
        int giving = std::atoi(infos[0].c_str());
        int to = std::atoi(infos[1].c_str());
        vector<string> receivers;
        cout << giver << " : " << giving << "/" << to << " to " << endl;
        for (int i = 0; i < to; ++i) {
            fin >> tmp;
            receivers.push_back(tmp);
            cout << tmp << endl;
        }

        if (!to)
            continue;
        else {
            for (int i = 0; i < receivers.size(); ++i) {
                vec[receivers.at(i)] += giving / to;
            }
            vec[giver] += giving % to;
            vec[giver] -= giving;
        }


    }
    for (int j = 0; j < gift2.size(); ++j) {
        tmp = gift2[j];
        string final = tmp + " " + SSTR(vec[tmp]) + "\n";
        fout << final;
    }
    return 0;
}

