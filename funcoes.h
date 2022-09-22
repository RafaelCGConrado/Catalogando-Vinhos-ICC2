#include <stdio.h>

typedef struct vinhos VINHO;

char *readline(FILE *stream);
//Lê uma linha inteira de entrada e retorna a string

VINHO *cria_vetor();
//cria vetor do tipo VINHO

char *recorta_string(char *str, char *delimitador);

void ordena(VINHO *p, int tamanho);
