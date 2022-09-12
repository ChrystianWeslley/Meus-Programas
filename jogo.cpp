#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>

int main(void)
{
	int num, contador, di = 1, escolha, ten, max, a;
	float pontos = 100, pontosp;
	
	setlocale(LC_ALL, "Portuguese");
	do
	{	
		do
		{	
			system("cls");
			fflush(stdin);
			printf("\n\t\t   Bem vindo ao jogo da adivinhação!");
			printf("\n\t\t\tescolha o nivel de jogo\n\tbebê(1), criança(2), adolescente(3), adulto(4), master(5): ");
			scanf("%d", & di);
			
			if(di > 5 | di < 0){
				printf("\nOpção invalida");
				getch();
			}
		 }while(di > 5 | di < 0);
		
		switch (di)
		{
			case 1: max = 20; ten = 20; break;
			case 2: max = 40; ten = 30; break;
			case 3: max = 60; ten = 20; break;
			case 4: max = 80; ten = 15; break;
			case 5: max = 100; ten = 10; break;
			default: printf("\nOpção invalida"); break;	
		}
		srand(time(0));
		a = rand() % max;
		printf("%d", a);
		getch();
		for(contador=1; 1<=ten; contador++)
		{
			system("cls");
			printf("\nOs numeros serão de 0 a %d!", max);
			printf("\nvoce tem %d tentativas de %d", contador, ten);
			fflush(stdin);
			printf("\nDigite um numero e tente acerta: ");
			scanf("%d", & num);
			
			if(num < 0)	{
				printf("\nVocê não pode digitar numeros negativos");
				getch();
			}else if(num > max){
				printf("\nVocê não pode digitar numeros acima do valor maximo!");
				contador--;
				getch();
			}else if(num == a){
				printf("\nVocê acertou");
				break;
			}else{
				if(num > a){
					printf("\nVocê errou");
					printf("\nSeu numero foi maior que o chute");
					getch();
				}else{
					printf("\nVocê errou");
					printf("\nSeu numero foi menor que o chute");
					getch();
				}	
			}	
			if(contador == ten){
				printf("\nVoce usou todas suas tentaivas!");
				getch();
				break;
			}
			pontosp	= (abs(num-a))/ 2.0;
			pontos = pontos - pontosp;
		}
		do
		{
			if(contador == ten){
				system("cls");
				printf("\nVocê usou todas as suas tentativas\nSeus pontos são %d", pontos);
				pontos = 0;
			}
			system("cls");
			fflush(stdin);
			printf("\nSua pontuação foi %.0f", pontos);
			printf("\nDeseja continuar SIM(1), NÃO(2): ");
			scanf("%d", & escolha);
			
			switch (escolha)
			{
				case 1: printf("\nO jogo ira continuar");break;
				case 2: printf("\nO jogo ira finalizar"); break;
				default: printf("\nOpção invalida"); break;
			}
			getch();
		}while(escolha > 2 | escolha < 0);
	}while(escolha != 2);
}
