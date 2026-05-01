#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funcoes.h"

int main(){
  system("clear");

  char tabuleiro[3][3];
  int i, j;
  int choi, choj;               //choice i, linha   |   choice j, coluna
  char pecJog, pecOpon, pecTurn;                  //peca do jogador;
  bool running = true;
  int rodada = 0;

  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      tabuleiro[i][j] = ' ';
    }
  }

  while((pecJog != 'X') && (pecJog != 'O')){
    printf("\nX | O\n");
    scanf("%c", &pecJog);
    system("clear");
  }

  pecOpon = (pecJog == 'X' ? 'O' : 'X');

  while(running){
    system("clear");

    rodada += 1;
    printf("Rodada [%d]\n", rodada);
    printf("------------");
    pecTurn = (rodada % 2) == 1 ? pecJog : pecOpon;
    printf("\n[%c] turn\n\n", pecTurn);

    showTab(tabuleiro);

    do{
      while((choi < 1) || (choi > 3)){
        printf("\n[linha]: ");
        scanf("%d", &choi);
      }

      while((choj < 1) || (choj > 3)){
        printf("\n[coluna]: ");
        scanf("%d", &choj);
      }

      if(tabuleiro[choi - 1][choj - 1] != ' '){
        printf("Campo ja preenchido!");
	choi = 0;
	choj = 0;
      }
    }while(tabuleiro[choi - 1][choj - 1] != ' ');

    tabuleiro[choi - 1][choj - 1] = pecTurn;   //jogada Jogador ou Oponente

    if(verify(tabuleiro, pecJog)){
      running = false;
      system("clear");

      printf("\n ---------");
      printf("\n| %c won! |", pecJog);
      printf("\n ---------\n");
    }

    if(verify(tabuleiro, pecOpon)){
      running = false;
      system("clear");

      printf("\n ---------");
      printf("\n| %c won! |", pecOpon);
      printf("\n ---------\n");
    }

    choi = 0;
    choj = 0;
  }

  printf("\n");
  showTab(tabuleiro);

  return 0;
}
