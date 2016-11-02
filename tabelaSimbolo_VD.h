#ifndef __TABELASIMBOLO_vd_H
#define __TABELASIMBOLO_vd_H

typedef struct  {
                data *bob;
                int ultPos;
                int max;
                } stableVD;

typedef struct  {
                char *palavra;
                int freq;
                } data;

/*Função que ira criar e devolver um ponteiro para uma tabela de simbolos que
 *usa um vetor desordenado com  seu tamanho sendo estipulado pelo usuario.
 */
stableVD *criaStableVD(int tamanho);
/*Função que receve uma de simbolos que usa um vetor desordenado e ira destruir
 *ela.
 */
void destroiStableVD(stableVD *stable);
/*Função que recebe uma string e uma tamabela de simbolos e ira inserir essa
 *palavra na tabela, se a palavra já estiver na tabela a função só ira
 *acrecentar a frequencia dela, se a tabela se encontar cheia a funçao ira chamar
 *a função realocaStableVD.
 */
void insereStableVD(char *key, stableVD stable);
/*Função que recebe uma tabela de simbolos e ira criar uma outra tabela de
 *simbolos com os mesmos itens porem com o dobro so tamanho da original.
 */
stableVD realocaStableVD(stableVD *stable);

#endif
