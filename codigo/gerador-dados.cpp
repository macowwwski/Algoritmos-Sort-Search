#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>

/*
TAM       CENÁRIO
P: 1.000       A: aleatório
M: 10.000      C: crescente
G: 100.000     D: decrescente
*/

int tratamento_tamanho(char tam){
    int n;

    switch (tam){
        case 'P':
            n = 1000;
            break;

        case 'M':
            n = 10000;
            break;

        case 'G':
            n = 10000;
            break;

        default:
            printf("Tamanho inválido. \n");
    }

    return n;
}


void gerador_arquivo(int tam, char cenario){
    int *vetor = (int *)malloc(tam * sizeof(int)); 

    if (vetor == NULL) {
        return; 
    }


    if (cenario == 'A'){
        int i;
        int limite_superior = 1000001;

        for (i = 0; i < tam; i++) {
            vetor[i] = rand() % limite_superior; 
        }
    }


    else if (cenario == 'C'){
        for (int i = 0; i < tam; i++){
            vetor[i] = i;
        }
    }


    else if (cenario == 'D'){
        for (int i = 0; i< tam; i++){
            vetor[i] = tam - i;
        }
    }

    //chamar função escrita_binario


    free(vetor);
}


void escrita_binario(int *conteudo, int tam, const char *nome_arquivo){
    FILE *arquivo = fopen(nome_arquivo, "wb");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita.");
        return;
    }

    size_t itens_escritos = fwrite(conteudo, sizeof(int), tam, arquivo);

    if (itens_escritos != tam) {
        fprintf(stderr, "Atenção: Apenas %zu de %d itens foram escritos.\n", itens_escritos, tam);
    }

    fclose(arquivo);

    printf("Arquivo binário '%s' criado com sucesso com %d inteiros.\n", nome_arquivo, tam);
}