/*
*CIC250 - Cálculo Numérico para Computação
*Exercicio pratico 06 - 29/03/2017
*30415 - Carlos Henrique Reis
*Interpolação de Lagrange
*/

#include <iostream>
#include <cmath> // ou <math.h>
using namespace std;


int main(){
int n, i, j;

cout<<"                                METODO DE LAGRANGE"<<endl;
cout<<"\nDigite o numero de entradas"<<endl;
cin>>n;
double x[n],y[n], L[n], xa, Pn;
cout<<"\n\nDigite o valor de x que se deseja interpolar"<<endl;
cin>>xa;

for(i=0; i<n; i++){
    cout<<"\nDigite x"<<i<<endl;
    cin>>x[i];
    cout<<"\nDigite f("<<x[i]<<")"<<endl;
    cin>>y[i];
}
Pn=0;
for(i=0; i<n;i++){
        L[i]=1;
    for(j=0;j<n;j++){
           if(j!=i){
            L[i]=L[i]*((xa-x[j])/(x[i]-x[j]));
           }

            }
     Pn=Pn + L[i]*y[i];

    }

    cout<<"\nO valor da funcao G(X) para x= "<<xa<<" eh "<<Pn<<"."<<endl;
    cout<<"\n\n\n\n\n                                       FIM!"<<endl;
cin>>xa;
}


