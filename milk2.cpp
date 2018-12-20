/*
ID: xiaochi2
TASK: milk2
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ofstream fout("milk2.out");
ifstream fin("milk2.in");
int N;

struct item{
    int start;
    int end;
}items[1000000];

bool cmp(const item n1,const item n2){
    if(n1.start < n2.start)
        return true;
    return false;
}

int main(){
    fin >> N;
    int s,e;
    for (int i=0; i<N; i++){
        fin >> s >> e;
        items[i].start = s;
        items[i].end = e;
    }
    sort(items,items+N,cmp);
    int le = items[0].start;
    int ri = items[0].end;

    int max_free = 0;
    int max_work = 0;
    for (int i=0; i<N; i++){
        if(ri >= items[i].start){
            ri = max(ri,items[i].end);
            max_work = max(max_work,ri-le);
        }else{
            le = items[i].start;
            max_free = max(max_free,le-ri);
            ri = items[i].end;
        }
    }
    fout << max_work << " " << max_free << endl;
    return 0;
}