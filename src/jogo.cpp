#include "jogo.hpp"
#include "excecao.hpp"
#include <string>
#include <iostream>

void Jogo::definePersonagem(Personagem **p, std::string tipo, std::string nomeJ){
   
    std::vector<int> vantSaci = {3, 0};
    std::vector<int> vantMula = {4, 0};  // Fogo ganha da planta
    std::vector<int> vantIara = {2, 0};  // Agua ganha do fogo
    std::vector<int> vantCurupira = {1, 3};  // Planta ganha da terra e da agua
 
    if(tipo == "1") {
        NomeJ = "Saci de " + nomeJ;
        //std::cout<<NomeJ;
        *p = new Saci (100, 30, 15, NomeJ, vantSaci, 1);
    }
    else if(tipo == "2") {
        NomeJ = "Mula de " + nomeJ;
        //std::cout<<NomeJ;
        *p = new Mula (100, 30, 15, NomeJ, vantMula, 2);
    }
    else if(tipo == "3") {
        NomeJ = "Iara de " + nomeJ;
        //std::cout<<NomeJ;
        *p = new Iara (100, 30, 15, NomeJ, vantIara, 3);
    }
    else if(tipo == "4") {
        NomeJ = "Curupira de " + nomeJ;
        //std::cout<<NomeJ;
        *p = new Curupira (100, 30, 15, NomeJ, vantCurupira, 4);
        //int pontos_vida, int ataque, int defesa, std::string nome, std::vector <int> vantagem, int tipo
    }
    else {
        throw TipoInexistente(tipo);
    }
}


std::string Jogo::getNome(){
    return NomeJ;
}

void Jogo::imprimeMenu(){
    std::cout<<std::endl; 
    std::cout<<"Selecione com qual personagem voce quer jogar!"<<std::endl<<std::endl;
    std::cout<<"1 - Saci"<<std::endl<<"2 - Mula"<<std::endl<<"3 - Iara"<<std::endl<<"4 - Curupira"<<std::endl;
    std::cout<<std::endl<<"Qual voce escolhe? Insira: ";
}


int jogando = 1;
int partida = 1;
std::string proxgame;

std::string nome1;
std::string nome2;
std::string tipo;

Personagem *p1;
Personagem *p2;
Jogo j;

int vitoriasP1 = 0;
int vitoriasP2 = 0;

void Jogo::startGame(){
    while(jogando){

        std::default_random_engine Sorteio(time(NULL));
        std::uniform_real_distribution<double> Sorte(0.60,1.00);

        std::cout << "Partida " << partida << std::endl << std::endl;
        std::cout<<"Insira seu nome aqui, Jogador 1: ";
        std::getline(std::cin, nome1);
        j.imprimeMenu();
        do {
            std::getline(std::cin, tipo);

            try {
                j.definePersonagem(&p1, tipo, nome1);
            } catch(std::exception& e) {
                std::cout << e.what();
            }
        } while(tipo != "1" && tipo != "2" && tipo != "3" && tipo != "4");
        
        std::cout<<std::endl<<"Insira seu nome aqui, Jogador 2: ";
        std::getline(std::cin, nome2);
        j.imprimeMenu();
        do {
            std::getline(std::cin, tipo);

            try {
                j.definePersonagem(&p2, tipo, nome2);
            } catch(std::exception& e) {
                std::cout << e.what();
            }
        } while(tipo != "1" && tipo != "2" && tipo != "3" && tipo != "4");
        
        std::cout << std::endl;
        p1->imprimePersonagem();
        std::cout << std::endl;
        p2->imprimePersonagem();
        std::cout << std::endl;

        while (p1->getVida()>0 && p2->getVida()>0){
        
            std::cout<<"Turno de "<<p1->getNome()<<", aperte enter somente 1 vez para atacar!"<<std::endl;
            std::cin.ignore();
            p2->setVida(p2->getVida() - p1->Ataque(p2, Sorte(Sorteio)));
            
            if(p2->getVida()>0){

            std::cout<<"Turno de "<<p2->getNome()<<", aperte enter somente 1 vez para atacar!"<<std::endl;
            std::cin.ignore();
            p1->setVida(p1->getVida() - p2->Ataque(p1, Sorte(Sorteio)));
            
            } 
        }

        std::cout << std::endl;
        p1->imprimePersonagem();
        std::cout << std::endl;
        p2->imprimePersonagem();
        std::cout << std::endl;
        
        if (p1->getVida()<0){
            std::cout<<"Vencedor eh o/a " << p2->getNome()<<"."<<std::endl;
            vitoriasP2++;
        } else{
            std::cout<<"Vencedor eh o/a " << p1->getNome()<<"."<<std::endl;
            vitoriasP1++;
        }

        std::cout << std::endl << "Deseja jogar Novamente? (S/N): ";
        proxgame.erase(proxgame.begin(), proxgame.end());
        
        do {
            std::cin >> proxgame;
            try {
                j.jogarNovamente(proxgame);
            } catch(std::invalid_argument& e) {
                std::cout << e.what();
            }
        } while(proxgame != "S" && proxgame != "s" && proxgame != "N" && proxgame != "n");
    }
}

void Jogo::jogarNovamente(std::string proxgame) {
    if(proxgame == "S" || proxgame == "s"){
            partida++;
            std::cout << std::endl << "Iniciando nova batalha" << std::endl << std::endl;
    }
    else if(proxgame == "N" || proxgame == "n"){
        std::cout << "Fim de Jogo!!" << std::endl;
        std::cout << "Vitorias do Jogador 1: " << vitoriasP1 << std::endl;
        std::cout << "Vitorias do Jogador 2: " << vitoriasP2 << std::endl;
        jogando = 0;
    }
    else {
        throw std::invalid_argument("Entrada invalida! Digite novamente: ");
    }
}

// void Jogo::controlaTurno(Personagem *p1, Personagem *p2)