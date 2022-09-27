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

char *recorta_string(char *str, char *delimitador);

void ordena(VINHO *p, int tamanho);

int readfile(FILE *stream, VINHO *arr);
 

int conta_vinhos(FILE *stream);
//CONTA A QUANTIDADE DE VINHOS PRESENTES NO ARQUIVO

// void ordena(VINHO *arr);
    //prototipo

void printa_vinhos(VINHO *arr, int tam);
