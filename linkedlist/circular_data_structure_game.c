

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./includes/data_structures/tad_circular_linked_list.h"
#include "./includes/terminal.h"

char dados[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
CircularLinkedList *leftList = NULL, *rightList = NULL;

void embaralhar(char dados[], int n) {
  srand(time(0));
  for(int i = 0; i < n; i++) {
    int j = rand() % n;
    char temp = dados[i];
    dados[i] = dados[j];
    dados[j] = temp;
  }
}

int venceu(CircularLinkedList *leftList, CircularLinkedList *rightList, char gabarito[]) {
  if(lista_igual_vetor(leftList, gabarito, 5) && lista_igual_vetor(rightList, gabarito+5, 5))
    return 1;
  return 0;
}

// Inicializa as configurações iniciais do jogo
int configurar_jogo() {
  leftList = criar_lista();
  rightList = criar_lista();

  if(!leftList || !rightList) {
    printf("Erro ao criar as listas do jogo\n");
    return 0;
  }

  embaralhar(dados, 10);
  // inserir os primeiros 5 elementos do vetor dados na lista da esquerda
  inserir_vetor_na_lista(leftList, dados, 5);
  // inserir os últimos 5 elementos do vetor dados na lista da direita
  inserir_vetor_na_lista(rightList, dados+5, 5);
  // embaralhar os dados para que você encontre o padrão
  embaralhar(dados, 10);
  // infelizmente não está funcionando para windows, mas compilará sem problemas
  ignora_pressionar_enter_para_leitura();
  ocultar_cursor();

  return 1;
}

void comecar_jogo() {
  char opcao;
  do {
    limpar_tela();
    definir_propriedade_da_fonte(FG_WHITE);
    desenharListaCircularEsquerda(15, 16, 6, leftList, dados);
    desenharListaCircularDireita(41, 16, 6, rightList, dados+5);
    definir_propriedade_da_fonte(BOLD);
    definir_propriedade_da_fonte(FG_YELLOW);
    printf("\033[15;26HTroca");
    printf("\033[16;26H<===>");
    if(venceu(leftList, rightList, dados)) {
      definir_propriedade_da_fonte(FG_GREEN);
      printf("\033[4;17HParabéns, você venceu!!");
      printf("\033[5;11HPressione qualquer tecla para sair...");
      getchar();
    }

    printf("\033[2;8HPressione:");
    printf("\033[3;8HW/S - Trocar");
    printf("\033[4;8H A  - Rotacionar lista da esquerda");
    printf("\033[5;8H D  - Rotacionar lista da direita");
    printf("\033[6;8H Q  - Sair");
    definir_propriedade_da_fonte(FG_WHITE);
    opcao = getchar();
    switch(opcao) {
      case 'A': case 'a':
        rotacionarLista(leftList);
        break;
      case 'D': case 'd':
        rotacionarLista(rightList);
        break;
      case 'W': case 'w':
      case 'S': case 's':
        trocar(leftList, rightList);
        break;
    }
  } while(opcao != 'Q' && opcao != 'q');
}

void finalizar_jogo() {
  deletarListaCircular(leftList);
  deletarListaCircular(rightList);
}

int main() {
  configurar_jogo();
  // descomente apenas para testar se suas funções funcionam
  // listar(leftList);
  // listar(rightList);
  comecar_jogo();
  finalizar_jogo();
}