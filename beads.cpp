/*
ID: xiaochi2
TASK: beads
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
int N;
string str;
int lft[2][1000]={0};
int rigt[2][1000]={0};

int main(){
    ofstream fout("beads.out");
    ifstream fin("beads.in");

    fin >> N;
    fin >> str;
    str += str;

    for(int i= str.size(); i>0;i--){
        if (str[i-1]=='r'){
            lft[0][i] = lft[0][i+1] + 1;
            lft[1][i] = 0;
        }
        else if(str[i-1]=='b'){
            lft[1][i] = lft[1][i+1] + 1;
            lft[0][i] = 0;
        }
        else{
            lft[0][i] = lft[0][i+1] + 1;
            lft[1][i] = lft[1][i+1] + 1;
        }
    }
    for(int i=1; i<=str.size() ; i++){
        if (str[i-1]=='r'){
            rigt[0][i] = rigt[0][i-1] + 1;
            rigt[1][i] = 0;
        }
        else if(str[i-1]=='b'){
            rigt[1][i] = rigt[1][i-1] + 1;
            rigt[0][i] = 0;
        }
        else{
            rigt[0][i] = rigt[0][i-1] + 1;
            rigt[1][i] = rigt[1][i-1] + 1;
        }
    }
    int sum=-1;
    int t1,t2;

    for(int i=1; i<=N; i++){
        t1 = max(lft[0][i],lft[1][i]);
        t2 = max(rigt[0][N+i-1],rigt[1][N+i-1]);
        sum = max(sum,t1+t2);
    }
    if(sum<N)
        fout << sum << endl;
    else
        fout << N << endl;
    return 0;
}