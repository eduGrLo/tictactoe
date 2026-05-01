#include "funcoes.h"

void showTab(char tab[3][3]){
  int i, j;

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

  for(j = 0; j < 3; j++){	//  Verifica condicao de vitoria vertical
    for(i = 0; i < 3; i++){
      if((t[i][j]) == p){
	temp++;
      }
    }
    if(temp == 3){
      win = true;
    }
    temp = 0;
  }

  j = 0;

  for(i = 0; i < 3; i++){	//  Verifica condicao de vitoria diagonal (top esq - bot dir)
    if(t[i][j++] == p){
      temp++;
    }
  }

  if(temp == 3){
    win = true;
  }
  temp = 0;

  j = 3;

  for(i = 0; i < 3; i++){	//  Verifica condicao de vitoria diagonal (top dir - bot esq)
    if(t[i][--j] == p){
      temp++;
    }
  }

  if(temp == 3){
    win = true;
  }
  temp = 0;

  return win;
}
