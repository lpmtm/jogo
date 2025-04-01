#ifndef TERMINAL_H
#define TERMINAL_H

#ifdef _WIN32
  #include "termWin.h"
#else
  #include <termios.h>
#endif
// -----------------------------------------------------------------------------------------------------
// Funções de terminal com termios.h
// -----------------------------------------------------------------------------------------------------

void mantem_pressionar_enter_para_leitura();
void ignora_pressionar_enter_para_leitura();

void esconde_texto_digitado_para_leitura();
void exibe_texto_digitado_para_leitura();

// -----------------------------------------------------------------------------------------------------
// Funções de terminal com ANSI escape codes
// -----------------------------------------------------------------------------------------------------

/*
O formato geral para definir a cor do texto usando códigos de escape ANSI é:

\033[<estilo>;<cor_do_texto>;<cor_do_fundo>m

onde:

\033 é o caractere de escape na representação octal, que inicia a sequência de escape ANSI.

[ é o introduzidor de sequência de controle.

<estilo>, <cor_do_texto> e <cor_do_fundo> são espaços reservados para códigos numéricos que 
  representam estilos de texto (como negrito ou sublinhado), cores de primeiro plano (texto) 
  e cores de fundo, respectivamente.

m indica que a sequência é uma configuração de modo de cor/gráficos.
*/

// estilos de fonte
#define BOLD 1
#define FAINT 2
#define ITALIC 3
#define UNDERLINE 4
#define BLINK 5
#define INVERSE 7
#define HIDDEN 8
#define STRIKETHROUGH 9
#define DOUBLE_UNDERLINE 21
#define NORMAL 22
#define NO_ITALIC 23
#define NO_UNDERLINE 24
#define NO_BLINK 25
#define NO_INVERSE 27
#define NO_HIDDEN 28
#define NO_STRIKETHROUGH 29

// cores de texto (foreground - fg)
#define FG_BLACK 30
#define FG_RED 31
#define FG_GREEN 32
#define FG_YELLOW 33
#define FG_BLUE 34
#define FG_MAGENTA 35
#define FG_CYAN 36
#define FG_WHITE 37
// cores de fundo (background - bg)
#define BG_BLACK 40
#define BG_RED 41
#define BG_GREEN 42
#define BG_YELLOW 43
#define BG_BLUE 44
#define BG_MAGENTA 45
#define BG_CYAN 46
#define BG_WHITE 47

void resetar_fonte();
void definir_propriedade_da_fonte(int propriedade);

void exibir_cursor();
void ocultar_cursor();
void mover_cursor_xy(int x, int y);
void limpar_tela();
void limpar_linha();
#endif // TERMINAL_H
