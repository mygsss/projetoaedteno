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

//Funcao recursiva da busca em profundidade
void fazer_dfs(int vertice){
	int k;
	visitados[vertice] = 1;
	ordem_visita[cont_dfs] = vertice;
	cont_dfs++;

	//Percorre os vertices adjacentes
	for(k = 1; k <= n; k++){
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

//Funcao remover da pilha
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
	
	if(aux == NULL){
		printf("\nPilha vazia!\n");
		return;
	}

	printf("\n==== Elementos da pilha ====\n\n");

	//Percorre ate achar o final da lista(NULL)
	while(aux != NULL){

		//Exibe o vertice armazenado no no atual
		printf("            %d\n", aux->vertice);
		
		//Vai para o proximo no
		aux = aux->prox;
	}
}

//Estrutura da fila
typedef struct{
    int dados[MAX];
    int inicio;
    int fim;
}Fila;

Fila fila_dfs;  //Variavel global da fila

//Funcao para inicializar a fila e garantir q o inicio e o fim sejam 0
void inicializar_fila(Fila *f){
    f -> inicio = 0;
    f -> fim = 0;
}

//Funcao para verificar se a fila esta vazia
int fila_vazia(Fila *f){
    return (f -> inicio == f -> fim);
}

//Funcao para inserir elemento no final da fila (enqueue)
void enfileirar(Fila *f, int valor){
    if(f -> fim < MAX){
        f -> dados[f -> fim] = valor;
        f -> fim++;
    }else{
        printf("Erro: A fila esta cheia.\n");
    }
}

//Funcao para retirar elemento do inicio da fila (dequeue)
int desenfileirar(Fila *f){
    if(fila_vazia(f)){
        printf("Erro: A fila esta vazia.\n");
        return -1;
    }
    int valor = f -> dados[f -> inicio];
    f -> inicio++;
    return valor;
}

//Funcao para exibir todos os elementos presentes na fila
void mostrar_fila(Fila *f){
    if(fila_vazia(f)){
        printf("A fila esta vazia.\n");
        return;
    }
    printf("\n===== Elementos da fila =====\n\n");
    for(int k = f -> inicio; k < f -> fim; k++){
        printf("   %d   ", f -> dados[k]);
    }
    printf("\n");
}

void menu_pilha(){ // Esta funcao serve para executar o menu de opcoes da pilha, onde podemos inserir, remover e mostrar os elementos.
    int escolha = -1;
    int valor;
    while(escolha !=0){
        printf("\nEscolha uma opcao:\n\n");
        printf("1 - Inserir elemento na pilha\n");
        printf("2 - Remover elemento da pilha\n");
        printf("3 - Mostrar elementos da pilha\n");
        printf("0 - Voltar\n\n");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
             	printf("\nDigite o valor: ");
             	scanf("%d", &valor);
             	if (valor >= 1) {                  // ajustar conforme o professor responder
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

void menu_fila(){ // Esta funcao serve para rodar o menu de opcoes da fila, onde podemos inserir, remover e mostrar os elementos.
    int escolha = -1;
    int valor;
    while(escolha !=0){    //O While 
        printf("\nEscolha uma opcao:\n\n");
        printf("1 - Inserir elemento na fila\n");
        printf("2 - Remover elemento da fila\n");
        printf("3 - Mostrar elementos da fila\n");
        printf("0 - Voltar\n\n");
        scanf("%d", &escolha);
        
        switch(escolha){
           case 1:
   				printf("\nDigite o valor: ");
    			scanf("%d", &valor);
  				if (valor >= 1) {
       				enfileirar(&fila_dfs, valor);
    			} else {
        			printf("\nValor invalido\n");
    			}
  				break;
  				
            case 2:
   				valor = desenfileirar(&fila_dfs);
    			if (valor != -1) {
    	    		printf("\nRemovido: %d\n", valor);
    			}
   				break;
   				
            case 3:
    			mostrar_fila(&fila_dfs);
   				break;
   				
            case 0:
                printf("\nVoltando...\n");
                break;
                
            default:
                printf("\nOpcao invalida.\n");
        }

    }
}

void menu_principal(){ // Esta funcao serve para rodar o menu de escolhas entre pilha, fila e sair do programa.
    int escolha = -1;
    while (escolha !=0){

        printf("\n\nEscolha uma opcao\n\n");
        printf("1 - Pilha\n");
        printf("2 - Fila\n");
        printf("0 - Sair\n\n");
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


void executafuncao (){   										

    int k;

    if(tamanho==0){
    	return;
	}

	for(k = 1; k <= n; k++){
    	visitados[k] = 0;
	}

    cont_dfs = 0;

	while(pilha!=NULL){
    	pilha = pop(pilha);
	}
		
	inicializar_fila(&fila_dfs);

	for(k = 1; k<= n; k++){
   		if(visitados [k]==0){
        	fazer_dfs(k);
    	}
	}			
	printf("-------  ORDEM DE VISITA -------\n\n");
	
	for(k = 0; k < cont_dfs; k++){
    	printf("  %d  ", ordem_visita[k]);
	}
	printf("\n");

	for(k=0; k<cont_dfs; k++){
    	pilha = push(pilha, ordem_visita[k]);
    	enfileirar(&fila_dfs, ordem_visita[k]);
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

