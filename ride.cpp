/*
ID: wissben
TASK: ride
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main1() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a,b;
    int A=1,B=1;
    fin>>a>>b;
    for (size_t i = 0; i < a.length(); i++) {
      A*=a[i]-'A'+1;
    }
    for (size_t i = 0; i < b.length(); i++) {
      B*=b[i]-'A'+1;
    }
    if(A%47 == B%47)
      fout << "GO\n";
      else
      fout << "STAY\n";
    //cout << A << "//" << B << endl;
    return 0;
}
