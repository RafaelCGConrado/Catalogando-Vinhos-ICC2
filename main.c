#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"


int main(){
    FILE *arq = fopen("vinho.csv", "r");
    VINHO *arr = cria_vetor();
    
    

    int tam_vetor = 0;

    //leitura do arquivo OBS TRANSFORMAR EM FUNÇÃO URGENTEMENTE
    char *str = readline(arq);
    char *token;
    while(!feof(arq)){
        
        str = readline(arq);
        
        token = strtok(str, ",");
        arr[tam_vetor].id = atoi(token);

        token = strtok(NULL, ",");
        arr[tam_vetor].citric_acid = atof(token);

        token = strtok(NULL, ",");
        arr[tam_vetor].residual_sugar = atof(token);
        
        token = strtok(NULL, ",");
        arr[tam_vetor].density = atof(token);
        
        token = strtok(NULL, ",");
        arr[tam_vetor].pH = atof(token);

        
        token = strtok(NULL, ",");
        arr[tam_vetor].alcohol = atof(token);


        tam_vetor++;

        arr = realloc(arr, (tam_vetor + 1) * sizeof(VINHO));

    }
    fclose(arq);

    printa_vinhos(arr, tam_vetor);
    char caracteristica[20];
    scanf("%s", caracteristica);

    ordena(arr, tam_vetor, caracteristica);
    printa_vinhos(arr, tam_vetor);
    

    


    //PROXIMO PASSO: ORDENAR ESSA BAGAÇA


    
    free(arr);

    return 0;

    
}   
