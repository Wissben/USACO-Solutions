/*
ID: wissben
TASK: friday
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include<cstdlib>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include<cstdlib>

#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
using namespace std;
#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
using namespace std;
#define _GLIBCXX_USE_C99 1


int main1() {
    ofstream fout("friday.out");
    ifstream fin("friday.in");
    int N ;
    fin >> N;
    int arr[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    vector<int> months(arr, arr + sizeof(arr)/sizeof(arr[0]));

    //vector<string> days ={"Sat","Sun","Mon","Tues","Wends","Thurs","Fri"} ;
    int darr[]={0,0,0,0,0,0,0};
    vector<int> days(darr, darr + sizeof(darr)/sizeof(darr[0]));
    int yearStart = 1900;
    int indexDayOfMonth = 2;
    for (int i = yearStart; i <yearStart+N; i++)
    {
        cout <<i <<" : the condition is " << (bool)((i%100==0 && i%400==0) || (i%100!=0 && i%4==0))<< endl;
        (i%100==0 && i%400==0) || (i%100!=0 && i%4==0) ? months[1]=29 : months[1]=28;
        for (int j = 0; j < months.size(); j++)
        {
            int indexDateOfmonth = 1;
            cout << "hada le mois : " << j << endl;
            while (indexDateOfmonth<=months.at(j))
            {
                //cout << indexDayOfMonth%7 << "/"<< indexDateOfmonth<< "/" << i<<endl;
                if(indexDateOfmonth==13)
                {
                    if(indexDayOfMonth%7==0) {
                        cout << indexDayOfMonth%7 << "/"<< indexDateOfmonth<< "/" << i<<endl;
                    }
                    //cout << "here "<< indexDayOfMonth%7<< endl;
                    days[indexDayOfMonth%7]++;
                }
                indexDateOfmonth++;
                indexDayOfMonth=indexDayOfMonth%7+1;
            }
            //cout << " end with " << indexDayOfMonth << endl;
        }
    }
    string tmp="";
    for (int k = 0; k < days.size(); ++k) {
        //cout << endl << k <<"=>" <<days[k] << endl;
        tmp+=SSTR(days[k])+" ";
    }
    cout << tmp;
    tmp[tmp.size()-1]='\n';
    fout << tmp;
    return 0;
}

