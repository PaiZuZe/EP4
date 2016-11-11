#include<stdlib.h>
#include<string.h>
#include"tabelaSimbolo_AB.h"
#include<stdio.h>


apontadorAB criaStableAB()
{
    apontadorAB inicio = NULL;
    return inicio;
}

void destroiStableLO(apontadorAB inicio)
{
    if(inicio = NULL) return;
    if(inicio->esq != NULL) destroiStableLO(inicio->esq);
    if(inicio->dir != NULL) destroiStableLO(inicio->dir);
    free(inicio);
    return;
}

apontadorAB insereStableAB(char *key, apontadorAB inicio)
{
    /*vamos primeiro verificar se a lista esta vazia.
     */
    if(!inicio){
        srtcpy(inicio->bob.palavra, key);
        inicio->bob.freq = 1;
        inicio->dir = NULL;
        inicio->esq = NULL;
        return inicio;
    }
    /*vamos verificar se achamos a palavra.
     */
    if(!strcmp(key, inicio->bob.palavra)){
        inicio->bob.freq++;
        return inicio;
    }
    /*agora iremos chamar recursivamente a função para a esquerda ou direita
     *dependendo da key.
     */
    if(strcmp(key, inicio->bob.palavra) < 0){
        insereStableAB(key, inicio->esq);
        return inicio;
    }
    insereStableAB(key, inicio->dir);
    return inicio;
}
