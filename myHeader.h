#ifndef __MYHEADER_H__
#define __MYHEADER_H__
typedef struct {
                char *palavra;
                int max;
                int top;
                }Buffer;
typedef struct{
                char *palavra;
                int freq;
                } data;
typedef struct{
                data *info;
                int ultPos;
                int max;
                } stableV;
typedef struct noLG {
                    data info;
                    struct noLG *next;
                    }celulaLG;
typedef celulaLG *apontadorLG;

/*esta é uma função de mergeSort que ira ordenar um vetor de uma struct(data), a
 *ordenção ira depender da variavel tipoOrd(pode ser por frequencia ou
 *alfabeticamente).
 */
void mergeSortM(int inicio, int fim, data *V, char *tipoOrd);
/*função de merge modificada.
 */
void mergeM(int inicio, int meio, int fim, data *V, char *tipoOrd);
/*esta função cria um buffer(vetor dinamico) de char e devolve um ponteiro para
 *o buffer criado.
*/
Buffer *criaBuffer();
/*esta função recebe um ponteiro para o buffer que sera realocado, ela ira
 *dobrar o tamanho do buffer original, mantendo seu conteudo igual.
 */
void realocaBuffer(Buffer *B);
/*a função recebe um buffer e um char que ira ser adicionado no buffer, a função
 *aumenta o tamanho do buffer se nescessario.
*/
void adicionaNoBuffer(Buffer *B, char c);
/*esta função recebe um buffer e ira desalocar a memoria usada por ele.
 */
void destroiBuffer(Buffer *B);
/*função recebe um buffer e faz com que ele volte para seu estado original.
 */
void clearBuffer(Buffer *B);
#endif
