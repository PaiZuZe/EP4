#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tabelaSimbolo_VD.h"

stableVD *criaStableVD()
{
    stableVD *stable = malloc(sizeof(stableVD));
    stable->max = 16;
    stable->ultPos = 0;
    stable->bob = malloc(stable->max*sizeof(dataVD));
    return(stable);
}

void destroiStableVD(stableVD *stable)
{
    int i;
    for(i = 0; i < stable->ultPos; i++)
        free(stable->bob[i].palavra);
    free(stable->bob);
    free(stable);
    return;
}

void insereStableVD(char *key, stableVD *stable)
{
    int i;
    for(i = 0; i < stable->ultPos; i++){
        if(!strcmp(key,stable->bob[i].palavra)){
            stable->bob[i].freq++;
            return;
        }
    }
    /*antes de inserirmos a palavra pode ser que a tabela esteja cheia*/
    if(stable->ultPos == stable->max){
        stable = realocaStableVD(stable);
    }
    /*como a tabela tem espaço para a palavra nova e ela não estava na lista
     *simplesmente podemos mudar a frequencia para um adicionar a palavra
     */
    stable->bob[i].palavra = malloc(strlen(key)*sizeof(char));
    strcpy(stable->bob[i].palavra,key);
    stable->bob[i].freq = 1;
    stable->ultPos++;
    return;
}

stableVD *realocaStableVD(stableVD *stable)
{
    stableVD *stableNova;
    int i;
    stableNova = criaStableVD(stable->max*2);
    stableNova->ultPos = stable->ultPos;
    /*ao dobrarmos o tamanho garantimos que não iremos fazer essa operação
     *muitas vezes
     */
    for(i = 0; i < stable->ultPos; i++){
        stableNova->bob[i].freq = stable->bob[i].freq;
        stableNova->bob[i].palavra = malloc(strlen(stable->bob[i].palavra)*sizeof(char));
        strcpy(stableNova->bob[i].palavra, stable->bob[i].palavra);
    }
    destroiStableVD(stable);
    return(stableNova);
}
