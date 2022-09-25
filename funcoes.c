#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "funcoes.h"





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

// void ordena(VINHO *p, int tamanho){

    
// }

int conta_vinhos(FILE *stream){
    

    int tamanho = 0;
    while(!feof(stream)){
        char *str = readline(stream);
        tamanho++;
    }
    //retornamos (tamanho-2) para "ignorar" o cabeçalho 
    return (tamanho-2);

}



void ordena(VINHO *arr, int tamanho){
    


}
