#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
/****************

LAED1 - Problema da Mochila

Alunos(as):Israel Terra // Lucas Alexsanderson

Data:20/09/2020

****************/

int isPiorCaso(int *peso,int tamanho,int *input,int capacidade){
    int pesoTotal=0;
    for(int i=0;i<tamanho;i++){
        if(input[i]==1){
            pesoTotal+=peso[i];
        }
    }
    if(pesoTotal>capacidade)
    return 1;
    return 0;
}
int isBetterCase(int* peso,int*valor,int* input,int capacidade,int tamanho){
    int maiorValor=0;
    for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            int pesoTotal=peso[i];
            if(j!=i){
            int posicao=0;
            int totalParcial=valor[i];
            for(int k=j;k<tamanho;k++){
                if(k!=i){
                    if(pesoTotal+peso[k]<=capacidade){
                        pesoTotal+=peso[k];
                        totalParcial+=valor[k];
                        posicao++;
                    }
                    
                }
            }
            if(totalParcial>maiorValor)
                maiorValor=totalParcial;
            // printf("%i,",peso[i]);
            // for(int i=0;i<posicao;i++){
            //     printf("%i,",caso[i]);
            // }
            // printf(" Valor total parcial= %i",totalParcial);
            // printf("\n");
            }
        } 
    }
    int inputTotal=0;
    for(int i=0;i<tamanho;i++){
        if(input[i]==1){
            inputTotal+=valor[i];
        }
    }
    if(maiorValor==inputTotal)
    return 1;
    return 0;
}


int main(){
    char fileName[100];
    int capacidade;
    int tamanho;
    int *peso,*valor,*input;
    printf("Digite o nome do arquivo: ");
    scanf("%s",fileName);      
    FILE *file; 
    file = fopen(fileName,"r"); 
    if (!file)         
    printf ("Erro na abertura do arquivo.");
    int controle=0,posicao=0;
    bool isPeso=true;
    while (!feof(file))
    {
        char linha[20];
        char *result;
        char *words;
        result=fgets(linha,20,file);
        if(result){   
            if(controle>1&&controle<=tamanho+1){
                words=strtok(linha,"  \n");
                while (words != NULL)
                {
                    if(isPeso){
                        peso[posicao]=atoi(words);
                    }else
                    {
                        valor[posicao]=atoi(words);
                    }
                    words = strtok (NULL, " \n");
                    isPeso=!isPeso;
                }
                    posicao++;
            }
            else if(controle>tamanho+1){
                if(controle==tamanho+2){
                    posicao=0;
                }
                input[posicao]=atoi(linha);
                posicao++;
            }
            else if(controle==0)
                capacidade=atoi(linha);
            else if(controle==1){
               tamanho=atoi(linha);
                peso=(int *) malloc(tamanho*sizeof(int));
                valor=(int *) malloc(tamanho*sizeof(int));
                input=(int *) malloc(tamanho*sizeof(int));
            }   
            controle++;
        }
    }
    fclose(file);
    // printf("Depois de lido");
    // printf("%i %i\n",capacidade,tamanho);
    // for(int i=0;i<tamanho;i++){
    //     printf("%i ",peso[i]);
    //     printf("%i",valor[i]);
    //     printf("\n");
    // }
    // printf("Input\n");
    //pior caso
    if(isPiorCaso(peso,tamanho,input,capacidade)==1)
        printf("Solucao inviavel.\n");
    else if(isBetterCase(peso,valor,input,capacidade,tamanho)==1)
        printf("Solucao otima.\n");
    else
        printf("Solucao viavel mas nao otima.\n");
}