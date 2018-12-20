/*
ID: xiaochi2
TASK: friday
LANG: C++                 
*/

#include <iostream>
#include <fstream>

using namespace std;

int mouth[400][13];
int statis_num[7];

int compute_february_leap_year(int year){
    return  28 + (year%4==0 && (year%400==0 || year%100!=0));
}

int compute_total_day(int y, int m){
    int sum = 0;
    for (int i=0; i<y; i++)
        for (int j=1;j<=12; j++)
            sum += mouth[i][j];
    for (int j=1; j<m; j++)
        sum += mouth[y][j];
    sum += 13;
    return sum;
}


int main(){
    ofstream fout("friday.out");
    ifstream fin("friday.in");
    int N;
    fin >> N;
    for(int j=0; j<N; j++){
        for(int i=1; i<=7; i+=2)
            mouth[j][i] = 31;
        for(int i=8; i<=12; i+=2)
            mouth[j][i] = 31;
        for(int i=2; i<=7; i+=2)
            mouth[j][i] = 30;
        for(int i=9; i<=12; i+=2)
            mouth[j][i] = 30;
    }
    for (int j=0; j<N; j++)
        mouth[j][2] = compute_february_leap_year(1900+j);

    for (int j=0; j<N; j++){
        for(int i=1; i<= 12; i++){
            int total_day = compute_total_day(j,i);
            statis_num[total_day%7] += 1;
        }
    }
    fout << statis_num[6] << " " << statis_num[0];
    for (int i=1; i<6; i++){
        fout << " " << statis_num[i];
    }    
    fout << endl;
    return 0;
}