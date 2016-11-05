#ifndef __TABELASIMBOLO_LO_H
#define __TABELASIMBOLO_LO_H

typedef struct no {
                    data bob;
                    struct no *next;
                    }celula;

typedef celula *apontador;

typedef struct{
                char *palavra;
                int freq;
                } data;

/*função cria uma variavel com o começo da lista.
 */
apontador criaStableLO();
/*função recebe o inicio da tabela de simbolos e ira desalocar a memória de
 *todos seus elementos.
 */
void destroiStableLO(apontador inicio);
/*função recebe o inicio da tabela de simbolos e uma string e ira inserir essa
 *string no local que ira deixar a tabela ordenada se ela não se encontar na
 tabela, se o ultímo for verdade a função ira aumentar a frequencia da palavra,
 a função devolve o inicio da tabela pois ele pode mudar;
 */
apontador insereStableLO(char *key ,apontador inicio);

#endif
