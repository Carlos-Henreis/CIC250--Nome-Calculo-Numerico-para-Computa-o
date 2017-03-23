#include <stdio.h>
#include <math.h>

#define log10(x) log(x)/log(10);

/*Carlos Henrique Reis
* Disciplina CIC250
* para compilar: gcc -Wall -o exercicio pontofalso.c
*/

/*Método que contem a função real que no qual deseja-se encontrar os zeros*/
float f(float x) {
	return 3*x-cos(x)+1;
}




int main(void) {
	// eps: erro
	// a0 e b0: pontos iniciais
	// tam: tamanho do intervlao
	// pm: ponto médio
	//teorema_OK: variavel de controle
	//it: Resultado de quantas interações são necessárias na bisserccao
	//qtd: Variavel que conta a quantidade de interações
	//a e b: auxiliam no cálculo
	float eps, a0, b0, tam, pm, a ,b, it;
	int /*teorema_OK,*/ qtd;
	/*printf("Digite a precisão: \n");
	scanf("%f",&eps);

	printf("Digite o intervalo (ex. [0,3;1] = digite 0.3 1): \n");
	scanf("%f %f",&a0,&b0);

	// O teorema do valor intermediário é válido 
	// f(a0) * f(b0) < 0 -> existe troca de sinal no intervalo dado e, portanto
	// existe raiz nele.
	teorema_OK = (f(a0)*f(b0) > 0?0:1);

	// Não, então pedir um novo intervalo inicial.
	while(teorema_OK == 0) {
		printf("\nIntervalo [%f;%f] não satisfaz as condições do teorema de Bolzano. Tente outro.\n Intervalo: ",a0,b0);
		scanf("%f %f", &a0, &b0);
		teorema_OK = (f(a0)*f(b0) > 0?0:1);
	}*/

	// Iteraçõs necessárias valor intermediário
	a0 = -0.1;
	b0 = 0.1;
	eps  = 0.0001;
	it = log10(b0 - a0);
	it -= log10(eps);
	it /= log(2);
	//para o exercicio c
	printf("Serão necessárias %.0f iterações.\n",ceil(it));

	// verifica se um dos extremos do intervalo é a raiz
	if(f(a0) == 0 || f(b0) == 0)  {
		printf("O valor %f é zero da expressão. \n", f(a0)==0?a0:b0);
		return 0;
	}
	//implementação da posição falsa
	qtd = 0;
	a = a0;
	b = b0;
	tam = fabs(b-a);
	while(tam > eps) {
		qtd += 1;
		tam = fabs(b-a);//módulo de a-b
		pm = ((a*f(b))-(b*f(a)))/(f(b)-f(a));
		if(f(pm) == 0) {
			printf("SOLUÇÃO EXATA ENCONTRADA!! x = %f\n",pm);   
			return 0;
		}

		if(f(a)*f(pm) < 0)  // a solução está a esquerda
			b = pm; 
		else // a solução está a direita
			a = pm;
		if (qtd >= 50) {//força o tam < pos para sair do loop
			tam = eps -1;//garanto que tam < eps
		}
			 

	}

	printf("Numero de interacoes: %d\nIntervalo final da posição falsa: [%f,%f]\n Solução aproximada: %f e f(x): %f",qtd,a,b, ((a*f(b))-(b*f(a)))/(f(b)-f(a)), f(((a*f(b))-(b*f(a)))/(f(b)-f(a))));

}
