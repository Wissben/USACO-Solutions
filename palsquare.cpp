/*
ID: wissben
TASK: palsquare
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

int numOf(char c) {
    int i;
    char a;
    if (c >= '0' && c <= '9') {
        i = 0;
        a = '0';
    }
    if (c >= 'A' && c <= 'J') {
        i = 10;
        a = 'A';
    }
    while (a < c) {
        a++;
        i++;
    }
    return i;
}

char charOf(int c)
{
    char i;
    int a;
    if (c >= 0 && c <= 9) {
        i = '0';
        a = 0;
    }
    if (c >= 10 && c <= 19) {
        i = 'A';
        a = 10;
    }
    while (a < c) {
        a++;
        i++;
    }
    return i;
}
int toBaseTen(string num, int base) {
    int res = 0;
    for (int i = 0; i < num.size(); ++i) {
        res += numOf(num[i]) * pow(base, num.size()-1-i);
    }
    return res;
}

string toBaseB(int num , int B)
{
    if(num==0)
        return "0";
    string res="";
    while (num>0)
    {
        res+=charOf(num%B);
        num/=B;
    }
    std::reverse(res.begin(),res.end());
    return  res;
}

bool isPalind(string num)
{
    for (int i = 0; i <num.size()/2 ; ++i) {
        if(num[i]!=num[num.size()-1-i])
            return false;
    }
    return true;
}

int main1() {
    ofstream fout("palsquare.out");
    ifstream fin("palsquare.in");
    int base;
    fin >> base;
    for (int i = 1; i <= 300; ++i) {
        int sqr = pow(i,2);
        string num = toBaseB(i,base);
        string numsqr = toBaseB(sqr,base);
        if(isPalind(numsqr))
            fout << num<< " " << numsqr<< endl;
    }
    return 0;
}