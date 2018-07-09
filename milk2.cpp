/*
ID: wissben
TASK: milk2
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::reverse
#include <vector>       // std::vector

using namespace std;

bool inter(int *A, int *B)
{
    return !(B[0] > A[1] || A[0] > B[1]);
}

void sortBounds(vector<int *> bounds, int size, int col, int str, int end)
{
    int tmp[2];
    for (int i = str; i < end - 1; ++i) {
        for (int j = i + 1; j < end; ++j) {
            if (bounds[j][col] < bounds[i][col]) {
                tmp[0] = bounds[i][0];
                tmp[1] = bounds[i][1];
                bounds[i][0] = bounds[j][0];
                bounds[i][1] = bounds[j][1];
                bounds[j][0] = tmp[0];
                bounds[j][1] = tmp[1];
            }
        }

    }
}

int main()
{
    ofstream fout("milk2.out");
    ifstream fin("milk2.in");
    int size;
    fin >> size;
    vector<int *> bounds;
    int a, b;
    int i = 0;
    while (fin >> a >> b) {
        bounds.push_back(new int[2]);
        bounds[i][0] = a;
        bounds[i][1] = b;
        i++;
    }
    fin.close();
    sortBounds(bounds, size, 0, 0, size);
    //sortBounds(bounds, size,1,0,size);
    int Max = bounds[0][1] - bounds[0][0];
    int MaxIdle = 0;
    for (int i = 0; i < bounds.size(); ++i) {
        int j = i + 1;
        while (j < bounds.size() && bounds[j][0] <= bounds[i][1]) {
            bounds[i][1] = bounds[i][1] >= bounds[j][1] ? bounds[i][1] : bounds[j][1];
            bounds.erase(bounds.begin() + j);
        }

    }
    for (int i = 0; i < bounds.size() - 1; ++i) {
        int diff = bounds[i + 1][0] - bounds[i][1];
        MaxIdle = (diff > MaxIdle) ? diff : MaxIdle;
        diff = bounds[i][1] - bounds[i][0];
        Max = (diff > Max) ? diff : Max;

    }
    fout << Max << " " << MaxIdle << endl;
    return 0;
}