#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
     int tam;          // tamanho do tabuleiro (um quadrado com "tam" casas de lado) (entre 3 e 20)
     int ncor;         // numero de cores usadas (valores entre 1 e "ncor") (entre 3 e 9)
     char mat[22][22]; // matriz com o estado atual do tabuleiro
   } tabuleiro;

//funções disponibilizadas no github
void muda_cor(int rl, int gl, int bl, int rf, int gf, int bf)
{
  printf("%c[38;2;%d;%d;%d;48;2;%d;%d;%dm", 27, rl, gl, bl, rf, gf, bf);
}

void cor_normal(void)
{
  printf("%c[0m", 27);
}

//função explicada em aula que
bool ta_fora(tabuleiro *tab, int lin, int col)
{
  if (lin < 1 || col < 1) return true;
  if (lin > tab->tam || col > tab->tam) return true;
  return false;
}

int numero_aleatorio_entre(int inf, int sup)
{
  return inf + rand()%(sup-inf+1);
}

bool tab_inic(tabuleiro *tab, int tam, int ncor) {
  //criei uma condição que verifica se tam e ncor estão de acordo com as restrições.
  if (tam < 3 || tam > 20) return false;  
  if (ncor < 3 || ncor > 9) return false;  
  // Inicializa o tabuleiro apontado por "tab", para ter o tamanho e o número de cores fornecidas.
  tab->tam = tam;
  tab->ncor = ncor;
      for (int l=0; l<22; l++) {
        for (int c=0; c<22; c++) {
            if (ta_fora(tab, l, c)) {
              tab->mat[l][c] = 0;
            } else {
              tab->mat[l][c] = numero_aleatorio_entre(1, ncor);
            }
        }
      }
      return true;
  }
  
void tab_desenha(tabuleiro *tab)
{
  //for que percorre o tabuleiro por linha e coluna
  for (int l=1; l<=tab->tam; l++) {
    for (int c=1; c<=tab->tam; c++) {
      if (tab->mat[l][c] == 1) {
        muda_cor(255, 255, 255, 243, 119, 53);
      } 
      else if (tab->mat[l][c] == 2) {
        muda_cor(255, 255,255, 255, 196, 37);
      } 
      else if (tab->mat[l][c] == 3) {
        muda_cor(255, 255, 255, 209,17,65);
      } 
      else if (tab->mat[l][c] == 4) {
        muda_cor(255, 255, 255, 162,82,241);
      } 
      else if (tab->mat[l][c] == 5) {
        muda_cor(255, 255, 255, 255,102,204);
      } 
      else if (tab->mat[l][c] == 6) {
        muda_cor(255, 255, 255, 149,210,104);
      } 
      else if (tab->mat[l][c] == 7) {
        muda_cor(255, 255, 255, 88, 99, 246);
      } 
      else if (tab->mat[l][c] == 8) {
        muda_cor(255, 255, 255, 5, 68, 189);
      } 
      else {
        muda_cor(255, 255, 255, 0,174,219);
      }
      //printa o espaço que foi solicitado na descrição da quarta linha das instruções da função tab_desenha
      printf(" %d ", tab->mat[l][c]);
    }
    cor_normal();
    printf("\n"); 
  }
}

//velhacor = cor na posição lin,col
  //se novacor == velhacor, tá feito
  //inicializa um vetor de posições com a posição x,y
  //enquanto o vetor contiver alguma posição
    //retira uma posição do vetor e coloca em x,y
    //muda a cor da posição x,y para ser novacor
    //para cada uma das 4 posições vizinhas a x,y
    //se essa posição contiver velhacor, coloca essa posição no vetor


typedef struct {
  int npos; // número de posições ocupadas no vetor
  int ncap; // número de posições que cabem no vetor (quanto foi alocado)
  int *vet; // local onde colocar os valores salvos no vetor
  } vetor;