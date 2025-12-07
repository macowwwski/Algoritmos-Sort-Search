#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/*
TAM            CENÁRIO
P: 1.000       A: aleatório
M: 10.000      C: crescente
G: 100.000     D: decrescente
*/

/*--------------- FUNÇÕES AUXILIARES ---------------*/

int tratamento_tamanho(char tam){
    int n;

    switch (tam){
        case 'P':
            n = 5;
            break;

        case 'M':
            n = 10000;
            break;

        case 'G':
            n = 100000;
            break;

        default:
            printf("Tamanho inválido. \n");
    }

    return n;
}


const char* obter_nome_tam(char tam) {
    if (tam == 'P') {
        return "pequeno";
    } 
    
    else if (tam == 'M') {
        return "medio";
    } 
    
    else if (tam == 'G') {
        return "grande";
    }

    return "desconhecido"; 
}


const char* obter_nome_cenario(char cenario) {
    if (cenario == 'A') {
        return "aleatorio";
    } 
    
    else if (cenario == 'C') {
        return "crescente";
    } 
    
    else if (cenario == 'D') {
        return "decrescente";
    }
    
    return "desconhecido"; 
}



/*--------------- FUNÇÃO GERADORA ---------------*/

void gerador_arquivo(char cod_tam, char cod_cenario){
    int tam = tratamento_tamanho(cod_tam);

    int *vetor = (int *)malloc(tam * sizeof(int)); 
    if (vetor == NULL) {
        perror("Erro ao alocar memória");
        return; 
    }

    // Preenchimento do vetor
    if (cod_cenario == 'A'){
        int limite_superior = 1000001;

        for (int i = 0; i < tam; i++) {
            vetor[i] = rand() % limite_superior; 
        }
    }

    else if (cod_cenario == 'C'){
        for (int i = 0; i < tam; i++){
            vetor[i] = i;
        }
    }

    else if (cod_cenario == 'D'){
        for (int i = 0; i< tam; i++){
            vetor[i] = tam - i;
        }
    }

    // Geração do nome do arquivo
    const char *nome_tamanho = obter_nome_tam(cod_tam);
    const char *nome_cenario = obter_nome_cenario(cod_cenario);

    char nome_arquivo[100];
    snprintf(nome_arquivo, sizeof(nome_arquivo),
                "%s_%sTESTE.bin", nome_tamanho, nome_cenario);
    
    // Escrita no arquivo binário            
    FILE *arquivo = fopen(nome_arquivo, "wb");

    if(arquivo == NULL){
        perror("Erro ao abrir o arquivo para escrita.");
        free(vetor);
        return;
    }

    fwrite(vetor, sizeof(int), tam, arquivo);

    fclose(arquivo);
    printf("Arquivo binário '%s' criado com sucesso com %d inteiros.\n", nome_arquivo, tam);

    
    free(vetor);
}



/*--------------- FUNÇÃO MAIN ---------------*/

int main(){
    srand(time(NULL));

    char tamanho;
    char cenario;

    printf("Digite o tamanho (P, M, G) e o cenario desejados (A, C, D)\n");
    scanf(" %c %c", &tamanho, &cenario);

    gerador_arquivo(tamanho, cenario);

    return 0;
}
