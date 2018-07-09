/*
ID: wissben
TASK: dualpal
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

int myStoi(string s)
{
    int res=0;
    for (int k = 0; k<s.size() ; k++) {
        res*=10;
        res+=numOf(s[k]);
    }
    return res;
}

int main1() {
    ofstream fout("dualpal.out");
    ifstream fin("dualpal.in");
    string line;
    getline(fin,line);
    string left="",right="";
    int i=0;
    while(line[i]!=' ')
    {
        left+=line[i];
        i++;
    }
    for (int j = i+1; j < line.size(); ++j) {
        right+=line[j];
    }
    std::string::size_type sz;
    int N=myStoi(left);
    int S=myStoi (right);
    int basePal=0;
    int cptN=1;
    int k = S+1;
    while(cptN<=N) {
        basePal=0;
        for (int j = 2; j <= 10; ++j) {
            if(isPalind(toBaseB(k,j)))
            {
                basePal++;
            }
            if (basePal>=2) {
                break;
            }
        }
        if(basePal>=2)
        {
            cptN++;
            cout << k << endl;
            fout << k << endl;
        }
        k++;
    }

    return 0;
}