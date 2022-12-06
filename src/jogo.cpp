#include "jogo.hpp"
#include "excecao.hpp"
#include <string>
#include <iostream>

void Jogo::definePersonagem(Personagem **p, std::string tipo, std::string nomeJ){
   
 
    if(tipo == "1") {
        NomeJ = "Saci de " + nomeJ;
        //std::cout<<NomeJ;
        *p = new Saci (NomeJ);
    }
    else if(tipo == "2") {
        NomeJ = "Mula de " + nomeJ;
        //std::cout<<NomeJ;
        *p = new Mula (NomeJ);
    }
    else if(tipo == "3") {
        NomeJ = "Iara de " + nomeJ;
        //std::cout<<NomeJ;
        *p = new Iara (NomeJ);
    }
    else if(tipo == "4") {
        NomeJ = "Curupira de " + nomeJ;
        //std::cout<<NomeJ;
        *p = new Curupira (NomeJ);
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

int aux;
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
            } catch(TipoInexistente& e) {
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
            } catch(TipoInexistente& e) {
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
            aux = p1->Ataque(p2, Sorte(Sorteio));
            p2->setVida(p2->getVida() - aux);
            std::cout<<"Vida de "<< p2->getNome()<< ": " << p2->getVida() << std::endl;
            std::cout<<"Dano do golpe: " << aux << std::endl;
            if(p2->getVida()>0){

                std::cout<<"Turno de "<<p2->getNome() <<", aperte enter somente 1 vez para atacar!"<<std::endl;
                std::cin.ignore();
                aux = p2->Ataque(p1, Sorte(Sorteio));
                p1->setVida(p1->getVida() - aux);
                std::cout<<"Vida de " << p1->getNome()<< ": " << p1->getVida() << std::endl;
                std::cout<<"Dano do golpe: " << aux << std::endl << std::endl;
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
    std::cin.ignore();
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
