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

void tabela(char *arquivoTxt,char *tipoTabela , char *tipoOrd){
    int caracter;
    /*as tabelas são iniciadas como NULL para evitar uma mensagem de warning.
     */
    apontadorAB stableAB, stableABf;
    apontadorLO stableLO = NULL;
    apontadorLD stableLD = NULL;
    stableV *stableVO = NULL;
    stableV *stableVD = NULL;
    FILE *arquivo;
    Buffer *word;
    stableAB = stableABf = NULL;
    arquivo = fopen(arquivoTxt, "r");
    word = criaBuffer();
    if(!strcmp(tipoTabela, "AB") && !strcmp(tipoOrd, "O"))  stableABf = criaStableAB();
    if(!strcmp(tipoTabela, "AB")) stableAB = criaStableAB();
    else if(!strcmp(tipoTabela, "LO")) stableLO = criaStableLO();
    else if(!strcmp(tipoTabela, "LD")) stableLD = criaStableLD();
    else if(!strcmp(tipoTabela, "VO")) stableVO = criaStableVO();
    else if(!strcmp(tipoTabela, "VD")) stableVD = criaStableVD();
    while(!feof(arquivo)){
        caracter = fgetc(arquivo);
        while(!isalpha(caracter) && !feof(arquivo)) caracter = fgetc(arquivo);
        while(isalnum(caracter)){
            caracter = tolower(caracter);
            adicionaNoBuffer(word, caracter);
            caracter = fgetc(arquivo);
        }
        /*este if é usado pois uma string vazia do final do texto era adicionada
         *na tabela.
         */
        if(feof(arquivo)) break;
        /*como por convenção strings terminan com 0, ele deve ser adicionado palavra
         *que as funções sa string.h operem como esperado.
         */
        adicionaNoBuffer(word, 0);
        if(!strcmp(tipoTabela, "AB"))
            stableAB = insereStableAB(word->palavra, stableAB);
        else if(!strcmp(tipoTabela, "LO"))
            stableLO = insereStableLO(word->palavra, stableLO);
        else if(!strcmp(tipoTabela, "LD"))
            stableLD = insereStableLD(word->palavra, stableLD);
        else if(!strcmp(tipoTabela, "VO"))
            stableVO = insereStableVO(word->palavra, stableVO);
        else if(!strcmp(tipoTabela, "VD"))
            stableVD = insereStableVD(word->palavra, stableVD);
        clearBuffer(word);
    }
    /*agora temos todas aspalavras do texto na table, basta imprimila como
     *desejado.
     */
    if(!strcmp(tipoTabela, "AB")){
        if(!strcmp(tipoOrd, "A")) imprimeAB_A(stableAB);
        else{
            stableABf = imprimeAB_O(stableAB, stableABf);
            imprimeAB_A(stableABf);
        }
        destroiStableAB(stableAB);
    }
    else if(!strcmp(tipoTabela, "LO")){
        if(!strcmp(tipoOrd, "A")) imprimeLO_A(stableLO);
        else imprimeLO_O(stableLO);
        destroiStableLO(stableLO);
    }
    else if(!strcmp(tipoTabela, "LD")){
        if(!strcmp(tipoOrd, "A")) imprimeLD_A(stableLD);
        else imprimeLD_O(stableLD);
        destroiStableLD(stableLD);
    }
    else if(!strcmp(tipoTabela, "VO")){
        if(!strcmp(tipoOrd, "A")) imprimeVO_A(stableVO);
        else imprimeVO_O(stableVO);
        destroiStableVO(stableVO);
    }
    else if(!strcmp(tipoTabela, "VD")){
        if(!strcmp(tipoOrd, "A")) imprimeVD_A(stableVD);
        else imprimeVD_O(stableVD);
        destroiStableVD(stableVD);
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
            return 1;
        }
    }
    else if(strcmp(argv[2], "VO") == 0){
        if(strcmp(argv[3], "A") == 0 || strcmp(argv[3], "O") == 0)
            tabela(argv[1], argv[2], argv[3]);
        else{
            printf("Argumento tipo de ordenação não é valido\n");
            return 1;
        }
    }
    else if(strcmp(argv[2], "LD") == 0){
        if(strcmp(argv[3], "A") == 0 || strcmp(argv[3], "O") == 0)
            tabela(argv[1], argv[2], argv[3]);
        else{
            printf("Argumento tipo de ordenação não é valido\n");
            return 1;
        }
    }
    else if(strcmp(argv[2], "LO") == 0){
        if(strcmp(argv[3], "A") == 0 || strcmp(argv[3], "O") == 0)
            tabela(argv[1], argv[2], argv[3]);
        else{
            printf("Argumento tipo de ordenação não é valido\n");
            return 1;
        }
    }
    else if(strcmp(argv[2], "AB") == 0){
        if(strcmp(argv[3], "A") == 0 || strcmp(argv[3], "O") == 0)
            tabela(argv[1], argv[2], argv[3]);
        else{
            printf("Argumento tipo de ordenação não é valido\n");
            return 1;
        }
    }
    else{
        printf("Argumento tipo de tabela não é valido\n");
        return 1;
    }
    return 0;
}
