/**
 * @file jogo.hpp
 * @author your name (you@domain.com)
 * @brief 
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
 * @brief 
 * 
 */

class Jogo {
    protected:
    std::string NomeJ;
    int derrotas;
    int vitorias;

    public:

    /**
     * @brief 
     * 
     * @param p 
     * @param tipo 
     * @param NomeJ 
     * @return * void 
     */

    void definePersonagem(Personagem **p, std::string tipo, std::string NomeJ);
    /**
     * @brief 
     * 
     * @param proxgame 
     */
    void jogarNovamente(std::string proxgame);
    /**
     * @brief 
     * 
     */
    void imprimeMenu();   
    /**
     * @brief 
     * 
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