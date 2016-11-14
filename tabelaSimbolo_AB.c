/*Nome: Victor Chiaradia Gramuglia Araujo
 *nºUSP:9793756
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"myHeader.h"
#include"tabelaSimbolo_AB.h"

void imprimeAB_A(apontadorAB stable)
{
    if (stable == NULL) return;
    imprimeAB_A(stable->esq);
    printf("%s ", stable->info.palavra);
    printf("%d\n", stable->info.freq);
    imprimeAB_A(stable->dir);
    return;
}
apontadorAB imprimeAB_O(apontadorAB stable, apontadorAB stableNova)
{
    if (stable == NULL) return stableNova;
    imprimeAB_O(stable->esq, stableNova);
    stableNova = insereStableABfreq(&(stable->info), stableNova);
    imprimeAB_O(stable->dir, stableNova);
    return stableNova;
}

apontadorAB criaStableAB()
{
    apontadorAB inicio = NULL;
    return inicio;
}

void destroiStableAB(apontadorAB inicio)
{
    if(inicio == NULL) return;
    if(inicio->esq != NULL) destroiStableAB(inicio->esq);
    if(inicio->dir != NULL) destroiStableAB(inicio->dir);
    free(inicio->info.palavra);
    free(inicio);
    return;
}

apontadorAB insereStableAB(char *key, apontadorAB inicio)
{
    /*vamos primeiro verificar se a lista esta vazia.
     */
    if(!inicio){
        inicio = malloc(sizeof(celulaAB));
        inicio->info.palavra = malloc(strlen(key)*sizeof(char));
        strcpy(inicio->info.palavra, key);
        inicio->info.freq = 1;
        inicio->dir = NULL;
        inicio->esq = NULL;
        return inicio;
    }
    /*vamos verificar se achamos a palavra.
     */
    if(!strcmp(key, inicio->info.palavra)){
        inicio->info.freq++;
        return inicio;
    }
    /*agora iremos chamar recursivamente a função para a esquerda ou direita
     *dependendo da key.
     */
    if(strcmp(key, inicio->info.palavra) < 0)
        inicio->esq = insereStableAB(key, inicio->esq);
    else if(strcmp(key, inicio->info.palavra) > 0)
        inicio->dir = insereStableAB(key, inicio->dir);
    return inicio;
}
apontadorAB insereStableABfreq(data *novo, apontadorAB inicio)
{
    /*vamos primeiro verificar se a lista esta vazia.
     */
    if(!inicio){
        inicio = malloc(sizeof(celulaAB));
        inicio->info.palavra = malloc(strlen(novo->palavra)*sizeof(char));
        strcpy(inicio->info.palavra, novo->palavra);
        inicio->info.freq = novo->freq;
        inicio->dir = NULL;
        inicio->esq = NULL;
        return inicio;
    }
    /*agora iremos chamar recursivamente a função para a esquerda ou direita
     *dependendo de onde o novo item deveria ser inserido.
     */
    if(novo->freq < inicio->info.freq)
        inicio->esq = insereStableABfreq(novo, inicio->esq);
    else if(novo->freq >= inicio->info.freq)
        inicio->dir = insereStableABfreq(novo, inicio->dir);
    return inicio;
}
