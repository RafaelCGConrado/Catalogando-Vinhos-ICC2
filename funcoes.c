#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "funcoes.h"





char *readline(FILE *stream){
    char *str = NULL;
    int n_char = 0;
     
     //Aqui, pegaremos char por char do fluxo de entrada
     //e iremos fazer as devidas comparações
     //caso não seja quebra de linha, armazenamos
     //o char na string e aumentamos seu tamanho
     //para que a leitura prossiga.
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

    //aqui, apenas criamos o vetor e alocamos o espaço de 
    //memória necessário
    VINHO *p = (VINHO *) malloc(1 * sizeof(VINHO));
    if(p) return p;
    return NULL;

}

int readfile(FILE *stream, VINHO *arr){


    
    int tam_vetor = 0;
    char *str = readline(stream);
    //Primeiro, lemos a primeira linha do arquivo e a desconsideramos
    char *token;
    
    while(!feof(stream)){
        
        //aqui, lemos a linha seguinte e vamos dividindo-na em partes,
        //pegando o conteúdo entra as vírgulas e armazenando
        //na respectiva característica do vetor.
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

        //depois de lermos a linha inteira, precisamos aumentar a
        //variavel tam_vetor, que conta o tamanho do vetor/quantidade
        //de vinhos, informação importante no realloc e também
        //em outras partes do programa.
        tam_vetor++;

        arr = realloc(arr, (tam_vetor + 1) * sizeof(VINHO));

    }
    
    return tam_vetor;

}

void printa_vinhos(VINHO *arr, int tam){

        //função básica para printar os registros.
      for(int i = 0; i < tam; i++){
        printf("%d:\n", arr[i].id);
        printf("Citric_Acid: %lf\n", arr[i].citric_acid);
        printf("Residual_Sugar: %lf\n", arr[i].residual_sugar);
        printf("Density: %lf\n", arr[i].density);
        printf("pH: %lf\n", arr[i].pH);
        printf("Alcohol: %lf\n", arr[i].alcohol);
        printf("\n\n");
    
    
    }
}

double compara_caracteristica(char *caracteristica, VINHO *arr, int j){

    //essa função é de extrema importancia para a ordenação, visto que
    //ela permitirá o reaproveitamento do código. Caso contrário, seriam
    //necessárias as repetidas funções de ordenação, com apenas a característica
    //a ser comparada tendo sido modificada em cada uma delas.
    if(strcmp(caracteristica, "citric_acid") == 0) return arr[j].citric_acid;
    if(strcmp(caracteristica, "residual_sugar") == 0) return arr[j].residual_sugar;
    if(strcmp(caracteristica, "density") == 0) return arr[j].density;
    if(strcmp(caracteristica, "pH") == 0) return arr[j].pH;
    if(strcmp(caracteristica, "alcohol") == 0) return arr[j].alcohol;
    //de maneira simples, comparamos a caracteristica desejada  pelo usuario
    //em uma busca e retornamos o valor da característica em questão
    //para determinada posição j do vetor de vinhos.
    

}


void ordena(VINHO *arr, int tamanho, char *caracteristica){

    //A cada iteração do laço exterior, o tamanho diminui
    //(já que queremos trocar de posição com o ultimo elemento do
    //vetor, depois com o penúltimo, ...)
    while(tamanho != 1){

        double maior_val = 0;
        int index_maior_val = 0;
        //o importante aqui será armazenar a posição da maior chave
        //para que a troca possa ser efetuada depois.

        for(int j = 0; j < tamanho; j++){
            double val_atual = compara_caracteristica(caracteristica, arr, j);
            if(val_atual > maior_val){
                index_maior_val = j;
            }

            //critério de desempate: O elemento de maior id
            //fica como o "maior" em ordem crescente.
            if(val_atual == maior_val){
                if(arr[j].id > arr[index_maior_val].id){
                    index_maior_val = j;
                }
            }


        }

        //tendo a posição da maior chave, podemos efetuar a troca
        VINHO aux = arr[tamanho-1];
        arr[tamanho-1] = arr[index_maior_val];
        arr[index_maior_val] = aux;

        tamanho --;

    }


}

