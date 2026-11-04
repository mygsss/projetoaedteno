#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 101

// ATEN��O: O c�lculo da complexidade deve incluir todo o cc�digo, inclusive a leitura do arquivo.


char nome_arquivo[50], aux[MAX];								// proibido alterar esta linha
int opcao, tamanho, i, j, n, m, digrafo, matriz_adj[MAX][MAX];  // proibido alterar esta linha
// Declare vari�veis globais a partir daqui.

void menu_pilha(){ // Esta função serve para executar o menu de opções da pilha, onde podemos inserir, remover e mostrar os elementos.
    int escolha = -1;
    while(escolha !=0){
        printf("escolha uma opção:\n");
        printf("1 - Inserir elemento na pilha\n");
        printf("2 - Remover elemento da pilha\n");
        printf("3 - Mostrar elementos da pilha\n");
        printf("0 - Voltar\n");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                printf("Você escolheu inserir elemento na pilha\n");
                break;
            case 2:
                printf("Você escolheu remover elemento da pilha\n");
                break;
            case 3:
                printf("Você escolheu mostrar elementos da pilha\n");
                break;
            case 0:
                printf("Voltando...\n");
                break;
            default:
                printf("Opção inválida\n");
        }

    }
}

void menu_fila(){ // Esta função serve para rodar o menu de opções da fila, onde podemos inserir, remover e mostrar os elementos.
    int escolha = -1;
    while(escolha !=0){    //O While 
        printf("escolha uma opção:\n");
        printf("1 - Inserir elemento na fila\n");
        printf("2 - Remover elemento da fila\n");
        printf("3 - Mostrar elementos da fila\n");
        printf("0 - Voltar\n");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                printf("Você escolheu inserir elemento na fila\n");
                break;
            case 2:
                printf("Você escolheu remover elemento da fila\n");
                break;
            case 3:
                printf("Você escolheu mostrar elementos da fila\n");
                break;
            case 0:
                printf("Voltando...\n");
                break;
            default:
                printf("Opção inválida\n");
        }

    }
}

void menu_principal(){ // Esta função serve para rodar o menu de escolhas entre pilha fila e sair do programa.
     int escolha = -1;
    while (escolha !=0){
        printf("Escolha uma opção:\n");
        printf("1 - pilha\n");
        printf("2 - fila\n");
        printf("0 - Sair\n");
        scanf("%d", &escolha);

         switch(escolha){
        case 1:
            menu_pilha();
            break;
        case 2:
            menu_fila();
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida\n");
    }
  }
}



void executafuncao (){   										// � dentro desta fun��o que o aluno dever� escrever seu c�digo
if(tamanho==0){
    return;
}

menu_principal();

}


int main() {
	opcao = 1;

    while(opcao != 0){
        inicio:
        tamanho = 0;
        m = 0;
        digrafo = 0;
        system("cls"); 
        fflush(stdin); 
        printf("Digite o nome do arquivo (sem o .txt): ");
        gets(nome_arquivo);
        FILE *arquivo; 
        strcat(nome_arquivo,".txt"); 
            
        if((arquivo = fopen(nome_arquivo,"r")) != NULL){
        	while(fgets(aux, MAX, arquivo)) { 
                   char *elemento; 
                   elemento = strtok(aux, " ");
                    while (elemento != NULL){
                        elemento = strtok(NULL, " "); 
                    }
                    tamanho = tamanho + 1; 
                }
                fclose(arquivo);
                
                printf ("\n --------------------------- MATRIZ DE ADJAC�NCIA ---------------------------\n");
                
                if((arquivo = fopen(nome_arquivo,"r")) != NULL){
                    printf("\n");
                    for(int i = 1; i <= tamanho; i++){
                        for(int j = 1; j <= tamanho; j++){
                            fscanf(arquivo, "%d", &matriz_adj[i][j]);
							printf("%3d ", matriz_adj[i][j]); 
                        }
                        printf("\n");
                    }
                }
                fclose(arquivo);
				n = tamanho;
				
                for(int i = 1; i <= tamanho; i++){
                    for(int j = 1; j <= tamanho; j++){
						if (matriz_adj[i][j] != matriz_adj[j][i]) {
							digrafo = 1;   // � d�grafo
						}
					}
				}
				
                for(int i = 1; i <= tamanho; i++){
                    for(int j = 1; j <= tamanho; j++){
						if (digrafo == 1 && matriz_adj[i][j] != 0) {
							m = m + 1;
						} 
						if (digrafo == 0 && matriz_adj[i][j] != 0 && i <= j) {
							m = m + 1;
						}
					}
				}
				
	          printf ("\nN = %d e M = %d \n \n",n,m);     
            } else {
                printf("\nErro ao abrir o arquivo/Erro ao localizar o arquivo\n\n");
                
            }
        	  
		executafuncao ();       
        printf("\nDigite 0 para sair ou qualquer outra coisa para continuar: ");
		scanf("%d", &opcao);
        
    }
    return 0;
}

