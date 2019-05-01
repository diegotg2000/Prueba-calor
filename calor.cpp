#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

const float K=1;
const float C=1;
const float rho=1;
const float Dx=1;
const float Dt=1;
const float eta=K*Dt/(C*rho*Dx*Dx);
const float L=200;
const float T=200;
const int Nx=int(L/Dx +1);
const int Nt=int(T/Dt +1);

void solucion();

int main(){
    solucion();
    return 0;
}

void solucion(){
    float T[Nx][Nt]={0};
   
    for(int i=80; i<=120; i++){
        T[i][0]=500;
    }
    for(int j=0; j<Nt; j++){
        for(int i=1; i<Nx-1; i++){
            T[i][j+1]=T[i][j] + eta*(T[i+1][j] + T[i-1][j]-2*T[i][j]);
        }
    }
    fstream outfile;
    outfile.open("datos.txt");
    for(int j=0; j<Nt;j++){
        for(int i=0;i<Nx;i++){
                outfile<<T[i][j]<<endl;
        }
    }

    outfile.close();

}