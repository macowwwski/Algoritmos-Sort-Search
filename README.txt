TRABALHO DE ALGORITMOS DE BUSCA E ORDENAÇÃO

Este projeto realiza testes empíricos com algoritmos de busca em vetores de inteiros,
variando tamanho e cenário dos dados.

----------------------------------------
ESTRUTURA DO PROJETO

codigo/
│── busca.c           # Algoritmos de busca e execução de testes
│── gerador_dados.c   # Geração de arquivos binários para testes
│── ordenacao.c       # Geração de vetores para ordenação
dados/
│── grande_aleatorio.bin
│── grande_crescente.bin
│── grande_decrescente.bin
│── medio_aleatorio.bin
│── medio_crescente.bin
│── medio_decrescente.bin
│── pequeno_aleatorio.bin
│── pequeno_crescente.bin
│── pequeno_decrescente.bin

----------------------------------------
ALGORITMOS IMPLEMENTADOS

BUSCA
- Sequencial: percorre todo o vetor até encontrar o elemento.
- Binária: divide o vetor ordenado até localizar o elemento (necessário vetor ordenado).

GERAÇÃO DE DADOS
Arquivos .bin gerados com tamanhos e cenários diferentes:

TAMANHOS:
P - Pequeno (1.000 elementos)
M - Médio   (10.000 elementos)
G - Grande  (100.000 elementos)

CENÁRIOS:
A - Aleatório
C - Crescente
D - Decrescente

Formato do arquivo: <tam>_<cenario>TESTE.bin
Exemplo: grande_aleatorioTESTE.bin

----------------------------------------
COMO COMPILAR

gcc codigo/busca.c -o busca
gcc codigo/gerador_dados.c -o gerador_dados
gcc codigo/ordenacao.c -o ordenacao

----------------------------------------
COMO EXECUTAR

GERAR DADOS:
./gerador_dados

Informe:
- Tamanho (P, M, G)
- Cenário (A, C, D)

TESTES DE ORDENAÇÃO:
./ordenacao

Selecione:
1. Arquivo .bin (1 a 9)
2. Algoritmo de ordenacao (Insertion, Selection, Bubble e Bubble Otimizado)

O programa exibirá:
- Tempo de execução
- Número de comparações
- Número de trocas

TESTES DE BUSCA:
./busca

Selecione:
1. Arquivo .bin (1 a 9)
2. Algoritmo de busca (Sequencial ou Binária)
3. Elemento a buscar

O programa exibirá:
- Tempo de execução
- Número de comparações

----------------------------------------
OBSERVAÇÕES

- Busca binária só funciona em vetores ordenados.
- Memória alocada dinamicamente para carregar vetores.
- Permite múltiplos testes consecutivos.

----------------------------------------
AUTORES

Ana Luiza Senger Macowski
Paulo Henrique Salvadori Junior
