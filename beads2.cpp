/*
   ID: wissben
   TASK: beads
   LANG: C++
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main1()
{
        ifstream fin("beads.in");
        ofstream fout("beads.out");
        string beads;
        int sze;
        fin >> sze;
        fin >> beads;
        char rep[2]={'b','r'};
        string tmp=beads;

        for (size_t i = 0; i < sze; i++) {
                if(tmp[i]=='b' || tmp[i]=='r')
                {
                  int j = (i-1)%sze;
                  while(tmp[j]=='w')
                  {
                    tmp[j]=tmp[i];
                    j--;
                  }
                }
        }
        int maxPrev=-1;
        int maxCurr=0;

        for (size_t i = 0;  i< sze && maxCurr!=maxPrev;i++) {
          string res = "";
          int j = i;
          int count=0;
          while (tmp[i]==tmp[j])
          {
            res+=tmp[j];
            count++;
            j=(j+1)%7;


          }
          while (tmp[i]==tmp[j])
          {
            cout << "how many i " << i << endl;
            count++;
            res+=tmp[j];
            j=(j+1)%7;

          }
          if(res.size() > maxCurr);
            maxCurr=count;
        }
        cout << maxPrev << "/" << maxCurr << endl;
        cout << tmp << endl;
        return 0;
}
