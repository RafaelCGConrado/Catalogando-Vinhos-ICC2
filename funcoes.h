#include <stdio.h>

struct vinhos{
    int id;
    double citric_acid, residual_sugar, 
    density, pH, alcohol;
};

typedef struct vinhos VINHO;

char *readline(FILE *stream);
//FUNÇÃO UTILIZADA PARA LER LINHA A LINHA DO ARQUIVO

VINHO *cria_vetor();
//cria vetor do tipo VINHO

int readfile(FILE *stream, VINHO *arr);
//lê o arquivo csv inteiro, retorna a quantidade de vinhos
//e armazena todas as características de cada um deles em um vetor
 
void printa_vinhos(VINHO *arr, int tam);
//printa todos os vinhos e suas características
//usada apenas para testes

double compara_caracteristica(char *caracteristica, VINHO *arr, int j);

void ordena(VINHO *p, int tamanho, char *caracteristica);

void busca_bin();
