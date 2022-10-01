#include <stdio.h>

struct vinhos{
    int id;
    double citric_acid, residual_sugar, 
    density, pH, alcohol;
};

typedef struct vinhos VINHO;

char *readline(FILE *stream);
//função utilizada para ler cada linha do arquivo de entrada

VINHO *cria_vetor();
//cria vetor do tipo VINHO

int readfile(FILE *stream, VINHO *arr);
//lê o arquivo csv inteiro, retorna a quantidade de vinhos
//e armazena todas as características de cada um deles em um vetor
 
void printa_vinhos(VINHO *arr, int tam);
//printa todos os vinhos e suas características
//usada apenas para testes

double compara_caracteristica(char *caracteristica, VINHO *arr, int j);
//Função que recebe a caracteristica desejada pelo usuário, o vetor em questão
//e a posição específica no vetor. Será extremamente  útil no reaproveitamento de código.
//Mais informações sobre no funcoes.c

void ordena(VINHO *p, int tamanho, char *caracteristica);
//ordena o array de acordo com a característica desejada pelo usuário

int busca_bin(VINHO *arr, int inicio, int fim, double chave, char *caracteristica, int *qtd);
//versão da busca binária. Retorna a posição do elemento buscado e também conta
//a quantidade de vinhos com a mesma chave, além de informar qual é a primeira ocorrência
// da chave em questão

void printa(VINHO *arr, int i);
//printa os vinhos buscados de acordo com a formatação sugerida na documentação do 
//projeto
