#include<stdlib.h>
#include<string.h>
#include"tabelaSimbolo_LD.h"
int nElementosLD(apontadorLD inicio)
{
    int j;
    apontadorLD i;
    for(i = inicio, j = 0; i != NULL; i = i->next, j++);
    return j;
}

dataLD *LDtoVD(apontadorLD inicio){
    int j;
    apontadorLD i;
    dataLD *V = NULL;
    V = malloc(nElementosLD(inicio)*sizeof(dataLD));
    for(i = inicio, j = 0; i != NULL; i = i->next, j++){
        V[j].palavra = malloc(strlen(i->info.palavra)*sizeof(char));
        strcpy(V[j].palavra, i->info.palavra);
        V[j].freq = i->info.freq;
    }
    return V;
}
void mergeSortLD(int inicio, int fim, dataLD *V, char *tipoOrd)
{
    int meio;
    if (inicio < fim - 1) {
        meio = (inicio + fim)/2;
        mergeSortLD(inicio, meio, V, tipoOrd);
        mergeSortLD(meio, fim, V, tipoOrd);
        mergeLD(inicio, meio, fim, V, tipoOrd);
    }
}

void mergeLD(int inicio, int meio, int fim, dataLD *V, char *tipoOrd)
{
    int i, j, k;
    dataLD *w;
    w = malloc ((fim - inicio) * sizeof (dataLD));
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


apontadorLD criaStableLD()
{
    apontadorLD inicio = NULL;
    return(inicio);
}
void destroiStableLD(apontadorLD inicio)
{
    apontadorLD prox;
    while(inicio != NULL){
        prox = inicio->next;
        free(inicio->info.palavra);
        free(inicio);
        inicio = prox;
    }
    return;
}
apontadorLD insereStableLD(char *key ,apontadorLD inicio)
{
    apontadorLD temp, anterior;
    apontadorLD novoItem;
    /*primeiro devemos verificar se a lista esta vazia.*/
    if(!inicio){
        inicio = malloc(sizeof(celulaLD));
        inicio->info.palavra = malloc(strlen(key)*sizeof(char));
        strcpy(inicio->info.palavra, key);
        inicio->info.freq = 1;
        inicio->next = NULL;
        return inicio;
    }
    /*como a lista não esta vazia, devemos procurar a palavra na tabela.*/
    anterior = NULL;
    for(temp = inicio; temp != NULL; anterior = temp, temp = temp->next){
        if(!strcmp(key, temp->info.palavra)){
            temp->info.freq++;
            return inicio;
        }
    }
    /*se a função chegou até este ponto, percorremos a tabela inteira sem
     *encontar a palavra, assim a iremos inserir no final.
     */
    novoItem = malloc(sizeof(celulaLD));
    novoItem->info.palavra = malloc(strlen(key)*sizeof(char));
    strcpy(novoItem->info.palavra, key);
    novoItem->info.freq = 1;
    novoItem->next = NULL;
    anterior->next = novoItem;
    return inicio;
}
/**/
