#include <stdio.h>
#include <math.h>

double f(double x) {
	return sin(x);//Necessita modificar a função aqui que se deseja nintegrar aqui

}

double derivadaSegunda(double x) {
	return sin(x);//Necessita modifiar a derivada de segunda
}

double calcErro (double x0, double x1, int n) {
	double max, h;
	h = (x1-x0)/n;
	//verifica qual f" é maior
	if (fabs(derivadaSegunda(x0)) > fabs(derivadaSegunda(x1))){//f"(x0) é o maior
		max = fabs(derivadaSegunda(x0));
	}
	else {
		max = fabs(derivadaSegunda(x1));
	}

	return ((pow(h, 2))/12)*max;//Retorna o erro limitante
}

int encontraH (double x0, double x1, int erro) {
	int n;
	double h, max;
	//verifica qual f" é maior
        if (fabs(derivadaSegunda(x0)) > fabs(derivadaSegunda(x1))){//f"(x0) é o ma$
                max = fabs(derivadaSegunda(x0));
        }
        else {
                max = fabs(derivadaSegunda(x1));
        }
	h = sqrt((erro*12)/((x1-x0)*max));
	n= h+1;
	return n;
}

double regraTrapezioRepetido (double x0, double x1, int n) {
	double h, sum=0, a;
	int i;
	h = (x1-x0)/n;
	a = x0;
	for (i = 0; i< n-1; i++) {
		sum = sum + f(a) + f(a + h);
    	a = a + h;
	}
	sum = sum * h / 2;
	return sum;
}

int main (void) {
	double x0, x1, area, erro;
	int n;
	printf ("Entre com os extremantes\n");
	scanf (" %lf %lf", &x0, &x1);
	printf ("Entre com a quantide de areas\n");
	scanf (" %d", &n);
	area = regraTrapezioRepetido (x0, x1, n);
	erro = calcErro (x0, x1, n);
	printf ("Area aproximada: %lf\n Erro: %lf\n", area, erro);
	return 0;
}