#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char fileName[5000];
    printf("Digite o nome do arquivo: ");
    scanf("%s",fileName);  
    printf("\n");    
    FILE *fp; 
    fp = fopen(fileName,"r"); 
    char palavra[100];
    int tamanhoPalavra=0;
    int pares=0;
    while(!feof(fp)){
        char c;
        fscanf(fp,"%c",&c);
        if(c!='\n'){
        palavra[tamanhoPalavra]=c;
        tamanhoPalavra++;
        }
    }
    palavra[tamanhoPalavra]='\0';
    char decodificado[tamanhoPalavra];
    strcpy(decodificado,palavra);
    pares=tamanhoPalavra/2;
    int inicio=0,fim=tamanhoPalavra-1;
    while(inicio<pares){
        char aux;
        aux=decodificado[inicio];
        decodificado[inicio]=decodificado[fim-1];
        decodificado[fim-1]=aux;
        aux=decodificado[inicio+1];
        decodificado[inicio+1]=decodificado[fim];
        decodificado[fim]=aux;
        inicio+=4;
        fim-=4;
    }
    for(int i=0;i<=tamanhoPalavra;i+=2){
        char aux;
        aux=decodificado[i];
        decodificado[i]=decodificado[i+1];
        decodificado[i+1]=aux;
    }
    for(int i=0;i<=tamanhoPalavra;i++){
        if(decodificado[i]=='#'){
            decodificado[i]=' ';
        }
    }
    decodificado[tamanhoPalavra]='\0';
    for(int i=0;i<tamanhoPalavra;i++){
        if(decodificado[i]!=' '){
            if(decodificado[i]=='a')
                decodificado[i]='x';
            else if(decodificado[i]=='b')
                decodificado[i]='y';
            else if(decodificado[i]=='c')
                decodificado[i]='z';
            else if(decodificado[i]=='A')
                decodificado[i]='X';
            else if(decodificado[i]=='B')
                decodificado[i]='Y';
             else if(decodificado[i]=='Z')
                decodificado[i]='Z';
            else
            {
                decodificado[i]=decodificado[i]-3;
            }
            
        }
    }
    printf("--------------------\nMensagem codificada:\n--------------------\n");
    printf("%s\n",palavra);
    printf("\n");
    printf("----------------------\nMensagem decodificada:\n----------------------\n");
    int i=0;
    for(i=0;decodificado[i]==' ';i++);
    printf("%s",decodificado);
    //for(int k=i;k<tamanhoPalavra;k++)
     //   printf("%c",decodificado[k]);
    printf("\n");
}