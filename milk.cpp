/*
ID: wissben
TASK: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>    // std::reverse
#include <vector>
using namespace std;

void display(vector<int> v)
{
    for (int i = 0; i < v.size()-1; i+=2) {
        cout << v[i] << "\t" << v[i+1] <<endl;
    }
    cout << endl;
}

void sortAll(vector<int>* all)
{
    int size=all->size();
    int tmp;
    for (int i = 0; i < size - 3; i += 2) {
        for (int j = i + 2; j < size - 1; j += 2) {
            if (all->at(j) < all->at(i)) {
                tmp=all->at(i);
                all->at(i)=all->at(j);
                all->at(j)=tmp;
                tmp=all->at(i+1);
                all->at(i+1)=all->at(j+1);
                all->at(j+1)=tmp;

            }
        }

    }
}

ofstream fout("milk.out");

ifstream fin("milk.in");

int main1()
{
    int count, nbs;
    fin >> count >> nbs;
    vector<int> all;
    int a, b;
    while (fin >> a >> b) {
        all.push_back(a);
        all.push_back(b);
    }
    sortAll(&all);
    //display(all);
    int botBrought = 0;
    int cost = 0;
    int i = 0;

    if(nbs!=0)
    {

        while (i < all.size() - 1) {
            int j = 0;
            while (j < all[i + 1] && botBrought < count) {
                botBrought++;
                cost += all[i];
                j++;
            }
            i += 2;
        }
    }
    fout<<cost<<endl ;
    return 0;
}

