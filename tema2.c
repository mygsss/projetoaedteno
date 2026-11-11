#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 101

// ATEN��O: O c�lculo da complexidade deve incluir todo o cc�digo, inclusive a leitura do arquivo.


char nome_arquivo[50], aux[MAX];								// proibido alterar esta linha
int opcao, tamanho, i, j, n, m, digrafo, matriz_adj[MAX][MAX];  // proibido alterar esta linha
// Declare vari�veis globais a partir daqui.

//Variaveis globais da DFS
int visitados[MAX];
int ordem_visita[MAX];
int cont_dfs = 0;

//Funcao recursiva da busca em profundidade DFS

void fazer_dfs(int vertice){          //Complexidade total: O(N^2)
	int k;
	visitados[vertice] = 1;
	ordem_visita[cont_dfs] = vertice;
	cont_dfs++;

	//Percorre os vertices adjacentes
	for(k = 1; k <= n; k++){         //Estrutura de repeticao - Complexidade: O(N))
	if(matriz_adj[vertice][k] == 1 && visitados[k] == 0){
		fazer_dfs(k); // chama a funcao recursiva 
	}
  }
}

//Estrutura da pilha
typedef struct No {
	int vertice;         //Armazena o numero do vertice
	struct No* prox;     //Aponta para o proximo no
}No;

No* pilha = NULL;        //Ponteiro que representa o topo da pilha

//Funcao inserir da pilha
No* push(No* pilha, int vertice){    //Complexidade: O(1) - A insercao ocorre no inicio da lista

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

//Funcao remover da pilha
No* pop(No*pilha){        //Complexidade: O(1) - A remocao ocorre no incio da lista

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
int peek(No* pilha){       //Complexidade: O(1) - O acesso e direto, nao precisa percorrer a estrutura

	//Verifica se a pilha esta vazia
	if(pilha == NULL){
		printf("\nPilha vazia\n");
		return -1;
	}
	
	//Acessa o valor armazenado no no que esta no topo
	return pilha->vertice;
}

//Funcao para exibir todos os elementos da pilha
void exibirPilha(No* pilha){       //Complexidade: O(N) - Precisa percorrer todos os nos 
	
	//Cria um ponteiro auxiliar para percorrer a pilha
	No* aux = pilha; 
	
	if(aux == NULL){
		printf("\nPilha vazia!\n");
		return;
	}

	printf("\n-------- Elementos da pilha --------\n");
	//Percorre ate achar o final da lista(NULL)
	while(aux != NULL){ // estrutura de repeticao (complexidade: O(N))

		//Exibe o vertice armazenado no no atual
		printf("               %d\n", aux->vertice);
		
		//Vai para o proximo no
		aux = aux->prox;
	}
}

// Estrutura da fila
typedef struct Fila {
    int vertice;
    struct Fila *prox;
} Fila;

Fila *fila_dfs = NULL; // Ponteiro para o início da fila

// Inserindo na fila
Fila *enqueue(Fila *fila, int valor) {   //Complexidade: O(N) - precisa percorrer toda a lista para achar o ultimo no
    Fila *novo = (Fila *) malloc(sizeof(Fila));
    
    if (novo == NULL) {
        printf("Erro de alocacao!\n");
        return fila;
    }
    
    novo->vertice = valor;
    novo->prox = NULL;
    
    // Se a fila estiver vazia
    if (fila == NULL) {
        return novo;
    }
    
    // Percorre até o último elemento
    Fila *aux = fila;
    while(aux->prox != NULL) {  // estrutura de repeticao (complexidade: O(N))
        aux = aux->prox;
    }
    
    aux->prox = novo;
    return fila;
}

// Removendo da fila
Fila *dequeue(Fila *fila) {   //Complexidade: O(1) - remove no inicio 
    if(fila == NULL) {
        printf("Fila vazia!\n");
        return NULL;
    }
    
    Fila *aux = fila;
    fila = fila->prox;
    free(aux);
    
    return fila;
}

// Consultando o topo
void front(Fila *fila) {     //Complexidade: O(1) - acesso direto, sem precisar percorrer a estrutura
    if(fila == NULL) {
        printf("Fila vazia!\n");
        return;
    }
    printf("\n-------- PRIMEIRO DA FILA ---------\n");
    printf("\nVertice : %d\n", fila->vertice);
}

// Verificando se a fila está vazia
int isEmpty(Fila *fila) {     //Complexidade: O(1) - consulta o primeiro ponteiro
    return (fila == NULL);
}

// Função auxiliar para mostrar a fila inteira
void mostrarFila(Fila *fila) {  //Complexidade: O(N) - percorre todos os nos da estrutura
    if(fila == NULL) {
        printf("Fila vazia!\n");
        return;
    }
    Fila *aux = fila;
    printf("\nConteudo da fila: ");
    while(aux != NULL) {  //estrutura de repeticao (complexidade: O(N))
        printf("%d ", aux->vertice);
        aux = aux->prox;
    }
    printf("\n");
}


void menu_pilha(){ // Esta funcao serve para executar o menu de opcoes da pilha, onde podemos inserir, remover e mostrar os elementos.
    int escolha = -1;
    int valor;
    while(escolha !=0){  //A quantidade de repeticoes depende das escolhas do usuario
        printf("\n====================================\n");
        printf("           MENU DA PILHA\n");
        printf("====================================\n");
        printf("1 - Inserir elemento na pilha\n");
        printf("2 - Remover elemento da pilha\n");
        printf("3 - Mostrar elementos da pilha\n");
        printf("0 - Voltar\n");
        printf("===================================\n");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
             	printf("\nDigite o valor: ");
             	scanf("%d", &valor);
             	if (valor >= 1) {                  
                	pilha = push(pilha, valor);
             	} else {
            		printf("\nValor invalido\n");
          		}
           		break;
             
            case 2:
    			valor = peek(pilha);               // le o topo antes de remover
    			if (valor != -1) {
       				pilha = pop(pilha);
       				printf("\nRemovido: %d\n", valor);
    				}
   				break;
   				
           case 3:
    			exibirPilha(pilha);
   				break;
   				
            case 0:
                printf("\nVoltando...\n");
                break;
                
            default:
                printf("\nOpcao invalida.\n");
        }

    }
}

void menu_fila(){  // Funcao para executar o menu de opcoes da fila, onde podemos inserir, remover, mostrar e verificar se a fila esta vazia.
    int opcao = -1;
    int valor;
    
    while(opcao != 0) {  //estrutura de repeticao
        printf("\n====================================\n");
        printf("           MENU DA FILA\n");
        printf("====================================\n");
        printf("1 - Enqueue (Inserir)\n");
        printf("2 - Dequeue (Remover)\n");
        printf("3 - Front (Primeiro)\n");
        printf("4 - Mostrar fila\n");
        printf("5 - Verificar fila vazia\n");
        printf("0 - Sair\n");
        printf("===================================\n");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("\nDigite o valor: ");
                scanf("%d", &valor);
                if (valor >= 1) {
                    fila_dfs = enqueue(fila_dfs, valor);
                } else {
                    printf("Valor invalido\n");
                }
                break;
            case 2:
                if (fila_dfs != NULL) {
                    valor = fila_dfs->vertice; // Lê o primeiro da fila antes de remover
                    fila_dfs = dequeue(fila_dfs);
                    printf("Removido: %d\n", valor);
                } else {
                    printf("\nFila vazia! Nao ha elementos para remover.\n");
                }
                break;
            case 3:
                front(fila_dfs);
                break;
            case 4:
                mostrarFila(fila_dfs);
                break;
            case 5:
                if(isEmpty(fila_dfs)) {
                    printf("\nFila vazia!\n");
                } else {
                    printf("\nA fila possui elementos.\n");
                }
                break;
            case 0:
                printf("\nEncerrando...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    }
}

void menu_principal(){ // Esta funcao serve para rodar o menu de escolhas entre pilha, fila e sair do programa.
    int escolha = -1;
    while (escolha !=0){  //estrutura de repeticao
        printf("\n===================================\n");
        printf("           MENU PRINCIPAL\n");
        printf("===================================\n");
        printf("1 - Pilha\n");
        printf("2 - Fila\n");
        printf("0 - Sair\n");
        printf("===================================\n");
        scanf("%d", &escolha);

        switch(escolha){
        	case 1:
            	menu_pilha();
           		break;
           		
        	case 2:
            	menu_fila();
            	break;
            	
        	case 0:
           		printf("\nSaindo...\n");
            	break;
            	
       		default:
            	printf("\nOpcao invalida.\n");
    }
  }
}

//Executa a DFS, organiza os vertices visitados e transforma em pilha e fila

void executafuncao (){    //Complexidade total: O(N^2)										
	/*int x = 0;
    if (!x) {
    printf ("deu certo");
    }*/
   int k;

    if(tamanho==0){
    	return;
	}

	for(k = 1; k <= n; k++){      //Complexidade: O(N) - organiza o vetor dos vertices visitados
    	visitados[k] = 0;
	}

    cont_dfs = 0;

	while(pilha!=NULL){           //Complexidade: O(N) - Esvazia a pilha
    	pilha = pop(pilha);
	}
		
	while(!isEmpty(fila_dfs)){     //Complexidade: O(N) - Esvazia a fila
    fila_dfs = dequeue(fila_dfs);
    }

    //Percorre os vertices e inicia a DFS nos que ainda nao foram visitados
	for(k = 1; k<= n; k++){        //Complexidade: O(N^2) - execucao completa da DFS com matriz de adjacencia
   		if(visitados [k]==0){
        	fazer_dfs(k);
    	}
	}			
	printf("\n------------- ORDEM DE VISITA -------------\n\n");
	
	for(k = 0; k < cont_dfs; k++){   //Complexidade: O(N) - exibe a ordem de visita dos vertices
    	printf("  %d  ", ordem_visita[k]);
	}
	printf("\n");

    //Insere os vertices vistados na pilha e fila
	for(k=0; k<cont_dfs; k++){       //Complexidade: O(N^2) - sao realizadas N insercoes na fila
    	pilha = push(pilha, ordem_visita[k]);            
    	fila_dfs = enqueue(fila_dfs, ordem_visita[k]);  
	}
	
	menu_principal();
}

int main() {
	opcao = 1;

    while(opcao != 0){        //Repeticao controlada pelo usuario
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
        	while(fgets(aux, MAX, arquivo)) {              //Complexidade: O(N^2)
                   char *elemento; 
                   elemento = strtok(aux, " ");
                    while (elemento != NULL){             //Complexidade: O(N^2)
                        elemento = strtok(NULL, " "); 
                    }
                    tamanho = tamanho + 1; 
                }
                fclose(arquivo);
                
                printf ("\n --------------------------- MATRIZ DE ADJAC�NCIA ---------------------------\n");
                
                if((arquivo = fopen(nome_arquivo,"r")) != NULL){
                    printf("\n");
                    for(int i = 1; i <= tamanho; i++){      //Complexidade: O(N^2) - leitura da matriz de adjacencia
                        for(int j = 1; j <= tamanho; j++){
                            fscanf(arquivo, "%d", &matriz_adj[i][j]);
							printf("%3d ", matriz_adj[i][j]); 
                        }
                        printf("\n");
                    }
                }
                fclose(arquivo);
				n = tamanho;
				
                for(int i = 1; i <= tamanho; i++){        //Complexidade: O(N^2) - verifica se o grafo e direcionado
                    for(int j = 1; j <= tamanho; j++){
						if (matriz_adj[i][j] != matriz_adj[j][i]) {
							digrafo = 1;   // � d�grafo
						}
					}
				}
				
                for(int i = 1; i <= tamanho; i++){        //Complexidade: O(N^2) - contagem de arestas
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
        	  
		executafuncao();     //Complexidade: O(N) - Processamento do grafo
        printf("\nDigite 0 para sair ou qualquer outra coisa para continuar: ");
		scanf("%d", &opcao);
        
    }

    return 0;
}

