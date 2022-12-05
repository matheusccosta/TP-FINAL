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


class Jogo {
    protected:
    std::string NomeJ;
    int derrotas;
    int vitorias;

    public: 
    void definePersonagem(Personagem **p, std::string tipo, std::string NomeJ);

    void jogarNovamente(std::string proxgame);

    void imprimeMenu();   

    void startGame();

    // void controlaTurno(Personagem *p1, Personagem *p2);

    std::string getNome();


};
#endif