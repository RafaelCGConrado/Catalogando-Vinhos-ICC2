#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"


int main(){
    
    char nome_arquivo[20];
    scanf("%s", nome_arquivo);
    FILE *arq = fopen(nome_arquivo, "r");
    VINHO *arr = cria_vetor();
    
    

    int tam_vetor = 0;


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

    int n, pos, qtd = 0;
    char caracteristica[20];
    double chave;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%s", caracteristica);
        scanf("%lf", &chave);
        ordena(arr, tam_vetor, caracteristica);
        pos = busca_bin(arr, 0, tam_vetor-1, chave, caracteristica, &qtd);
        if(pos != -1){
            printa(arr, pos);
            printf("Total de vinhos encontrados: %d\n", qtd);
        }
        else{
            printf("Nenhum vinho encontrado\n");
        }

    }




    
    free(arr);

    return 0;

    
}   
