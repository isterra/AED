#include <stdio.h>
#include<stdlib.h>
#include <string.h>
//5909
//\0
int qtdeEstradas(FILE *fp){
    int i=0;
    char c;
    char estradas[5];
      while(!feof(fp)){
        fscanf(fp,"%c",&c);
        if(c!='\n')
            estradas[i]=c;
        else
            break;
        i++;
    }
    return atoi(estradas);  
}
int main(){
    char fileName[100];
    //printf("Digite o nome do arquivo de entrada: ");
    //scanf("%s",fileName);      
    FILE *fp; 
    fp = fopen("arquivo.txt","r"); 
    if (!fp)         
    printf ("Erro na abertura do arquivo.");
    
    int Estradas=qtdeEstradas(fp);
    char rota1[Estradas+1][20];
    char rota2[Estradas+1][20];
    char distancia[Estradas][20];
    char destino[2][20];
    int controle=0;
    int cIR1=0,cJR1=0;
    int cIR2=0,cJR2=0;
    int cID=0,cJD=0;
    while(!feof(fp)){
        if(controle>2)
            controle=0;
        char c;
        fscanf(fp,"%c",&c);
            if(c!=' '&&c!='\n'){
                if(controle==0){
                    rota1[cIR1][cJR1]=c;
                    cJR1++;
                    }
                    if(controle==1){
                    rota2[cIR2][cJR2]=c;
                    cJR2++;
                    }
                    if(controle==2){
                    distancia[cID][cJD]=c;
                    cJD++;
                    }
            }
            if(c==' '||c=='\n'){
                if(controle==0){
                rota1[cIR1][cJR1]='\0'; 
               // printf("%s\n",rota1[cIR1]); 
                    cIR1++;
                    cJR1=0;
                }
                if(controle==1){
                rota2[cIR2][cJR2]='\0';
                   // printf("%s\n",rota2[cIR2]);
                    cIR2++;
                    cJR2=0;   
                }
                if(controle==2){
                distancia[cID][cJD]='\0';
                //printf("%s\n",distancia[cID]);
                    cID++;
                    cJD=0;
                } 
                controle++;      
            } 
    }
    fclose(fp);
    strcpy(destino[0],rota1[10]);
    strcpy(destino[1],rota2[10]);
    printf("Rota1:");
    for(int i =0 ;i<Estradas;i++)
        printf("\n%s",rota1[i]);
        printf("\n");
    printf("Rota2:");
    for(int i =0 ;i<Estradas;i++)
        printf("\n%s",rota2[i]);
        printf("\n");
        printf("Distancias:");
    for(int i =0 ;i<Estradas;i++)
        printf("%s\n",distancia[i]);
        printf("\n");
    int qtdeCidades=0;
    for(int i=0,igual=0;i<Estradas;i++){
        for(int k=0;k<i;k++){
            if(!strcmp(rota1[i],rota1[k])){
                igual++;
                break;
            }
        }
        if(igual==0)
            qtdeCidades++;
        igual=0;
    }
    for(int i=0,igual=0;i<Estradas;i++){
        for(int j=0;j<Estradas;j++){
            if(!strcmp(rota1[j],rota2[i])){
                igual++;
                break;
            }
        }
        for(int k=0;k<i;k++){
            if(!strcmp(rota2[i],rota2[k])){
                igual++;
                break;
            }
        }
        if(igual==0)
            qtdeCidades++;
        igual=0;
    }
    printf("Quantidade de cidades: %i ",qtdeCidades);
    printf("Quantidade de estradas: %i\n",Estradas);
    char cidades[qtdeCidades][20];
    int posicoes=0;
    for(int i=0,igual=0;i<Estradas;i++){
        for(int k=0;k<i;k++){
            if(!strcmp(rota1[i],rota1[k])){
                igual++;
                break;
            }
        }
        if(igual==0){
            strcpy(cidades[posicoes],rota1[i]);
            strcat(cidades[posicoes],"\0");
            posicoes++;
        }
        igual=0;
    }
    for(int i=0,igual=0;i<Estradas;i++){
        for(int j=0;j<Estradas;j++){
            if(!strcmp(rota1[j],rota2[i])){
                igual++;
                break;
            }
        }
        for(int k=0;k<i;k++){
            if(!strcmp(rota2[i],rota2[k])){
                igual++;
                break;
            }
        }
        if(igual==0){
            strcpy(cidades[posicoes],rota2[i]); 
            strcat(cidades[posicoes],"\0");
            posicoes++;
        }
            
        igual=0;
    }
    //Printa as cidades diferentes
    //for(int i=0;i<qtdeCidades;i++){
      // printf("%s\n",cidades[i]);
    //}
    //Organiza a matriz de distancia
    //compara as cidades isoladas pelas combinacoes
    /*
    ex: cidades A,B,C,D
    se for msm cidade ex A/A coloca 0
    ai compara 
    A/A , A/B, A/C ,A/D ,A/E, B/B ,B/C - isso dentro do vetor de cidades
    conseguindo essas 2 chaves procura no vetor de rotas , e o indice que der igual
    é o mesmo indice para a distancia , ai coloco na matriz de distancias*/
    int distancias[qtdeCidades][qtdeCidades];
    for(int i=0;i<qtdeCidades;i++){
        for(int j=i;j<qtdeCidades;j++){
            if(i==j){
                distancias[i][j]=0;
            }else{
                for(int k=0;k<Estradas;k++){
                    if(!strcmp(rota1[k],cidades[i])&&!strcmp(rota2[k],cidades[j])){
                        distancias[i][j]=atoi(distancia[k]);
                        distancias[j][i]=atoi(distancia[k]);    
                        break;
                    }
                }
            }
        }
    }
    printf("Matriz de distancias\n");
    for(int i=0;i<qtdeCidades;i++){
        for(int j=0;j<qtdeCidades;j++){
           printf("%i ",distancias[i][j]);
        }
        printf("\n");
    }
    printf("Origem: %s Destino: %s\n",destino[0],destino[1]);



    
    
    
    
}

