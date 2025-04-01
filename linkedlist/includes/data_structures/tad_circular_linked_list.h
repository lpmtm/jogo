#ifndef CIRCULAR_LINKED_LIST
#define CIRCULAR_LINKED_LIST

typedef struct circularLinkedList CircularLinkedList;

CircularLinkedList* criar_lista();
int lista_igual_vetor(CircularLinkedList *lista, char vetor[], int n);
void inserir_vetor_na_lista(CircularLinkedList *lista, char vetor[], int n);
void desenharListaCircularEsquerda(int x, int y, float raio, CircularLinkedList *list, char gabarito[]);
void desenharListaCircularDireita(int x, int y, float raio, CircularLinkedList *list, char gabarito[]);
void deletarListaCircular(CircularLinkedList *lista);
void rotacionarLista(CircularLinkedList *list);
void trocar(CircularLinkedList *leftList, CircularLinkedList *rightList);
void listar(CircularLinkedList *lista);
#endif // CIRCULAR_LINKED_LIST