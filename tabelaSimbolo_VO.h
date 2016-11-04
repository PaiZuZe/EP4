#ifndef __TABELASIMBOLO_VO_H__
#define __TABELASIMBOLO_VO_H__

typedef struct{
                data *bob;
                int ultPos;
                int max;
                } stableVO;

typedef struct{
                char *palavra;
                int freq;
                } data;

/*Função que ira criar e devolver um ponteiro para uma tabela de simbolos que
*usa um vetor ordenado com  seu tamanho sendo estipulado pelo usuario.
 */
stableVO *criaStableVO(int tamanho);

/*Função que receve uma de simbolos que usa um vetor ordenado e ira destruir ela.
 */
void destroiStableVO(stableVO *stable);

/*Função que recebe uma string, uma tamabela de simbolos e ira inserir essa
 *palavra na tabela, a inserção ira manter a tabela ordenada, se a palavra já
 *estiver na tabela a função só ira acrecentar a frequencia dela, se a tabela se
 *encontar cheia a funçao ira chamar a função realocaStableVO.
 */
void insereStableVO(char *key, stableVO stable);

/*Função que recebe uma tabela de simbolos e ira criar uma outra tabela de
 *simbolos com os mesmos itens porem com o dobro so tamanho da original.
 */
stableVO realocaStableVO(stableVO *stable);

/*Função recebe uma tabela de simbolos ordenada, uma string e retorna o valor
 *da posição se a string estiver na tabela e -1 se não se encontar; buscaBin
 *modificada para ser usada em string's e não números
 */
int buscaBin(stableVO *stable, char *key);
