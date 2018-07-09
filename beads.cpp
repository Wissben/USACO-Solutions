/*
ID: wissben
TASK: beads
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int modulo(int l, int size) {
    int times = ceil((double) abs(l) / size);
    return (l + times * size) % size;
}


bool allSame(string in) {
    for (int i = 0; i < in.size() - 1; ++i) {
        if (in[i] != in[i + 1])
            return false;
    }
    return true;
}

string setMark(string s, int index) {
    string tmp = s.substr(0, index);
    tmp = tmp + "|" + s.substr(index, s.size() - 1);
    return tmp;
}

int main1
        () {
    ofstream fout("beads.out");
    ifstream fin("beads.in");
    int cpts[200] = {0};
    int max = 0;
    string in;
    int size;
    fin >> size >> in;
    if (allSame(in))
        fout << size << endl;
    else {
        for (int i = 0; i < size; i++) {
            cout << setMark(in, i) << endl;
            int k = i + 1;
            int j = modulo(i, size);
            cpts['b'] = cpts['w'] = cpts['r'] = 0;
            char right = in[k];
            char left = in[j];
            int r = 0, l = 0;
            if (right == 'w')
                while (in[k] == 'w') {
                    cpts['w']++;
                    k = (k + 1) % size;
                    right = in[k];
                }
            while (in[k] == right || in[k] == 'w') {
                cpts[right]++;
//                if (in[k] == 'w')
//                    cpts['w']++;
                k = (k + 1) % size;
            }
            cpts[right] += cpts['w'];
            r = cpts[right];
            cpts['b'] = cpts['w'] = cpts['r'] = 0;
            if (left == 'w')
                while (in[j] == 'w') {
                    cpts['w']++;
                    j = modulo(j - 1, size);
                    left = in[k];
                }

            while (in[j] == left || in[j] == 'w') {
                cpts[left]++;
                j = modulo(j - 1, size);
            }
            cpts[left] += cpts['w'];
            l = cpts[left];
            cout << l << "/" << r << endl;
            if ((r + l) > max)
                max = r + l;
            cout << max << endl;
        }
        fout << max <<
             endl;
    }

    return 0;
}