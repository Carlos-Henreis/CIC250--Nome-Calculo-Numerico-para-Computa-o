/*
*CIC250 - Cálculo Numérico para Computação
*Exercicio pratico 10 - 17/05/2017
*30415 - Carlos Henrique Reis
*Integração pelo métodos do trapézio
*/
#include <stdio.h>
#include <math.h>

double f(double x) {
	return sin(x);//Necessita modificar a função aqui que se deseja nintegrar aqui

}

double derivadaSegunda(double x) {
	return sin(x);//Necessita modifiar a derivada de segunda
}

double calcErro (double x0, double x1) {
	double max, h;
	//verifica qual f" é maior
	if (fabs(derivadaSegunda(x0)) > fabs(derivadaSegunda(x1))){//f"(x0) é o maior
		max = fabs(derivadaSegunda(x0));
	}
	else {
		max = fabs(derivadaSegunda(x1));
	}
	h = (x1-x0);
	printf ("%lf", max);
	return ((pow(h, 3))/12)*max;//Retorna o erro limitante
}

double regraTrapezio (double x0, double x1) {
	double h;
	h = x1-x0;
	return ((h/2)*(f(x1)+f(x0)));
}

int main (void) {
	double x0, x1, area, erro;
	printf ("Entre com os extremantes\n");
	scanf (" %lf %lf", &x0, &x1);
	area = regraTrapezio (x0, x1);
	erro = calcErro (x0, x1);
	printf ("Area aproximada: %lf\n Erro: %lf\n", area, erro);
	return 0;
}
