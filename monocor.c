// Parte III - Registro de maiores pontuações
// A pontuação no jogo é o número de rodadas necessárias para preencher o tabuleiro todo da mesma cor. O jogo deve guardar em um arquivo as 3 melhores pontuações já obtidas em cada configuração (tamanho do tabuleiro, número de cores), junto com as iniciais do jogador. O formato desse arquivo é de um registro de pontuação por linha, contendo 3 inteiros e uma sequência de letras em cada linha, separados por espaço. Os 3 inteiros são o tamanho do tabuleiro, o número de cores, o número de jogadas até o final do jogo; a sequência de letras são as iniciais do jogador (5 letras no máximo). O arquivo não deve conter mais de 3 (mas pode conter menos, inclusive 0) linhas com a mesma configuração (mesmo tamanho de tabuleiro e número de cores). O arquivo pode conter mais de uma linha com resultados empatados. Abaixo exemplo de conteúdo do arquivo de recordes:

//   5 4 6 JBJ
//   7 5 19 asm
//   7 5 12 asm
// Quando uma partida é terminada, o programa deve mostrar os registros de recorde existentes no arquivo para a mesma configuração, em ordem de pontuação, juntamente com a pontuação obtida. Se houverem 3 registros gravados para a configuração e a pontuação obtida for pior ou igual ao pior desses 3 registros, o programa informa ao usuário e pergunta se quer jogar uma nova partida. Caso contrário, antes de fazer isso o programa pergunta as iniciais ao jogador e atualiza o arquivo de recordes.

// Como ler o arquivo de recordes
// Faça uma função que recebe como argumento a configuração a ler (tamanho do tabuleiro e número de cores), lê o arquivo, ignora as linhas que contiverem configurações diferentes, e retorna o número de linhas encontradas, além da pontuação e iniciais de cada uma delas.

// Como atualizar o arquivo de recordes
// Faça uma função que recebe a configuração, o número de linhas a gravar para essa configuração e a pontuação e iniciais de cada uma delas. A função então abre 2 arquivos: o de recordes, para leitura e um arquivo temporário, para gravação. Ela lê cada linha do arquivo de recordes, e se for de configuração diferente, grava a mesma linha no arquivo de saída; se for de configuração igual, ignora a linha. Quando chegar no final do arquivo de recordes, a função grava no arquivo temporário as pontuações recebidas. Fecha os dois arquivos e renomeia o arquivo temporário para ter o nome do arquivo de recordes. Essa operação irá substituir o arquivo de recordes pelo temporário. Para renomear o arquivo, use a função rename (está no stdio.h):

//    rename("nome_velho", "nome_novo");
// A função rename retorna um inteiro, com o valor 0 se deu certo e -1 se houve algum problema; você pode usar essa informação para dar uma mensagem de desalento ao usuário.