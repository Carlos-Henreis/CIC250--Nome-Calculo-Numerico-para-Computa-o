#include <stdio.h>
#include <math.h>

#define MAX 4//Alterar aqui para alterar o numero de interações

/*CIC250 matematica computacional
* Exercicio pratico 03 - 22/03/2017
* 30415 - Carlos Henrique Reis
* Calculo de raizes reais de funcoes reais - metodo de Newton
* para compilar: gcc -Wall -o exercicio Newton.c -lm
* Executar: ./exercicio
*/


/*Método que contem a função real que no qual deseja-se encontrar os zeros*/
double f(double x) {
    return -1+5.5*x-4*pow(x,2)+0.5*pow(x,3);//Tem que mudar aqui
}

/*derivada da função*/
double flinha(double x){
    return 5.5-8*x+1.5*pow(x,2);//tem que mudar aqui
}

int main() {
    int k;
    /*Dados iniciais*/
    double x0=4.52, e1_precisao=0.00000001, e2_precisao=0.0001;//ALTERAR ESSES VALORES
    double xbarra, x1;
    if (fabs(f(x0))<e1_precisao){
        xbarra  = x0;
        printf("Valor da raiz encontrada: %lf \n",xbarra);
        return 0;
    }
    k = 1;
    while(k <= MAX){
        printf("F(x0) = %lf\n%lf\n",f(x0), x0);
        x1 = x0-(f(x0)/flinha(x0));
        if(fabs(f(x0))<e1_precisao || fabs(x1-x0)<e2_precisao){
            xbarra = x1;
            printf("Valor da raiz encontrada: %lf \ne F(xbarra) = %lf",xbarra, f(xbarra));
            return 0;
        }
        x0 = x1;
        k+=1;
    }
    return 0;
}
