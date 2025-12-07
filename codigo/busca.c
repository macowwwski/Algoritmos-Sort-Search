#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <string.h>


/*--------------- ALGORITMOS DE BUSCA ---------------*/
//1. Busca Sequencial
int busca_sequencial(int arr[], int n, int elemento, long long *comparacoes) {
    *comparacoes = 0;

    for (int i = 0; i < n; i++) {
        (*comparacoes)++;
        if (arr[i] == elemento) {
            return i; 
        }
    }
    return -1; 
}

//2. Busca Binária
int busca_binaria(int arr[], int n, int elemento, long long *comparacoes) {
    *comparacoes = 0;

    int esquerda = 0;
    int direita = n - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        (*comparacoes)++;

        if (arr[meio] == elemento) {
            return meio;  // Encontrou
        }

        (*comparacoes)++;

        if (arr[meio] < elemento) {
            esquerda = meio + 1;  // busca na direita
        } else {
            direita = meio - 1;   // busca na esquerda
        }
    }

    return -1;  // Não encontrado
}




/*--------------- CARREGAMENTO DE ARQUIVO ---------------*/

int* carregar_arquivo_memoria(const char *nome_arquivo, int *tamanho_ptr) {
    FILE *arquivo = fopen(nome_arquivo, "rb");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        *tamanho_ptr = 0;
        return NULL;
    }

    // Determina o tamanho do arquivo em inteiros
    fseek(arquivo, 0, SEEK_END);
    long tamanho_em_bytes = ftell(arquivo);
    rewind(arquivo);

    int num_inteiros = tamanho_em_bytes / sizeof(int);
    *tamanho_ptr = num_inteiros;

    // Aloca memória
    int *vetor = (int *)malloc(tamanho_em_bytes);
    if (vetor == NULL) {
        perror("Erro ao alocar memória");
        fclose(arquivo);
        *tamanho_ptr = 0;
        return NULL;
    }

    // Lê o conteúdo
    fread(vetor, sizeof(int), num_inteiros, arquivo);

    fclose(arquivo);
    return vetor;
}


/*--------------- AUXILIARES CHAMADA DO TESTE ---------------*/

void executar_teste(const char *nome_arquivo, const char *nome_algoritmo, const int elemento) {
    int tamanho_vetor;
    
    // Carrega o vetor original do .bin
    int *vetor_original = carregar_arquivo_memoria(nome_arquivo, &tamanho_vetor);

    if (vetor_original == NULL || tamanho_vetor == 0) {
        return;
    }
    
    // Criar uma cópia para o teste 
    int *vetor_teste = (int *)malloc(tamanho_vetor * sizeof(int));
    if (vetor_teste == NULL) {
        perror("Erro ao alocar memória para cópia");
        free(vetor_original);
        return;
    }
    
    memcpy(vetor_teste, vetor_original, tamanho_vetor * sizeof(int));

    // Variáveis de controle
    clock_t inicio, fim;
    double tempo_execucao;

    long long comparacoes = 0;

    // Cronômetro
    printf("Testando %s em %s (Tamanho: %d)...\n", nome_algoritmo, nome_arquivo, tamanho_vetor);
    inicio = clock();
    
    // Chamada das funções de busca
    if (strcmp(nome_algoritmo, "Busca Sequencial") == 0) {
        busca_sequencial(vetor_teste, tamanho_vetor, elemento, &comparacoes);
    }
    else if (strcmp(nome_algoritmo, "Busca Binária") == 0) {
        busca_binaria(vetor_teste, tamanho_vetor, elemento, &comparacoes);
    }
    else printf("Algoritmo não reconhecido.\n");

    
    fim = clock();

    // Cálculo do tempo de execução
    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
   
    // Exibição dos resultados
    printf("Tempo de execucao: %.15f segundos\n", tempo_execucao); 
    printf("Numero de comparacoes: %lld\n", comparacoes); 

    // Liberação de memória
    free(vetor_teste);
    free(vetor_original); 
}


/*--------------- FUNÇÃO MAIN ---------------*/

int main() {
    // Lista dos arquivos
    const char *arquivos[] = {
        "../dados/grande_aleatorio.bin",
        "../dados/grande_crescente.bin",
        "../dados/grande_decrescente.bin",
        "../dados/medio_aleatorio.bin",
        "../dados/medio_crescente.bin",
        "../dados/medio_decrescente.bin",
        "../dados/pequeno_aleatorio.bin",
        "../dados/pequeno_crescente.bin",
        "../dados/pequeno_decrescente.bin"
    };
    int num_arquivos = sizeof(arquivos) / sizeof(arquivos[0]);
    
    // Lista dos algoritmos 
    const char *algoritmos[] = {  
      "Busca Sequencial",
      "Busca Binária"
    };
    int num_algoritmos = sizeof(algoritmos) / sizeof(algoritmos[0]);
  
    int escolha_arquivo = -1;
    int escolha_algoritmo = -1;
    char continuar = 's';
    int elemento;


    printf("--- Iniciando Teste Empirico de Algoritmos de Ordenacao ---\n\n");

    while (continuar == 's' || continuar == 'S') {
        
        // Menu de arquivos
        printf("\n| Escolha o Arquivo de Entrada: |\n");
        for (int i = 0; i < num_arquivos; i++) {
            printf("| %d - %s\n", i + 1, arquivos[i]);
        }
        printf("Selecione (1 a %d): ", num_arquivos);
        if (scanf(" %d", &escolha_arquivo) != 1 || escolha_arquivo < 1 || escolha_arquivo > num_arquivos) {
            printf("Seleção de arquivo inválida! Tente novamente.\n");
          
            while (getchar() != '\n'); 
            continue; 
        }

        // Menu de algoritmos
        printf("\n| Escolha o Algoritmo de busca: |\n");
        for (int i = 0; i < num_algoritmos; i++) {
            printf("| %d - %s\n", i + 1, algoritmos[i]);
        }
        printf("Selecione (1 a %d): ", num_algoritmos);
        if (scanf(" %d", &escolha_algoritmo) != 1 || escolha_algoritmo < 1 || escolha_algoritmo > num_algoritmos) {
            printf("Seleção de algoritmo inválida! Tente novamente.\n");
            while (getchar() != '\n'); 
            continue; 
        }

        // Menu do elemento a ser buscado
        printf("\nDigite o elemento que deseja buscar: ");
        if (scanf("%d", &elemento) != 1) {
            printf("Entrada inválida! Tente novamente.\n");
            while (getchar() != '\n'); 
            continue;
        }

        printf("\n============================================\n");
        
        // Execução do teste       
        const char *arquivo_selecionado = arquivos[escolha_arquivo - 1];
        const char *algoritmo_selecionado = algoritmos[escolha_algoritmo - 1];
        
        executar_teste(arquivo_selecionado, algoritmo_selecionado, elemento);
        
        printf("============================================\n");
        
        // Continuidade no teste
        printf("\nDeseja executar outro teste? (s/n): ");
        if (scanf(" %c", &continuar) != 1) {
             continuar = 'n'; 
        }
    }

    printf("\nTestes encerrados.\n");
    return 0;
}