#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"


int main(){
    FILE *arq = fopen("vinho.csv", "r");
    VINHO *p = cria_vetor();
    
    int tam_vetor = 1; 

    //PRECISO LER LINHA POR LINHA, USAR STRTOK PARA RECORTAR A STRING DA LINHA,
    //CONVERTER CADA SUBSTRING PARA DOUBLE E ARMAZENAR NO VETOR

    fclose(arq);

    return 0;

    
}   
