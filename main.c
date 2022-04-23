/*************************************************************
Derivada de uma Função Polinomial

(a) Faça uma função que recebe um inteiro n > 0 e um vetor de números reais c, o qual
armazena os coeficientes de um polinômio p(x) = c0 + c1 * x + ... + c_n * x^n de grau n, e
devolve a derivada de p(x) no próprio vetor c. Além disso, devolve via return o grau
do polinômio derivado.

(b) Faça uma função que recebe um inteiro n > 0, um vetor de números reais c, o qual
armazena os coeficientes de um polinômio p(x) = c0 + c1 * x + ... + cn * x
n de grau n, e um real a e devolve p(a), ou seja, o valor do polinômio no ponto a.
(c) Faça um programa que leia um inteiro m > 0, os coeficientes reais de um polinômio
p(x) = c0 + c1 * x + ... + c_m * x^m de grau m e um número real a e imprima o valor de
p'(p(a) - 1) + p"(a + 4).
************************************************************/

#include <stdio.h>
#include <math.h>
#define TAM 100

//parte (a) do exercicio
int deriva(int m, float c[]){
	int i;
	c[0]=0;
	for(i=1;i<=m;i++)
		c[i-1]=c[i]*i;
	return m-1;
}
//parte (b) do exercicio
float p(int m, float c[], float a){
	int i;
	float soma;
	soma+=c[0];
	for(i=1;i<=m;i++)
		soma+=c[i]*pow(a,i);
	return soma;
}
//parte (c) do exercicio
float equacao(int m,float c[],float a){
	int i;
	float soma1=0,soma2=0,pa,derivada1,derivada2;
	pa=p(m,c,a)-1;
	derivada1=deriva(m,c);
	for(i=0;i<=derivada1;i++){
		if(i>=1)
			soma1+=c[i]*pow(pa,i);
		else
			soma1+=c[i];
	
	}	
	
	derivada2=deriva(derivada1,c);	
	for(i=0;i<=derivada2;i++){
		if(i>=1)
			soma2+=c[i]*pow((a+4),i);
		else
			soma2+=c[i];
	
	}

	return soma1+soma2;
}

int main(){
	
	int m,i;
	float c[TAM],a;
	printf("------------------------------------------------ Derivada de um polinomio ---------------------------------------------\n\n");
	printf("                                               Digite o grau do polinomio: ");
	scanf("%d",&m);
	
	printf("\n                              Digite os coeficientes do polinomio (separados por espaco)\n ");
	printf("                                              na forma: c + bx + ax^2\n");
	printf("\t\t\t\t\t\t\t");
	for(i=0;i<=m;i++)
		scanf("%f",&c[i]);
	
	printf("\n                                                Digite o valor de  a: ");
	scanf("%f",&a);
	printf("\n"); 
	printf("\n                                           p'(p(a)-1) + p\"(a+4) =  %.2f\n",equacao(m,c,a));
	printf("\n------------------------------------------------------------------------------------------------------------------------");
	
	return 0;
}
