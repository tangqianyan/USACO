/*
ID: xiaochi2
TASK: gift1
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct giver{
    string name;
    int init;
    int give;
    int receive;
}givers[11];

int NP;

int getIndex(string name){
    for(int i=0; i<NP; i++){
        if (givers[i].name == name)
            return i;
    }
    return -1;

}

int main(){
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");

    fin >> NP;
    for(int i=0;i<NP;i++){
        string name;
        fin >> name;
        givers[i].name = name;
        givers[i].init = 0;
        givers[i].give = 0;
        givers[i].receive = 0;
    }
    for (int i=0; i<NP; i++){
        string name;
        int init,num;
        fin >> name;
        int indx_g = getIndex(name);
        
        fin >> init >> num;
        givers[indx_g].init = init;
        
        if (num==0)
            continue;
        if (init==0)
            continue;
        
        int avg = int(init / num);
        givers[indx_g].give -= init;
        givers[indx_g].receive += (init - avg*num);
        for (int j=0; j<num; j++){
            string name;
            fin >> name;
            int indx_r = getIndex(name);
            givers[indx_r].receive += avg;
        }
    }

    for (int i=0; i<NP; i++){
        fout << givers[i].name << " " << givers[i].receive + givers[i].give << endl;
    }
    return 0;

}