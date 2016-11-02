#include<stdlib.h>
#include<string.h>
#include"tabelaSimbolo_VO.h"

stableVO criaStableVO(int tamanho)
{
    stableVO *stable = malloc(sizeof(stableVO));
    stable->max = tamanho;
    stable->ultPos = 0;
    stable->bob = malloc(tamanho*sizeof(data));
    return(stable);
}

void destroiStableVO(stableVO *stable)
{
    int i;
    for(i = 0; i < stable->ultPos; i++){
        free(stable->bob[i]->palavra);
        free(stable->bob[i]);
    }
    free(stable);
    return;
}

void insereStableVO(char *key, stableVO *stable)
{

    for(i = 0; i < stable->ultPos; i++){
        if(!strcmp(key,stable->bob[i]->palavra)){
            stable->bob[i]->freq +=1;
            return;
        }
    }
    if(stabe->ultPos == stable->max){
        stable = realocaStableVD(stable);
    }
    strcpy(stable->bob[i]->palavra,key);
    stable->ultPos++;
    return;
}

int buscaBin(stableVO *stable, char *key)
{
    int inicio, meio, fim, temp;
    inicio = 0;
    fim = stable->ultPos -1;
    while(inicio <= fim){
        meio = (inicio + fim)/2;
        temp = strcmp(key, stable->bob[meio]->palavra);
        if(temp )
    }
}
