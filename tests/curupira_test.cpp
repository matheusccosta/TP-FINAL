#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "curupira.hpp"
#include "personagem.hpp"


TEST_CASE("TESTANDO ATAQUE"){

std::string NomeJ="test";
Personagem *p1 = new Curupira (NomeJ);
Personagem *p2 = new Curupira (NomeJ);
CHECK(p1->Ataque(p2, 0.6) == 18-p2->getDefesa());
CHECK(p1->Ataque(p2, 0.7) == 21-p2->getDefesa());
CHECK(p1->Ataque(p2, 0.8) == 24-p2->getDefesa());
CHECK(p1->Ataque(p2, 0.9) == 27-p2->getDefesa());
CHECK(p1->Ataque(p2, 1.0) == 30-p2->getDefesa());

    
}
