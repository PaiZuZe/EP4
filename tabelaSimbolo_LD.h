#ifndef __TABELASIMBOLO_LD_H
#define __TABELASIMBOLO_LD_H

typedef struct{
                char *palavra;
                int freq;
                } dataLD;
typedef struct noLD {
                    dataLD bob;
                    struct noLD *next;
                    }celulaLD;

typedef celulaLD *apontadorLD;

/*função cria uma variavel com o começo da lista.
 */
apontadorLD criaStableLD();

/*função recebe o inicio da tabela de simbolos e ira desalocar a memória de
 *todos seus elementos.
 */
void destroiStableLD(apontadorLD inicio);
/*função recebe o inicio da tabela de simbolos e uma string e ira inserir essa
 *string no fim da tabela se ela não se encontar na tabela, se o ultímo for
 *verdade a função ira aumentar a frequencia da palavra.
 */
void insereStableLD(char *key ,apontadorLD inicio);

#endif
