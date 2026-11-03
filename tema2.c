#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 101

// ATEN��O: O c�lculo da complexidade deve incluir todo o c�digo, inclusive a leitura do arquivo.


char nome_arquivo[50], aux[MAX];								// proibido alterar esta linha
int opcao, tamanho, i, j, n, m, digrafo, matriz_adj[MAX][MAX];  // proibido alterar esta linha
// Declare variáveis globais a partir daqui.


//Estrutura de um no na pilha
typedef struct No{
	int vertice;         //Armazena o numero do vertice
	struct No* prox;     //Aponta para o proximo no
}No;

No* pilha = NULL;        //Ponteiro que representa o topo da pilha

//Funcao inserir
No* push(No* pilha, int vertice){

	No* novo = (No*) malloc(sizeof(No));
	 
	//Verifica se a alocacao de memoria foi realizada
	if(novo == NULL){
		printf("\nErro de alocacao\n");
		return pilha;
	}

	//Armazena o vertice no novo no
	novo->vertice = vertice;

	//Faz o novo no apontar para o antigo topo
	novo->prox = pilha;

	//Atualiza o topo
	pilha = novo;
	
	return pilha ;
}

//Funcao remover
No* pop(No*pilha){

	//Verifica se a pilha esta vazia
	if(pilha == NULL){
		printf("\nPilha vazia\n");
		return NULL;
	}
	
	//Guarda o endereco do no que vai ser removido
	No* aux = pilha;
	
	//Atualiza o topo para o proximo no
	pilha = aux->prox;
	
	//Libera a memoria do no removido
	free(aux);
	
	return pilha;
}

//Funcao para consultar o topo da pilha
int peek(No* pilha){

	//Verifica se a pilha esta vazia
	if(pilha == NULL){
		printf("\nPilha vazia\n");
		return -1;
	}
	
	//Acessa o valor armazenado no no que esta no topo
	return pilha->vertice;
}

//Funcao para exibir todos os elementos da pilha
void exibirPilha(No* pilha){
	
	//Cria um ponteiro auxiliar para percorrer a pilha
	No* aux = pilha; 
	
	//Percorre ate achar o final da lista(NULL)
	while(aux != NULL){

		//Exibe o vertice armazenado no no atual
		printf("%d\n", aux->vertice);
		
		//Vai para o proximo no
		aux = aux->prox;
	}
	
}


void executafuncao (){   										// � dentro desta fun��o que o aluno dever� escrever seu c�digo
	
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

