//CIC250 - Cálculo Numérico para Computação
//Exercício prático x - 24/05/2017
//24433 - Carlos Henique Reis
//Método de resolução de inegrais pela Regra Generalizada de 1/3 de Simpson

#include <stdio.h>
#include <math.h>
#define tam 20       //Número de subintervalos. Alterar

double funcao(double x) {
    return cos(x); //Mudar função f(x)
}

double derivada_quarta(double x) {
    return cos(x); //Esta é a derivada quarta da função. Alterar.
}

int main (void) {
    double x[tam+1],Isg,h,maxd,erro,pares=0,impares=0;
    int i;

    /*Relação de variáveis:
      --------------------
    tam: número de subdivisões
    Isg: Integral de Simpson generalizada
    maxd: O máximo valor obtido pela quarta derivada
    pares: Soma das funções cujos x possuem índices pares
    impares: Soma das funções cujos x possuem índices ímpares
    x[]: x com índice dentro dos colchetes*/

    //Entrada de dados
    printf("Entre com os valores de x0 e x%d: ",tam);
    scanf("%lf %lf",&x[0],&x[tam]);

    //Cálculo de h e dos outros x
    h=(x[tam]-x[0])/tam;

    for(i=1;i<tam;i++)
    {
        x[i]=x[i-1]+h;
    }

    //Cálculo da Integral
    for(i=1;i<tam;i++)
    {
        if((i%2)==0)
        {
            pares=pares+funcao(x[i]);
        } else {
            impares=impares+funcao(x[i]);
        }
    }

    Isg=(h/3)*(funcao(x[0])+4*impares+2*pares+funcao(x[tam]));

    //Cálculo do erro
    maxd=derivada_quarta(x[0]);

    for(i=1;i<tam+1;i++)
    {
        if(derivada_quarta(x[i])>maxd)
        {
            maxd=derivada_quarta(x[i]);
        }
    }

    erro=sqrt(pow((pow(h,4)/180)*(x[tam]-x[0])*maxd,2));

    //Impressão dos resultados
    printf("\n------------------\n");

    for(i=0;i<tam+1;i++)
    {
        printf("x%d = %.4lf\n",i,x[i]);
    }

    printf(" h = %.4lf\n",h);
    printf("------------------\n");
    printf("\n------------------\n");

    for(i=0;i<tam+1;i++)
    {
        printf("f(x%d) = %.4lf\n",i,funcao(x[i]));
    }

    printf("------------------\n");
    printf("\nIsg = %.4lf\n",Isg);
    printf("Erro = %.4lf\n\n",erro);

    return 0;
}
