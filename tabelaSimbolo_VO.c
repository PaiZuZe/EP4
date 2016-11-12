#include<stdlib.h>
#include<string.h>
#include"tabelaSimbolo_VO.h"

stableVO *criaStableVO()
{
    stableVO *stable = malloc(sizeof(stableVO));
    stable->max = 16;
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
    /*vamos ver antes se a tabela esta vazia ja que srcmp buga*/
    if(stable->ultPos == 0){
        stable->info[0].palavra = malloc(strlen(key)*sizeof(char));
        strcpy(stable->info[0].palavra,key);
        stable->info[0].freq = 1;
        stable->ultPos++;
        return stable;
    }
    /*antes de posivelmente inserir um novo elemento, iremos verificar se a
     *tebala esta cheia.
     */
    if(stable->ultPos == stable->max){
        stable = realocaStableVO(stable);
    }
    /*com uma busca binaria podemos descobrir se o elemento se encontra na
     *tabela e também se a palavra não se encontar podemos descobrir sua posição
     */
    /*esquece a busca binaria*/
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

int buscaBin(stableVO *stable, char *key)
{
    int inicio, meio, fim, temp;
    inicio = 0;
    fim = stable->ultPos -1;
    while(inicio <= fim){
        meio = (inicio + fim)/2;
        temp = strcmp(key, stable->info[meio].palavra);
        if(temp == 0) return(meio);
        else if(temp < 0) inicio = meio + 1;
        else fim = meio;
    }
    return inicio;
}
