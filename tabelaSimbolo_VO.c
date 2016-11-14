/*Nome: Victor Chiaradia Gramuglia Araujo
 *nºUSP:9793756
 */
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"myHeader.h"
#include"tabelaSimbolo_VO.h"

void imprimeVO_A(stableV *stable)
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
void imprimeVO_O(stableV *stable)
{
    int i;
    mergeSortM(0, stable->ultPos, stable->info, "O");
    for(i = 0; i < stable->ultPos; i++){
        printf("%s ", stable->info[i].palavra);
        printf("%d\n", stable->info[i].freq);
    }
    return;
}
stableV *criaStableVO()
{
    stableV *stable = malloc(sizeof(stableV));
    stable->max = 8;
    stable->ultPos = 0;
    stable->info = malloc(stable->max*sizeof(data));
    return(stable);
}

void destroiStableVO(stableV *stable)
{
    int i;
    for(i = 0; i < stable->ultPos; i++)
        free(stable->info[i].palavra);
    free(stable->info);
    free(stable);
    return;
}

stableV *insereStableVO(char *key, stableV *stable)
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
                free(stable->info[k].palavra);
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

stableV *realocaStableVO(stableV *stable)
{
    stableV *stableNova;
    int i;
    stableNova = malloc(sizeof(stableV));
    stableNova->max = stable->max*2;
    stableNova->ultPos = stable->ultPos;
    stableNova->info = malloc(stableNova->max*sizeof(data));
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
