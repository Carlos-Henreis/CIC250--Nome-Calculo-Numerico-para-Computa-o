//CIC250 - Cálculo Numérico para Computação
//Exercício prático x - 24/05/2017
//24433 - Carlos Henique Reis
//Método de resolução de inegrais pela Regra de 1/3 de Simpson

#include <stdio.h>
#include <math.h>

double funcao(double x)
{
    return cos(x); //Mudar função f(x)
}

double derivada_quarta(double x)
{
    return cos(x); //Esta é a derivada quarta da função. Alterar.
}

int main(void){
    double x0,x1,x2,Is,h,maxd,erro;

    //Entrada de dados
    printf("Entre com os valores de x0 e x2: ");
    scanf("%lf %lf",&x0,&x2);

    //Cálculos de x1 e h
    x1=(x0+x2)/2;
    h=(x2-x0)/2;

    //Cálculo da integral de Simpson
    Is=(h/3)*(funcao(x0)+4*funcao(x1)+funcao(x2));

    //Cálculo do erro
    if(derivada_quarta(x0)>derivada_quarta(x1))
    {
        maxd=derivada_quarta(x0); //maxd é o maior valor da derivada
    } else {
        maxd=derivada_quarta(x2);
    }

    erro=sqrt(pow((pow(h,5)/90)*maxd,2));

    //Impressão dos resultados
    printf("\n------------------\n");
    printf("x0 = %.4lf\n",x0);
    printf("x1 = %.4lf\n",x1);
    printf("x2 = %.4lf\n",x2);
    printf("h = %.4lf\n",h);
    printf("------------------\n");

    printf("\n------------------\n");
    printf("f(%.4lf) = %.4lf\n",x0,funcao(x0));
    printf("f(%.4lf) = %.4lf\n",x1,funcao(x1));
    printf("f(%.4lf) = %.4lf\n",x2,funcao(x2));
    printf("\n------------------\n");

    printf("\nIs = %.4lf\n",Is);
    printf("Erro = %lf\n\n",erro);

    return 0;
}

