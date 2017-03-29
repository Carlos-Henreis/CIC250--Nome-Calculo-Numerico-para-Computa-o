/*
*CIC250 - Cálculo Numérico para Computação
*Exercicio pratico 04 - 29/03/2017
*30415 - Carlos Henrique Reis
*Resolução de Sistemas lineares pelo método de Eliminalção de Gauss
*/
#include <stdio.h>
#define TAMMAX 40

int main(void) {
	int i, j, k, n, p, l;
	float A[TAMMAX][TAMMAX], c, x[TAMMAX], soma;
	printf("Ordem da matriz\n");
	scanf ("%d", &n);
	printf("Escreva os elementos da matriz aumentada\n");
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= (n+1); j++){
			printf("A[%d][%d]: ", i, j);
			scanf ("%f", &A[i][j]);

		}
	}
	printf ("Matriz digitada\n");
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n+1; j++){
			if (j != n+1) {
				printf("%f ", A[i][j]);
			}
			else{
				printf("%f \n", A[i][j]);
			}
		}	
	}
	for (j = 1; j  <= n; j++) {
		for (i = 1; i <= n; i++) {
			if (i>j) {
				c = -(A[i][j]/A[j][j]);
			}
			for (k = 1; k <= n+1; k++) {
				A[i][k] = c*A[j][k]+A[i][k];
			}
		}
		printf ("\n-------------------\nInteração %d\nMatriz:\n", j);

		for (p = 1; p <= n; p++) {
			for (l = 1; l <= n+1; l++){
				if (l != n+1) {
					printf("%f ", A[p][l]);
				}
				else{
					printf("%f \n", A[p][l]);
				}
			}	
		}
	}
	printf ("Matriz escalonada\n");
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n+1; j++){
			if (j != n+1) {
				printf("%f ", A[i][j]);
			}
			else{
				printf("%f \n", A[i][j]);
			}
		}	
	}

	x[n]=A[n][n+1]/A[n][n];

	for (i = n-1; i >= 1; i--) {
		soma = 0;
		for (j = i+1; j <= n; j++){
			soma = soma+A[i][j]*x[j];
		}
		x[i] = (A[i][n+1]-soma)/A[i][i];
	}

	printf("Solução:\n");
	for (i = 1; i <= n; i++){
		printf("x%d= %f\t", i, x[i]);
	}
	return 0;
}
