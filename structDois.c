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
#define CAIXA 81

struct endereco{
	int numero;
	char logradouro[50], nome_end[50], bairo[50],complemento[60];
};

struct datanasc{
	int dia,mes,ano;
};


struct cliente{
	int codigo, telefone;
	char nome[50], email[50];
	
	struct endereco ende_cli;
	struct datanasc data;
	
}vet_func[3];

void gotoxy(int x,int y){

    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void caixa(){
    int i;
    
	gotoxy(44,9);
	printf("%c",201);
	gotoxy(81,9);
	printf("%c",187);

	for(i=45;i<CAIXA;i++)
	{
        gotoxy(i,9);
        printf("%c", 205);
	}

	gotoxy(44,11);
	printf("%c",200);
	gotoxy(81,11);
	printf("%c",188);

	for(i=45;i<CAIXA;i++)
	{
        gotoxy(i,11);
        printf("%c", 205);
	}	

	for(i=10;i<11;i++)
	{
        gotoxy(44,i);
        printf("%c", 186);
        gotoxy(81,i);
        printf("%c", 186);
	}
}

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

void cadastro(cadastro_func){
	
	fflush(stdin);
	gotoxy(40,7);
	printf("Digite o codigo do cliente: ");
	caixa();
    gotoxy(50,10);
	scanf("%d", &vet_func[cadastro_func].codigo);
	system("cls");
	
	fflush(stdin);
	gotoxy(40,7);
	printf("Digite o nome do cliente: ");
	caixa();
    gotoxy(50,10);
	gets(vet_func[cadastro_func].nome);
	system("cls");	
	
	fflush(stdin);
	gotoxy(40,7);
	printf("Digite o email cliente: ");
	caixa();
    gotoxy(50,10);
	gets(vet_func[cadastro_func].email);
    system("cls");
	
	fflush(stdin);
	gotoxy(40,7);
	printf("Digite o telefone: ");
	caixa();
    gotoxy(50,10);
	scanf("%d", & vet_func[cadastro_func].telefone);
	system("cls");
	
	fflush(stdin);
	gotoxy(40,7);
	printf("Digite o dia do seu aniversario");
	caixa();
    gotoxy(50,10);
	scanf("%d", & vet_func[cadastro_func].data.dia);
	system("cls");

	fflush(stdin);
	gotoxy(40,7);
	printf("Digite o mes do seu aniversario");
	caixa();
    gotoxy(50,10);
	scanf("%d", & vet_func[cadastro_func].data.mes);
	system("cls");

	fflush(stdin);
	gotoxy(40,7);
	printf("Digite o dia do seu aniversario");
	caixa();
    gotoxy(50,10);
	scanf("%d", & vet_func[cadastro_func].data.ano);
	system("cls");

	fflush(stdin);
	gotoxy(40,7);
	printf("Digite o nome doo endereco");
	caixa();
    gotoxy(50,10);
	scanf("%s", & vet_func[cadastro_func].ende_cli.nome_end);
	system("cls");

	fflush(stdin);
	gotoxy(40,7);
	printf("Digite o bairro");
	caixa();
    gotoxy(50,10);
	scanf("%s", & vet_func[cadastro_func].ende_cli.bairo);
	system("cls");

	fflush(stdin);
	gotoxy(40,7);
	printf("Digite o logradouro");
	caixa();
    gotoxy(50,10);
	scanf("%s", & vet_func[cadastro_func].ende_cli.logradouro);
	system("cls");

	fflush(stdin);
	gotoxy(40,7);
	printf("Digite o numero da casa");
	caixa();
    gotoxy(50,10);
	scanf("%d", & vet_func[cadastro_func].ende_cli.numero);
	system("cls");

	fflush(stdin);
	gotoxy(40,7);
	printf("Digite um complemento");
	caixa();
    gotoxy(50,10);
	scanf("%s", & vet_func[cadastro_func].ende_cli.complemento);
	system("cls");
}

int consultar(){
	
	int tecla, i, consul_matri, soma=0, li=9, consulta, aux;
	
	system("cls");

	do
	{
		system("cls");
		criaLsup();
        criaLinf();
        criaLlat();
		gotoxy(45,9);
        printf("\t1 - Consultar todas as codigos\n");
        gotoxy(45,10);
        printf("\t2 - Consultar por codigo \n");
        gotoxy(45,li);
        printf("->");
        gotoxy(100,30);
        gotoxy(56,15);
        //pressiona a tecla esc para finalizar o codigo
        gotoxy(50,13);
        printf("Precione ESC para sair..."); 

        do//do para interssao comas setas do teclado
        {
            tecla=0;
            if(kbhit())
            {
                tecla = getch();
                gotoxy(45,li);
                printf("  ");
                if(tecla==27)
                    return 1;
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

                gotoxy(45,li);
                printf("->");
                gotoxy(100,28); // se não quiser que cursor fique piscando ali 
            }
        }while(tecla != 13);
        system("cls");

        switch(li)
		{
	        case 9: consulta = 1; break;

	        case 10: consulta = 2; break;
		}
	        
		for(i=0; i<3; i++)//consultar se a codigo cadastrada e esconde as excluidas
		{
			if(vet_func[i].codigo == -1){
				i++;
			}
			
			if(vet_func[i].codigo != NULL){
				soma++;
			}
			
			if(soma == 0){
				printf("\nn%co a dados cadastrados!",198);
				Sleep(1000);
				break;
			}
		}
	
		if(consulta > 2 || consulta < 1)
		{
			printf("op%c%co invalida",135,198);
			system("cls");
		}

	}while(consulta > 2 || consulta < 1);
	
	if(consulta == 1)
	{
		soma=0;
		
		for(i=0; i < 3; i++)
		{
            if(vet_func[i].codigo == -1){
				i++;
			}
			
			if(vet_func[i].codigo > 0){
				aux=1;
			}
			
			if(vet_func[i].codigo==NULL){
				 Sleep(2000);
				 return 1;
			}

			if(aux < 0){
				printf("\nN%co a dados cadastrados!\n",198);
				Sleep(4000);
				break;
			}
			
			if(vet_func[i].codigo != NULL && vet_func[i].codigo != -1){
				printf("\n%d\n",vet_func[i].codigo);
				printf("\n%s\n",vet_func[i].nome);
				printf("\n%s\n",vet_func[i].email);
				printf("\n%d\n",vet_func[i].data.dia);
				printf("\n%d\n",vet_func[i].data.mes);
				printf("\n%d\n",vet_func[i].data.ano);
				printf("\n%s\n",vet_func[i].ende_cli.nome_end);
				printf("\n%s\n",vet_func[i].ende_cli.logradouro);
				printf("\n%s\n",vet_func[i].ende_cli.bairo);
				printf("\n%d\n",vet_func[i].ende_cli.numero);
				printf("\n%s\n",vet_func[i].ende_cli.complemento);
			}
		}
        Sleep(2000);
	}else{
		
        do
        {
            fflush(stdin);
            gotoxy(45,7);
            printf("Digite a codigo que deseja consultar:");
            caixa();
            gotoxy(50,10);
            scanf("%d", &consul_matri);
            if (consul_matri<0)
            {
                printf("n%co digite numeros negativos",198);
            }
            
        }while(consul_matri<0);

		for(i=0; i < 3; i++)
		{
			if(vet_func[i].codigo == -1)
			{
				i++;
			}
			if(vet_func[i].codigo < 0 && vet_func[i].codigo != NULL)
			{
				soma++;
			}
			if(soma == 0&&i==2)
			{
				printf("\nn%co a dados cadastrados!",198);
				Sleep(1000);
				return 1;
			}
    
			if(consul_matri == vet_func[i].codigo)
			{
				printf("\n%d\n",vet_func[i].codigo);
				printf("\n%s\n",vet_func[i].nome);
				printf("\n%s\n",vet_func[i].email);
				printf("\n%d\n",vet_func[i].data.dia);
				printf("\n%d\n",vet_func[i].data.mes);
				printf("\n%d\n",vet_func[i].data.ano);
				printf("\n%s\n",vet_func[i].ende_cli.nome_end);
				printf("\n%s\n",vet_func[i].ende_cli.logradouro);
				printf("\n%s\n",vet_func[i].ende_cli.bairo);
				printf("\n%d\n",vet_func[i].ende_cli.numero);
				printf("\n%s\n",vet_func[i].ende_cli.complemento);
				break;
			}
            if(i==2){
                printf("codigo n%co encontrada",198);
                Sleep(1000);
                break;
            }
		}
	}
}

void alterar(){
	int alterar_mat, i, aumenta=0,tecla, aux;
	char alt_opcao, maiusculo;
    printf("\nDigite a codigo que deseja alterar: ");
    scanf("%d",&alterar_mat);
		
	for(i=0;i<3;i++)
	{
		if(vet_func[i].codigo < 0 || vet_func[i].codigo > 0){
				aux++;
			}
			
		if(aux == 0 && i==2){
			printf("\nn%co a dados cadastrados!",198);
			printf("\ncodigo n%co encontrada",198);	
			Sleep(2000);
			return 1;
		}
		
		if(alterar_mat == vet_func[i].codigo)
		{
			// altera o nome
			fflush(stdin);
			printf("\nDeseja alterar o nome Sim( S ) ou n%co ( N )",198);
			scanf("%c", &alt_opcao);
			maiusculo = toupper(alt_opcao);
			alt_opcao = maiusculo;
			system("cls");
			
			if(alt_opcao == 'S')
			{
				fflush(stdin);
				printf("Digite o nome do cliente: ");
				gets(vet_func[i].nome);
			}
			// altera o curso
			fflush(stdin);	
			printf("\nDeseja alterar email( S ) ou n%co ( N )",198);
			scanf("%c", &alt_opcao);
			maiusculo = toupper(alt_opcao);
			alt_opcao = maiusculo;
			system("cls");
			
			if(alt_opcao == 'S')
			{
				fflush(stdin);
				printf("Digite o email: ");
				gets(vet_func[i].email);
			}		
			//altera o email
			fflush(stdin);
			printf("\nDeseja alterar o telefone Sim( S ) ou n%co ( N )",198);
			scanf("%c", &alt_opcao);
			maiusculo = toupper(alt_opcao);
			alt_opcao = maiusculo;
			system("cls");
			
			if(alt_opcao == 'S')
			{
				fflush(stdin);
				printf("Digite o email do cliente: ");
				gets(vet_func[i].telefone);
			}				
			//altera o endereço
			
			fflush(stdin);
			printf("\nDeseja alterar o dia do aniversario Sim( S ) ou n%co ( N )");
			scanf("%c", &alt_opcao);
			maiusculo = toupper(alt_opcao);
			alt_opcao = maiusculo;
			system("cls");
			
			if(alt_opcao == 'S')
			{
				fflush(stdin);
				printf("Digite o dia: ",135);
				scanf("%d",&vet_func[i].data.dia);
			}			
			
			fflush(stdin);
			printf("\nDeseja alterar o mes Sim( S ) ou n%co ( N )");
			scanf("%c", &alt_opcao);
			maiusculo = toupper(alt_opcao);
			alt_opcao = maiusculo;
			system("cls");
			
			if(alt_opcao == 'S')
			{
				fflush(stdin);
				printf("Digite o mes: ");
				scanf("%d", &vet_func[i].data.mes);
			}			
			
			fflush(stdin);
			printf("\nDeseja alterar o ano Sim( S ) ou n%co ( N )",135,198);
			scanf("%c", &alt_opcao);
			maiusculo = toupper(alt_opcao);
			alt_opcao = maiusculo;
			system("cls");
			
			if(alt_opcao == 'S')
			{
				fflush(stdin);
				printf("Digite o ano: ",135);
				scanf("%d",& vet_func[i].data.ano);
			}			
			
			fflush(stdin);
			printf("\nDeseja alterar o nome do endere%co Sim( S ) ou n%co ( N )",135,198);
			scanf("%c", &alt_opcao);
			maiusculo = toupper(alt_opcao);
			alt_opcao = maiusculo;
			system("cls");
			
			if(alt_opcao == 'S')
			{
				fflush(stdin);
				printf("Digite o nome do endere%co : ",135);
				gets(vet_func[i].ende_cli.nome_end);
			}			
			
			//altera a media 
			fflush(stdin);
			printf("\nDeseja alterar o logradouro ( S ) ou n%co ( N )");
			scanf("%c", &alt_opcao);
			maiusculo = toupper(alt_opcao);
			alt_opcao = maiusculo;
			system("cls");
			
			if(alt_opcao == 'S')
			{
				fflush(stdin);
				printf("Digite o logradouro: ");
				gets(vet_func[i].ende_cli.logradouro);
			}			
			
			//altera a colocação 
			fflush(stdin);
			printf("\nDeseja alterar o nome do bairro Sim( S ) ou n%co ( N )");
			scanf("%c", &alt_opcao);
			maiusculo = toupper(alt_opcao);
			alt_opcao = maiusculo;
			system("cls");
			
			if(alt_opcao == 'S')
			{
				fflush(stdin);
				printf("Digite o bairro do cliente: ");
				gets(vet_func[i].ende_cli.bairo);
			}	
			
			fflush(stdin);
			printf("\nDeseja alterar o numero Sim( S ) ou n%co ( N )");
			scanf("%c", &alt_opcao);
			maiusculo = toupper(alt_opcao);
			alt_opcao = maiusculo;
			system("cls");
			
			if(alt_opcao == 'S')
			{
				fflush(stdin);
				printf("Digite o numero: ");
				scanf("%d",&vet_func[i].ende_cli.numero);
			}	
			
			fflush(stdin);
			printf("\nDeseja alterar o complemento Sim( S ) ou n%co ( N )");
			scanf("%c", &alt_opcao);
			maiusculo = toupper(alt_opcao);
			alt_opcao = maiusculo;
			system("cls");
			
			if(alt_opcao == 'S')
			{
				fflush(stdin);
				printf("Digite o complemento: ");
				gets(vet_func[i].ende_cli.complemento);
			}							
		}
	}
}

int excluir(){
	
	int excluir_mat, i, soma=0, tecla;
	gotoxy(40,7);
	printf("Digite a codigo que deseja excluir os dados");
    gotoxy(50,15);
    printf("Precssione ESC para sair");
    caixa();
    gotoxy(50,10);
    tecla = getch();

	if(tecla==27){
        gotoxy(58,13);
        printf("Saindo ...");
        Sleep(1000);
        return 1;
    }else{
        gotoxy(50,10);
        scanf("%d",&excluir_mat);
    }
	
	for(i=0; i<3; i++)
	{
		if(vet_func[i].codigo == excluir_mat)
        {
			soma++;
		}
	}
		
	if(soma == 0 || excluir_mat < 0)
    {
        gotoxy(50,13);
		printf("codigo n%co encontrada!",198);
		Sleep(2000);
		return 1;
	}
	
	for(i=0; i < 3; i++)
    {
		if(excluir_mat==vet_func[i].codigo)
        {
			vet_func[i].codigo = -1;
            gotoxy(50,13);
			printf("codigo excluida!");
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

void main (){
	
	int li=9,tecla, i;
	int opcoes, funcionario_atual = -1;
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

                if(tecla==27){
                	sair();
				}
	            gotoxy(50,li);
	            printf("->");
	            gotoxy(100,28); /* se não quiser que cursor fique piscando ali */
          	}
		}while(tecla != 13);
        
        system("cls");
        switch(li)
		{
	        case 9: funcionario_atual = funcionario_atual + 1; 
			cadastro(funcionario_atual); break;
				
	        case 10: consultar(); break;
	        
	        case 11: alterar(); break;
	        
	        case 12: excluir(); break;
	
	        case 27: sair();
        }
    }while(li != 13);
}
