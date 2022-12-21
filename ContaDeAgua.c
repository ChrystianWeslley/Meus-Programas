#include<stdio.h>
#include<math.h>
#include<string.h>
#include <locale.h>

void residencial(conta,agua){
	
	float calculo;
	char consumidor[15]= "RESIDENCIAL";
	
	system("cls");
	
	if (strcmp(consumidor,"RESIDENCIAL") == 0)
	{
		calculo = 5.00 + (0.05 * agua);
		printf("CONTA = %d\n",conta);
		printf("VALOR DA CONTA = %.2f\n",calculo);
	}
	
}

void comercio(conta,agua){
	
	float calculo;
	char consumidor[15]= "COMERCIAL";
	
	system("cls");
	
	if (strcmp(consumidor,"COMERCIAL") == 0 && agua <= 80 )
	{
		calculo = 500.00;
		printf("\nCONTA = %d\n",conta);
		printf("\nVALOR DA CONTA = %.2f\n",calculo);
	}
	
	else if (strcmp(consumidor,"COMERCIAL") == 0 && agua > 80 )
	{
		calculo = 500.00 + ((agua - 80) * 0.25);
		printf("\nCONTA = %d\n",conta);
		printf("\nVALOR DA CONTA = %.2f\n",calculo);
	}
}

void industrial(conta,agua){

	
	float calculo;
	char consumidor[15]= "INDUSTRIAL";
	
	system("cls");
	
	if (strcmp(consumidor,"INDUSTRIAL") == 0 && agua <= 100)
	{
		calculo = 800.00;
		printf("\nCONTA = %d\n",conta);
		printf("\nVALOR DA CONTA = %.2f",calculo);
	}
	else if (strcmp(consumidor,"INDUSTRIAL") == 0 && agua > 100)
	{
		calculo = 800.00 + ((agua - 100 )* 0.04);
		printf("\nCONTA = %d\n",conta);
		printf("\nVALOR DA CONTA = %.2f\n",calculo);
	}
	
}

void main(){
	
	int conta, agua;
	int consumidor;
	
	setlocale(LC_ALL, "Portuguese");
	
	fflush(stdin);
	printf("\nDigite a conta do cliente: ");
	scanf("%d",&conta);
	fflush(stdin);
	printf("\nDigite o consumo de aguá do cliente: ");
	scanf("%d",&agua);
	fflush(stdin);
	printf("\nDigite o tipo de consumidor RESIDENCIAL(1), COMERCIO(2), INDUSTRIAL(3): ");
	scanf("%d",&consumidor);
	
	switch(consumidor)
	{
		case 1: residencial(conta,agua); break;
		
		case 2: comercio(conta,agua); break;
		
		case 3: industrial(conta,agua); break;
	}
}
