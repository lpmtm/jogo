#include <stdio.h>

#include "../includes/terminal.h"

// -----------------------------------------------------------------------------------------------------
// Funções de terminal com termios.h
// -----------------------------------------------------------------------------------------------------

void mantem_pressionar_enter_para_leitura() {
	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag |= ICANON;
	tcsetattr(1, TCSANOW, &term);
}

void ignora_pressionar_enter_para_leitura() {
	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag &= ~ICANON;
	tcsetattr(1, TCSANOW, &term);
}

void esconde_texto_digitado_para_leitura() {
	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag &= ~ECHO;
	tcsetattr(1, TCSANOW, &term);
}

void exibe_texto_digitado_para_leitura() {
	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag |= ECHO;
	tcsetattr(1, TCSANOW, &term);
}

// -----------------------------------------------------------------------------------------------------
// Funções de terminal com ANSI escape codes
// -----------------------------------------------------------------------------------------------------

void resetar_fonte() {
  printf("\033[0m");
}

void definir_propriedade_da_fonte(int property) {
  printf("\033[%dm", property);
}

void exibir_cursor() {
  printf("\033[?25h");
}
void ocultar_cursor() {
  printf("\033[?25l");
}
void mover_cursor_xy(int x, int y) {
  printf("\033[%d;%dH", y, x);
}
void limpar_tela() {
  // \033[2J - Limpa a Tela                         (y,x)
  // \033[1;1H - Posiciona o cursor no topo da tela (1,1)
  printf("\033[2J\033[1;1H");
}
void limpar_linha() {
  // \033[K - Limpa a linha
  printf("\033[K");
}

