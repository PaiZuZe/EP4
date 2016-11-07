#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"tabelaSimbolo_VD.h"
#include"tabelaSimbolo_VO.h"
#include"tabelaSimbolo_LD.h"
#include"tabelaSimbolo_LO.h"
void tabelaVD(char *arquivoTxt, char *tipoOrd){

    return;
}
void tabelaVO(char *arquivoTxt, char *tipoOrd){

    return;
}
void tabelaLD(char *arquivoTxt, char *tipoOrd){

    return;
}
void tabelaLO(char *arquivoTxt, char *tipoOrd){

    return;
}

int main()
{
    char *arquivoTxt, *tipoTabela, *tipoOrd;
    arquivoTxt = malloc(sizeof(char));
    tipoTabela = malloc(sizeof(char));
    tipoOrd = malloc(sizeof(char));
    if(scanf("%s%s%s", arquivoTxt, tipoTabela, tipoOrd) != 3){
        printf("VOCE TENTOU ME PASSAR MERDA\n");
        return 0;
    }
    if(strcmp(tipoTabela, "VD") == 0){
        if(strcmp(tipoOrd, "A") == 0 || strcmp(tipoOrd, "O") == 0){
            tabelaVD(arquivoTxt, tipoOrd);
        }
        else{
            printf("Argumento tipo de ordenação não é valido\n");
            return 0;
        }
    }
    else if(strcmp(tipoTabela, "VO") == 0){
        if(strcmp(tipoOrd, "A") == 0 || strcmp(tipoOrd, "O") == 0){
            tabelaVO(arquivoTxt, tipoOrd);
        }
        else{
            printf("Argumento tipo de ordenação não é valido\n");
            return 0;
        }
    }
    else if(strcmp(tipoTabela, "LD") == 0){
        if(strcmp(tipoOrd, "A") == 0 || strcmp(tipoOrd, "O") == 0){
            tabelaLD(arquivoTxt, tipoOrd);
        }
        else{
            printf("Argumento tipo de ordenação não é valido\n");
            return 0;
        }
    }
    else if(strcmp(tipoTabela, "LO") == 0){
        if(strcmp(tipoOrd, "A") == 0 || strcmp(tipoOrd, "O") == 0){
            tabelaLO(arquivoTxt, tipoOrd);
        }
        else{
            printf("Argumento tipo de ordenação não é valido\n");
            return 0;
        }
    }
    else if(strcmp(tipoTabela, "AB") == 0){
        if(strcmp(tipoOrd, "A") == 0 || strcmp(tipoOrd, "O") == 0){
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
