#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "curupira.hpp"
#include "personagem.hpp"


TEST_CASE("TESTANDO ATAQUE"){

std::string NomeJ="test";
std::vector<int> vantCurupira = {1, 3};
Personagem *p1 = new Curupira (100, 30, 15, NomeJ, vantCurupira, 4);
Personagem *p2 = new Curupira (100, 30, 15, NomeJ, vantCurupira, 4);
CHECK(p1->Ataque(p2, 0.6) == 18-p2->getDefesa());
CHECK(p1->Ataque(p2, 0.7) == 21-p2->getDefesa());
CHECK(p1->Ataque(p2, 0.8) == 24-p2->getDefesa());
CHECK(p1->Ataque(p2, 0.9) == 27-p2->getDefesa());
CHECK(p1->Ataque(p2, 1.0) == 30-p2->getDefesa());

    
}
