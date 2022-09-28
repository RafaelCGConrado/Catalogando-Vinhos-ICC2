#include <stdio.h>
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

    
    char caracteristica[20];
    int i = compara_caracteristica(caracteristica);
    printf("%d", i);

    


    //PROXIMO PASSO: ORDENAR ESSA BAGAÇA


    
    free(arr);

    return 0;

    
}   #include <string.h> 
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


int readfile(FILE *stream, VINHO *arr){

       
    char *str, *token;
    str = readline(stream);
    int tam_vetor = 0;
    
    while(!feof(stream)){
        
        str = readline(stream);
        
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
