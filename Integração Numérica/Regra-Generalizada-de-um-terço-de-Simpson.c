//CIC250 - C�lculo Num�rico para Computa��o
//Exerc�cio pr�tico x - 24/05/2017
//24433 - Carlos Henique Reis
//M�todo de resolu��o de inegrais pela Regra Generalizada de 1/3 de Simpson

#include <stdio.h>
#include <math.h>
#define tam 20       //N�mero de subintervalos. Alterar

double funcao(double x) {
    return cos(x); //Mudar fun��o f(x)
}

double derivada_quarta(double x) {
    return cos(x); //Esta � a derivada quarta da fun��o. Alterar.
}

int main (void) {
    double x[tam+1],Isg,h,maxd,erro,pares=0,impares=0;
    int i;

    /*Rela��o de vari�veis:
      --------------------
    tam: n�mero de subdivis�es
    Isg: Integral de Simpson generalizada
    maxd: O m�ximo valor obtido pela quarta derivada
    pares: Soma das fun��es cujos x possuem �ndices pares
    impares: Soma das fun��es cujos x possuem �ndices �mpares
    x[]: x com �ndice dentro dos colchetes*/

    //Entrada de dados
    printf("Entre com os valores de x0 e x%d: ",tam);
    scanf("%lf %lf",&x[0],&x[tam]);

    //C�lculo de h e dos outros x
    h=(x[tam]-x[0])/tam;

    for(i=1;i<tam;i++)
    {
        x[i]=x[i-1]+h;
    }

    //C�lculo da Integral
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

    //C�lculo do erro
    maxd=derivada_quarta(x[0]);

    for(i=1;i<tam+1;i++)
    {
        if(derivada_quarta(x[i])>maxd)
        {
            maxd=derivada_quarta(x[i]);
        }
    }

    erro=sqrt(pow((pow(h,4)/180)*(x[tam]-x[0])*maxd,2));

    //Impress�o dos resultados
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
