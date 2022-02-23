#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_PALAVRAS 16734

typedef struct {
    char sem_acento[5];
    char com_acento[10];
    bool usada;
} palavra_t;

palavra_t lista_de_palavras[NUM_PALAVRAS];

bool le_palavra(FILE *arquivo, palavra_t *p) {
    int i = 0;
    int numPalavras = 0;
    char* palavras[50];
    char line[50];

    while(fgets(line, sizeof line, arquivo) != NULL)
    {
        //Adiciona cada palavra no vetor
        palavras[i] = strdup(line);

        i++;

        //Conta a quantidade de palavras
        numPalavras++;
    }

    int j;

    for (j = 0; j < numPalavras; j++)
        printf("\n%s", palavras[j]); //Exibi as palavras que estao no vetor.

    printf("\n\n");

    // char palavraAux[4];
    
    // while(!feof(arquivo)) {
    //     fscanf(arquivo, "%s", palavraAux);
        
    //     for(int i = 0; i < 15; i++){
    //         if(i < 5) {
    //             p -> sem_acento[i] = palavraAux[i];
    //         } else {
    //             if(palavraAux[i] >= 'a' && palavraAux[i] <= 'z') {
    //                 p -> com_acento[i] = palavraAux[i];
    //                 p -> com_acento[i + 1] = 0;
    //             } else {
    //                 p -> com_acento[i] = palavraAux[i];
    //             }
    //         }
    //     }
    // }
    
    return true;
}

bool grava_palavra(FILE *arquivo, palavra_t *p) {
    // for(int i = 0; i < NUM_PALAVRAS; i++){
    //     fprintf(arquivo, "%c %c", p -> sem_acento[i],a  p -> com_acento[i]);
    //     if(feof(arquivo)){
    //         break;
    //     }
    // }
    return true;
}

int main() {
    FILE *entrada;
    FILE *saida;
    entrada = fopen("palavras.txt", "r");
    saida = fopen("copia-das-palavras", "w");

    if (entrada == NULL || saida == NUL) {
        printf("Erro no acesso aos arquivos.\n");
        exit(1);
    }
    
    palavra_t palavra;
    
    while (le_palavra(entrada, &palavra)) {
        if (!grava_palavra(saida, &palavra)) {
            printf("problema na gravação.\n");
            break;
        }
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_PALAVRAS 10

typedef struct {
    char sem_acento[5];
    char com_acento[10];
    bool usada;
} palavra_t;

palavra_t lista_de_palavras[NUM_PALAVRAS];

bool le_palavra(FILE *arquivo, palavra_t *p) {
    char auxPalavras[NUM_PALAVRAS];
    fscanf(arquivo, "%s\n", auxPalavras);

    for (int j = 0; j < NUM_PALAVRAS; j++)
        printf("\n%s", auxPalavras);
    
    if (feof(arquivo)) {
        return false;
    }
    // int i = 0;
    // char linha[15];
    
    while(fgets(linha, sizeof linha, arquivo) != NULL) {
        auxPalavras[i] = strdup(linha);
        i++;
    }

    // return false;
}

bool grava_palavra(FILE *arquivo, palavra_t *p) {
    // for(int i = 0; i < NUM_PALAVRAS; i++){
    //     fprintf(arquivo, "%c %c", p -> sem_acento[i],a  p -> com_acento[i]);
    //     if(feof(arquivo)){
    //         break;
    //     }
    // }
    return true;
}

int main() {
    FILE *entrada;
    FILE *saida;
    entrada = fopen("palavras.txt", "r");
    saida = fopen("copia-das-palavras", "w");

    if (entrada == NULL || saida == NULL) {
        printf("Erro no acesso aos arquivos.\n");
        exit(1);
    }
    
    palavra_t palavra;
    
    while (le_palavra(entrada, &palavra)) {
        if (!grava_palavra(saida, &palavra)) {
            printf("problema na gravação.\n");
            break;
        }
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
#define NUM_PALAVRAS 15
 
typedef struct {
    char sem_acento[6];
    char com_acento[16];
    bool usada;
} palavra_t;


palavra_t lista_de_palavras[NUM_PALAVRAS];
    
bool le_palavra(FILE *arquivo) {
    int i = 0;
    while (fscanf(fin, "%s%s", lista_de_palavras[i].sem_acento, lista_de_palavras[i].com_acento) == 2)
    ++i;
    fclose(fin);
    return i;
}
 
void grava_palavra(FILE *arquivo, palavra_t *p) {
    for (int i = 0; i < size; ++i) {
        palavra_t *m = &lista_de_palavras[i];
        printf("%i.%s\n", i, m->sem_acento);
    }
}
 
// int main() {
//     int size = read_lista_de_palavras("palavras.txt", lista_de_palavras);
//     print_lista_de_palavras(lista_de_palavras, size);
//     return 0;
// }

int main() {
    FILE *entrada;
    FILE *saida;
    entrada = fopen("palavras.txt", "r");
    saida = fopen("copia-das-palavras", "w");

    if (entrada == NULL || saida == NUL) {
        printf("Erro no acesso aos arquivos.\n");
        exit(1);
    }
    
    palavra_t palavra;
    
    while (le_palavra(entrada)) {
        if (!grava_palavra(saida, &palavra)) {
            printf("problema na gravação.\n");
            break;
        }
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
#define NUM_PALAVRAS 15
 
typedef struct {
    char sem_acento[6];
    char com_acento[16];
    bool usada;
} palavra_t;


palavra_t lista_de_palavras[NUM_PALAVRAS];
    
bool le_palavra(FILE *arquivo) {
    int i = 0;
    while (fscanf(arquivo, "%s%s", lista_de_palavras[i].sem_acento, lista_de_palavras[i].com_acento) == 2)
    ++i;
    return true;
}
 
bool grava_palavra(FILE *arquivo, palavra_t *p) {
    for (int i = 0; i < NUM_PALAVRAS; ++i) {
        palavra_t *m = &lista_de_palavras[i];
        fprintf(arquivo,"%s %s\n", m->sem_acento, m->com_acento);
    }
    return true;
}

int main() {
    FILE *entrada;
    FILE *saida;
    entrada = fopen("palavras.txt", "r");
    saida = fopen("copia-das-palavras", "w");

    if (entrada == NULL || saida == NULL) {
        printf("Erro no acesso aos arquivos.\n");
        exit(1);
    }
    
    palavra_t palavra;
    
    while (le_palavra(entrada)) {
        if (!grava_palavra(saida, &palavra)) {
            printf("problema na gravação.\n");
            break;
        }
        break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}



















#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
 
#define NUM_PALAVRAS 15
 
typedef struct {
    char sem_acento[6];
    char com_acento[16];
    bool usada;
} palavra_t;


palavra_t lista_de_palavras[NUM_PALAVRAS];
    
bool le_palavra(FILE *arquivo) {
    int i = 0;
    while (fscanf(arquivo, "%s%s", lista_de_palavras[i].sem_acento, lista_de_palavras[i].com_acento) == 2)
    ++i;
    return true;
}
 
bool grava_palavra(FILE *arquivo, palavra_t *p) {
    for (int i = 0; i < NUM_PALAVRAS; ++i) {
        palavra_t *m = &lista_de_palavras[i];
        fprintf(arquivo,"%s %s\n", m->sem_acento, m->com_acento);
    }
    return true;
}

int num_rand() {
    srand(time(NULL));
    int aux = rand() % NUM_PALAVRAS;
    return aux;
}

int main() {
    FILE *entrada;
    FILE *saida;
    entrada = fopen("palavras.txt", "r");
    saida = fopen("copia-das-palavras", "w");

    if (entrada == NULL || saida == NULL) {
        printf("Erro no acesso aos arquivos.\n");
        exit(1);
    }
    
    palavra_t palavra;
    
    while (le_palavra(entrada)) {
        // printf("%i", num_rand());
        palavra_t *m = &lista_de_palavras[num_rand()];
        printf("Palavra sorteada: %s", m->sem_acento);
        if (!grava_palavra(saida, &palavra)) {
            printf("problema na gravação.\n");
            break;
        }
        break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
 
#define NUM_PALAVRAS 15
 
typedef struct {
    char sem_acento[6];
    char com_acento[16];
    bool usada;
} palavra_t;


palavra_t lista_de_palavras[NUM_PALAVRAS];

int num_rand() {
    srand(time(NULL));
    int aux = rand() % NUM_PALAVRAS;
    return aux;
}

bool le_palavra(FILE *arquivo) {
    int i = 0;
    while (fscanf(arquivo, "%s%s", lista_de_palavras[i].sem_acento, lista_de_palavras[i].com_acento) == 2)
    ++i;
    return true;
}
 
bool grava_palavra(FILE *arquivo, palavra_t *p) {
    for (int i = 0; i < NUM_PALAVRAS; ++i) {
        palavra_t *m = &lista_de_palavras[i];
        fprintf(arquivo,"%s %s\n", m->sem_acento, m->com_acento);
    }
    return true;
}

int main() {
    FILE *entrada;
    FILE *saida;
    entrada = fopen("palavras.txt", "r");
    saida = fopen("copia-das-palavras", "w");
    char *palavra_sorteada[6];

    if (entrada == NULL || saida == NULL) {
        printf("Erro no acesso aos arquivos.\n");
        exit(1);
    }
    
    palavra_t palavra;
    
    while (le_palavra(entrada)) {
        palavra_t *m = &lista_de_palavras[num_rand()];
        *palavra_sorteada = m->sem_acento;
        
        printf("Palavra sorteada: %s", *palavra_sorteada);
        
        if (!grava_palavra(saida, &palavra)) {
            printf("problema na gravação.\n");
            break;
        }
        break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
 
#define NUM_PALAVRAS 15
#define COR1 106, 90, 205   // SlateBlue
#define COR2 30, 144, 255   // DodgerBlue
#define COR3 34, 139, 34    // ForestGreen
#define WHITE 255, 255, 255 // White
 
typedef struct {
    char sem_acento[6];
    char com_acento[16];
    bool usada;
} palavra_t;


palavra_t lista_de_palavras[NUM_PALAVRAS];

void mudaCor(int rl, int gl, int bl, int rf, int gf, int bf)
{
    printf("%c[38;2;%d;%d;%d;48;2;%d;%d;%dm", 27, rl, gl, bl, rf, gf, bf);
}

void corNormal(void)
{
    printf("%c[0m", 27);
}

int num_rand() {
    srand(time(NULL));
    int aux = rand() % NUM_PALAVRAS;
    return aux;
}

bool le_palavra(FILE *arquivo) {
    int i = 0;
    while (fscanf(arquivo, "%s%s", lista_de_palavras[i].sem_acento, lista_de_palavras[i].com_acento) == 2)
    ++i;
    return true;
}
 
bool grava_palavra(FILE *arquivo, palavra_t *p) {
    for (int i = 0; i < NUM_PALAVRAS; ++i) {
        palavra_t *m = &lista_de_palavras[i];
        fprintf(arquivo,"%s %s\n", m->sem_acento, m->com_acento);
    }
    return true;
}

void tela_principal(void) {
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 4; j++) {
            switch(j) {
                case 0:
                    for(int aux2 = 0; aux2 < 5; aux2++) {
                        printf("cor1_");
                    }
                printf("\n");
                break;
                    
                case 1:
                    for(int aux2 = 0; aux2 < 5; aux2++) {
                        printf("cor2_");
                    }
                printf("\n");
                break;
                    
                case 2:
                    for(int aux2 = 0; aux2 < 5; aux2++) {
                        printf("cor3_");
                    }
                printf("\n");
                break;
                    
                case 3:
                    for(int aux2 = 0; aux2 < 5; aux2++) {
                        printf("cor4_");
                    }
                printf("\n");
                break;
            }
        }
    }
    printf("\n");
                case 9:
                mudaCor(WHITE, COR9);
                break;
            }
            printf(" ");
            printf("%d", tab->mat[i][j]);
            printf(" ");
            corNormal();
}

int main() {
    FILE *entrada;
    FILE *saida;
    entrada = fopen("palavras.txt", "r");
    saida = fopen("copia-das-palavras", "w");
    char *palavra_sorteada[6];

    if (entrada == NULL || saida == NULL) {
        printf("Erro no acesso aos arquivos.\n");
        exit(1);
    }
    
    palavra_t palavra;
    
    while (le_palavra(entrada)) {
        palavra_t *m = &lista_de_palavras[num_rand()];
        *palavra_sorteada = m->sem_acento;
        
        printf("Palavra sorteada: %s\n\n", *palavra_sorteada);
        tela_principal();
        
        if (!grava_palavra(saida, &palavra)) {
            printf("Problema na gravação.\n");
            break;
        }
        break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
 
#define NUM_PALAVRAS 15
#define CINZA 169,169,169   // SlateBlue
#define LARANJA 244,164,96   // DodgerBlue
#define VERDE 144,238,144    // ForestGreen
#define WHITE 255, 255, 255 // White
 
typedef struct {
    char sem_acento[6];
    char com_acento[16];
    bool usada;
} palavra_t;


palavra_t lista_de_palavras[NUM_PALAVRAS];

void mudaCor(int rl, int gl, int bl, int rf, int gf, int bf)
{
    printf("%c[38;2;%d;%d;%d;48;2;%d;%d;%dm", 27, rl, gl, bl, rf, gf, bf);
}

void corNormal(void)
{
    printf("%c[0m", 27);
}

int num_rand() {
    srand(time(NULL));
    int aux = rand() % NUM_PALAVRAS;
    return aux;
}

bool le_palavra(FILE *arquivo) {
    int i = 0;
    while (fscanf(arquivo, "%s%s", lista_de_palavras[i].sem_acento, lista_de_palavras[i].com_acento) == 2)
    ++i;
    return true;
}
 
bool grava_palavra(FILE *arquivo, palavra_t *p) {
    for (int i = 0; i < NUM_PALAVRAS; ++i) {
        palavra_t *m = &lista_de_palavras[i];
        fprintf(arquivo,"%s %s\n", m->sem_acento, m->com_acento);
    }
    return true;
}

void tela_principal(void) {
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 4; j++) {
            switch(j) {
                case 0:
                    for(int aux2 = 0; aux2 < 5; aux2++) {
                        mudaCor(WHITE, CINZA);
                        printf("   ");
                        corNormal();
                        printf(" ");
                    }
                printf("\n");
                break;
                    
                case 1:
                    for(int aux2 = 0; aux2 < 5; aux2++) {
                        mudaCor(WHITE, CINZA);
                        printf(" o ");
                        corNormal();
                        printf(" ");
                    }
                printf("\n");
                break;
                    
                case 2:
                    for(int aux2 = 0; aux2 < 5; aux2++) {
                        mudaCor(WHITE, CINZA);
                        printf("   ");
                        corNormal();
                        printf(" ");
                    }
                printf("\n");
                break;
                    
                case 3:
                    for(int aux2 = 0; aux2 < 5; aux2++) {
                        printf("    ");
                    }
                printf("\n");
                break;
            }
        }
    }
}

int main() {
    FILE *entrada;
    FILE *saida;
    entrada = fopen("palavras.txt", "r");
    saida = fopen("copia-das-palavras", "w");
    char *palavra_sorteada[6];

    if (entrada == NULL || saida == NULL) {
        printf("Erro no acesso aos arquivos.\n");
        exit(1);
    }
    
    palavra_t palavra;
    
    while (le_palavra(entrada)) {
        palavra_t *m = &lista_de_palavras[num_rand()];
        *palavra_sorteada = m->sem_acento;
        
        printf("Palavra sorteada: %s\n\n", *palavra_sorteada);
        tela_principal();
        
        if (!grava_palavra(saida, &palavra)) {
            printf("Problema na gravação.\n");
            break;
        }
        break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
 
#define NUM_PALAVRAS 15
#define CINZA 169,169,169   
#define LARANJA 244,164,96  
#define VERDE 144,238,144   
#define WHITE 255, 255, 255 

typedef struct {
    char sem_acento[6];
    char com_acento[16];
    bool usada;
} palavra_t;


palavra_t lista_de_palavras[NUM_PALAVRAS];

void mudaCor(int rl, int gl, int bl, int rf, int gf, int bf)
{
    printf("%c[38;2;%d;%d;%d;48;2;%d;%d;%dm", 27, rl, gl, bl, rf, gf, bf);
}

void corNormal()
{
    printf("%c[0m", 27);
}

int num_rand() {
    srand(time(NULL));
    int aux = rand() % NUM_PALAVRAS;
    return aux;
}

bool le_palavra(FILE *arquivo) {
    int i = 0;
    while (fscanf(arquivo, "%s%s", lista_de_palavras[i].sem_acento, lista_de_palavras[i].com_acento) == 2)
    ++i;
    return true;
}
 
bool grava_palavra(FILE *arquivo, palavra_t *p) {
    for (int i = 0; i < NUM_PALAVRAS; ++i) {
        palavra_t *m = &lista_de_palavras[i];
        fprintf(arquivo,"%s %s\n", m->sem_acento, m->com_acento);
    }
    return true;
}

void desenha(int aux) {
    switch(aux) {
        case 0:
            for(int aux2 = 0; aux2 < 5; aux2++) {
                mudaCor(WHITE, CINZA);
                printf("   ");
                corNormal();
                printf(" ");
            }
        printf("\n");
        break;
            
        case 1:
            for(int aux2 = 0; aux2 < 5; aux2++) {
                mudaCor(WHITE, CINZA);
                printf(" o ");
                corNormal();
                printf(" ");
            }
        printf("\n");
        break;
            
        case 2:
            for(int aux2 = 0; aux2 < 5; aux2++) {
                mudaCor(WHITE, CINZA);
                printf("   ");
                corNormal();
                printf(" ");
            }
        printf("\n");
        break;
            
        case 3:
            for(int aux2 = 0; aux2 < 5; aux2++) {
                printf("    ");
            }
        printf("\n");
        break;
    }
}

void tela_principal() {
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 4; j++) {
            desenha(j);
        }
    }
}

char* verificacao(char *palavra_sorteada[], char *palavra_chute[]) {
    if(*palavra_chute[] == *palavra_sorteada[]) {
        printf("UPU");
    }
    printf("Palavra chute: %s\n\n", *palavra_chute);
    printf("Palavra sorteada: %s\n\n", *palavra_sorteada);
    return "laura";
}

int main() {
    FILE *entrada;
    FILE *saida;
    entrada = fopen("palavras.txt", "r");
    saida = fopen("copia-das-palavras", "w");
    char *palavra_sorteada[5];
    char *palavra_chute[5];

    if (entrada == NULL || saida == NULL) {
        printf("Erro no acesso aos arquivos.\n");
        exit(1);
    }
    
    palavra_t palavra;
    
    while (le_palavra(entrada)) {
        palavra_t *m = &lista_de_palavras[num_rand()];
        *palavra_sorteada = m->sem_acento;
        printf("Palavra sorteada: '%s'\n\n", *palavra_sorteada);
        
        printf("Informe uma tentativa...");
        scanf("%s", *palavra_chute);
        
        verificacao(palavra_sorteada, palavra_chute);
        // tela_principal();
        
        if (!grava_palavra(saida, &palavra)) {
            printf("Problema na gravação.\n");
            break;
        }
        break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}






#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
 
#define NUM_PALAVRAS 15
#define CINZA 169,169,169   
#define LARANJA 244,164,96  
#define VERDE 144,238,144   
#define WHITE 255, 255, 255 

typedef struct {
    char sem_acento[6];
    char com_acento[16];
    bool usada;
} palavra_t;


palavra_t lista_de_palavras[NUM_PALAVRAS];

void mudaCor(int rl, int gl, int bl, int rf, int gf, int bf)
{
    printf("%c[38;2;%d;%d;%d;48;2;%d;%d;%dm", 27, rl, gl, bl, rf, gf, bf);
}

void corNormal()
{
    printf("%c[0m", 27);
}

int num_rand() {
    srand(time(NULL));
    int aux = rand() % NUM_PALAVRAS;
    return aux;
}

bool le_palavra(FILE *arquivo) {
    int i = 0;
    while (fscanf(arquivo, "%s%s", lista_de_palavras[i].sem_acento, lista_de_palavras[i].com_acento) == 2)
    ++i;
    return true;
}
 
bool grava_palavra(FILE *arquivo, palavra_t *p) {
    for (int i = 0; i < NUM_PALAVRAS; ++i) {
        palavra_t *m = &lista_de_palavras[i];
        fprintf(arquivo,"%s %s\n", m->sem_acento, m->com_acento);
    }
    return true;
}

void desenha(int aux, char dica, char letra_chute) {
    for(int aux2 = 0; aux2 < 5; aux2++) {
        if(aux == 0 || aux == 2) {
            mudaCor(WHITE, CINZA);
            printf("   ");
            corNormal();
            printf(" ");
        } else if(aux == 1) {
            mudaCor(WHITE, CINZA);
            printf(" %s ", letra_chute);
            corNormal();
            printf(" ");
        } else {
            printf("    ");
        }
    }
    printf("\n");
}

void tela_principal(char *dica[], char *palavra_chute[]) {
    printf("dica no desenho: '%s'\n\n", *dica);
    printf("Palavra chute: %s\n\n", *palavra_chute);

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 4; j++) {
            switch(aux) {
                case 0:
                    desenha(0, *dica[j], *palavra_chute[j]);
                break;
                    
                case 1:
                    desenha(1, *dica[j], *palavra_chute[j]);
                printf("\n");
                break;
                    
                case 2:
                    desenha(2, *dica[j], *palavra_chute[j]);
                printf("\n");
                break;
                    
                case 3:
                    desenha(3, *dica[j], *palavra_chute[j]);
                printf("\n");
                break;
            }
        }
    }
}

char* verificacao(char *palavra_sorteada[], char *palavra_chute[]) {

    int value = strcmp(*palavra_chute,*palavra_sorteada);
    if(value == 0) {
        return "ccccc";
    }
    // printf("Palavra chute: %s\n\n", *palavra_chute);
    // printf("Palavra sorteada: %s\n\n", *palavra_sorteada);
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
        palavra_t *m = &lista_de_palavras[num_rand()];
        *palavra_sorteada = m->sem_acento;
        printf("Palavra sorteada: '%s'\n\n", *palavra_sorteada);
        
        printf("Informe uma tentativa...");
        scanf("%s", *palavra_chute);
        
        verificacao(palavra_sorteada, palavra_chute);
        *dica = verificacao(palavra_sorteada, palavra_chute);
        
        tela_principal(dica, palavra_chute);
        
        if (!grava_palavra(saida, &palavra)) {
            printf("Problema na gravação.\n");
            break;
        }
        break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}
















#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
 
#define NUM_PALAVRAS 15
#define CINZA 169,169,169   
#define LARANJA 244,164,96  
#define VERDE 144,238,144   
#define WHITE 255, 255, 255 

typedef struct {
    char sem_acento[6];
    char com_acento[16];
    bool usada;
} palavra_t;


palavra_t lista_de_palavras[NUM_PALAVRAS];

void mudaCor(int rl, int gl, int bl, int rf, int gf, int bf)
{
    printf("%c[38;2;%d;%d;%d;48;2;%d;%d;%dm", 27, rl, gl, bl, rf, gf, bf);
}

void corNormal()
{
    printf("%c[0m", 27);
}

int num_rand() {
    srand(time(NULL));
    int aux = rand() % NUM_PALAVRAS;
    return aux;
}

bool le_palavra(FILE *arquivo) {
    int i = 0;
    while (fscanf(arquivo, "%s%s", lista_de_palavras[i].sem_acento, lista_de_palavras[i].com_acento) == 2)
    ++i;
    return true;
}
 
bool grava_palavra(FILE *arquivo, palavra_t *p) {
    for (int i = 0; i < NUM_PALAVRAS; ++i) {
        palavra_t *m = &lista_de_palavras[i];
        fprintf(arquivo,"%s %s\n", m->sem_acento, m->com_acento);
    }
    return true;
}

void desenha(int aux, char dica, char letra_chute) {
    // printf("Palavra chute: %c\n\n", letra_chute);
    for(int aux2 = 0; aux2 < 5; aux2++){
        if(aux == 0 || aux == 2) {
            mudaCor(WHITE, CINZA);
            printf("   ");
            corNormal();
            printf(" ");
        } 
        if(aux == 1) {
            mudaCor(WHITE, CINZA);
            printf(" %c ", letra_chute);
            corNormal();
            printf(" ");
        } 
        if(aux == 3){
            printf("    ");
        }
    }
    printf("\n");
}

void tela_principal(char *dica[], char *palavra_chute[]) {
    char aux_dica[5];
    char aux_chute[5];
    strcpy(aux_dica, *dica);
    strcpy(aux_chute, *palavra_chute);
    
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 4; j++) {
            desenha(j, aux_dica[j], aux_chute[j]);
        }
    }
}

char* verificacao(char *palavra_sorteada[], char *palavra_chute[]) {

    int value = strcmp(*palavra_chute,*palavra_sorteada);
    if(value == 0) {
        return "ccccc";
    }
    // printf("Palavra chute: %s\n\n", *palavra_chute);
    // printf("Palavra sorteada: %s\n\n", *palavra_sorteada);
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
        palavra_t *m = &lista_de_palavras[num_rand()];
        *palavra_sorteada = m->sem_acento;
        printf("Palavra sorteada: '%s'\n\n", *palavra_sorteada);
        
        printf("Informe uma tentativa...");
        scanf("%s", *palavra_chute);
        
        verificacao(palavra_sorteada, palavra_chute);
        *dica = verificacao(palavra_sorteada, palavra_chute);
        
        tela_principal(dica, palavra_chute);
        
        if (!grava_palavra(saida, &palavra)) {
            printf("Problema na gravação.\n");
            break;
        }
        break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
 
#define NUM_PALAVRAS 15
#define CINZA 169,169,169   
#define LARANJA 244,164,96  
#define VERDE 144,238,144   
#define WHITE 255, 255, 255 

typedef struct {
    char sem_acento[6];
    char com_acento[16];
    bool usada;
} palavra_t;


palavra_t lista_de_palavras[NUM_PALAVRAS];

void mudaCor(int rl, int gl, int bl, int rf, int gf, int bf)
{
    printf("%c[38;2;%d;%d;%d;48;2;%d;%d;%dm", 27, rl, gl, bl, rf, gf, bf);
}

void corNormal()
{
    printf("%c[0m", 27);
}

int num_rand() {
    srand(time(NULL));
    int aux = rand() % NUM_PALAVRAS;
    return aux;
}

bool le_palavra(FILE *arquivo) {
    int i = 0;
    while (fscanf(arquivo, "%s%s", lista_de_palavras[i].sem_acento, lista_de_palavras[i].com_acento) == 2)
    ++i;
    return true;
}
 
bool grava_palavra(FILE *arquivo, palavra_t *p) {
    for (int i = 0; i < NUM_PALAVRAS; ++i) {
        palavra_t *m = &lista_de_palavras[i];
        fprintf(arquivo,"%s %s\n", m->sem_acento, m->com_acento);
    }
    return true;
}

void tela_principal(char *dica[], char *palavra_chute[]) {
    char aux_dica[5];
    char aux_chute[5];
    strcpy(aux_dica, *dica);
    strcpy(aux_chute, *palavra_chute);
    
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 4; j++) {
            for(int aux = 0; aux < 5; aux++) {
                if(j == 0 || j == 2) {
                    switch(aux_dica[aux]) {
                        case 'c':
                            mudaCor(WHITE, CINZA);
                            break;
                        case 'l':
                            mudaCor(WHITE, LARANJA);
                            break;
                        case 'v':
                            mudaCor(WHITE, VERDE);
                            break;
                    }
                    printf("   ");
                    corNormal();
                    printf(" ");
                } 
                if(j == 1) {
                    switch(aux_dica[aux]) {
                        case 'c':
                            mudaCor(WHITE, CINZA);
                            break;
                        case 'l':
                            mudaCor(WHITE, LARANJA);
                            break;
                        case 'v':
                            mudaCor(WHITE, VERDE);
                            break;
                    }
                    printf(" %c ", aux_chute[aux]);
                    corNormal();
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

    int value = strcmp(*palavra_chute,*palavra_sorteada);
    if(value == 0) {
        return "ccccc";
    }
    // printf("Palavra chute: %s\n\n", *palavra_chute);
    // printf("Palavra sorteada: %s\n\n", *palavra_sorteada);
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
        palavra_t *m = &lista_de_palavras[num_rand()];
        *palavra_sorteada = m->sem_acento;
        printf("Palavra sorteada: '%s'\n\n", *palavra_sorteada);
        
        printf("Informe uma tentativa...");
        scanf("%s", *palavra_chute);
        
        verificacao(palavra_sorteada, palavra_chute);
        *dica = verificacao(palavra_sorteada, palavra_chute);
        
        tela_principal(dica, palavra_chute);
        
        if (!grava_palavra(saida, &palavra)) {
            printf("Problema na gravação.\n");
            break;
        }
        break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}