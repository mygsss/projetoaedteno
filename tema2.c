#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 101

// ATENÇÃO: O cálculo da complexidade deve incluir todo o ccódigo, inclusive a leitura do arquivo.


char nome_arquivo[50], aux[MAX];								// proibido alterar esta linha
int opcao, tamanho, i, j, n, m, digrafo, matriz_adj[MAX][MAX];  // proibido alterar esta linha
// Declare variáveis globais a partir daqui.
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
    printf("Conteudo da fila: ");
    for(int k = f -> inicio; k < f -> fim; k++){
        printf("%d", f -> dados[k]);
    }
    printf("\n");
}

void executafuncao (){   										// É dentro desta função que o aluno deverá escrever seu código
int x = 0;
if (!x) {
printf ("deu certo");
}
int opcao_fila = -1;
    int valor;

    inicializar_fila(&fila_dfs);

    while (opcao_fila != 0) {
        printf("\n\n--- TESTE ISOLADO DA FILA ---\n");
        printf("1. Inserir na fila (Enqueue)\n");
        printf("2. Remover da fila (Dequeue)\n");
        printf("3. Mostrar fila inteira\n");
        printf("0. Concluir teste\n");
        printf("Escolha: ");
        scanf("%d", &opcao_fila);

        switch (opcao_fila) {
            case 1:
                printf("Digite o valor para enfileirar: ");
                scanf("%d", &valor);
                enfileirar(&fila_dfs, valor);
                break;
            case 2:
                valor = desenfileirar(&fila_dfs);
                if (valor != -1) {
                    printf("Sucesso: Vertice %d removido.\n", valor);
                }
                break;
            case 3:
                mostrar_fila(&fila_dfs);
                break;
            case 0:
                printf("Encerrando painel de testes...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    }
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
                
                printf ("\n --------------------------- MATRIZ DE ADJACÊNCIA ---------------------------\n");
                
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
							digrafo = 1;   // é dígrafo
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

