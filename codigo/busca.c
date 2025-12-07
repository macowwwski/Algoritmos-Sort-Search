#include <stdio.h>
#include <stdlib.h> 


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
