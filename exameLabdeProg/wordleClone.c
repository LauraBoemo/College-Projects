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
    static char aux_retorno_dica[5];
    char aux_sorteio[5];
    char aux_chute[5];
    strcpy(aux_sorteio, *palavra_sorteada);
    strcpy(aux_chute, *palavra_chute);
    
    for(int i = 0; i < 5; i++) {
        if(aux_chute[i] == aux_sorteio[i]) {
            aux_retorno_dica[i] = 'v';
        } else if(aux_chute[i] != aux_sorteio[i]) {
            aux_retorno_dica[i] = 'c';
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
#define CINZA 169, 169, 169   
#define LARANJA 230, 126, 34 
#define VERDE 39, 174, 96   
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
#define CINZA 169, 169, 169   
#define LARANJA 230, 126, 34 
#define VERDE 39, 174, 96   
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
    int aux_tentativas = 0;
    
    while (le_palavra(entrada)) {
        palavra_t *m = &lista_de_palavras[num_rand()];
        *palavra_sorteada = m->sem_acento;
        printf("Palavra sorteada: '%s'\n\n", *palavra_sorteada);
        
        printf("Informe uma tentativa...");
        scanf("%s", *palavra_chute);
        
        verificacao(palavra_sorteada, palavra_chute);
        *dica = verificacao(palavra_sorteada, palavra_chute);
        
        tela_principal(dica, palavra_chute, aux_tentativas);
        
        aux_tentativas++;
        if(aux_tentativas == 5) {
            printf("opa opa oap");
        }
        if (!grava_palavra(saida, &palavra)) {
            printf("Problema na gravação.\n");
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
#include <time.h>
 
#define NUM_PALAVRAS 15
#define CINZA 169, 169, 169   
#define LARANJA 230, 126, 34 
#define VERDE 39, 174, 96   
#define WHITE 255, 255, 255 

typedef struct {
    char sem_acento[6];
    char com_acento[16];
    bool usada;
} palavra_t;

typedef struct {
  palavra_t sorteada;     
  int nchutes;            
  chute_t chutes[6];      
  char letras_usadas[26]; 
} partida_t;

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

        *palavra_sorteada = gerar_palavra_aleatoria();
        *auxiliar_sorteada = gerar_palavra_auxiliar(palavra_sorteada);
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
        
        palavra_t *m = &lista_de_palavras[num_rand()];
        *palavra_sorteada = m->sem_acento;
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

typedef struct {
 char letras[5]; 
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
    // *palavra_sorteada = m->sem_acento;
    for(int i = 0; i < 6; i++) {
        partida->sorteada.sem_acento[i] = m->sem_acento[i];
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

void tela_principal(chute_t *chute, partida_t *partida) {
    for(int i = 0; i < partida->nchutes + 1; i++){
        for(int j = 0; j < 4; j++) {
            for(int aux = 0; aux < 5; aux++) {
                if(j == 0 || j == 2) {
                    switch(chute -> dicas[aux]) {
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
                    switch(chute -> dicas[aux]) {
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
                    printf(" %c ", chute -> letras[aux]);
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

char* verificacao(chute_t *chute, partida_t *partida) {
    for(int i = 0; i < 5; i++) {
        if(chute->letras[i] != partida->sorteada.sem_acento[i]) {
            chute->dicas[i] = 'c';
        }
        
        for(int j = 0; j < 5; j++) {
            if(chute->letras[i] == partida->sorteada.sem_acento[j]) {
                chute->dicas[i] = 'l';
            }
        }
        
        if(chute->letras[i] == partida->sorteada.sem_acento[i]) {
            chute->dicas[i] = 'v';
        } 
    }
    
    return chute->dicas;
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
    
    chute_t chute;
    partida_t partida;
    palavra_t palavra;
    
    while (le_palavra(entrada)) {
        gerar_palavra_aleatoria(&partida);
        printf("\n\n%s", partida.sorteada.sem_acento);
        
        if (!grava_palavra(saida, &palavra)) {
            printf("Problema na gravação.\n");
            break;
        }
        
        for(partida.nchutes = 0; partida.nchutes < 6; partida.nchutes++) {
            printf("Informe uma tentativa...");
            scanf("%s", chute.letras);
            
            verificacao(&chute, &partida);
            tela_principal(&chute, &partida);
        }
        
        break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}








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
    // *palavra_sorteada = m->sem_acento;
    for(int i = 0; i < 6; i++) {
        partida->sorteada.sem_acento[i] = m->sem_acento[i];
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

/*-----------------------------------------------------------------------------*/
/* Corpo da função - tela_principal                                            */
/*                                                                             */
/* Função que desenha na tela as palavras conforme suas devidas cores          */
/* indicadas.                                                                  */
/*-----------------------------------------------------------------------------*/

void tela_principal(chute_t *chute, partida_t *partida) {
    
    
    
    
    for(int i = 0; i < partida->nchutes + 1; i++){
        for(int j = 0; j < 4; j++) {
            for(int aux = 0; aux < 5; aux++) {
                if(j == 0 || j == 2) {
                    switch(chute -> dicas[aux]) {
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
                    switch(chute -> dicas[aux]) {
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
                    printf(" %c ", chute -> letras[aux]);
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

/*-----------------------------------------------------------------------------*/
/* Corpo da função - verificacao                                               */
/*                                                                             */
/* Função que verifica a relação do chute com a palavra real, assim            */
/* gerando a string de dicas.                                                  */
/*-----------------------------------------------------------------------------*/

char* verificacao(chute_t *chute, partida_t *partida) {
    strcpy(chute->letras, chute->palavra.sem_acento);
    int aux = 0;
    
    for(int i = 0; i < 5; i++) {
        if(chute->letras[i] != partida->sorteada.sem_acento[i]) {
            chute->dicas[i] = 'c';
        }
        
        for(int j = 0; j < 5; j++) {
            if(chute->letras[i] == partida->sorteada.sem_acento[j]) {
                chute->dicas[i] = 'l';
            }
        }
        
        if(chute->letras[i] == partida->sorteada.sem_acento[i]) {
            chute->dicas[i] = 'v';
            aux++;
        } 
        
        partida->chutes[partida->nchutes].palavra.sem_acento[i] = chute->palavra.sem_acento[i];
        // printf("\n%c\n", partida->chutes[partida->nchutes].palavra.sem_acento[i]);
    }
    
    if(aux == 5) {
        chute->correto = true;
    } else {
        chute->correto = false;
    }
    
    
    return chute->dicas;
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
    
    chute_t chute;
    partida_t partida;
    palavra_t palavra;
    
    while (le_palavra(entrada)) {
        gerar_palavra_aleatoria(&partida);
        printf("\n\n%s", partida.sorteada.sem_acento);
        
        if (!grava_palavra(saida, &palavra)) {
            printf("Problema na gravação.\n");
            break;
        }
        
        for(partida.nchutes = 0; partida.nchutes < 6; partida.nchutes++) {
            printf("Informe uma tentativa...");
            scanf("%s", chute.palavra.sem_acento);
            
            verificacao(&chute, &partida);
            tela_principal(&chute, &partida);
            
            if(chute.correto) {
                printf("UOUUU");
                        // printf("\n%c", partida.chutes[0].palavra.sem_acento[0]);
                break;
            }
        }
        
        break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}




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
    // *palavra_sorteada = m->sem_acento;
    for(int i = 0; i < 6; i++) {
        partida->sorteada.sem_acento[i] = m->sem_acento[i];
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
                    switch(chute -> dicas[aux]) {
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
                    switch(chute -> dicas[aux]) {
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

/*-----------------------------------------------------------------------------*/
/* Corpo da função - verificacao                                               */
/*                                                                             */
/* Função que verifica a relação do chute com a palavra real, assim            */
/* gerando a string de dicas.                                                  */
/*-----------------------------------------------------------------------------*/

char* verificacao(chute_t *chute, partida_t *partida) {
    strcpy(chute->letras, chute->palavra.sem_acento);
    int aux = 0;
    
    for(int i = 0; i < 5; i++) {
        if(chute->letras[i] != partida->sorteada.sem_acento[i]) {
            chute->dicas[i] = 'c';
        }
        
        for(int j = 0; j < 5; j++) {
            if(chute->letras[i] == partida->sorteada.sem_acento[j]) {
                chute->dicas[i] = 'l';
            }
        }
        
        if(chute->letras[i] == partida->sorteada.sem_acento[i]) {
            chute->dicas[i] = 'v';
            aux++;
        } 
        
        partida->chutes[partida->nchutes].palavra.sem_acento[i] = chute->palavra.sem_acento[i];
        // printf("\n%c\n", partida->chutes[partida->nchutes].palavra.sem_acento[i]);
    }
    
    if(aux == 5) {
        chute->correto = true;
    } else {
        chute->correto = false;
    }
    
    
    return chute->dicas;
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
            printf("Informe uma tentativa...");
            scanf("%s", chute.palavra.sem_acento);
            
            verificacao(&chute, &partida);
            tela_principal(&chute, &partida);
            
            if(chute.correto) {
                printf("UOUUU");
                    // printf("\n%c", partida.chutes[0].palavra.sem_acento[0]);
                break;
            }
        }
        
        break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}















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
    // *palavra_sorteada = m->sem_acento;
    for(int i = 0; i < 6; i++) {
        partida->sorteada.sem_acento[i] = m->sem_acento[i];
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
                    switch(partida->chutes[i].dicas[aux]) {
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
                    switch(partida->chutes[i].dicas[aux]) {
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

/*-----------------------------------------------------------------------------*/
/* Corpo da função - verificacao                                               */
/*                                                                             */
/* Função que verifica a relação do chute com a palavra real, assim            */
/* gerando a string de dicas.                                                  */
/*-----------------------------------------------------------------------------*/

char* verificacao(chute_t *chute, partida_t *partida) {
    strcpy(chute->letras, chute->palavra.sem_acento);
    int aux = 0;
    
    for(int i = 0; i < 5; i++) {
        if(chute->letras[i] != partida->sorteada.sem_acento[i]) {
            chute->dicas[i] = 'c';
        }
        
        for(int j = 0; j < 5; j++) {
            if(chute->letras[i] == partida->sorteada.sem_acento[j]) {
                chute->dicas[i] = 'l';
            }
        }
        
        if(chute->letras[i] == partida->sorteada.sem_acento[i]) {
            chute->dicas[i] = 'v';
            aux++;
        } 
        
        partida->chutes[partida->nchutes].palavra.sem_acento[i] = chute->palavra.sem_acento[i];
        partida->chutes[partida->nchutes].dicas[i] = chute->dicas[i];
        // printf("\n%c\n", partida->chutes[partida->nchutes].palavra.sem_acento[i]);
    }
    
    if(aux == 5) {
        chute->correto = true;
    } else {
        chute->correto = false;
    }
    
    
    return chute->dicas;
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
            printf("Informe uma tentativa...");
            scanf("%s", chute.palavra.sem_acento);
            
            verificacao(&chute, &partida);
            tela_principal(&chute, &partida);
            
            if(chute.correto) {
                printf("UOUUU");
                    // printf("\n%c", partida.chutes[0].palavra.sem_acento[0]);
                break;
            }
        }
        
        break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}












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
    // *palavra_sorteada = m->sem_acento;
    for(int i = 0; i < 6; i++) {
        partida->sorteada.sem_acento[i] = m->sem_acento[i];
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

/*-----------------------------------------------------------------------------*/
/* Corpo da função - verificacao                                               */
/*                                                                             */
/* Função que verifica a relação do chute com a palavra real, assim            */
/* gerando a string de dicas.                                                  */
/*-----------------------------------------------------------------------------*/

char* verificacao(chute_t *chute, partida_t *partida) {
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
            printf("Informe uma tentativa...");
            scanf("%s", chute.palavra.sem_acento);
            
            verificacao(&chute, &partida);
            tela_principal(&chute, &partida);
            
            if(chute.correto) {
                printf("UOUUU");
                break;
            }
        }
        
        break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}

for(partida.nchutes = 0; partida.nchutes < 6; partida.nchutes++) {
            printf("Informe uma tentativa...");
            scanf("%s", chute.palavra.sem_acento);
            
            if(verificacao(&chute, &partida) == "tamanhoExcedido") {
                printf("\n\n=== ATENÇÃO ===\nA palavra deve conter no mínimo e no máximo, 5 caracteres. Insira novamente.\n===============\n\n");
                partida.nchutes--;
            } else if(verificacao(&chute, &partida) == "palavraInexistente") { 
                printf("\n\n=== ATENÇÃO ===\nA palavra precisa ser existente. Insira novamente.\n===============\n\n");
                partida.nchutes--;
            } else {
                tela_principal(&chute, &partida);
                if(chute.correto) {
                    printf("UOUUU");
                    break;
                }
            }
        }


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
    // *palavra_sorteada = m->sem_acento;
    for(int i = 0; i < 6; i++) {
        partida->sorteada.sem_acento[i] = m->sem_acento[i];
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

/*-----------------------------------------------------------------------------*/
/* Corpo da função - verificacao                                               */
/*                                                                             */
/* Função que verifica a relação do chute com a palavra real, assim            */
/* gerando a string de dicas.                                                  */
/*-----------------------------------------------------------------------------*/

char* verificacao_palavra(chute_t *chute) {
    int aux_verificador = 0;
    
    if(strlen(chute->palavra.sem_acento) != 5) {
        return "tamanhoExcedido";
    }
    
    for(int b = 0; b < NUM_PALAVRAS; b++) {
        palavra_t *m = &lista_de_palavras[b];
        if(strcmp(chute->palavra.sem_acento, m->sem_acento) == 0) {
            aux_verificador++;
        } 
    }
    
    if(aux_verificador == 0) {
        return "palavraInexistente";
    } 
}

char* verificacao(chute_t *chute, partida_t *partida) {
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
            printf("Informe uma tentativa...");
            scanf("%s", chute.palavra.sem_acento);
            
            if(verificacao(&chute, &partida) == "tamanhoExcedido") {
                printf("\n\n=== ATENÇÃO ===\nA palavra deve conter no mínimo e no máximo, 5 caracteres. Insira novamente.\n===============\n\n");
                partida.nchutes--;
            } else if(verificacao(&chute, &partida) == "palavraInexistente") { 
                printf("\n\n=== ATENÇÃO ===\nA palavra precisa ser existente. Insira novamente.\n===============\n\n");
                partida.nchutes--;
            } else {
                tela_principal(&chute, &partida);
                if(chute.correto) {
                    printf("UOUUU");
                    break;
                }
            }
        }
        
        break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}















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
    // *palavra_sorteada = m->sem_acento;
    for(int i = 0; i < 6; i++) {
        partida->sorteada.sem_acento[i] = m->sem_acento[i];
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

/*-----------------------------------------------------------------------------*/
/* Corpo da função - verificacao                                               */
/*                                                                             */
/* Função que verifica a relação do chute com a palavra real, assim            */
/* gerando a string de dicas.                                                  */
/*-----------------------------------------------------------------------------*/

int verificacao_palavra(chute_t *chute) {
    int aux_verificador = 0;
    
    if(strlen(chute->palavra.sem_acento) != 5) {
        return 1;
    }
    
    for(int b = 0; b < NUM_PALAVRAS; b++) {
        palavra_t *m = &lista_de_palavras[b];
        if(strcmp(chute->palavra.sem_acento, m->sem_acento) == 0) {
            aux_verificador++;
        } 
    }
    
    if(aux_verificador == 0) {
        return 2;
    } 
    
    return 3;
}

char* verificacao_dicas(chute_t *chute, partida_t *partida) {
    strcpy(chute->letras, chute->palavra.sem_acento);
    int aux = 0;
    
    if(verificacao_palavra(chute) == 3) {
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
    } else if (verificacao_palavra(chute) == 1) {
        return "tamanhoExcedido";
    } else if (verificacao_palavra(chute) == 2) {
        return "palavraInexistente";
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
            printf("Informe uma tentativa...");
            scanf("%s", chute.palavra.sem_acento);
            
            if(verificacao_dicas(&chute, &partida) == "tamanhoExcedido") {
                printf("\n\n=== ATENÇÃO ===\nA palavra deve conter no mínimo e no máximo, 5 caracteres. Insira novamente.\n===============\n\n");
                partida.nchutes--;
            } else if(verificacao_dicas(&chute, &partida) == "palavraInexistente") { 
                printf("\n\n=== ATENÇÃO ===\nA palavra precisa ser existente. Insira novamente.\n===============\n\n");
                partida.nchutes--;
            } else {
                tela_principal(&chute, &partida);
                if(chute.correto) {
                    printf("UOUUU");
                    break;
                }
            }
        }
        
        break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}


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
                
#define erroChute1   '\n\n=== ATENÇÃO ===\nA palavra deve conter no mínimo e no máximo, 5 caracteres. Insira novamente.\n===============\n\n'
#define erroChute2   '\n\n=== ATENÇÃO ===\nA palavra precisa ser existente. Insira novamente.\n===============\n\n'
#define chuteCorreto 'Chute correto'

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
    // *palavra_sorteada = m->sem_acento;
    for(int i = 0; i < 6; i++) {
        partida->sorteada.sem_acento[i] = m->sem_acento[i];
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

/*-----------------------------------------------------------------------------*/
/* Corpo da função - verificacao                                               */
/*                                                                             */
/* Função que verifica a relação do chute com a palavra real, assim            */
/* gerando a string de dicas.                                                  */
/*-----------------------------------------------------------------------------*/

char* verificacao_chute(chute_t *chute) {
    int aux_verificador = 0;
    
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
            printf("Informe uma tentativa...");
            scanf("%s", chute.palavra.sem_acento);
            
            if(verificacao_chute(&chute) == erroChute1) {
                printf(erroChute1);
                partida.nchutes--;
            } else if(verificacao_chute(&chute) == erroChute2) {
                printf(erroChute2);
                partida.nchutes--;
            } else {
                if(verificacao_dicas(&chute, &partida) == "tamanhoExcedido") {
                    printf("\n\n=== ATENÇÃO ===\nA palavra deve conter no mínimo e no máximo, 5 caracteres. Insira novamente.\n===============\n\n");
                    partida.nchutes--;
                } else if(verificacao_dicas(&chute, &partida) == "palavraInexistente") { 
                    printf("\n\n=== ATENÇÃO ===\nA palavra precisa ser existente. Insira novamente.\n===============\n\n");
                    partida.nchutes--;
                } else {
                    tela_principal(&chute, &partida);
                    if(chute.correto) {
                        printf("UOUUU");
                        break;
                    }
                }
            }
        }
        
        break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}





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
    // *palavra_sorteada = m->sem_acento;
    for(int i = 0; i < 6; i++) {
        partida->sorteada.sem_acento[i] = m->sem_acento[i];
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
            printf("Informe uma tentativa...");
            scanf("%s", chute.palavra.sem_acento);
            
            if(verificacao_chute(&chute) == erroChute1) {
                printf(erroChute1);
                partida.nchutes--;
            } else if(verificacao_chute(&chute) == erroChute2) {
                printf(erroChute2);
                partida.nchutes--;
            } else if(verificacao_chute(&chute) == erroChute3) {
                printf(erroChute3);
                break;
            } else {
                verificacao_dicas(&chute, &partida);
                tela_principal(&chute, &partida);
                
                if(chute.correto) {
                    printf("UOUUU");
                    break;
                }
            }
        }
        
        break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}





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

void finaliza_jogo(bool status_final, chute_t *chute, partida_t *partida) {
    char reiniciar[1];
    
    if(status_final) {
        printf("=== TU ÉS VENCEDOR ==\nPalavra original: %c%c%c%c%c\nQuantidade de tentativas: %i\n", partida->sorteada.com_acento[0], partida->sorteada.com_acento[1], partida->sorteada.com_acento[2], partida->sorteada.com_acento[3], partida->sorteada.com_acento[4], partida->nchutes + 1);
    } else {
        printf("=== TU ÉS PERDEDOR ==\nPalavra original: %c%c%c%c%c\n", partida->sorteada.com_acento[0], partida->sorteada.com_acento[1], partida->sorteada.com_acento[2], partida->sorteada.com_acento[3], partida->sorteada.com_acento[4]);
    }
    
    printf("Desejas jogar novamente? s/n");
    scanf("%s", reiniciar);

    if(*reiniciar == 's') {
        printf("bo de novo");
    } else if (*reiniciar == 'n') {
        printf("byeee");
    } else {
        printf("informa direito merda");
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
            printf("Informe uma tentativa...");
            scanf("%s", chute.palavra.sem_acento);
            
            if(verificacao_chute(&chute) == erroChute1) {
                printf(erroChute1);
                partida.nchutes--;
            } else if(verificacao_chute(&chute) == erroChute2) {
                printf(erroChute2);
                partida.nchutes--;
            } else if(verificacao_chute(&chute) == erroChute3) {
                printf(erroChute3);
                break;
            } else {
                verificacao_dicas(&chute, &partida);
                tela_principal(&chute, &partida);
                
                if(chute.correto) {
                    finaliza_jogo(1, &chute, &partida);
                    break;
                }
            }
        }
        if( partida.nchutes == 6) {
            finaliza_jogo(0, &chute, &partida);
        }

        break;
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}