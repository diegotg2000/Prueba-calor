#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

const float K=200;
const float C=900;
const float rho=2700;
const int Nx=201;
const int Nt=201;
const float L=2;
const float T=100;
const float Dx=L/(Nx-1);
const float Dt=T/(Nt-1);
const float eta=K*Dt/(C*rho*Dx*Dx);


void solucion(void);

int main(){
    solucion();
    return 0;
}

void solucion(void){
    float T[Nx][Nt]={0};
	for(int j=0; j<Nt; j++){
        for(int i=0; i<Nx; i++){
            T[i][j]=300;
        }
    }
   
    for(int i=80; i<=120; i++){
        T[i][0]=500;
    }
    for(int j=0; j<Nt-1; j++){
        for(int i=1; i<Nx-1; i++){
            T[i][j+1]=T[i][j] + eta*(T[i+1][j] + T[i-1][j]-2*T[i][j]);
        }
    }
    ofstream outfile;
    outfile.open("datos.txt");
    for(int j=0; j<Nt;j++){
        for(int i=0;i<Nx;i++){
                outfile<<T[i][j]<<endl;
        }
    }
    outfile.close();
    

}