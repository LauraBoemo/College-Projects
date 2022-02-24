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

#define chuteL 'l'
#define chuteV 'v'
#define chuteC 'c'
                
#define erroChute1   "\n\n=== ATENÇÃO ===\nA palavra deve conter no mínimo e no máximo, 5 caracteres. Insira novamente.\n===============\n\n"
#define erroChute2   "\n\n=== ATENÇÃO ===\nA palavra precisa ser existente. Insira novamente.\n===============\n\n"
#define erroChute3   "\n\n=== DESISTENCIA ===\n\n"
#define chuteCorreto "Chute correto"

/*==============================================================================*/
/* Typedef                                                                      */
/*==============================================================================*/

typedef struct {
    char sem_acento[6];
    char com_acento[16];
    bool usada;
} palavra_t;

typedef struct {
    char letras[6]; 
    palavra_t palavra;
    char dicas[5];
    bool correto;
} chute_t;

typedef struct {
    palavra_t sorteada;     
    int nchutes;            
    chute_t chutes[6];      
    char letras_usadas[26]; 
} partida_t;


palavra_t lista_de_palavras[NUM_PALAVRAS];

/*==============================================================================*/
/* Funções                                                                      */
/*==============================================================================*/

int main();

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

char* gerar_palavra_aleatoria(partida_t *partida) {
    char *palavra_sorteada[5];
    
    srand(time(NULL));
    int aux = rand() % NUM_PALAVRAS;
    
    palavra_t *m = &lista_de_palavras[aux];
    for(int i = 0; i < 6; i++) {
        partida->sorteada.sem_acento[i] = m->sem_acento[i];
        partida->sorteada.com_acento[i] = m->com_acento[i];
    }
    printf("%s", partida->sorteada.sem_acento);
    
    return partida->sorteada.sem_acento;
}

/*-----------------------------------------------------------------------------*/
/* Corpo da função - le_palavra                                                */
/*                                                                             */
/* Escaneando o arquivo e armazendo, dentro da lista, na palavra de            */
/* linha "i", a string "sem_acento" e "com_acento".                            */
/*-----------------------------------------------------------------------------*/

bool le_palavra(FILE *arquivo) {
    int i = 0;
    while (fscanf(arquivo, "%s%s", lista_de_palavras[i].sem_acento, 
            lista_de_palavras[i].com_acento) == 2) ++i;
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

/*-----------------------------------------------------------------------------*/
/* Corpo da função - verifica_dica                                             */
/*                                                                             */
/* Função para auxiliar a alterar de cor na função tela_principal              */
/*-----------------------------------------------------------------------------*/

void verifica_dica(partida_t *partida, int i, int aux) {
    switch(partida->chutes[i].dicas[aux]) {
        case chuteC:
            muda_cor(BRANCO, CINZA);
            break;
        case chuteL:
            muda_cor(BRANCO, LARANJA);
            break;
        case chuteV:
            muda_cor(BRANCO, VERDE);
            break;
    }
}

/*-----------------------------------------------------------------------------*/
/* Corpo da função - tela_principal                                            */
/*                                                                             */
/* Função que desenha na tela as palavras conforme suas devidas cores          */
/* indicadas.                                                                  */
/*-----------------------------------------------------------------------------*/

void tela_principal(chute_t *chute, partida_t *partida) {
    int aux_contador = 6 - partida->nchutes;
    
    for(int i = 0; i <= partida->nchutes; i++) {
        for(int j = 0; j < 4; j++) {
            for(int aux = 0; aux < 5; aux++) {
                if(j == 0 || j == 2) {
                    verifica_dica(partida, i, aux);
                    printf("   ");
                    cor_normal();
                    printf(" ");
                } 
                
                if(j == 1) {
                    verifica_dica(partida, i, aux);
                    printf(" %c ", partida->chutes[i].palavra.sem_acento[aux]);
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

    for(int i = 0; i <= aux_contador - 2; i++){
        for(int j = 0; j < 3; j++) {
            for(int aux = 0; aux < 5; aux++) {
                muda_cor(BRANCO, CINZA);
                printf("   ");
                cor_normal();
                printf(" ");
            }
            
            printf("\n");
        }
        
        printf("\n");
    }
}

void tela_secundaria(chute_t *chute, partida_t *partida) {
    char a;
    int aux = 0;
    int aux_contador = 0;
    
    for(int aux = 0; aux < 26; aux++) {
        partida->letras_usadas[aux] = '0';
        for(int aux2 = 0; aux2 < 4; aux2++) {
            if(partida->letras_usadas[aux] == chute->letras[aux2]) {
                aux_contador++;
            }
        }
    }
    
    printf("%i", aux_contador);
    
    for(a='a';a!='z';a++) {
        muda_cor(BRANCO, CINZA);
        printf(" %c ", a);
        cor_normal();
        printf(" ");
        aux++;
    }

    // for(int i = 0; i < 26; i++) {
    //     // for(int j = 0; j < 5; j++) {
    //         if(partida->letras_usadas[i] == chute->letras[i]) {
    //             if(chute->dicas[i] == 'v') {
    //                 muda_cor(BRANCO, VERDE);
    //                 printf(" %c ", partida->letras_usadas[i]);
    //                 cor_normal();
    //                 printf(" ");
    //             } else if(chute->dicas[i] == 'l') {
    //                 muda_cor(BRANCO, LARANJA);
    //                 printf(" %c ", partida->letras_usadas[i]);
    //                 cor_normal();
    //                 printf(" ");
    //             }
    //         } else {
    //             muda_cor(BRANCO, CINZA);
    //             printf(" %c ", partida->letras_usadas[i]);
    //             cor_normal();
    //             printf(" ");
    //         }
    //     // }
    // }
    
    // int aux_contador = 6 - partida->nchutes;
    
    // for(int i = 0; i <= partida->nchutes; i++) {
    //     for(int j = 0; j < 4; j++) {
    //         for(int aux = 0; aux < 5; aux++) {
    //             if(j == 0 || j == 2) {
    //                 verifica_dica(partida, i, aux);
    //                 printf("   ");
    //                 cor_normal();
    //                 printf(" ");
    //             } 
                
    //             if(j == 1) {
    //                 verifica_dica(partida, i, aux);
    //                 printf(" %c ", partida->chutes[i].palavra.sem_acento[aux]);
    //                 cor_normal();
    //                 printf(" ");
    //             } 
                
    //             if(j == 3){
    //                 printf("    ");
    //             }
    //         }
            
    //         printf("\n");
    //     }
    // }

    // for(int i = 0; i <= aux_contador - 2; i++){
    //     for(int j = 0; j < 3; j++) {
    //         for(int aux = 0; aux < 5; aux++) {
    //             muda_cor(BRANCO, CINZA);
    //             printf("   ");
    //             cor_normal();
    //             printf(" ");
    //         }
            
    //         printf("\n");
    //     }
        
    //     printf("\n");
    // }
}

/*-----------------------------------------------------------------------------*/
/* Corpo da função - verificacao_chutes                                        */
/*                                                                             */
/* Função que verifica se o chute é uma palavra válida                         */
/*-----------------------------------------------------------------------------*/

char* verificacao_chute(chute_t *chute) {
    int aux_verificador = 0;
    
    if(strcmp(chute->palavra.sem_acento, "desisto") == 0) {
        return erroChute3;
    } 
    
    if(strlen(chute->palavra.sem_acento) != 5) {
        return erroChute1;
    }
    
    for(int b = 0; b < NUM_PALAVRAS; b++) {
        palavra_t *m = &lista_de_palavras[b];
        if(strcmp(chute->palavra.sem_acento, m->sem_acento) == 0) {
            aux_verificador++;
        } 
    }
    
    if(aux_verificador == 0) {
        return erroChute2;
    } 
    
    return chuteCorreto;
}

/*-----------------------------------------------------------------------------*/
/* Corpo da função - verificacao_dicas                                         */
/*                                                                             */
/* Função que verifica a relação do chute com a palavra real, assim            */
/* gerando a string de dicas.                                                  */
/*-----------------------------------------------------------------------------*/

char* verificacao_dicas(chute_t *chute, partida_t *partida) {
    strcpy(chute->letras, chute->palavra.sem_acento);
    int aux = 0;
    for(int i = 0; i < 5; i++) {
            if(chute->letras[i] != partida->sorteada.sem_acento[i]) {
                chute->dicas[i] = chuteC;
            }
            
            for(int j = 0; j < 5; j++) {
                if(chute->letras[i] == partida->sorteada.sem_acento[j]) {
                    chute->dicas[i] = chuteL;
                }
            }
            
            if(chute->letras[i] == partida->sorteada.sem_acento[i]) {
                chute->dicas[i] = chuteV;
                aux++;
            } 
            
            partida->chutes[partida->nchutes].palavra.sem_acento[i] = chute->palavra.sem_acento[i];
            partida->chutes[partida->nchutes].dicas[i] = chute->dicas[i];
        }
    
        
        if(aux == 5) {
            chute->correto = true;
        } else {
            chute->correto = false;
        }
        
        return chute->dicas;
}

/*-----------------------------------------------------------------------------*/
/* Corpo da função - finaliza_jogo                                             */
/*                                                                             */
/* Função que verifica o resultado e o desempenho do jogaodr.                  */
/*-----------------------------------------------------------------------------*/

void finaliza_jogo(bool status_final, chute_t *chute, partida_t *partida) {
    char reiniciar[1];
    
    if(status_final) {
        printf("=== TU ÉS VENCEDOR ==\nPalavra original: %c%c%c%c%c\nQuantidade de tentativas: %i\n", partida->sorteada.com_acento[0], partida->sorteada.com_acento[1], partida->sorteada.com_acento[2], partida->sorteada.com_acento[3], partida->sorteada.com_acento[4], partida->nchutes + 1);
    } else {
        printf("=== TU ÉS PERDEDOR ==\nPalavra original: %c%c%c%c%c\n", partida->sorteada.com_acento[0], partida->sorteada.com_acento[1], partida->sorteada.com_acento[2], partida->sorteada.com_acento[3], partida->sorteada.com_acento[4]);
    }
    
    verificacao:
    printf("\n\n==============\nDesejas jogar novamente? (s/n): ");
    scanf("%s", reiniciar);
    
    if(*reiniciar == 's') {
        main();
    } else if (*reiniciar == 'n') {
        printf("\nObrigada por jogar!");
    } else {
        printf("Informe uma resposta válida.");
        goto verificacao;
    }
    
}

/*==============================================================================*/
/* Função Main                                                                  */
/*==============================================================================*/

int main() {
    FILE *entrada;
    FILE *saida;
    entrada = fopen("palavras.txt", "r");
    saida = fopen("copia-das-palavras", "w");
    
    if (entrada == NULL || saida == NULL) {
        printf("Erro no acesso aos arquivos.\n");
        exit(1);
    }
    
    printf("\n=== NOVA PARTIDA ===\n");
    
    chute_t chute;
    partida_t partida;
    palavra_t palavra;

    
    while (le_palavra(entrada)) {
        gerar_palavra_aleatoria(&partida);
        
        if (!grava_palavra(saida, &palavra)) {
            printf("Problema na gravação.\n");
            break;
        }
        
        for(partida.nchutes = 0; partida.nchutes < 6; partida.nchutes++) {
            printf("\n\nInforme uma tentativa: ");
            scanf("%s", chute.palavra.sem_acento);
            
            if(verificacao_chute(&chute) == erroChute1) {
                printf(erroChute1);
                partida.nchutes--;
            } else if(verificacao_chute(&chute) == erroChute2) {
                printf(erroChute2);
                partida.nchutes--;
            } else if(verificacao_chute(&chute) == erroChute3) {
                printf(erroChute3);
                finaliza_jogo(0, &chute, &partida);
            } else {
                verificacao_dicas(&chute, &partida);
                tela_principal(&chute, &partida);
                tela_secundaria(&chute, &partida);
                
                if(chute.correto) {
                    finaliza_jogo(1, &chute, &partida);
                    break;
                }
            }
        }
        
        if(partida.nchutes == 6) {
            finaliza_jogo(0, &chute, &partida);
        }

        break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}