/*
ID: xiaochi2
TASK: transform
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ofstream fout("transform.out");
ifstream fin("transform.in");

int N;
int raw_matx[10][10]={0};
int new_matx[10][10]={0};

bool compare(const int m[][10],const int n[][10]){
    bool flag = true;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if (m[i][j]!=n[i][j])
                flag = false;
    return flag;
}

void rotate(){

}

void reflection(){
    int tmp = 0;
    for (int j=0; j<N; j++)
        for (int i=0; i<(N/2); i++)
           tmp = raw_matx[j][i];
           raw_matx[j][i] = raw_matx[j][N-i];
}

void 

int main(){
    fin >> N;
    for (int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            fin >> raw_matx[i][j];

    for (int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            fin >> new_matx[i][j];
    
}