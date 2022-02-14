// Parte III - Registro de maiores pontuações

// A pontuação no jogo é o número de rodadas necessárias para preencher o tabuleiro todo da mesma cor.
// -- Necessidade de um auxiliar contador para cada vez que o laço de inserir cor for ativado por partida

//  O jogo deve guardar em um arquivo
// -- No início do jogo, deve ser criado um arquivo 

//  as 3 melhores pontuações já obtidas em cada configuração (tamanho do tabuleiro, número de cores), junto com as iniciais do jogador.
// Aqui também vamos ter que armazenar o nome do jogador (5 LETRAS MO MAXIMO) (junto com tamanho tabuleiro e numero de cores - mas creio que isso já tenha sido setado) ao iniciar a partida
// -- TAMANHOTABULEIRO NUMEROCORES INICIAISDOJOGADOR

// O formato desse arquivo é de um registro de pontuação por linha, contendo 3 inteiros e uma sequência de letras em cada linha, separados por espaço. Os 3 inteiros são o tamanho do tabuleiro, o número de cores, o número de jogadas até o final do jogo; a sequência de letras são as iniciais do jogador (5 letras no máximo). 

// O arquivo não deve conter mais de 3 (mas pode conter menos, inclusive 0) linhas com a mesma configuração (mesmo tamanho de tabuleiro e número de cores). 
// -- 0? Ou seja, o arquivo pode não ter nada, mas se passar de 3 a gente vai substituindo 

// O arquivo pode conter mais de uma linha com resultados empatados. Abaixo exemplo de conteúdo do arquivo de recordes:

//   5 4 6 JBJ
//   7 5 19 asm
//   7 5 12 asm

// -- Nice

// Quando uma partida é terminada, o programa deve mostrar os registros de recorde existentes no arquivo para a mesma configuração, em ordem de pontuação, juntamente com a pontuação obtida.
// -- Ou seja, vou ter que fazer uma função que extraia os valores do arquivo e os coloque em ordem 

//  Se houverem 3 registros gravados para a configuração e a pontuação obtida for pior ou igual ao pior desses 3 registros, o programa informa ao usuário e pergunta se quer jogar uma nova partida. Caso contrário, antes de fazer isso o programa pergunta as iniciais ao jogador e atualiza o arquivo de recordes.
// -- OU seja, antes de armazenar algo no arquvio e solicitar o nome, o usuário tem a condiução de jogar novamente  

// Como ler o arquivo de recordes
// Faça uma função que recebe como argumento a configuração a ler (tamanho do tabuleiro e número de cores), lê o arquivo, ignora as linhas que contiverem configurações diferentes, e retorna o número de linhas encontradas, além da pontuação e iniciais de cada uma delas.

// Como atualizar o arquivo de recordes
// Faça uma função que recebe a configuração, o número de linhas a gravar para essa configuração e a pontuação e iniciais de cada uma delas. A função então abre 2 arquivos: o de recordes, para leitura e um arquivo temporário, para gravação. Ela lê cada linha do arquivo de recordes, e se for de configuração diferente, grava a mesma linha no arquivo de saída; se for de configuração igual, ignora a linha. Quando chegar no final do arquivo de recordes, a função grava no arquivo temporário as pontuações recebidas. Fecha os dois arquivos e renomeia o arquivo temporário para ter o nome do arquivo de recordes. Essa operação irá substituir o arquivo de recordes pelo temporário. Para renomear o arquivo, use a função rename (está no stdio.h):

//    rename("nome_velho", "nome_novo");
// A função rename retorna um inteiro, com o valor 0 se deu certo e -1 se houve algum problema; você pode usar essa informação para dar uma mensagem de desalento ao usuário.

// Monocor - Laura B. - 14-02-2022

// OBJETIVO GERAL 

// Neste trabalho, você vai implementar um jogo cujo objetivo é preencher o tabuleiro, inicialmente colorido, 
// com uma única cor. O tabuleiro é um quadrado, composto por NxN quadradinhos coloridos. A cada jogada, você 
// pode escolher a cor do quadrado superior esquerdo, o que irá pintar toda a região conectada a ele que estiver 
// na mesma cor para a cor escolhida. O jogo termina quando todo o tabuleiro estiver na mesma cor; seu escore
// é definido pelo número de jogadas necessárias para isso. É uma reimplementação do jogo "flood it" ou "color flood".

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define VERMELHO      0, 0, 0, 250, 128, 114
#define LIGHTPINK     0, 0, 0, 255, 182, 193
#define AZULPASTEL    0, 0, 0, 173, 216, 230
#define MARROMLIGHT   0, 0, 0, 222, 184, 135
#define ROSAESCURIO   0, 0, 0, 188, 143, 143
#define LARANJA       0, 0, 0, 255, 218, 185
#define MUSGO         0, 0, 0, 238, 232, 170
#define VERDE         0, 0, 0, 102, 205, 170
#define AMARELO       0, 0, 0, 255, 215, 0

// O tabuleiro será armazenado em um registro com o tipo definido abaixo 
typedef struct {
    int tam;             // Tamanho do tabuleiro (um quadrado com "tam" casas de lado) (entre 3 e 20)
    int ncor;            // Numero de cores usadas (valores entre 1 e "ncor") (entre 3 e 9)
    int matriz[22][22];  // Matriz com o estado atual do tabuleiro
} tabuleiro;

//  As posições da matriz não usadas pelo tabuleiro serão preenchidas pelo número 0. A primeira posição do tabuleiro será 
// colocada na posição 1,1 da matriz, de modo que em volta de todo o tabuleiro tem pelo menos uma posição livre na matriz.
bool ta_fora(tabuleiro *tabuleiro, int linha, int coluna) {
    if (linha < 1 || coluna < 1 || linha > tabuleiro->tam || coluna > tabuleiro->tam) return true;
    return false;
}

int numero_aleatorio_entre(int inf, int sup) {
    return inf + rand()%(sup-inf+1);
}

// Inicializa o tabuleiro apontado por "tab", para ter o tamanho e o número de cores fornecidas.
// Retorna true se tudo ok e false em caso de problema (os problemas possíveis são tam ou ncor
// não estarem de acordo com as restrições)
// A matriz deve ser inicializada com números aleatórios entre 1 e ncor na região do tabuleiro 
// e com 0 no restante.
bool tab_inic(tabuleiro *tabuleiro, int tam, int ncor) {
    tabuleiro->tam = tam;
    tabuleiro->ncor = ncor;
    
    // Suportaremos tabuleiros entre 3x3 e 20x20 entre 3 e 9 cores diferentes. 
    if(tabuleiro->tam < 3 || tabuleiro->tam > 20 || tabuleiro->ncor < 3 ||  tabuleiro->ncor > 9){
        return false;
    }
    
    for (int linha=0; linha<=tam+1; linha++) {
        for (int coluna=0; coluna<=tam+1; coluna++) {
            // Explicação acima da fubção ta_fora
            if (ta_fora(tabuleiro, linha, coluna)) {
                // As posições da matriz não usadas pelo tabuleiro serão preenchidas pelo número 0
                tabuleiro->matriz[linha][coluna] = 0;
            } else {
                // O programa todo funcionará baseado nesses números, que somente serão
                // traduzidos em cores para a apresentação do tabuleiro na tela
                tabuleiro->matriz[linha][coluna] = numero_aleatorio_entre(1, ncor);
            }
        }
    }
    
    return true;
}

// Alterando o fundo de alguma posição conforme o número que ela armazena
void muda_cor(int rl, int gl, int bl, int rf, int gf, int bf) {
  printf("%c[38;2;%d;%d;%d;48;2;%d;%d;%dm", 27, rl, gl, bl, rf, gf, bf);
}

// Limpando a posição 
void cor_normal(void) {
  printf("%c[0m", 27);
}

// Desenha o tabuleiro apontado por "tab".
// Deve ser desenhado somente a parte da matriz que contém o tabuleiro.
// Cada posição do tabuleiro deve ser desenhada com 3 caracteres: 
// um espaço, um dígito correspondente à cor e outro espaço.
// Os 3 caracteres devem ser desenhados com a cor de fundo correspondente à cor representada pelo dígito.
// Para selecionar a cor, use as funções que foram disponibilizadas em alguma aula passada.
// Você pode escolher as cores que quiser, mas deve ser possível diferenciar facilmente as 9 cores.
// Você pode decorar o entorno do tabuleiro como quiser.
void tab_desenha(tabuleiro *tabuleiro) {
    for (int l=1; l<=tabuleiro->tam; l++) {
        for (int c=1; c<=tabuleiro->tam; c++) {
            switch (tabuleiro->matriz[l][c]) {
                case 1:
                    muda_cor(VERMELHO);
                    break;
                case 2:
                    muda_cor(LIGHTPINK);
                    break;
                case 3:
                    muda_cor(AZULPASTEL); 
                    break;
                case 4:
                    muda_cor(MARROMLIGHT);
                    break;
                case 5:
                    muda_cor(ROSAESCURIO); 
                    break;
                case 6:
                    muda_cor(LARANJA);
                    break;
                case 7:
                    muda_cor(MUSGO);
                    break;
                case 8:
                    muda_cor(VERDE);
                    break;
                case 9:
                    muda_cor(AMARELO);  
                    break;
            }
            printf(" %d ", tabuleiro->matriz[l][c]);
        }
        cor_normal();
        printf("\n");
    }
}

// O "vetor" referenciado no algoritmo deve ser implementado em uma estrutura, descrita abaixo
typedef struct {
    int npos;   // Número de posições ocupadas no vetor
    int ncap;   // Número de posições que cabem no vetor (quanto foi alocado)
    int *vet;   // Local onde colocar os valores salvos no vetor   
} vetor;
 
// inicializa o vetor apontado por v
// coloca 0 em npos e em ncap; NULL em vet
void vet_inic(vetor *v) {
    v->npos = 0;
    v->ncap = 0;
    v->vet = NULL;
}

// retorna true se o vetor não contiver nenhuma posição, false caso contenha alguma
void vet_libera(vetor *v) {
  if (v->vet == NULL) {
    free(v->vet);
  }
  vet_inic(v);
}

// insere os valores a, b no vetor apontado por v
// caso não tenha sido alocada memória ainda, aloca o suficiente para 2 posições (4 inteiros)
// caso a capacidade atual do vetor seja insuficiente, realoque o vetor com o dobro da capacidade atual
// imprime uma mensagem de erro e aborta a execução caso não consiga alocar memória
// retorna true se o vetor não contiver nenhuma posição, false caso contenha alguma
bool vet_vazio(vetor *v) {
    if(v->npos == 0){
        return true;
    }else{
        return false;
    }
}

// insere os valores a, b no vetor apontado por v
// caso não tenha sido alocada memória ainda, aloca o suficiente para 2 posições (4 inteiros)
// caso a capacidade atual do vetor seja insuficiente, realoque o vetor com o dobro da capacidade atual
// imprime uma mensagem de erro e aborta a execução caso não consiga alocar memória
void vet_insere(vetor *v, int a, int b) {
    int realocaDobro = 0;
    
    if(v->vet == NULL){
        // caso não tenha sido alocada memória ainda, aloca o suficiente para 2 posições (4 inteiros)
        v->vet = (int *) malloc(4 * sizeof(int));
        
        if(v->vet == NULL){
            printf("\nErro ao alocar memória.");
            exit(1);
        }
        
        v->ncap = 4;
    }
    
    // caso a capacidade atual do vetor seja insuficiente, realoque o vetor com o dobro da capacidade atual
    if(v->ncap == v->npos){
        realocaDobro = (v->ncap)*2;
        
        v->vet = (int *) realloc(v->vet, realocaDobro * sizeof(int));
        
        if(v->vet == NULL){
            printf("\nErro ao realocar memória.");
            exit(1);
        }
        
        v->ncap = realocaDobro;
    }
    
    // insere os valores a, b no vetor apontado por v
    v->vet[v->npos] = a;
    v->vet[v->npos+1] = b;
    v->npos += 2;
}

// remove uma posição (dois inteiros) do vetor apontado por v; coloca esses valores nos locais apontados por pa e pb
// imprime uma mensagem de erro e aborta a execução do programa caso o vetor esteja vazio
// caso o número de posições ocupadas seja inferior a 1/3 da capacidade, realoque o vetor com metade da capacidade
void vet_remove(vetor *v, int *pa, int *pb) {
    if(vet_vazio(v) == true){
        printf("Vetor vazio.");
        exit(1);
    }
    
    *pa = v->vet[v->npos-2];
    *pb = v->vet[v->npos-1];
    v->npos -= 2;
    
    if(v->npos < ((v->ncap)/3)){
        v->ncap = (v->ncap)/2;
        v->vet = realloc(v->vet, v->ncap * sizeof(int));
        if(v->vet == NULL){
            printf("\nErro ao realocar memória.");
            exit(1);
        }
    } 
}

// preenche no tabuleiro apontado por "tab", a região de mesma cor que inicia na posição "lin,col", com a cor "cor"
void flood_fill(tabuleiro *tabuleiro, int lin, int col, int novaCor) {
    int velhaCor = tabuleiro->matriz[lin][col];
    
    if(velhaCor == novaCor){
        printf("\nFeito\n");
    }else{
        vetor vetor;
        vet_inic(&vetor);
        vet_insere(&vetor, lin, col);
        
        while(vet_vazio(&vetor) == false){
            
            vet_remove(&vetor, &lin, &col);
            
            tabuleiro->matriz[lin][col] = novaCor;
            
            if(lin > 0 && tabuleiro->matriz[lin][col] == velhaCor){
                vet_insere(&vetor, lin, col);
            }
            if(lin < tabuleiro->tam && tabuleiro->matriz[lin+1][col] == velhaCor){
                vet_insere(&vetor, lin+1, col); 
            }
            if(col > 0 && tabuleiro->matriz[lin][col] == velhaCor){
                vet_insere(&vetor, lin, col); 
            } 
            if(col < tabuleiro->tam && tabuleiro->matriz[lin][col+1] == velhaCor){
                vet_insere(&vetor, lin, col+1); 
            }
        }
        
        vet_libera(&vetor);
    }
}

// bool rankingTop3Monocor(tamanhoTabuleiro, numCores, auxTentativas, iniciaisJovador) {
//     FILE *saida;
//     saida = fopen("nanking", "w");
//     if (saida == NULL) {
//         printf("problema para abrir arquivo\n");
//         return false;
//     } else {
//         for(int i = 0; i < L; i++){
//             for(int j = 0; j < C; j++){
//                 fprintf(saida, "%c %c %c %c", tamanhoTabuleiro, numCores, auxTentativas, iniciaisJovador);
//                 if(feof(saida)){
//                     break;
//                 }
//             }
//             fprintf(saida, "\n");
//         }
//         return true;
//     }
//     fclose(saida);
// }

int main() {
    tabuleiro t;
    int tamanhoTabuleiro, numCores, corNova, auxTentativas = 0;
    // char[5] iniciaisJovador;
    
    //  O tamanho do tabuleiro e o número de cores usado afetam a dificuldade do jogo
    printf("Digite o tamanho do tabuleiro e o número de cores: ");
    scanf("%d%d", &tamanhoTabuleiro, &numCores);
    printf("\n");
    
    if (tab_inic(&t, tamanhoTabuleiro, numCores)) {
        tab_desenha(&t);
    } else {
        printf("Dados inválidos\n");
    }
    
    while(true){
        printf("\nDigite o número da cor: ");
        scanf("%d", &corNova);
        flood_fill(&t, 0, 0, corNova);
        printf("\n");
        tab_desenha(&t);
        // auxTentativas++;
    } 
    
    // printf("O ranking está assim...")
    // lerRanking()
    // printf("Deseja continuar (s/n)?")
    
    // if(resposta = s) {
    //     informe o seu = iniciaisJovador
    //     rankingTop3Monocor(tamanhoTabuleiro, numCores, auxTentativas, iniciaisJovador)
    // }
    
  return 0;
}