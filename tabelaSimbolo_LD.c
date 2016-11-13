#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"myHeader.h"
#include"tabelaSimbolo_LD.h"
int nElementosLD(apontadorLD inicio)
{
    int j;
    apontadorLD i;
    for(i = inicio, j = 0; i != NULL; i = i->next, j++);
    return j;
}

data *LDtoVD(apontadorLD inicio){
    int j;
    apontadorLD i;
    data *V = NULL;
    V = malloc(nElementosLD(inicio)*sizeof(data));
    for(i = inicio, j = 0; i != NULL; i = i->next, j++){
        V[j].palavra = malloc(strlen(i->info.palavra)*sizeof(char));
        strcpy(V[j].palavra, i->info.palavra);
        V[j].freq = i->info.freq;
    }
    return V;
}
void imprimeLD_A(apontadorLD stable)
{
    int i;
    data *V;
    /*como ordenar uma lista ligada é muito dificil iremos criar um vetor com
     *os elementos da tabela e ordenalo em NlogN.
     */
    V = LDtoVD(stable);
    mergeSortM(0, nElementosLD(stable), V, "A");
    for(i = 0; i < nElementosLD(stable); i++){
        printf("%s ", V[i].palavra);
        printf("%d\n", V[i].freq);
    }
    return;
}
void imprimeLD_O(apontadorLD stable)
{
    int i;
    data *V;
    /*como ordenar uma lista ligada é muito dificil iremos criar um vetor com
     *os elementos da tabela e ordenalo em NlogN.
     */
    V = LDtoVD(stable);
    mergeSortM(0, nElementosLD(stable), V, "O");
    for(i = 0; i < nElementosLD(stable); i++){
        printf("%s ", V[i].palavra);
        printf("%d\n", V[i].freq);
    }
    return;
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
            /*strcmp retorna 0 se duas strings forem iguais, assim basta
             *aumentar a frequencia e sair da função.
             */
            temp->info.freq++;
            return inicio;
        }
    }
    /*se a função chegou até este ponto, percorremos a tabela inteira sem
     *encontar a palavra, assim a iremos inserir a nova palavra no final.
     */
    novoItem = malloc(sizeof(celulaLD));
    novoItem->info.palavra = malloc(strlen(key)*sizeof(char));
    strcpy(novoItem->info.palavra, key);
    novoItem->info.freq = 1;
    novoItem->next = NULL;
    anterior->next = novoItem;
    return inicio;
}
