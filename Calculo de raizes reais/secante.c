#include <stdio.h>
#include <math.h>//necessário para alguns tipos de funções

#define MAX 4//Alterar aqui para aumentar o numero de interações

/*CIC250 matematica computacional
* Exercicio pratico 03 - 22/03/2017
* 30415 - Carlos Henrique Reis
* Calculo de raizes reais de funcoes reais - metodo da Secante
* para compilar: gcc -Wall -o exercicio secante.c -lm
* Executar: ./exercicio
*/

/*Método que contem a função real que no qual deseja-se encontrar os zeros*/
double f(double x) {
	return sin(x)+cos(1+pow(x,2))-1;//Tem que mudar aqui
}
double calculaX2(double x0,double x1){
    double x2;
    x2 = x1-(f(x1)/(f(x1)-f(x0)))*(x1-x0);
    return x2;
}

int main(void) {
	int k;
	/*Dados iniciais*/
    double x0=1, x1=2.25, e1_precisao=0.0001, e2_precisao=0.0001;//ALTERAR ESSES VALORES
    double xbarra, x2;
    if (fabs(f(x0))<e1_precisao){
    	xbarra  = x0;
    	printf("Valor da raiz encontrada: %lf \n",xbarra);
    	return 0;
    }
    if (fabs(f(x1))<e1_precisao){
    	xbarra  = x1;
    	printf("Valor da raiz encontrada: %lf \n",xbarra);
    	return 0;
    }
    k = 1;
    while (k <= MAX) {
    	printf("F(x0) = %lf\nF(x1) = %lf\n",f(x0),f(x1));
    	x2 = calculaX2 (x0, x1);
        printf("x2 = %lf\nf(x2)=%lf", x2, f(x2));
        if(fabs(f(x0))<e1_precisao||fabs(x1-x0)<e2_precisao){
        	xbarra = x2;
        	printf("Valor da raiz encontrada: %lf \n",xbarra);
        	return 0;
        }
        x0 = x1;
        x1 = x2;
        k+=1;
    }


	return 0;
}
