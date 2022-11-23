#include "personagem.hpp"
#include "saci.hpp"
#include "mula.hpp"
#include "iara.hpp"
#include "curupira.hpp"

int main() {

    std::default_random_engine Sorteio(time(NULL));
    std::uniform_real_distribution<double> Sorte(0.60,1.00);

    std::vector<int> vantSaci = {3, 0}; //funciona pra carai / Terra ganha da agua
    std::vector<int> vantMula = {4, 0}; //funciona pra carai / Fogo ganha da planta
    std::vector<int> vantIara = {2, 0}; //funciona pra carai / Agua ganha do fogo
    std::vector<int> vantCurupira = {1, 3}; //funciona pra carai / Planta ganha da terra e da agua
    // std::vector <int> vetor;
    // vetor.push_back(2);
    // vetor.push_back(0);

    Personagem *saci = new Saci(100, 30, 6, "gustavoo", vantSaci, 1);
    Personagem *mula = new Mula(100, 28, 8, "henrique", vantMula, 2);
    Personagem *iara = new Iara(100, 24, 12, "matheus", vantIara, 3);
    Personagem *curupira = new Curupira(100, 26, 10, "raony", vantCurupira, 4);
    
    saci->imprimePersonagem();
    std::cout << std::endl;
    mula->imprimePersonagem();
    std::cout << std::endl;
    iara->imprimePersonagem();
    std::cout << std::endl;
    curupira->imprimePersonagem();
    std::cout << std::endl;

    saci->Ataque(saci, Sorte(Sorteio));
    mula->Ataque(mula, Sorte(Sorteio));
    iara->Ataque(iara, Sorte(Sorteio));
    curupira->Ataque(curupira, Sorte(Sorteio));
    std::cout << std::endl;

    saci->imprimePersonagem();
    std::cout << std::endl;
    mula->imprimePersonagem();
    std::cout << std::endl;
    iara->imprimePersonagem();
    std::cout << std::endl;
    curupira->imprimePersonagem();
    
    return 0;
}