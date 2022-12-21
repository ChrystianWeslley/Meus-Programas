using System;
using static System.Net.Mime.MediaTypeNames;

namespace CursoCSharp.EstruturasDeControle {
    class estruturaWhile {
        public static void Executar() {

            int chute = 0, max = 0, tent = 1, tentativas = 0, dificuldade = 0, tentativasRestantes = 0;
            bool numEncontrado = false;
            string entrada;

            do 
            {
                Console.Clear();
                Console.Write("\nEscolha a dificultado de jogo entre 1 e 5: ");
                string numero;
                numero = Console.ReadLine();
                int.TryParse(numero, out dificuldade);
                if(dificuldade != 0) {

                    switch (dificuldade) 
                    {
                        case 1: max = 10; tentativasRestantes = tent = 5; break;
                        case 2: max = 20; tentativasRestantes = tent = 8; break;
                        case 3: max = 30; tentativasRestantes = tent = 10; break;
                        case 4: max = 40; tentativasRestantes = tent = 12; break;
                        case 5: max = 50; tentativasRestantes = tent = 15; break;
                    }

                } else {
                    Console.WriteLine("digite um valor valido!");
                    Console.ReadKey();
                }

            }while(dificuldade == 0);
           
            Random random = new Random();
            int numeroSecreto = random.Next(1, max);

            Console.WriteLine($"\nVoce tera {tentativasRestantes} tentativas");
            Console.ReadKey();

            while (tentativasRestantes > 0 && !numEncontrado) 
            { 
                do
                {
                    do 
                    {
                        Console.Clear();
                        Console.Write($"\nDigite o seu chute entre 1 e {max}: ");
                        entrada = Console.ReadLine();
                        int.TryParse(entrada, out chute);

                        if(chute == 0) {
                            Console.WriteLine("digite um valor valido!");
                            Console.ReadKey();
                        } else if( chute > max) {
                            Console.Clear();
                            Console.WriteLine($"\nSeu numero esta entre 1 e {max}");
                            Console.WriteLine("Não digite valores maiores que isso!");
                            Console.ReadKey();
                        }
                        
                    }while(chute == 0 || chute > max);

                    tentativas++;
                    tentativasRestantes--;

                    if(chute == 0 || chute < 0) {
                        Console.Clear();
                        Console.WriteLine("Digite um valor valido");
                        Console.ReadKey();
                    }

                }while(chute < 0 || chute == 0);

                if(numeroSecreto == chute) {
                    numEncontrado = true;
                    var corAnterior = Console.BackgroundColor;
                    Console.BackgroundColor = ConsoleColor.DarkGreen;
                    Console.Clear();
                    Console.WriteLine($"numero encontrado! voce gastou {tentativas} tentativas de {tentativasRestantes}!");
                    Console.ReadKey();
                    Console.BackgroundColor = corAnterior;
                } else if (chute > numeroSecreto) {
                    Console.Clear();
                    Console.WriteLine("Seu chute foi maior que o numero");
                    Console.WriteLine($"Restam {tentativasRestantes} tentativas");
                    Console.ReadKey();
                } else if(chute < numeroSecreto) { 
                    Console.Clear();
                    Console.WriteLine("Seu chute foi menor que o numero");
                    Console.WriteLine($"Restam {tentativasRestantes} tentativas");
                    Console.ReadKey();
                }else if( tentativasRestantes == 0) {
                    Console.Clear();
                    Console.WriteLine("voce gastou todas as suas tentativas\n");
                    Console.WriteLine("Voce perdeu");
                    Console.ReadKey();
                }
            }
        }
    }
}
