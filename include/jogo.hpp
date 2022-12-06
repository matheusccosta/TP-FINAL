/**
 * @file jogo.hpp
 * @author Gustavo Luís (gustavolmf@ufmg.br)
 * @brief Arquivo responsável pela entrada, processamento e execução dos dados inseridos pelo jogador,
 * além de gerar a interface do jogo no cmd.
 * @version 0.1
 * @date 2022-12-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef JOGO_HPP
#define JOGO_HPP
#include "personagem.hpp"
#include "saci.hpp"
#include "mula.hpp"
#include "iara.hpp"
#include "curupira.hpp"
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <list>
#include <random>

/**
 * @brief Cria um jogo e todas as ações que os jogadores podem realizar
 * 
 */

class Jogo {
    protected:
    /**
     * @brief variável que recebe o nome do jogador
     * 
     */
    std::string NomeJ;
   
    public:

    /**
     * @brief Constrói o Personagem com o tipo escolhido e o associa ao nome dado pelo jogador
     * @details Com base no tipo selecionado, é acionado um construtor correspondente ao Personagem
     * com seus atributos específicos ou lança um erro de TipoInexistente. Depois o nome fornecido 
     * é atribuído ao Personagem. 
     * Ex: Iara de João
     * 
     * @param p 
     * @param tipo 
     * @param NomeJ
     */

    void definePersonagem(Personagem **p, std::string tipo, std::string NomeJ);

    /**
     * @brief Inicia uma nova partida ou encerra com base na resposta recebida
     * @details Quando perguntado se o jogador deseja iniciar uma nova partida, ele pode responder s
     * para sim ou n para encerrar o jogo e exibir a quantidade de vitórias dos jogadores daquela partida.
     * Caso outra coisa seja enviada como entrada, a função lança um erro de entrada inválida.
     * 
     * @param proxgame 
     */
    void jogarNovamente(std::string proxgame);

    /**
     * @brief Imprime o menu de início da partida.
     * @details Exibe um menu de seleção do Personagem, em que cada um está associado ao seu respectivo
     * tipo e fornece um espaço para o jogador digitar qual Personagem ele escolhe.
     */
    void imprimeMenu();   

    /**
     * @brief Inicia o jogo, constrói e desenvolve a partida.
     * @details Quando o jogo é iniciado, apresenta qual número de partida está sendo jogada e pede o nome 
     * do primeiro jogador. Em seguida, constrói o menu, em que cada jogador insere seu Personagem e ele é criado.
     * Após isso, os ataques são realizados alternadamente até que um dos Personagens dos jogadores tenha sua vida
     * reduzida a 0. Por fim, é perguntado se o jogador deseja jogar outra partida e realiza uma ação com base na
     * resposta dele.
     */
    void startGame();

    // void controlaTurno(Personagem *p1, Personagem *p2);
    /**
     * @brief Get the Nome object
     * 
     * @return std::string 
     */
    std::string getNome();


};
#endif