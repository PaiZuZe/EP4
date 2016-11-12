#include<stdlib.h>
#include<string.h>
#include"tabelaSimbolo_VD.h"

void mergeSortVD(int inicio, int fim, stableVD *stable, char *tipoOrd)
{
    int meio;
    if (inicio < fim - 1) {
        meio = (inicio + fim)/2;
        mergeSortVD(inicio, meio, stable, tipoOrd);
        mergeSortVD(meio, fim, stable, tipoOrd);
        mergeVD(inicio, meio, fim, stable, tipoOrd);
    }
}

void mergeVD(int inicio, int meio, int fim, stableVD *stable, char *tipoOrd)
{
    int i, j, k;
    dataVD *w;
    w = malloc ((fim - inicio) * sizeof (dataVD));
    i = inicio; j = meio;
    k = 0;
    while (i < meio && j < fim) {
        if(!strcmp(tipoOrd, "A")){
            if (strcmp(stable->info[i].palavra,stable->info[j].palavra) <= 0){
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
        else{
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

stableVD *criaStableVD()
{
    stableVD *stable = malloc(sizeof(stableVD));
    stable->max = 8;
    stable->ultPos = 0;
    stable->info = malloc(stable->max*sizeof(dataVD));
    return(stable);
}

void destroiStableVD(stableVD *stable)
{
    int i;
    for(i = 0; i < stable->ultPos; i++)
        free(stable->info[i].palavra);
    free(stable->info);
    free(stable);
    return;
}

stableVD *insereStableVD(char *key, stableVD *stable)
{
    int i;
    for(i = 0; i < stable->ultPos; i++){
        if(!strcmp(key,stable->info[i].palavra)){
            stable->info[i].freq++;
            return stable;
        }
    }
    /*antes de inserirmos a palavra pode ser que a tabela esteja cheia*/
    if(stable->ultPos == stable->max){
        stable = realocaStableVD(stable);
    }
    /*como a tabela tem espaço para a palavra nova e ela não estava na lista
     *simplesmente podemos mudar a frequencia para um adicionar a palavra
     */
    stable->info[i].palavra = malloc(strlen(key)*sizeof(char));
    strcpy(stable->info[i].palavra,key);
    stable->info[i].freq = 1;
    stable->ultPos++;
    return stable;
}

stableVD *realocaStableVD(stableVD *stable)
{
    stableVD *stableNova;
    int i;
    stableNova = malloc(sizeof(stableVD));
    stableNova->max = stable->max*2;
    stableNova->ultPos = stable->ultPos;
    stableNova->info = malloc(stableNova->max*sizeof(dataVD));
    /*ao dobrarmos o tamanho garantimos que não iremos fazer essa operação
     *muitas vezes
     */
    for(i = 0; i < stable->ultPos; i++){
        stableNova->info[i].freq = stable->info[i].freq;
        stableNova->info[i].palavra = malloc(strlen(stable->info[i].palavra)*sizeof(char));
        strcpy(stableNova->info[i].palavra, stable->info[i].palavra);
    }
    destroiStableVD(stable);
    return(stableNova);
}
