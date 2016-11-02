#include<stdlib.h>
#include<strcmp.h>
#include"tabelaSimbolo_VD.h"


stableVD criaStableVD(int tamanho)
{
    stableVD *stable = malloc(sizeof(stableVD));
    stable->max = tamanho;
    stable->ultPos = 0;
    stable->bob = malloc(tamanho*sizeof(data));
    return(stable);
}

void destroiStableVD(stableVD *stable)
{
    int i;
    for(i = 0; i < stable->ultPos; i++){
        free(stable->bob[i]->palavra);
        free(stable->bob[i]);
    }
    free(stable);
    return;
}

void insereStableVD(char *key, stableVD *stable)
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

stableVD realocaStableVD(stableVD *stable)
{
    stableVD stableNova;
    stableNova = criaStableVD(stable->max*2);
    stableNova->ultPos = stable->ultPos;
    for(i = 0; i < stable->ultPos; i++){
        stableNova->bob[i]->freq = stable->bob[i]->freq;
        strcpy(stableNova->bob[i]->palavra,stable->bob[i]->palavra);
    }
    destroiStableVD(stable);
    return(stableNova);
}
