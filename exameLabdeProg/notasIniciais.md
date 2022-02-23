# Programar Wordle 

## Funcionalidades
- O jogo sorteia uma palavra de 5 letras;
    - Declarar de array 
- O jogador tenta adivinhar a palavra. Ele tem até seis tentativas. 
    - Gerar um While (contador < 7) para executar a chamada das tentativas
    - Declarar contador para tentativas
- O jogador chuta uma palavra.
    - Dentro do While, popula-se uma variável de 5 caracteres que será a tentativa.
- A palavra só é aceita se estiver entra as palavras conhecidas pelo jogo.
    - Laço condicional que verificará se a palavra ao menos existe. Caso não, a tentativa é anulada e o contator regride um numeral.
- O jogo verifica a palavra chutada, 
    - Acredito que, dentro do laço condicional declarado acima, podemos ter outras duas condicionais...
        - Uma caso a palavra não exista, que regride uma tentativa.
        - Outra caso aconteça do contrario, quando a palavra existe, para verificá-la
- E desenha ela de uma forma especial, que diz quais letras dela existem ou não na palavra sorteada, e se as que existem estão na posição correta ou não
    - Para isso posso seguir a mesma lógica do trabalho anterior, onde o fundo das letras é alterado por cores
        - Cinza para posição e letra inexistentes
        - Amarelo para letra existente porem posicao errada
        - Verde para posição e letra corretas
- Se o jogador acertar a palavra, a partida termina (com vitória).
    - Ótimo, nesse caso podemos verificar dentro do laço principal mencionado lá em cima se todas as letras forem verdes, o contador assume 7 quebrando o while e encerrando o jogo com sucesso, indicando o if contador = 8 (como uma flag)
- Se o jogador não acertar em 6 tentativas, a partida também termina (com derrota).
    - Nesse caso, é possível simplesmente quebrar o laço como o contador em 7, o que assume derrota.
- No término da partida, o programa mostra qual foi a palavra sorteada, e mostra estatísticas de desempenho do jogador.
    - Mostra a variavel da palavra e, bem como, a quantidade de tentativas
    - SUGESTÃO::: Dava para mostrar a tabela tipo quando postamos no Twitter.
- No jogo original, o jogo pode ser jogado somente uma vez por dia. Nossa versão não tem essa restrição: ao final de uma partida o programa oferece outra.
    - Ok, após apresentar os dados, o programa pode ser chamado novamente.
- Na nossa versão, o jogador poderá desistir da jogada, digitando a palavra "desisto". O jogo se comporta nesse caso da mesma forma que quando o jogador erra a sexta tentativa.
    - Ok, se ele digitar qualquer coisa diferente de enter é desistencia. Aparecem as estatisticas e papum. As estatisticas vão ser uma função. Mais fácil assim. 

## Sobre as palavras XX
- O professor separou o que vai nos servir de "API" para as palavras 
    - Link da API https://github.com/BenhurUFSM/l121b/blob/main/Assuntos/palavras
    - Cada linha contém 11 espaços, ou seja, duas palavras de 5 letras divididas por um espaço.
    - A palavra da posição 0-4 é a que o usuário vai tentar adivinhar, ela é toda minuscula e sem acentos.
    - Posição 5 é apenas um espaço.
    - Da posição 6-11 teremos a palavra com suas letras maiusculas e acentos, que será usada para as estatísticas ao fim do jogo. 
- Temos 16734 palavras no arquivo.
- Alem das duas grafias, também podemos adicionar uma informação de sorteado ou não, que deverá ser " S\n" ao final da linha.

## Armazenar as palavras
- Hora de armazenar o arquivo na nossa memória...
    - As primeiras 5 posições (letras minúsculas e sem acentos) ocuparão 5 bytes, a sexta posição ocupará 1 bite. Chegamos em 6 bites de início.
    - Já na segunda grafia, pode ser uma letra minuscula ou maiuscula, que ocupam 1 byte. Ou uma letra com acentos, que ocupa 2 bytes. IOu seja, podemos usar de 5 a 10 bytes na segunda grafia.
    - Por fim, o byte seguinte pode ser apenas '\n' (sem adicionais), ou pode ser um ' S\n' (com adicionais). Ou seja, é um bool.
- Assim, o código de armazenamento se torna algo como...
```
   typedef struct {
     char sem_acento[5];
     char com_acento[10];
     bool usada;
   } palavra_t;
```

## Ler e gravar nos arquivos as palavras
Para ler as palavras vamos ter de...
```
   bool le_palavra(FILE *arquivo, palavra_t *p)
```
- Essa função recebe em arquivo um descritor de arquivo já aberto para leitura, 
    - Ou seja...
```
    FILE *entrada;
    FILE *saida;
    entrada = fopen("palavras", "r");
    saida = fopen("copia-das-palavras", "w");
```
- E em p um ponteiro para uma estrutura de armazenamento de uma palavra.
    - Nesse caso, o P nada mais é que uma máscara para o que nós já fizemos aqui
```
   typedef struct {
     char sem_acento[5];
     char com_acento[10];
     bool usada;
   } palavra_t;
```
- Você deve também implementar a função grava_palavra, que recebe uma estrutura preenchida e grava uma linha no arquivo, no mesmo formato.
    - MAS QUE PORRA, eu deveria fazer isso exatamente por que?? Sei lá, preciso rever essa parte depois.
- Okay, enfim, com essas duas funções a gente já consegue testar o arquivo fazendo algo tipo...
```
   int main()
   {
     FILE *entrada;
     FILE *saida;
     entrada = fopen("palavras", "r");
     saida = fopen("copia-das-palavras", "w");
     if (entrada == NULL || saida == NULL) {
       printf("Erro no acesso aos arquivos\n");
       exit(1);
     }
     palavra_t palavra;
     while (le_palavra(entrada, &palavra)) {
       if (!grava_palavra(saida, palavra)) {
         printf("problema na gravação\n");
         break;
       }
     }
     fclose(entrada);
     fclose(saida);
     return 0;
   }
```
- Legal, caso os arquivos terminem iguais, aqui passamos de um marco!!


## Gravar localmente as palavras
Okay, eles querem que salvemos um arquivo de palavras gigantescos na memória. Usaremos um vetor para tal, ficará tipo...
consegue testar o arquivo fazendo algo tipo...
```
   int main()
   {
    #define NUM_PALAVRAS 16734
    palavra_t lista_de_palavras[NUM_PALAVRAS];
   }
```
- Faça uma função que recebe o nome de um arquivo e o vetor acima e preenche o vetor com as palavras lidas do arquivo (usando a função de leitura de uma palavra vista acima). A função deve retornar um bool dizendo se a leitura foi bem sucedida (leu todas as NUM_PALAVRAS) ou não.
    - Ta legal, basicamente a memsa coisa que a gente fez para popular o outro arquivo.
- Faça outra função, que atualiza a lista de palavras no arquivo.
    - Okay, função para atualizar o arquivo.
        - Ela recebe o nome do arquivo e a lista de palavras. Depois de passar todas as palavras, ela fecha o arquivo e RENOMEIA ele (COMO?). A função também retorna um bool se deu bom.
        - Acredito que essa função será a responsável por elimitar a palavra já utilizada do jogo, chamamos o arquivo atualizado como o nome da ultima palavra, o que já contém ela eliminada.

## Sorteio da palavra
- A cada partida, o jogo deve sortear uma palavra a ser adivinhada pelo jogador.
    - Estou começando a pensar na possibilidade de fazer um while dentro do while, o primeiro para a quantidade de jogadas, o segundo para o jogo em si
- A palavra sorteada pode ser qualquer uma da lista, que ainda não tenha sido usada. 
    - Ou seja, necessário verificar se tem o S
- Faça uma função que recebe a lista de palavras e retorna um inteiro com a posição na lista da palavra sorteada. A função deve chutar um número aleatório entre 0 e NUM_PALAVRAS-1, até que a palavra nessa posição seja uma palavra não usada.
    - Nice.

## Recebendo um chute
- Um chute é uma palavra que o usuário digita, para tentar a palavra sorteada. 
    - Ou seja, uma das 6 palavras
- Um chute deve ser submetido a duas análises: uma para saber se é um chute válido e outra para produzir as dicas sobre esse chute para o usuário. 
    - Okay, já discutimos isso lá em cima, é um if dentro de outro
- Vamos usar uma estrutura para armazenar um chute:
```
   typedef struct {
     char letras[5];    // as letras que o jogador chutou
     palavra_t palavra; // a palavra correspondente ao chute
     char dicas[5];     // a classificação de cada letra do chute
     bool correto;      // true se a palavra corresponde à sorteada
   } chute_t;
```
- O campo letras tem as 5 letras usadas que compõe o chute, todas minúsculas. 
- O campo palavra contém uma cópia da palavra corresondente ao chute na lista de palavras. 
- O campo dicas tem, para cada letra, a informação...
    - se ela pertence à palavra sorteada e está na posição correta (representado por um 'v'), 
    - se ela pertence à palavra mas está em posição incorreta (representado por um 'l') 
    - ou se ela não pertence à palavra (representado por um 'c'). 
- O campo correto é somente para facilitar a verificação de se a palavra é igual a sorteada ou não (vai ser true se as 5 dicas forem 'v').

## Preparando um chute
- A primeira função recebe um ponteiro para um chute e a lista de palavras, e retorna um bool dizendo se o chute é válido ou não. 
- O chute é considerado válido se ele é igual a uma das palavras da lista (comparando suas 5 letras com as 5 letras sem acento da palavra). 
- No caso de o chute ser válido, a função copia a palavra correspondente da lista de palavras para a estrutura do chute.
    - Okay, o que eu notei desses 3 pontos... antes do chute ser armazenado na struct, ele precisa passar por essa avaliação. E ela precisa retornar true. Então o role de fazer uma função dentro da outra talvez não seja possível.
```
 bool chute_valido(chute_t *pchute, palavra_t lista[NUM_PALAVRAS])
 ``` 

## Avaliando um chute
- A função que analisa um chute vai receber um ponteiro para o chute e a palavra correta, e vai preencher os campos dicas e correto do chute. 
- Uma forma simples de calcular as dicas, que funciona com letras repetidas, é a seguinte:
    - inicializa as dicas com 'c';
    - para cada uma das 5 posições, se a letra do chute e da palavra nessa posição forem iguais, marca a dica dessa posição com 'v';
    - para cada posição, se a dica nessa posição não for 'v', busca a letra que está nessa posição na palavra, em uma outra posição no chute, que tenha dica igual a 'c' e muda essa dica para 'l'.
        - essa última verificalão vai ser uma MERDA
- se todas as dicas forem 'v', coloca correto em true, senão, coloca em false.
    - nice, aí encerra o jogo com vitória.
```
void analisa_chute(chute_t *pchute, palavra_t palavra_sorteada)
```

## Vetor de letras usadas
- NÃO CREIO QUE PEDIRAM ISSO 
- Para auxiliar o jogador, o jogo apresenta para ele o conjunto das 26 letras, classificando cada uma em:
    - querem o teclado??? minha nossa.
- não usada (ainda não foi usada em nenhum chute)
- não existente (já foi usada em algum chute, mas - não existe na palavra sorteada)
- em posição errada (já foi usada em algum chute, mas nunca na posição correta)
- em posição certa (já foi usada na posição correta em algum chute) Em memória, essa informação vai ser mantida em um vetor de 26 posições (uma para cada letra), com sua situação codificada pelas letras 'n', 'c', 'l' ou 'v', respectivamente à lista acima. No início de uma partida esse vetor é inicializado com 'n' em todas as posições, e a função abaixo atualiza as posições do vetor após a análise de cada chute:

```
   void atualiza_letras_usadas(chute_t chute, char letras_usadas[26])
```

- Essa função verifica cada letra do chute. Cada letra que for marcada com 'v' no chute deve ser marcada também com 'v' no vetor de letras usadas. As que forem marcadas com 'l' no chute e que não estejam marcadas com 'v' no vetor de letras usadas, devem ser marcadas com 'l' nesse vetor. As que estão marcadas com 'c' no chute e que estejam com 'n' no vetor são marcadas com 'c' no vetor.
    - Coisa boa, vou ter que fazer duas funções que rodam a mesma coisa. Ou talvez eu ainda não tenha entendido direito... well, we will see...
    
## Representação de uma partida em memória
- Uma partida é constituída por uma palavra sorteada, pelo conjunto de até seis chutes e pelo vetor de letras usadas. Em memória, essa partida será implementada pela estrutura abaixo:
```
typedef struct {
  palavra_t sorteada;     // a palavra que o jogador deve adivinhar
  int nchutes;            // quantos chutes já foram feitos
  chute_t chutes[6];      // aqui estão os chutes
  char letras_usadas[26]; // vetor com o estado de cada letra
} partida_t;
```
- Okay, isso é legal, teremos uma representação da partida na memória

## Desenho da tela
- Antes de pedir cada chute do usuário, a tela mostrando a situação da partida deve ser desenhada
    - O desenho da tela é realizado com as informações constantes na estrutura partida acima. Devem ser mostrados todos os chutes já realizados e espaço para os não realizados. 
    - Deve ser mostrado também o conjunto de letras.
        - HUUUUUUUUUUUR
- Cada letra de um chute será desenhado na tela ocupando 3 linhas de 3 caracteres. A cor de fundo desses caracteres será escolhida conforme a dica armazenada para o caractere no chute:
    - se a dica for 'c' deverá ser cinza;
    - se a dica for 'l' deverá ser laranja;
    - se a dica for 'v' deverá ser verde. Os caracteres são espaços, exceto o do meio, que será o caractere correspondente ao chute.
- O desenho de cada chute ocupará 4 linhas na tela:
    - a primeira contém, para cada um dos 5 caracteres do chute, 3 espaços com a cor de fundo correspondente ao caracter seguidos por um espaço na cor de fundo normal;
    - a segunda contém, para cada um dos 5 caracteres do chute, 1 espaços com a cor de fundo correspondente ao caracter, seguido pelo caractere, seguido por outro espaço ainda com a mesma cor de fundo, seguido por um espaço na cor de fundo normal;
    - a terceira é igual à primeira;
    - a quarta é em branco.
- Para escrever o chute, deve-se usar os caracteres da segunda versão da palavra do chute (que pode conter acentos). Quando o caractere for uma letra minúscula ou maiúscula, ele é impresso com um só byte, se não for nem minúscula nem maiúscula, é um caracter acentuado, que é impresso escrevendo-se dois bytes seguidos.

- O desenho dos chutes ainda não realizados será feito da mesma forma, só que tem espaço no lugar do caracter e o fundo é cinza escuro para todos eles.

- O conjunto de letras é desenhado após os chutes, seguindo a mesma codificação de cor de fundo (cinza escuro, cinza, laranja e verde para 'n', 'c', 'l' ou 'v').

## Funcionamento Geral do programa
O funcionamento geral do jogo deve ser:

1. o programa lê o arquivo de palavras X
2. o programa sorteia uma palavra, marca como usada, atualiza o arquivo de palavras e inicializa a estrutura da partida X
3. o programa desenha a tela principal X
4. o programa pede um chute ao jogador X
5. se o chute for "desisto", continua no passo 11
6. se o chute não for válido, informa o jogador e volta ao passo 2
7. o programa insere o chute na estrutura da partida, analisa ele, atualiza o vetor de letras
8. se o chute for correto, desenha a tela, felicita o jogador, continua no passo 12
9. se foi o último chute (sexto), desenha a tela, infelicita o jogador, continua no passo 11
10. volta para o passo 3
11. informa a palavra sorteada ao jogador
12. pergunta se quer jogar de novo e volta ao passo 2 se for o caso, senão vai para o passo 13
13. termina o programa
Organize isso!


AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA