#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"myHeader.h"
#include"tabelaSimbolo_LO.h"

int nElementosLO(apontadorLO inicio)
{
    int j;
    apontadorLO i;
    for(i = inicio, j = 0; i != NULL; i = i->next, j++);
    return j;
}

data *LOtoVD(apontadorLO inicio){
    int j;
    apontadorLO i;
    data *V = NULL;
    V = malloc(nElementosLO(inicio)*sizeof(data));
    for(i = inicio, j = 0; i != NULL; i = i->next, j++){
        V[j].palavra = malloc(strlen(i->info.palavra)*sizeof(char));
        strcpy(V[j].palavra, i->info.palavra);
        V[j].freq = i->info.freq;
    }
    return V;
}
void mergeSortLO(int inicio, int fim, data *V, char *tipoOrd)
{
    int meio;
    if (inicio < fim - 1) {
        meio = (inicio + fim)/2;
        mergeSortLO(inicio, meio, V, tipoOrd);
        mergeSortLO(meio, fim, V, tipoOrd);
        mergeLO(inicio, meio, fim, V, tipoOrd);
    }
}

void mergeLO(int inicio, int meio, int fim, data *V, char *tipoOrd)
{
    int i, j, k;
    data *w;
    w = malloc ((fim - inicio) * sizeof (data));
    i = inicio; j = meio;
    k = 0;
    while (i < meio && j < fim) {
        if(!strcmp(tipoOrd, "A")){
            if (strcmp(V[i].palavra,V[j].palavra) <= 0){
                w[k].palavra = malloc(strlen(V[i].palavra)*sizeof(char));
                strcpy(w[k].palavra, V[i].palavra);
                w[k].freq = V[i].freq;
                k++;
                i++;
            }
            else{
                w[k].palavra = malloc(strlen(V[j].palavra)*sizeof(char));
                strcpy(w[k].palavra, V[j].palavra);
                w[k].freq = V[j].freq;
                k++;
                j++;
            }
        }
        else{
            if (V[i].freq <=  V[j].freq){
                w[k].palavra = malloc(strlen(V[i].palavra)*sizeof(char));
                strcpy(w[k].palavra, V[i].palavra);
                w[k].freq = V[i].freq;
                k++;
                i++;
            }
            else{
                w[k].palavra = malloc(strlen(V[j].palavra)*sizeof(char));
                strcpy(w[k].palavra, V[j].palavra);
                w[k].freq = V[j].freq;
                k++;
                j++;
            }
        }
    }
    while (i < meio){
        w[k].palavra = malloc(strlen(V[i].palavra)*sizeof(char));
        strcpy(w[k].palavra, V[i].palavra);
        w[k].freq = V[i].freq;
        k++;
        i++;
    }

    while (j < fim){
        w[k].palavra = malloc(strlen(V[j].palavra)*sizeof(char));
        strcpy(w[k].palavra, V[j].palavra);
        w[k].freq = V[j].freq;
        k++;
        j++;
    }
    for (i = inicio; i < fim; ++i){
        V[i].palavra = malloc(strlen(w[i - inicio].palavra)*sizeof(char));
        strcpy(V[i].palavra, w[i - inicio].palavra);
        V[i].freq = w[i - inicio].freq;
    }
    free (w);
}
void imprimeLO_A(apontadorLO stable)
{
    apontadorLO i;
    /*como a tabela já esta ordenada só iremos imprimir seus elemntos na ordem
     *que eles se encontram.
     */
    for(i = stable; i != NULL; i = i->next){
        printf("%s ", i->info.palavra);
        printf("%d\n", i->info.freq);
    }
    return;
}
void imprimeLO_O(apontadorLO stable)
{
    int i;
    data *V;
    /*como ordenar uma lista ligada é muito dificil iremos criar um vetor com
     *os elementos da tabela e ordenalo em NlogN.
     */
    V = LOtoVD(stable);
    mergeSortLO(0, nElementosLO(stable), V, "O");
    for(i = 0; i < nElementosLO(stable); i++){
        printf("%s ", V[i].palavra);
        printf("%d\n", V[i].freq);
    }
    return;
}
apontadorLO criaStableLO()
{
    apontadorLO inicio = NULL;
    return(inicio);
}

void destroiStableLO(apontadorLO inicio)
{
    apontadorLO prox;
    while(inicio != NULL){
        prox = inicio->next;
        free(inicio->info.palavra);
        free(inicio);
        inicio = prox;
    }
    return;
}

apontadorLO insereStableLO(char *key ,apontadorLO inicio)
{
    apontadorLO temp, anterior;
    apontadorLO novoItem = malloc(sizeof(celulaLO));
    temp = inicio;
    anterior = NULL;
    /*primeiro devemos verificar se a lista esta vazia.
     */
    if(!inicio){
        inicio = malloc(sizeof(celulaLO));
        inicio->info.palavra = malloc(strlen(key)*sizeof(char));
        strcpy(inicio->info.palavra, key);
        inicio->info.freq = 1;
        inicio->next = NULL;
        return inicio;
    }
    /*agora iremos procurar o iten desejado na lista e mudar sua frequencia se
     *ele estiver presente na lista.
     */
    while(temp != NULL && strcmp(key, temp->info.palavra) >= 0){
        if(!strcmp(key, temp->info.palavra)){
            temp->info.freq++;
            return(inicio);
        }
        anterior = temp;
        temp = temp->next;
    }
    novoItem->info.palavra = malloc(strlen(key)*sizeof(char));
    strcpy(novoItem->info.palavra, key);
    novoItem->info.freq = 1;
    novoItem->next = temp;
    /*Agora vamos verificar se temos que mudar o inicio da lista.
     */
    if(anterior == NULL){
        inicio = novoItem;
        return(inicio);
    }
    anterior->next = novoItem;
    return(inicio);
}
