/*
ID: wissben
TASK: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int depth;

int *digits;

int cpt = 0;

void display(int *t, int N)
{
    for (int i = 0; i < N; ++i) {
        cout << t[i] << " ";
    }
    cout << endl;
}

int getNbDig(int a)
{
    int i = 0;
    while (a > 0) {
        i++;
        a /= 10;
    }
    return i;
}

int *intToArr(int a)
{
    int nbdig = getNbDig(a);
    int *arr = new int[nbdig];
    for (int i = nbdig - 1; i >= 0; i--) {
        arr[i] = a % 10;
        a /= 10;
    }
    return arr;
}

bool inVal(int *a, int A, int x)
{
    for (int i = 0; i < A; ++i) {
        if (a[i] == x) {
            return true;
        }
    }
    return false;
}

bool arrInArr(int *a, int A, int *b, int B)
{
    bool in = true;
    int i = 0;
    while (i < B) {
        if (!inVal(a, A, b[i])) {
            in = false;
            break;
        }
        i++;
    }
    return in;

}

bool val(int *t, int N)
{
    int ABC = t[0] * 100 + t[1] * 10 + t[2];
    int DE = t[3] * 10 + t[4];
    return (getNbDig(ABC * t[4]) == 3 && getNbDig(ABC * t[3]) == 3 && getNbDig(ABC * DE) &&
        arrInArr(digits, depth, intToArr(ABC * t[4]), getNbDig(ABC * t[4])) &&
        arrInArr(digits, depth, intToArr(ABC * t[3]), getNbDig(ABC * t[3])) &&
        arrInArr(digits, depth, intToArr(ABC * DE), getNbDig(ABC * DE)));
}
void DFS(int d, int *test)
{
    //cout << d;
    if (d == depth) {
        if (val(test, d)) {
            display(test, d);
            cpt++;
        }
        return;
    }
    else {
        for (int i = 0; i < depth; ++i) {
            //cout << digits[i];
            test[d] = digits[i];
            DFS(d + 1, test);
        }
    }
}

ofstream fout("crypt1.out");

ifstream fin("crypt1.in");

int main1()
{
    fin >> depth;
    digits = new int[depth];
    for (int i = 0; i < depth; ++i) {
        fin >> digits[i];
    }
    int *test = new int[depth];
    for (int j = 0; j < depth; ++j) {
        for (int i = 0; i < depth; ++i) {
            for (int k = 0; k < depth; ++k) {
                for (int l = 0; l < depth; ++l) {
                    for (int m = 0; m < depth; ++m) {
                        int ABC = digits[j] * 100 + digits[i] * 10 + digits[k];
                        int DE = digits[l] * 10 + digits[m];

                        if (getNbDig(ABC * digits[m]) == 3 && getNbDig(ABC * digits[l]) == 3 && getNbDig(ABC * DE) &&
                            arrInArr(digits, depth, intToArr(ABC * digits[m]), getNbDig(ABC * digits[m])) &&
                            arrInArr(digits, depth, intToArr(ABC * digits[l]), getNbDig(ABC * digits[l])) &&
                            arrInArr(digits, depth, intToArr(ABC * DE), getNbDig(ABC * DE))) {
                            cpt++;
                        }
                    }
                }
            }
        }

    }
    fout << cpt << endl;
    return 0;
}

