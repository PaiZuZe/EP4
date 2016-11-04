#ifndef __TABELASIMBOLO_LD_H
#define __TABELASIMBOLO_LD_H

typedef struct no {
                    data *bob;
                    struct no *next;
                    }celula;

typedef celula *apontador;

typedef struct{
                char *palavra;
                int freq;
                } data;
/*função aloca espaço para uma celula que sera o começo da lista e devolve seu
 *emdereço.
 */
apontador criaStableLD();

/*função recebe o inicio da tabela de simbolos e ira desalocar a memória de
 *todos seus elementos.
 */
void destroiStableLD(apontador inicio);
/*função recebe o inicio da tabela de simbolos e uma string e ira inserir essa
 *string no inicio da tabela, assim devolvendo o novo inicio da lista
 */
apontador insereStableLD(char *key ,apontador inicio);
