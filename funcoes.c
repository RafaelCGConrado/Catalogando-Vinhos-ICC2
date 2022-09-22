#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "funcoes.h"

struct vinhos{
    double id, citric_acid, 
    residual_sugar, density, pH, alcohol;
};

char *readline(FILE *stream){
    char *str = NULL;
    int n_char = 0;
     
     while(1){
        char c = fgetc(stream);
        
        if(c == '\r') continue;

        str = realloc(str, (n_char+1) * sizeof(char));
        if(c == '\n' || c == EOF){
            str[n_char] = '\0';
            break;
        }

        str[n_char] = c;
        n_char ++;
     }

    return str;

}


VINHO *cria_vetor(){

    VINHO *p = (VINHO *) malloc(1 * sizeof(VINHO));
    if(p) return p;
    return NULL;

}

char *recorta_string(char *str, char *delimitador){

}

void ordena(VINHO *p, int tamanho){

    
}
