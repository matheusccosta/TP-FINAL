#include "personagem.hpp"
#include "saci.hpp"
#include "mula.hpp"
#include "iara.hpp"
#include "curupira.hpp"
#include "jogo.hpp"


int main() {

    std::default_random_engine Sorteio(time(NULL));
    std::uniform_real_distribution<double> Sorte(0.60,1.00);
    std::string nome1;
    std::string nome2;
    int tipo;
    Personagem *p1;
    Personagem *p2;
    Jogo j;

    JogarNovamente:
    std::cout<<"Insira seu nome aqui, Jogador 1: ";
    std::cin >> nome1; 
    j.imprimeMenu();
    std::cin>>tipo;
    j.definePersonagem(&p1, tipo, nome1);
    std::cout<<std::endl<<"Insira seu nome aqui, Jogador 2: ";
    std::cin >> nome2;
    j.imprimeMenu();
    std::cin>>tipo;
    std::cin.ignore();
    j.definePersonagem(&p2, tipo, nome2);
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
        std::cout<<"Vencedor eh o/a " << p2->getNome()<<"."<<std::endl;
    } else{
        std::cout<<"Vencedor eh o/a " << p1->getNome()<<"."<<std::endl;
    }

    std::cout << std::endl << "Deseja jogar Novamente? (S/N)";

    //Pergunta ao Jogador se ele quer iniciar o jogo novamente
    int partida = 1;
    std::string proxgame;
    std::cin >> proxgame;
    if(proxgame == "S"){
        partida++;
        std::cout << std::endl << "Novo Jogo: Partida " << partida << std::endl << std::endl;
        goto JogarNovamente;
    }
    // iara->imprimePersonagem();
    // std::cout << std::endl;
    // curupira->imprimePersonagem();
    
    return 0;
}