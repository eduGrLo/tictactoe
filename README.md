# projetoRandom

um jogo da velha buxa :|


ahhhh:
  GNU nano 7.2                                                                                                                       tictac.c                                                                                                                                 #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void showTab(char tab[3][3]){
  int i, j;
  static int count = 0;

  printf("Rodada [%d]\n", (++count));

  for(i = 0; i < 3; i++){

    if(i > 0) {
      printf("|");
    }
    printf("\n ___ ___ ___ \n");

    for(j = 0; j < 3; j++){
      printf("| %c ", tab[i][j]);
    }
  }

  printf("|\n ___ ___ ___ \n");

}

bool verify(char t[3][3], char p){
  bool win = false;
  int i, j, temp = 0;

  for(i = 0; i < 3; i++){       //  Verifica condicao de vitoria horizontal
    for(j = 0; j < 3; j++){
      if((t[i][j]) == p){
        temp++;
      }
    }
    if(temp == 3){
      win = true;
    }
    temp = 0;
  }
  return win;
}

int main(){
  system("clear");

  char tabuleiro[3][3];
  int i, j;
  int choi, choj;               //choice i, linha   |   choice j, coluna
  char pecJog;                  //peca do jogador;
  bool running = true;

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

  while(running){
    system("clear");
    showTab(tabuleiro);

    while((choi < 1) || (choi > 3)){
      printf("\n[linha]: ");
      scanf("%d", &choi);
    }

    while((choj < 1) || (choj > 3)){
      printf("\n[coluna]: ");
      scanf("%d", &choj);
    }

    tabuleiro[choi - 1][choj - 1] = pecJog;

    if(verify(tabuleiro, pecJog)){
      running = false;
      system("clear");
      printf("You win!");
    }

    choi = 0;
    choj = 0;
  }

  return 0;
}
