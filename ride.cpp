/*
ID: xiaochi2
TASK: ride
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int convert_to_numer(string str){
    int prudt = 1;
    for(int i=0;i<str.size();i++)
        prudt *= (str[i]-'A'+1);
    return prudt;
}

int main(){
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    string comet;
    string group;
    fin >> comet;
    fin >> group;

    int c_p = convert_to_numer(comet);
    int g_p = convert_to_numer(group);
    if(c_p%47==g_p%47)
        fout << "GO" << endl;
    else
        fout << "STAY" <<  endl;
}