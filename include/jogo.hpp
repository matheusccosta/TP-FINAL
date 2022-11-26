#ifndef JOGO_HPP
#define JOGO_HPP
#include "personagem.hpp"
#include "saci.hpp"
#include "mula.hpp"
#include "iara.hpp"
#include "curupira.hpp"

class Jogo {
    protected:
    std::string NomeJ;
    int derrotas;
    int vitorias;

    public: 
    void definePersonagem(Personagem **p, int tipo, std::string NomeJ);

    void imprimeMenu();   

    // void controlaTurno(Personagem *p1, Personagem *p2);

    std::string getNome();


};
#endif