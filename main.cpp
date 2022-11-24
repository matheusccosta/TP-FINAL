#include "personagem.hpp"
#include "saci.hpp"
#include "mula.hpp"
#include "iara.hpp"
#include "curupira.hpp"

void definePersonagem(Personagem **p, int tipo, std::string nome){

    std::string nomeP;
    std::vector<int> vantSaci = {3, 0};
    std::vector<int> vantMula = {4, 0};  // Fogo ganha da planta
    std::vector<int> vantIara = {2, 0};  // Agua ganha do fogo
    std::vector<int> vantCurupira = {1, 3};  // Planta ganha da terra e da agua
    
    switch (tipo){

        case 1: 
        nomeP = "Saci de " + nome;
        //std::cout<<nomeP;
        *p = new Saci (100, 30, 15, nomeP, vantSaci, 1);
        break;

        case 2:
        nomeP = "Mula de " + nome;
        //std::cout<<nomeP;
        *p = new Mula (100, 30, 15, nomeP, vantMula, 2);
        break;

        case 3:
        nomeP = "Iara de " + nome;
        //std::cout<<nomeP;
        *p = new Iara (100, 30, 15, nomeP, vantIara, 3);
        break;

        case 4:
        nomeP = "Curupira de " + nome;
        //std::cout<<nomeP;
        *p = new Curupira (100, 30, 15, nomeP, vantCurupira, 4);
        break;
        //int pontos_vida, int ataque, int defesa, std::string nome, std::vector <int> vantagem, int tipo

    }


}

int main() {

    std::default_random_engine Sorteio(time(NULL));
    std::uniform_real_distribution<double> Sorte(0.60,1.00);
    std::string nome1;
    std::string nome2;
    int tipo;
    Personagem *p1;
    Personagem *p2;

    std::cout<<"Insira seu nome aqui, Jogador 1: ";
    std::cin >> nome1; 
    std::cout<<std::endl;
    std::cout<<"Selecione com qual personagem voce quer jogar!"<<std::endl<<std::endl;
    std::cout<<"1 - Saci"<<std::endl<<"2 - Mula"<<std::endl<<"3 - Iara"<<std::endl<<"4- Curupira"<<std::endl;
    std::cout<<std::endl<<"Qual voce escolhe? Insira: ";
    std::cin>>tipo;
    definePersonagem(&p1, tipo, nome1);
    std::cout<<std::endl<<"Insira seu nome aqui, Jogador 2: ";
    std::cin >> nome2;
    std::cout<<std::endl; 
    std::cout<<"Selecione com qual personagem voce quer jogar!"<<std::endl<<std::endl;
    std::cout<<"1 - Saci"<<std::endl<<"2 - Mula"<<std::endl<<"3 - Iara"<<std::endl<<"4- Curupira"<<std::endl;
    std::cout<<std::endl<<"Qual voce escolhe? Insira: ";
    std::cin>>tipo;
    std::cin.ignore();
    definePersonagem(&p2, tipo, nome2);
    std::cout<<std::endl;
    p1->imprimePersonagem();
    std::cout<<std::endl;
    p2->imprimePersonagem();
    std::cout << std::endl;

    while (p1->getVida()>0 && p2->getVida()>0){
        
        std::cout<<"Turno de "<<p1->getNome()<<", aperte enter somente 1 vez para atacar!"<<std::endl;
        std::cin.ignore();
        p1->Ataque(p2, Sorte(Sorteio));
        
        if(p2->getVida()>0){

        std::cout<<"Turno de "<<p2->getNome()<<", aperte enter somente 1 vez para atacar!"<<std::endl;
        std::cin.ignore();
        p2->Ataque(p1, Sorte(Sorteio));
        
        }
    
    }
    std::cout << std::endl;
    p1->imprimePersonagem();
    std::cout << std::endl;
    p2->imprimePersonagem();
    std::cout << std::endl;
    
    if (p1->getVida()<0){
        std::cout<<"Vencedor eh o/a " << p2->getNome()<<".";
    } else{
        std::cout<<"Vencedor eh o/a " << p1->getNome()<<".";
    }
    // iara->imprimePersonagem();
    // std::cout << std::endl;
    // curupira->imprimePersonagem();
    
    return 0;
}