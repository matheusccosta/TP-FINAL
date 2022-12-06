#include "jogo.hpp"
#include "excecao.hpp"
#include <string>
#include <iostream>

//Recebe as escolhas de nome e personagem que o jogador fez e instancia um personagem
//de acordo com a escolha do tipo e atribui o nome ao jogador.
void Jogo::definePersonagem(Personagem **p, std::string tipo, std::string nomeJ){
   
 //Para cada tipo é instanciado um personagem
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

//Imprime as opções de escolha para o jogador.
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

//guarda historico de vitórias.
int vitoriasP1 = 0;
int vitoriasP2 = 0;

//Controla o jogo
void Jogo::startGame(){

    while(jogando){
        
        //Atribui um valor aleatório a variável sorte
        std::default_random_engine Sorteio(time(NULL));
        std::uniform_real_distribution<double> Sorte(0.60,1.00);

        std::cout << "Partida " << partida << std::endl << std::endl;
        std::cout<<"Insira seu nome aqui, Jogador 1: ";
        std::getline(std::cin, nome1);
        j.imprimeMenu();
        
        //Emite um erro caso o jogador1 digite um tipo inexistente e solicita uma nova entrada.
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

        //Emite um erro caso o jogador2 digite um tipo inexistente e solicita uma nova entrada.
        do {
            std::getline(std::cin, tipo);

            try {
                j.definePersonagem(&p2, tipo, nome2);
            } catch(TipoInexistente& e) {
                std::cout << e.what();
            }
        } while(tipo != "1" && tipo != "2" && tipo != "3" && tipo != "4");
        
        //Imprime os atributos dos personagem escolhidos pelo jogador 1 e 2.
        std::cout << std::endl;
        p1->imprimePersonagem();
        std::cout << std::endl;
        p2->imprimePersonagem();
        std::cout << std::endl;

        //Confere se os dois jogadores estão vivos.
        while (p1->getVida()>0 && p2->getVida()>0){
        
            //O Ataque é feito ao apertar enter e as novas vidas são setadas.
            std::cout<<"Turno de "<<p1->getNome()<<", aperte enter somente 1 vez para atacar!"<<std::endl;
            std::cin.ignore();
            aux = p1->Ataque(p2, Sorte(Sorteio));
            p2->setVida(p2->getVida() - aux);
            std::cout<<"Vida de "<< p2->getNome()<< ": " << p2->getVida() << std::endl;
            std::cout<<"Dano do golpe: " << aux << std::endl << std::endl;

            //Confere se o jogador que acabou de receber o ataque continua vivo para realizar o seu turno.
            if(p2->getVida()>0){

                std::cout<<"Turno de "<<p2->getNome() <<", aperte enter somente 1 vez para atacar!"<<std::endl;
                std::cin.ignore();
                aux = p2->Ataque(p1, Sorte(Sorteio));
                p1->setVida(p1->getVida() - aux);
                std::cout<<"Vida de " << p1->getNome()<< ": " << p1->getVida() << std::endl;
                std::cout<<"Dano do golpe: " << aux << std::endl << std::endl;
            } 
        }

        //Imprime os atributos de cada personagem ao final da batalha.
        std::cout << std::endl;
        p1->imprimePersonagem();
        std::cout << std::endl;
        p2->imprimePersonagem();
        std::cout << std::endl;
        
        //Concede a vitoria ao jogador que restou vivo
        if (p1->getVida()<0){
            std::cout<<"Vencedor eh o/a " << p2->getNome()<<"."<<std::endl;
            vitoriasP2++;
        } else{
            std::cout<<"Vencedor eh o/a " << p1->getNome()<<"."<<std::endl;
            vitoriasP1++;
        }

        //Opção jogar novamente
        std::cout << std::endl << "Deseja jogar Novamente? (S/N): ";
        proxgame.erase(proxgame.begin(), proxgame.end());
        
        //Emite um erro caso seja inserida uma entrada inválida e trata as entradas minúsculas
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

//Caso inserido s: reinicia a partida caso o jogador solicite,
//Caso inserido n: finaliza o jogo e imprime o historico de vitórias,
//e caso for inserido uma entrada inválida chama throw.
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

