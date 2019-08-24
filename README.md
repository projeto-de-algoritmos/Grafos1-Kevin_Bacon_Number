# LISTA 1 - PROJETO DE ALGORITMOS - 2019/2

### Henrique Martins de Messias - 17/0050394

<br>

### Instalações necessárias
- No teminal, digite os seguinte comando para instalar as dependências:
  ```bash
    $ sudo apt-get install build-essential
    $ sudo apt-get install qt5-default
  ```


### Instruções de uso

- No terminal, vá até o diretório do exercício, que contém, além de arquivos como o README, a pasta "Graph"
- Digite o seguinte comando:

  ```bash
    $ cd Graph
    $ qmake
  ```

  - Para compilar o código, digite:

  ```bash
    $ make
  ```

- Para executar o código, digite:

  ```bash
    $ ./Graph
  ```

### Detalhes da Lista 1

O software deste repositório é uma simulação do <b>Kevin Bacon Number</b>.

Cada pessoa possui os seguintes dados:
 - ID (cada pessoa possui um, sem repetição)
 - Nome
 - Cidade
 - Quantidade de amigos

O software armazena as pessoas em um grafo, sendo esse grafo uma lista de adjacências, conectando pessoas aos seus amigos e conhecidos

 O usuário possui as seguintes opções:
  - Adicionar Pessoa (o usuário insere o nome da pessoa e a cidade em que ela mora)
  - Gerar um grafo aleatório (o usuário deve dizer quantas pessoas e relacionamentos existirão)
  - Buscar Perfil (o usuário insere o ID da pessoa, e o programa irá procurar a pessoa)
  - Adicionar Relacionamento (o usuário informará os IDs das pessoas e o programa irá cadastrar um relaciomento entre elas)
  - Menor caminho entre duas Pessoas (o usuário informará os IDs das pessoas e o programa irá calcular a menor quantidade de pessoas entre essas duas)
  - Conexão entre uma Pessoa e as outras (o usuário insere o ID da pessoa e o programa irá calcular a menor distância entre essa pessoa e todas as outras)