/*==============================================================================*/
/* Includes                                                                     */
/*==============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/*==============================================================================*/
/* Define                                                                       */
/*==============================================================================*/

#define NUM_PALAVRAS 15

#define CINZA 169, 169, 169   
#define LARANJA 230, 126, 34 
#define VERDE 39, 174, 96   
#define BRANCO 255, 255, 255 

/*==============================================================================*/
/* Typedef                                                                      */
/*==============================================================================*/

typedef struct {
    char sem_acento[6];
    char com_acento[16];
    bool usada;
} palavra_t;

palavra_t lista_de_palavras[NUM_PALAVRAS];

/*-----------------------------------------------------------------------------*/
/* Corpo das funções - muda_cor & cor_normal                                   */
/*                                                                             */
/* Funções que alteram a cor de fundo e a fonte do printf quando chamadas.     */
/*-----------------------------------------------------------------------------*/

void muda_cor(int rl, int gl, int bl, int rf, int gf, int bf) {
    printf("%c[38;2;%d;%d;%d;48;2;%d;%d;%dm", 27, rl, gl, bl, rf, gf, bf);
}

void cor_normal() {
    printf("%c[0m", 27);
}

/*-----------------------------------------------------------------------------*/
/* Corpo da função - gerar_palavra_aleatoria                                   */
/*                                                                             */
/* Utilizando função rand() para selecionar um número aleatório que            */
/* irá definir qual linha que irá fornecer a palavra (apontando para           */
/* "sem_acento").                                                              */
/*-----------------------------------------------------------------------------*/

char* gerar_palavra_aleatoria() {
    char *palavra_sorteada[5];
    
    srand(time(NULL));
    int aux = rand() % NUM_PALAVRAS;
    
    palavra_t *m = &lista_de_palavras[aux];
    *palavra_sorteada = m->sem_acento;
    
    return *palavra_sorteada;
}

char* gerar_palavra_auxiliar(char *palavra[]) {
    char *auxiliar[5];
    strcpy(*auxiliar, *palavra);
    
    return *auxiliar;
}

/*-----------------------------------------------------------------------------*/
/* Corpo da função - le_palavra                                                */
/*                                                                             */
/* Escaneando o arquivo e armazendo, dentro da lista, na palavra de            */
/* linha "i", a string "sem_acento" e "com_acento".                            */
/*-----------------------------------------------------------------------------*/

bool le_palavra(FILE *arquivo) {
    int i = 0;
    while (fscanf(arquivo, "%s%s", lista_de_palavras[i].sem_acento, lista_de_palavras[i].com_acento) == 2) ++i;
    return true;
}

/*-----------------------------------------------------------------------------*/
/* Corpo da função - grava_palavra                                             */
/*                                                                             */
/* Função para percorrer o vetor de lista_de_palavras e, conforme              */
/* sua posição definia por "i", aponta e insere os devidos valores.            */
/*-----------------------------------------------------------------------------*/
 
bool grava_palavra(FILE *arquivo, palavra_t *p) {
    for (int i = 0; i < NUM_PALAVRAS; ++i) {
        palavra_t *m = &lista_de_palavras[i];
        fprintf(arquivo,"%s %s\n", m->sem_acento, m->com_acento);
    }
    
    return true;
}

void tela_principal(char *dica[], char *palavra_chute[], int aux_tentativas) {
    char aux_dica[5];
    char aux_chute[5];
    strcpy(aux_dica, *dica);
    strcpy(aux_chute, *palavra_chute);
    
    for(int i = 0; i < aux_tentativas + 1; i++){
        for(int j = 0; j < 4; j++) {
            for(int aux = 0; aux < 5; aux++) {
                if(j == 0 || j == 2) {
                    switch(aux_dica[aux]) {
                        case 'c':
                            muda_cor(BRANCO, CINZA);
                            break;
                        case 'l':
                            muda_cor(BRANCO, LARANJA);
                            break;
                        case 'v':
                            muda_cor(BRANCO, VERDE);
                            break;
                    }
                    printf("   ");
                    cor_normal();
                    printf(" ");
                } 
                if(j == 1) {
                    switch(aux_dica[aux]) {
                        case 'c':
                            muda_cor(BRANCO, CINZA);
                            break;
                        case 'l':
                            muda_cor(BRANCO, LARANJA);
                            break;
                        case 'v':
                            muda_cor(BRANCO, VERDE);
                            break;
                    }
                    printf(" %c ", aux_chute[aux]);
                    cor_normal();
                    printf(" ");
                } 
                if(j == 3){
                    printf("    ");
                }
            }
            printf("\n");
        }
    }
}

char* verificacao(char *palavra_sorteada[], char *palavra_chute[]) {
    static char aux_retorno_dica[5];
    char aux_sorteio[5];
    char aux_chute[5];
    strcpy(aux_sorteio, *palavra_sorteada);
    strcpy(aux_chute, *palavra_chute);
    
    for(int i = 0; i < 5; i++) {
        if(aux_chute[i] != aux_sorteio[i]) {
            aux_retorno_dica[i] = 'c';
        }
        
        for(int j = 0; j < 5; j++) {
            if(aux_chute[i] == aux_sorteio[j]) {
                aux_retorno_dica[i] = 'l';
            }
        }
        
        if(aux_chute[i] == aux_sorteio[i]) {
            aux_retorno_dica[i] = 'v';
        } 
    }
    
    return aux_retorno_dica;
}

int main() {
    FILE *entrada;
    FILE *saida;
    entrada = fopen("palavras.txt", "r");
    saida = fopen("copia-das-palavras", "w");
    char *palavra_sorteada[5];
    char *palavra_chute[5];
    char *dica[4];

    if (entrada == NULL || saida == NULL) {
        printf("Erro no acesso aos arquivos.\n");
        exit(1);
    }
    
    palavra_t palavra;
    
    while (le_palavra(entrada)) {
        
        *palavra_sorteada = gerar_palavra_aleatoria();
        printf("Palavra sorteada: '%s'\n\n", *palavra_sorteada);
        
        if (!grava_palavra(saida, &palavra)) {
            printf("Problema na gravação.\n");
            break;
        }
        
        for(int aux_tentativas = 0; aux_tentativas < 6; aux_tentativas++) {
            printf("Informe uma tentativa...");
            scanf("%s", *palavra_chute);
            
            verificacao(palavra_sorteada, palavra_chute);
            *dica = verificacao(palavra_sorteada, palavra_chute);
            
            tela_principal(dica, palavra_chute, aux_tentativas);
        }
        
        break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}