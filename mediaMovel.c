#include <stdio.h>
#include <stdbool.h>

#define VERMELHO 255, 0, 0, 0, 0, 0
#define AMARELO  255, 165, 0, 0, 0, 0
#define VERDE    50, 205, 50, 0, 0, 0

int verificarFile(FILE *aux) {
    if (aux == NULL) { 
        printf("Não foi possível abrir o arquivo\n");
        return 5;
    }
}

void coloracaoAlterada(int rl, int gl, int bl, int rf, int gf, int bf) {
    printf("%c[38;2;%d;%d;%d;48;2;%d;%d;%dm", 27, rl, gl, bl, rf, gf, bf);

    if(rl == 255) {
        if(gl == 0) {
            printf("em alta");
        } else {
            printf("estável");
        }
    } else {
        printf("em queda");
    }
    
    printf("%c[0m", 27);
}

int mediaMovelFunc(int aux[]) {
    int mediaMovelAux = 0;
    
    for(int i=0; i<7; i++) {
        mediaMovelAux += aux[i];
    }

    return mediaMovelAux/7;
}

void analiseTendencia(int mediaMovelValoresAntes, int ultimaMediaMovel) {
    if(ultimaMediaMovel > (mediaMovelValoresAntes*1.15)) {
        coloracaoAlterada(VERDE);
    } else if(ultimaMediaMovel < (mediaMovelValoresAntes*0.85)) {
        coloracaoAlterada(VERMELHO);
    } else {
        coloracaoAlterada(AMARELO);
    } 
}

int main() {
    int tendencia[14], mediaMovel[7], obitosDia = 0, obitosAnteriores = 0, obitosDiferenca = 0, aux = 0, aux2 = 0;
    
    FILE *obitosFile = fopen("obitos.txt", "r");
    verificarFile(obitosFile);
    
    while(true) {
        fscanf(obitosFile, "%d", &obitosDia);
        
        obitosDiferenca = obitosDia - obitosAnteriores;
        
        if(aux<6) {        
            mediaMovel[aux] = obitosDia;
            printf("[%d] --- ---\n", obitosDia);
        } else if (aux==6) {
            mediaMovel[aux] = obitosDia;
            printf("[%d] %d ", obitosDia, mediaMovelFunc(mediaMovel));
        } else {
            if(aux2<6) {
                mediaMovel[aux2] = obitosDia;
                
                if(aux>=20) {
                    for(int aux2=0; aux2<14; aux2++) {
                        if((aux2+1)<14){
                            tendencia[aux2] = tendencia[aux2+1];
                        }
                    }
                    
                    tendencia[13] = obitosDiferenca;
                    analiseTendencia(mediaMovelFunc(mediaMovel), tendencia[0]);
                    printf(" [%d->%d]\n", obitosAnteriores, obitosDia);
                } else {
                    printf("---\n");
                }
                
                if (feof(obitosFile)) {
                    break;
                }   
                
                printf("[%d] %d ", obitosDia,  mediaMovelFunc(mediaMovel));
                aux2++;
            } else if(aux2==6) {
                aux2 = 0;
            }
        }

        obitosAnteriores = obitosDia;
        aux++;
    }
    
    fclose(obitosFile);
    return 0;
}
