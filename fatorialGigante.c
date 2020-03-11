#include <stdio.h>
#include <stdlib.h>
int main(){
    int* total;
    int posicaoTotal=0,indice=0,cout=0;
    total=(int*) calloc (35660,sizeof(int));
    int multiplicador;
    printf("Digite um numero inteiro: ");
    scanf("%i",&multiplicador);
    if(multiplicador<=2){
        printf("%i\n",multiplicador);
        return 0;
    }
    int numero=multiplicador;
    while(numero!=0){
        total[indice]=numero%10;
        //("%i\n",numero%10);
        //("Rest: %i\n",numero%10);
        numero/=10;
        //("Novo numero : %i\n",numero);
        indice++;
        posicaoTotal++;
    }
    for(int i=multiplicador-1;i>=1;i--){
        for(int j=0;j<posicaoTotal;j++){ 
            cout=total[j]*i+cout;
            if(cout>=10){
                total[j]=(cout%10);
                cout/=10;
                if(j+1>=posicaoTotal)
                    posicaoTotal++;
            }
            else{
                total[j]=cout;
                cout=0;    
            }
        }
    }
    printf("Resultado: ");
    int i=posicaoTotal;
    for(i=posicaoTotal;total[i]==0;i--);
    for(int k=i;k>=0;k--){
        printf("%i",total[k]);
    }
    printf("\n");
free(total);

}
