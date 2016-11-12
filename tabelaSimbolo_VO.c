#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tabelaSimbolo_VO.h"

void mergeSortVOfreq(int inicio, int fim, stableVO *stable)
{
    int meio;
    if (inicio < fim - 1) {
        meio = (inicio + fim)/2;
        mergeSortVOfreq(inicio, meio, stable);
        mergeSortVOfreq(meio, fim, stable);
        mergeVOfreq(inicio, meio, fim, stable);
    }
}

void mergeVOfreq(int inicio, int meio, int fim, stableVO *stable)
{
    int i, j, k;
    dataVO *w;
    w = malloc ((fim - inicio) * sizeof (dataVO));
    i = inicio; j = meio;
    k = 0;
    while (i < meio && j < fim) {
        if (stable->info[i].freq <=  stable->info[j].freq){
            w[k].palavra = malloc(strlen(stable->info[i].palavra)*sizeof(char));
            strcpy(w[k].palavra, stable->info[i].palavra);
            w[k].freq = stable->info[i].freq;
            k++;
            i++;
        }
        else{
            w[k].palavra = malloc(strlen(stable->info[j].palavra)*sizeof(char));
            strcpy(w[k].palavra, stable->info[j].palavra);
            w[k].freq = stable->info[j].freq;
            k++;
            j++;
        }
    }
    while (i < meio){
        w[k].palavra = malloc(strlen(stable->info[i].palavra)*sizeof(char));
        strcpy(w[k].palavra, stable->info[i].palavra);
        w[k].freq = stable->info[i].freq;
        k++;
        i++;
    }

    while (j < fim){
        w[k].palavra = malloc(strlen(stable->info[j].palavra)*sizeof(char));
        strcpy(w[k].palavra, stable->info[j].palavra);
        w[k].freq = stable->info[j].freq;
        k++;
        j++;
    }
    for (i = inicio; i < fim; ++i){
        stable->info[i].palavra = malloc(strlen(w[i - inicio].palavra)*sizeof(char));
        strcpy(stable->info[i].palavra, w[i - inicio].palavra);
        stable->info[i].freq = w[i - inicio].freq;
    }
    free (w);
}
void imprimeVO_A(stableVO *stable)
{
    int i;
    /*como a tabela já esta ordenada só iremos imprimir ela.
     */
    for(i = 0; i < stable->ultPos; i++){
        printf("%s ", stable->info[i].palavra);
        printf("%d\n", stable->info[i].freq);
    }
    return;
}
void imprimeVO_O(stableVO *stable)
{
    int i;
    mergeSortVOfreq(0, stable->ultPos, stable);
    for(i = 0; i < stable->ultPos; i++){
        printf("%s ", stable->info[i].palavra);
        printf("%d\n", stable->info[i].freq);
    }
    return;
}
stableVO *criaStableVO()
{
    stableVO *stable = malloc(sizeof(stableVO));
    stable->max = 8;
    stable->ultPos = 0;
    stable->info = malloc(stable->max*sizeof(dataVO));
    return(stable);
}

void destroiStableVO(stableVO *stable)
{
    int i;
    for(i = 0; i < stable->ultPos; i++)
        free(stable->info[i].palavra);
    free(stable->info);
    free(stable);
    return;
}

stableVO *insereStableVO(char *key, stableVO *stable)
{
    int i,k;
    /*primeiro iremos verificar se a tabela esta cheia.
     */
    if(stable->ultPos == stable->max){
        stable = realocaStableVO(stable);
    }
    for(i = 0; i < stable->ultPos; i++){
        if(!strcmp(key,stable->info[i].palavra)){
            stable->info[i].freq++;
            return stable;
        }
        if(strcmp(key, stable->info[i].palavra) < 0){
            for(k = stable->ultPos - 1; k >= i; k--){
                stable->info[k + 1].palavra = malloc(strlen(stable->info[k].palavra)*sizeof(char));
                strcpy(stable->info[k + 1].palavra,stable->info[k].palavra);
                stable->info[k + 1].freq = stable->info[k].freq;
            }
            break;
        }
    }
    stable->info[i].palavra = malloc(strlen(key)*sizeof(char));
    strcpy(stable->info[i].palavra,key);
    stable->info[i].freq = 1;
    stable->ultPos++;
    return stable;
}

stableVO *realocaStableVO(stableVO *stable)
{
    stableVO *stableNova;
    int i;
    stableNova = malloc(sizeof(stableVO));
    stableNova->max = stable->max*2;
    stableNova->ultPos = stable->ultPos;
    stableNova->info = malloc(stableNova->max*sizeof(dataVO));
    /*ao dobrarmos o tamanho garantimos que não iremos fazer essa operação
     *muitas vezes
     */
    for(i = 0; i < stable->ultPos; i++){
        stableNova->info[i].freq = stable->info[i].freq;
        stableNova->info[i].palavra = malloc(strlen(stable->info[i].palavra)*sizeof(char));
        strcpy(stableNova->info[i].palavra, stable->info[i].palavra);
    }
    destroiStableVO(stable);
    return(stableNova);
}
