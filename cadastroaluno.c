#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#define STRTAM 81
#define LADO 15

struct estudante{
	int matricula, colocacao;
	char nome[50], curso[50], endereco[60], email[60];
	float media;
	
}vet_estud[3];

void criaLsup(){
	int i;
	gotoxy(44,5);
	printf("%c",201);
	gotoxy(81,5);
	printf("%c",187);
	for(i=45;i<STRTAM;i++)
	{
        	gotoxy(i,5);
        	printf("%c", 205);
	}	
} 
void criaLinf(){
	int i;
	gotoxy(44,15);
	printf("%c",200);
	gotoxy(81,15);
	printf("%c",188);
	for(i=45;i<STRTAM;i++)
	{
        	gotoxy(i,15);
        	printf("%c", 205);
	}	
} 

void criaLlat(){
	int i;
	for(i=6;i<LADO;i++)
	{
        	gotoxy(44,i);
        	printf("%c", 186);
        	gotoxy(81,i);
        	printf("%c", 186);
	}	
} 

void gotoxy(int x,int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void cadastro(cadastro_aluno){
	
			fflush(stdin);
				gotoxy(50,8);
	printf("Digite a matricula do aluno: ");
	scanf("%d", &vet_estud[cadastro_aluno].matricula);
	system("cls");
	
			fflush(stdin);
			gotoxy(50,8);
	printf("Digite o nome do aluno: ");
	gets(vet_estud[cadastro_aluno].nome);
	system("cls");	
	
			fflush(stdin);
			gotoxy(50,8);
	printf("Digite o curso do aluno: ");
	gets(vet_estud[cadastro_aluno].curso);
	system("cls");
	
			fflush(stdin);
			gotoxy(50,8);
	printf("Digite o email do aluno: ");
	gets(vet_estud[cadastro_aluno].email);
	system("cls");
	
			fflush(stdin);
			gotoxy(50,8);
	printf("Digite o endre�o do aluno: ");
	gets(vet_estud[cadastro_aluno].endereco);
	system("cls");
	
			fflush(stdin);
			gotoxy(50,8);
	printf("Digite o media do aluno: ");
	scanf("%f", & vet_estud[cadastro_aluno].media);
	system("cls");
	
			fflush(stdin);
			gotoxy(50,8);
	printf("Digite o coloca��o do aluno: ");
	scanf("%d", & vet_estud[cadastro_aluno].colocacao);
	system("cls");
	
}

int consultar(){
	
	int tecla, i, consul_matri, soma=0, li=9, consulta;
	
	system("cls");
	do
	{
		system("cls");
		gotoxy(50,9);
        printf("\t1 - Consultar todas as matriculas\n");
        gotoxy(50,10);
        printf("\t2 - Consultar por matricula \n");
        gotoxy(50,li);
        printf("->");
        gotoxy(100,30);
        gotoxy(50,20);
        printf("Precione ESC para sair..."); 
        tecla=getch();
        if(tecla==27){
        	return 1;
		}

        do{
            tecla=0;
            if(kbhit()){
                tecla = getch();
                gotoxy(50,li);
                printf("  ");
                if(tecla==224)
                    tecla = getch();
                if(tecla == 72)
                    li--;
                else
                    if(tecla == 80)
                        li++;
                if(li > 10)
                    li=9;
                else
                    if(li < 9)
                        li=10;
                if(tecla==0)
                	tecla=-getch();
	
                if(tecla==-67)
                	egg();
                	
                gotoxy(50,li);
                printf("->");
                gotoxy(100,28); /* se n�o quiser que cursor fique piscando ali */
            }
        }while(tecla != 13);
        system("cls");
        switch(li)
		{
	        case 9: consulta = 1; break;
				
	        case 10: consulta = 2; break;
		}
	        
		
		for(i=0; i<3; i++)
		{
			if(vet_estud[i].matricula == -1){
				i++;
			}
			
			if(vet_estud[i].matricula != NULL){
				soma++;
			}
			
			if(soma == 0){
				printf("\nn�o a dados cadastrados!");
				Sleep(1000);
				i=3;
			}
		}
	
		if(consulta > 2 || consulta < 1)
		{
			printf("op��o invalida");
			system("cls");
		}
	}while(consulta > 2 || consulta < 1);
	
	if(consulta == 1)
	{
		for(i=0; i < 3; i++)
		{
			if(vet_estud[i].matricula == NULL & vet_estud[0].matricula == NULL){
				printf("\nN�o conseguimos mostrar nenhum dado pois n�o a dados cadastrados!\n");
				Sleep(4000);
				break;
			}
			
			if(vet_estud[i].matricula == NULL){
				printf("\nN�o a dados cadastrados!\n");
				Sleep(2000);
				break;
			}
			if(vet_estud[i].matricula!= -1)
			{
				printf("\n%d",vet_estud[i].matricula);
				printf("\n%s",vet_estud[i].nome);
				printf("\n%s",vet_estud[i].curso);
				printf("\n%s",vet_estud[i].email);
				printf("\n%s",vet_estud[i].endereco);
				printf("\n%.1f",vet_estud[i].media);
				printf("\n%d\n",vet_estud[i].colocacao);
			}
			if(i < 3){
				Sleep(3000);
				return 1;
			}
			
		}
		Sleep(2000);
	}else{
		
		fflush(stdin);
		printf("\nDigite a matricula que deseja consulta:");
		scanf("%d", &consul_matri);
		
		do
		{
			if(consul_matri < 0)
			{	
				printf("\nN�o a matriculas com numeros negativos!");
			}
		}while(consul_matri < 0);
		
		
		for(i=0; i < 3; i++)
		{
			if(vet_estud[i].matricula == 0){
				printf("\nMatricula n�o encontrada!\n");
				Sleep(2000);
				break;
			}
			if(vet_estud[i].matricula == -1)
			{
				i++;
			}
			if(vet_estud[i].matricula != NULL)
			{
				soma++;
			}
			if(soma == 0)
			{
				printf("\nn�o a dados cadastrados!");
				Sleep(1000);
				return 1;
			}
			
			if(consul_matri==vet_estud[i].matricula)
			{
				printf("\n%d",vet_estud[i].matricula);
				printf("\n%s",vet_estud[i].nome);
				printf("\n%s",vet_estud[i].curso);
				printf("\n%s",vet_estud[i].email);
				printf("\n%s",vet_estud[i].endereco);
				printf("\n%.1f",vet_estud[i].media);
				printf("\n%d",vet_estud[i].colocacao);
				Sleep(2000);
				return 1;
			}
		}
	}
	
}

int alterar(){
	int alterar_mat, i, soma=0, aumenta=0;
	char alt_opcao, maiusculo;
	
	printf("\nDigite a matricula que deseja alterar: ");
	scanf("%d", &alterar_mat);
		
	for(i=0;i<3;i++)
	{
		if(vet_estud[i].matricula != NULL){
				soma++;
			}
		if(vet_estud[i].matricula < 0){
				printf("\nMatricula n�o encontrada");
				Sleep(1000);
				return 1;
			}
		if(soma == 0){
			printf("\nn�o a dados cadastrados!");	
			Sleep(2000);
			i=3;
			return 1;
		}
		
		if(alterar_mat == vet_estud[i].matricula)
		{
			// altera o nome
			fflush(stdin);
			printf("\nDeseja alterar o nome Sim( S ) ou n�o ( N )");
			scanf("%c", &alt_opcao);
			maiusculo = toupper(alt_opcao);
			alt_opcao = maiusculo;
			system("cls");
			
			if(alt_opcao == 'S')
			{
				fflush(stdin);
				printf("Digite o nome do aluno: ");
				gets(vet_estud[i].nome);
			}
			// altera o curso
			fflush(stdin);	
			printf("\nDeseja alterar o curso Sim( S ) ou n�o ( N )");
			scanf("%c", &alt_opcao);
			maiusculo = toupper(alt_opcao);
			alt_opcao = maiusculo;
			system("cls");
			
			if(alt_opcao == 'S')
			{
				fflush(stdin);
				printf("Digite o curso do aluno: ");
				gets(vet_estud[i].curso);
			}		
			//altera o email
			fflush(stdin);
			printf("\nDeseja alterar o email Sim( S ) ou n�o ( N )");
			scanf("%c", &alt_opcao);
			maiusculo = toupper(alt_opcao);
			alt_opcao = maiusculo;
			system("cls");
			
			if(alt_opcao == 'S')
			{
				fflush(stdin);
				printf("Digite o email do aluno: ");
				gets(vet_estud[i].email);
			}				
			//altera o endere�o
			fflush(stdin);
			printf("\nDeseja alterar o endereco Sim( S ) ou n�o ( N )");
			scanf("%c", &alt_opcao);
			maiusculo = toupper(alt_opcao);
			alt_opcao = maiusculo;
			system("cls");
			
			if(alt_opcao == 'S')
			{
				fflush(stdin);
				printf("Digite o endre�o do aluno: ");
				gets(vet_estud[i].endereco);
			}			
			
			//altera a media 
			fflush(stdin);
			printf("\nDeseja alterar a media Sim( S ) ou n�o ( N )");
			scanf("%c", &alt_opcao);
			maiusculo = toupper(alt_opcao);
			alt_opcao = maiusculo;
			system("cls");
			
			if(alt_opcao == 'S')
			{
				fflush(stdin);
				printf("Digite a media do aluno: ");
				scanf("%f", & vet_estud[i].media);
			}			
			
			//altera a coloca��o 
			fflush(stdin);
			printf("\nDeseja alterar a coloca��o Sim( S ) ou n�o ( N )");
			scanf("%c", &alt_opcao);
			maiusculo = toupper(alt_opcao);
			alt_opcao = maiusculo;
			system("cls");
			
			if(alt_opcao == 'S')
			{
				fflush(stdin);
				printf("Digite o coloca��o do aluno: ");
				scanf("%d", & vet_estud[i].colocacao);
			}		
					
		}
	}
}

int excluir(){
	
	int excluir_mat, i, soma=0;
	
	
	printf("\nDigite a matricula que deseja excluir os dados");
	scanf("%d", &excluir_mat);
	
	for(i=0; i<3; i++)
	{
			if(vet_estud[i].matricula == excluir_mat)
		{
			soma++;
		}
	}
		
	if(soma == 0 || excluir_mat < 0)
	{
		printf("\nMatricula n�o encontrada!");
		Sleep(1000);
		return 1;
	}
	
	for(i=0; i < 3; i++)
	{
		if(excluir_mat==vet_estud[i].matricula)
		{
				vet_estud[i].matricula = -1;
				printf("Matricula excluida!");
				Sleep(2000);
				return(1);
		}
	}	
}

void sair(){
   	system("cls");
    gotoxy(50,10);
    printf("Saindo . . . !\n\n");
    Sleep(1000);
    exit(0);
}

void egg(){
	gotoxy(10,7);
	printf("seu curioso :0");
}

void main (){
	
	int li=9,tecla, i;
	int opcoes, estudante_atual = -1;
    system("color F1");
    do{
        system("cls");
        criaLsup();
        criaLinf();
        criaLlat();
		gotoxy(50,7);
		printf("Escolha a opera%c%co desejada\n",135,198);
		gotoxy(50,9);
        printf("\t1 - Cadastrar\n");
        gotoxy(50,10);
        printf("\t2 - Consultar\n");
        gotoxy(50,11);
        printf("\t3 - alterar\n");
        gotoxy(50,12);
        printf("\t4 - excluir\n");
        gotoxy(50,14);
        printf("\tESC para sair\n");
        gotoxy(50,li);
        printf("->");
        gotoxy(100,28);

        do
		{
            tecla=0;
            if(kbhit())
			{
                tecla = getch();
                gotoxy(50,li);
                printf("  ");
                if(tecla==224)
                    tecla = getch();
                if(tecla==27){
                	sair();
				}
                if(tecla == 72)
                    li--;
                else
                    if(tecla == 80)
                        li++;
                if(li > 12)
                    li=9;
                else
                    if(li < 9)
                        li=12;
                if(tecla==0)
                	tecla=-getch();
	
                if(tecla==-67)
                	egg();
                if(tecla==27){
                	sair();
				}
                
	                gotoxy(50,li);
	                printf("->");
	                gotoxy(100,28); /* se n�o quiser que cursor fique piscando ali */
          	}
		}while(tecla != 13);
        
        system("cls");
        switch(li)
		{
	        case 9: estudante_atual = estudante_atual + 1; 
				cadastro(estudante_atual); break;
				
	        case 10: consultar(estudante_atual); break;
	        
	        case 11: alterar(estudante_atual); break;
	        
	        case 12: excluir(estudante_atual); break;
	
	        case 27: sair();
        }
    }while(li != 13);
}
