
# Folclore Kombat


Folclore Kombat é jogo de batalha RPG baseado em turnos, com uma mecanica de Multiplayer local, tendo como tema principal o folclore brasileiro e seus personagens.

Inicialmente o jogo terá dois jogadores controlando uma (1) equipe cada, a qual será selecionada a partir de diferentes personagens, pertencentes a diferentes classes que possuem distintos atributos e características. Cada jogador controlará, inicialmente, apenas 1 personagem.

O jogador só tem permissão para realizar ataques quando o jogador adversário terminar seu turno

Cada rodada so pode ter um vencedor e chega ao fim quando a vida de um dos dois personagens controlados no momento (cada um por um jogador) chegar a 0 (zero). O jogo suporta que sejam jogadas diversas rodadas consecutivamente, sendo o grande vencedor quem ganhar mais batalhas individualmente.



## Autores

- [Henrique Fantini](https://github.com/HenriqueFantini)
- [Matheus Costa](https://github.com/matheusccosta)
- [Raony Marinho](https://github.com/RaonyM)
- [Gustavo Luis](https://github.com/gustavoldmf)



## Documentação

*A documentação deste projeto foi feita utilizando doxygen.*

Passo a passo para abrir:

```bash
- Clone o projeto em uma pasta (https://github.com/Matheus-CastroCosta/TP-FINAL)

- Nesta pasta, abra a pasta "html"

- Dentro dela, va no espaco de pesquisa da pasta

- Procure por index

- Basta clicar no icone do index e abrir em seu navegador de preferencia.
```

## Rodando localmente

Link do projeto para clonagem

```bash
  https://github.com/Matheus-CastroCosta/TP-FINAL
```

Compilação

```bash
  * Necessita-se que seja feita usando WSL*
  
  - Abra seu terminal de preferencia onde seja possivel o uso do ambiente Linux

  - Encaminhe para pasta onde foi clonada o programa

  - Use o comando 'make' para realizar a compilação por meio do Makefile. Caso deseje limpar a compilação ja feita, basta dar 'make clean')

  - Após concluida a compilação, digite './main.out'
  
  - Quando concluido, o programa estará pronto para uso
```


## Testes

Para realizar os testes de unidade do programa, é necessario:

```bash
 - Estar com o programa compilado (como ensinado anteriormente)

 - Caso o arquivo de teste nao seja encontrado, é necessario digitar 'make test'

 - Execute, no mesmo terminal de compilação, './test.out', para verificar apenas os testes falhos

 - Para vizualizar os teste funcionais, execute './test.out -s'


```
## User Stories

1) Como um jogador de RPG de turno, eu quero poder selecionar meu personagem para jogar.

- *Critérios de aceitação:*

    -Visualização de todos os personagens disponíveis para serem selecionados.

    -Permitir que o jogador possa selecionar os mesmos personagens do seu adversário.


2) Como um jogador comandante de uma equipe, eu quero poder visualizar os ataques e atributos dos meus personagens para duelar com meus adversários.

- *Critérios de aceitação:*

    -Visualização dos atributos  atualizados constantemente;

    -Visualizar as características específicas do personagem que está batalhando.

    -Visualizar o dano que meu personagem causou no adversário.

3) Como jogador que tenho que selecionar o meu personagem eu quero poder visualizar as vantagens dos personagens para saber qual o melhor a escolher na situação.

- *Critérios de aceitação:*

    -O jogador deve poder visualizar qual personagem é forte contra o outro na seleção;

    -O jogador deve poder visualizar qual característica o personagem possui em destaque (ex: mais força, mais escudo etc.);
    
    -Visualizar o elemento referente ao personagem.

4) Como um jogador eu quero poder visualizar o histórico de vitórias entre os competidores em duelo para descobrir qual é o mais vitorioso.

- *Critérios de aceitação:*

    -Deve ser apresentado histórico geral, ao final da partida.

    -Essa relação será atualizada ao final de cada rodada;

5) Como um jogador que terminou uma partida eu quero ter a possibilidade de iniciar um novo confronto para continuar jogando.

- *Critérios de aceitação:*

    -Deve ser possível optar por continuar ou fechar o jogo;

    -O jogador deve poder fazer essa escolha em todos os finais de partida, enquanto não fechar o jogo;
    
    -Caso opte por continuar jogando, o processo de seleção de personagens será reiniciado;

## UML Class

![App a](https://s4.aconvert.com/convert/p3r68-cdx67/atl7p-jfh71.png)

*Opcoes para abrir a imagem do diagrama*
- https://lucid.app/lucidchart/c4930b1b-6ac5-4027-b479-bde416e8ef9e/edit?viewport_loc=-48%2C-104%2C2766%2C1680%2CHWEp-vi-RSFO&invitationId=inv_c8ec284c-35e1-4a10-bcac-c6a8169b625d
- https://prnt.sc/Qw6rxmhwG_-m
- https://s4.aconvert.com/convert/p3r68-cdx67/atl7p-jfh71.png


