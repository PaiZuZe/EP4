#ifndef __TABELASIMBOLO_LD_H
#define __TABELASIMBOLO_LD_H

typedef struct{
    char *palavra;
    int freq;
} data;
typedef struct no {
                    data bob;
                    struct no *next;
                    }celula;

typedef celula *apontador;

/*função cria uma variavel com o começo da lista.
 */
apontador criaStableLD();

/*função recebe o inicio da tabela de simbolos e ira desalocar a memória de
 *todos seus elementos.
 */
void destroiStableLD(apontador inicio);
/*função recebe o inicio da tabela de simbolos e uma string e ira inserir essa
 *string no fim da tabela se ela não se encontar na tabela, se o ultímo for
 *verdade a função ira aumentar a frequencia da palavra.
 */
void insereStableLD(char *key ,apontador inicio);

#endif
