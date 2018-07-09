/*
ID: wissben
TASK: transform
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

char **ninty(char **mat, int N) {
    char **res = new char *[N];
    for (int i = 0; i < N; ++i) {
        res[i] = new char[N];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            res[j][N-1-i] = mat[i][j];
        }

    }
    return res;
}

char **reflect(char **mat, int N) {
    char **res = new char *[N];
    for (int i = 0; i < N; ++i) {
        res[i] = new char[N];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            res[j][N - 1 - i] = mat[j][i];
        }

    }
    return res;
}

void printMat(char **mat, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

char ***readMat(ifstream &fin, int N) {
    char ***res = new char **[2];
    string line;
    res[0] = new char *[N];
    res[1] = new char *[N];
    for (int i = 0; i < N; ++i) {
        fin >> line;
        res[0][i] = new char[N];
        for (int j = 0; j < N; j++) {
            res[0][i][j] = line[j];
            //cout << res[0][i][j];
        }
        // cout << endl;
    }

    for (int i = 0; i < N; ++i) {
        fin >> line;
        res[1][i] = new char[N];
        for (int j = 0; j < N; ++j) {
            res[1][i][j] = line[j];
            //cout <<res[1][i][j] ;
        }
        //cout << endl;

    }

    return res;
}


bool eqauls(char **A, char **B, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (A[i][j] != B[i][j])
                return false;
        }
    }
    return true;
}

int main1() {
    ofstream fout("transform.out");
    ifstream fin("transform.in");
    int N;
    fin >> N;
    char ***mats = readMat(fin, N);
    //
    printMat(mats[0], N);
    cout << endl;
    for (int i = 1; i <= 7; ++i) {
            if (eqauls(mats[1], ninty(mats[0], N), N)) {
                fout << 1 << endl;
                break;
            }
            if (eqauls(mats[1], ninty(ninty(mats[0], N), N), N)) {
                fout << 2 << endl;
                break;
            }
            if (eqauls(mats[1], ninty(ninty(ninty(mats[0], N), N), N), N)) {
                fout << 3 << endl;
                break;
            }
            if (eqauls(mats[1], reflect(mats[0], N), N)) {
                fout << 4 << endl;
                break;
            }
            if (eqauls(mats[1], ninty(reflect(mats[0], N), N), N) ||
                eqauls(mats[1], ninty(ninty(reflect(mats[0], N), N), N), N)) {
                fout << 5 << endl;
                break;
            }
            if (eqauls(mats[1], mats[0], N)) {
                fout << 6 << endl;
                break;
            }

                fout << 7 << endl;
                break;

    }

    return 0;
}