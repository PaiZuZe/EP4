#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"myHeader.h"
#include"tabelaSimbolo_VD.h"
#include"tabelaSimbolo_VO.h"
#include"tabelaSimbolo_LD.h"
#include"tabelaSimbolo_LO.h"
void imprimeVD_A(stableVD *stable)
{
    int i;
    for(i = 0; i < stable->ultPos; i++){
        printf("%s ", stable->bob[i].palavra);
        printf("%d\n", stable->bob[i].freq);
    }
    return;
}
void imprimeVO_A(stableVO *stable)
{
    int i;
    for(i = 0; i < stable->ultPos; i++){
        printf("%s ", stable->bob[i].palavra);
        printf("%d\n", stable->bob[i].freq);
    }
    return;
}
void imprimeLD_A(apontadorLD stable)
{
    apontadorLD i;
    for(i = stable; i != NULL; i = i->next){
        printf("%s ", i->bob.palavra);
        printf("%d\n", i->bob.freq);
    }
    return;
}


void tabelaVD(char *arquivoTxt, char *tipoOrd){
    int caracter;
    stableVD *stable;
    FILE *arquivo;
    Buffer *word;
    arquivo = fopen(arquivoTxt, "r");
    word = criaBuffer();
    stable = criaStableVD();
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
        stable = insereStableVD(word->palavra, stable);
        clearBuffer(word);
    }
    /*agora temos todas aspalavras do texto na table, basta imprimila como
     *desejado.
     */
    if(!strcmp(tipoOrd, "A")){
        imprimeVD_A(stable);
    }
    return;
}
void tabelaVO(char *arquivoTxt, char *tipoOrd){
    int caracter;
    stableVO *stable;
    FILE *arquivo;
    Buffer *word;
    arquivo = fopen(arquivoTxt, "r");
    word = criaBuffer();
    stable = criaStableVO();
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
        stable = insereStableVO(word->palavra, stable);
        clearBuffer(word);
    }
    /*agora temos todas aspalavras do texto na table, basta imprimila como
     *desejado.
     */
    if(!strcmp(tipoOrd, "A")){
        imprimeVO_A(stable);
    }
    return;
}
void tabelaLD(char *arquivoTxt, char *tipoOrd){
    int caracter;
    apontadorLD stable;
    FILE *arquivo;
    Buffer *word;
    arquivo = fopen(arquivoTxt, "r");
    word = criaBuffer();
    stable = criaStableLD();
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
        stable = insereStableLD(word->palavra, stable);
        clearBuffer(word);
    }
    /*agora temos todas aspalavras do texto na table, basta imprimila como
     *desejado.
     */
    if(!strcmp(tipoOrd, "A")){
        imprimeLD_A(stable);
    }
    return;
}
void tabelaLO(char *arquivoTxt, char *tipoOrd){

    return;
}

int main(int argc, char *argv[])
{
    if(strcmp(argv[2], "VD") == 0){
        if(strcmp(argv[3], "A") == 0 || strcmp(argv[3], "O") == 0){
            tabelaVD(argv[1], argv[3]);
        }
        else{
            printf("Argumento tipo de ordenação não é valido\n");
            return 0;
        }
    }
    else if(strcmp(argv[2], "VO") == 0){
        if(strcmp(argv[3], "A") == 0 || strcmp(argv[3], "O") == 0){
            tabelaVO(argv[1], argv[3]);
        }
        else{
            printf("Argumento tipo de ordenação não é valido\n");
            return 0;
        }
    }
    else if(strcmp(argv[2], "LD") == 0){
        if(strcmp(argv[3], "A") == 0 || strcmp(argv[3], "O") == 0){
            tabelaLD(argv[1], argv[3]);
        }
        else{
            printf("Argumento tipo de ordenação não é valido\n");
            return 0;
        }
    }
    else if(strcmp(argv[2], "LO") == 0){
        if(strcmp(argv[3], "A") == 0 || strcmp(argv[3], "O") == 0){
            tabelaLO(argv[1], argv[3]);
        }
        else{
            printf("Argumento tipo de ordenação não é valido\n");
            return 0;
        }
    }
    else if(strcmp(argv[2], "AB") == 0){
        if(strcmp(argv[3], "A") == 0 || strcmp(argv[3], "O") == 0){
            printf("yay\n");
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
