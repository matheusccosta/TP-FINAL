#include "jogo.hpp"

void Jogo::definePersonagem(Personagem **p, int tipo, std::string nomeJ){
   
    std::vector<int> vantSaci = {3, 0};
    std::vector<int> vantMula = {4, 0};  // Fogo ganha da planta
    std::vector<int> vantIara = {2, 0};  // Agua ganha do fogo
    std::vector<int> vantCurupira = {1, 3};  // Planta ganha da terra e da agua
    
    switch (tipo){

        case 1: 
        NomeJ = "Saci de " + nomeJ;
        //std::cout<<NomeJ;
        *p = new Saci (100, 30, 15, NomeJ, vantSaci, 1);
        break;

        case 2:
        NomeJ = "Mula de " + nomeJ;
        //std::cout<<NomeJ;
        *p = new Mula (100, 30, 15, NomeJ, vantMula, 2);
        break;

        case 3:
        NomeJ = "Iara de " + nomeJ;
        //std::cout<<NomeJ;
        *p = new Iara (100, 30, 15, NomeJ, vantIara, 3);
        break;

        case 4:
        NomeJ = "Curupira de " + nomeJ;
        //std::cout<<NomeJ;
        *p = new Curupira (100, 30, 15, NomeJ, vantCurupira, 4);
        break;
        //int pontos_vida, int ataque, int defesa, std::string nome, std::vector <int> vantagem, int tipo
    }
}

std::string Jogo::getNome(){
    return NomeJ;
}

void Jogo::imprimeMenu(){
    std::cout<<std::endl; 
    std::cout<<"Selecione com qual personagem voce quer jogar!"<<std::endl<<std::endl;
    std::cout<<"1 - Saci"<<std::endl<<"2 - Mula"<<std::endl<<"3 - Iara"<<std::endl<<"4- Curupira"<<std::endl;
    std::cout<<std::endl<<"Qual voce escolhe? Insira: ";
}

// void Jogo::controlaTurno(Personagem *p1, Personagem *p2)