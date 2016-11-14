/*Nome: Victor Chiaradia Gramuglia Araujo
 *nºUSP:9793756
 */
#ifndef __MYHEADER_H__
#define __MYHEADER_H__
typedef struct{
                char *palavra;
                int freq;
                } data;
typedef struct {
                char *palavra;
                int max;
                int top;
                }Buffer;
typedef struct {
                data *info;
                int max;
                int top;
                }BufferData;
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
/*esta função uma  Lista ligada e conta o números de elementos presentes nela.
 */
int nElementosLG(apontadorLG inicio);
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
/*esta função cria um buffer(vetor dinamico) de datas e devolve um ponteiro para
 *o buffer criado.
*/
BufferData *criaBufferData();
/*esta função recebe um ponteiro para o buffer que sera realocado, ela ira
 *dobrar o tamanho do buffer original, mantendo seu conteudo igual.
 */
void realocaBufferData(BufferData *B);
/*a função recebe um buffer e um tipo data que ira ser adicionado no buffer, a
 *função aumenta o tamanho do buffer se nescessario.
 */
void adicionaNoBufferData(BufferData *B, data *Novo);
/*esta função recebe um buffer e ira desalocar a memoria usada por ele.
 */
void destroiBufferData(BufferData *B);
#endif
