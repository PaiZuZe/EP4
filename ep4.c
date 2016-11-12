#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"myHeader.h"
#include"tabelaSimbolo_VD.h"
#include"tabelaSimbolo_VO.h"
#include"tabelaSimbolo_LD.h"
#include"tabelaSimbolo_LO.h"
#include"tabelaSimbolo_AB.h"
void imprimeVD_A(stableVD *stable)
{
    int i;
    mergeSortVD(0, stable->ultPos, stable, "A");
    for(i = 0; i < stable->ultPos; i++){
        printf("%s ", stable->info[i].palavra);
        printf("%d\n", stable->info[i].freq);
    }
    return;
}
void imprimeVD_O(stableVD *stable)
{
    int i;
    mergeSortVD(0, stable->ultPos, stable, "O");
    for(i = 0; i < stable->ultPos; i++){
        printf("%s ", stable->info[i].palavra);
        printf("%d\n", stable->info[i].freq);
    }
    return;
}

void imprimeVO_A(stableVO *stable)
{
    int i;
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
void imprimeLD_A(apontadorLD stable)
{
    int i;
    dataLD *V;
    V = LDtoVD(stable);
    mergeSortLD(0, nElementosLD(stable), V, "A");
    for(i = 0; i < nElementosLD(stable); i++){
        printf("%s ", V[i].palavra);
        printf("%d\n", V[i].freq);
    }
    return;
}
void imprimeLD_O(apontadorLD stable)
{
    int i;
    dataLD *V;
    V = LDtoVD(stable);
    mergeSortLD(0, nElementosLD(stable), V, "O");
    for(i = 0; i < nElementosLD(stable); i++){
        printf("%s ", V[i].palavra);
        printf("%d\n", V[i].freq);
    }
    return;
}
void imprimeLO_A(apontadorLO stable)
{
    apontadorLO i;
    for(i = stable; i != NULL; i = i->next){
        printf("%s ", i->info.palavra);
        printf("%d\n", i->info.freq);
    }
    return;
}
void imprimeLO_O(apontadorLO stable)
{
    int i;
    dataLO *V;
    V = LOtoVD(stable);
    mergeSortLO(0, nElementosLO(stable), V, "O");
    for(i = 0; i < nElementosLO(stable); i++){
        printf("%s ", V[i].palavra);
        printf("%d\n", V[i].freq);
    }
    return;
}
void imprimeAB_A(apontadorAB stable)
{
    if (stable == NULL) return;
    imprimeAB_A(stable->esq);
    printf("%s ", stable->info.palavra);
    printf("%d\n", stable->info.freq);
    imprimeAB_A(stable->dir);
    return;
}
void tabela(char *arquivoTxt,char *tipoTabela , char *tipoOrd){
    int caracter;
    apontadorAB stableAB = NULL;
    apontadorLO stableLO = NULL;
    apontadorLD stableLD = NULL;
    stableVO *stableVO = NULL;
    stableVD *stableVD = NULL;
    FILE *arquivo;
    Buffer *word;
    arquivo = fopen(arquivoTxt, "r");
    word = criaBuffer();
    if(!strcmp(tipoTabela, "AB")){
        stableAB = criaStableAB();
    }
    else if(!strcmp(tipoTabela, "LO")){
        stableLO = criaStableLO();
    }
    else if(!strcmp(tipoTabela, "LD")){
        stableLD = criaStableLD();
    }
    else if(!strcmp(tipoTabela, "VO")){
        stableVO = criaStableVO();
    }
    else if(!strcmp(tipoTabela, "VD")){
        stableVD = criaStableVD();
    }
    while(!feof(arquivo)){
        caracter = fgetc(arquivo);
        while(!isalpha(caracter) && !feof(arquivo))
            caracter = fgetc(arquivo);
        while(isalnum(caracter)){
            caracter = tolower(caracter);
            adicionaNoBuffer(word, caracter);
            caracter = fgetc(arquivo);
        }
        adicionaNoBuffer(word, 0);
        if(!strcmp(tipoTabela, "AB")){
            stableAB = insereStableAB(word->palavra, stableAB);
        }
        else if(!strcmp(tipoTabela, "LO")){
            stableLO = insereStableLO(word->palavra, stableLO);
        }
        else if(!strcmp(tipoTabela, "LD")){
            stableLD = insereStableLD(word->palavra, stableLD);
        }
        else if(!strcmp(tipoTabela, "VO")){
            stableVO = insereStableVO(word->palavra, stableVO);
        }
        else if(!strcmp(tipoTabela, "VD")){
            stableVD = insereStableVD(word->palavra, stableVD);
        }
        clearBuffer(word);
    }
    /*agora temos todas aspalavras do texto na table, basta imprimila como
     *desejado.
     */
    if(!strcmp(tipoTabela, "AB")){
        if(!strcmp(tipoOrd, "A")){
            imprimeAB_A(stableAB);
        }
    }
    else if(!strcmp(tipoTabela, "LO")){
        if(!strcmp(tipoOrd, "A")) imprimeLO_A(stableLO);
        else imprimeLO_O(stableLO);
    }
    else if(!strcmp(tipoTabela, "LD")){
        if(!strcmp(tipoOrd, "A")) imprimeLD_A(stableLD);
        else imprimeLD_O(stableLD);
    }
    else if(!strcmp(tipoTabela, "VO")){
        if(!strcmp(tipoOrd, "A")) imprimeVO_A(stableVO);
        else imprimeVO_O(stableVO);
    }
    else if(!strcmp(tipoTabela, "VD")){
        if(!strcmp(tipoOrd, "A")) imprimeVD_A(stableVD);
        else imprimeVD_O(stableVD);
    }
    return;
}


int main(int argc, char *argv[])
{
    /*primeiro devemos ver se temos todos os argumentos nescessarios.
     */
    if(argv[3] == NULL){
        printf("ERRO, falta de argumento\n");
        return 1;
    }
    /*agora iremos comparar os argumentos dados com os esperados, a função strcmp
     *retorna 0 se duas strings forem iguais.
     */
    if(strcmp(argv[2], "VD") == 0){
        if(strcmp(argv[3], "A") == 0 || strcmp(argv[3], "O") == 0){
            tabela(argv[1], argv[2], argv[3]);
        }
        else{
            printf("Argumento tipo de ordenação não é valido\n");
            return 0;
        }
    }
    else if(strcmp(argv[2], "VO") == 0){
        if(strcmp(argv[3], "A") == 0 || strcmp(argv[3], "O") == 0){
            tabela(argv[1], argv[2], argv[3]);
        }
        else{
            printf("Argumento tipo de ordenação não é valido\n");
            return 0;
        }
    }
    else if(strcmp(argv[2], "LD") == 0){
        if(strcmp(argv[3], "A") == 0 || strcmp(argv[3], "O") == 0){
            tabela(argv[1], argv[2], argv[3]);
        }
        else{
            printf("Argumento tipo de ordenação não é valido\n");
            return 0;
        }
    }
    else if(strcmp(argv[2], "LO") == 0){
        if(strcmp(argv[3], "A") == 0 || strcmp(argv[3], "O") == 0){
            tabela(argv[1], argv[2], argv[3]);
        }
        else{
            printf("Argumento tipo de ordenação não é valido\n");
            return 0;
        }
    }
    else if(strcmp(argv[2], "AB") == 0){
        if(strcmp(argv[3], "A") == 0 || strcmp(argv[3], "O") == 0){
            tabela(argv[1], argv[2], argv[3]);
        }
        else{
            printf("Argumento tipo de ordenação não é valido\n");
            return 0;
        }
    }
    else{
        printf("Argumento tipo de tabela não é valido\n");
        return 0;
    }
    return 0;
}
