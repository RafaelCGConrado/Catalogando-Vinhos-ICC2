#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"


int main(){
    FILE *arq = fopen("vinho.csv", "r");
    VINHO *v = cria_vetor();
    
    

    int tam_vetor = 1;

    //leitura do arquivo
    char *str = readline(arq);
    double valor;
    while(!feof(arq)){
        str = readline(arq);
        char *token = strtok(str, ",");

        while(token != NULL){
            
            valor = atof(token);
            printf("%lf\n", valor);
            token = strtok(NULL, ",");

        }

    } 
    

    //PRECISO LER LINHA POR LINHA, USAR STRTOK PARA RECORTAR A STRING DA LINHA,
    //CONVERTER CADA SUBSTRING PARA DOUBLE E ARMAZENAR NO VETOR

    fclose(arq);

    return 0;

    
}   
