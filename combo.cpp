/*
ID: wissben
TASK: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int cpt=0;
int N;

bool valid(int a , int b)
{
    return (abs(a-b)<=2 || abs(a-b)>=N-2);
}

bool check(int a , int b ,int c, int A , int B , int C)
{
    return (valid(a,A)&&valid(b,B)&&valid(c,C));
}

ofstream fout("combo.out");

ifstream fin("combo.in");

int main1()
{

    int a,b,c;
    int x,y,z;
    fin >> N;
    fin>>a>>b>>c>>x>>y>>z;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int k = 1; k <= N; ++k) {
                cpt=(check(i,j,k,a,b,c) || check(i,j,k,x,y,z))?cpt+1:cpt;

            }
        }
    }
    fout << cpt << endl;
    return 0;
}

