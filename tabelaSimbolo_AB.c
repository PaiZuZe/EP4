#include<stdlib.h>
#include<string.h>
#include"tabelaSimbolo_AB.h"

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
    if(strcmp(key, inicio->info.palavra) < 0){
        inicio->esq = insereStableAB(key, inicio->esq);
        return inicio;
    }
    else if(strcmp(key, inicio->info.palavra) > 0){
        inicio->dir = insereStableAB(key, inicio->dir);
    }
    return inicio;
}
