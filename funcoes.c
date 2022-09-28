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






int readfile(FILE *stream, VINHO *arr){

    
    int tam_vetor = 0;
    char *str = readline(stream);
    char *token;
    
    while(!feof(stream)){
        
        str=readline(stream);
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
    
    return tam_vetor;

}

void printa_vinhos(VINHO *arr, int tam){

      for(int i = 0; i < tam; i++){
        printf("%d:\n", arr[i].id);
        printf("%lf\n", arr[i].citric_acid);
        printf("%lf\n", arr[i].residual_sugar);
        printf("%lf\n", arr[i].density);
        printf("%lf\n", arr[i].pH);
        printf("\n\n");
    
    
    }
}

int compara_caracteristica(char *caracteristica){

    if(strcmp(caracteristica, "citric_acid") == 0) return 1;
    if(strcmp(caracteristica, "residual_sugar") == 0) return 2;
    if(strcmp(caracteristica, "density") == 0) return 3;
    if(strcmp(caracteristica, "pH") == 0) return 4;
    if(strcmp(caracteristica, "alcohol") == 0) return 5;

}

void ordena_geral(VINHO *arr, int tamanho, int caract){

    switch(caract){
        case 1:


        case 2:


        case 3:


        case 4:


        case 5:



    }
    


}

void ordena_acid(VINHO *arr, int tamanho){

    double maior = arr[0].citric_acid;
    int index_maior = 0;

    for(int i = 1; i < tamanho; i++){
        if(arr[i].citric_acid > maior){
            maior = arr[i].citric_acid;
            index_maior = i;
        }
        
        
        if(arr[i].citric_acid == maior){
            if(arr[index_maior].id < arr[i].id){
                 maior = arr[i].citric_acid;
                 index_maior = i;
            }
        }
    }

    //localizada a maior chave, trocar de valor com o último elemento 
    





}

