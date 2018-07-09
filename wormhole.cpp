/*
ID: wissben
TASK: wormhole
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ofstream fout("wormhole.out");

ifstream fin("wormhole.in");

int main()
{


    int N;
    int total = 0;
    fin >> N;
    int **all = new int *[N];
    for (int i = 0; i < N; ++i) {
        all[i] = new int[2];
        fin >> all[i][0];
        fin >> all[i][1];

    }
    //std::sort (all,all+N);

    do {
        for (int i = 0; i < N-1; i += 2) {

        }
    }
    while (std::next_permutation(all, all + N));


    cout << total << endl;
    return 0;
}

