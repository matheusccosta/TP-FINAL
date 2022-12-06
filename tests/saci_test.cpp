#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "jogo.hpp"


TEST_CASE("TESTANDO ATAQUE"){

std::string NomeJ="test";
Personagem *p1 = new Saci (NomeJ);
Personagem *p2 = new Iara (NomeJ);
Personagem *p3 = new Curupira (NomeJ);
Personagem *p4 = new Mula (NomeJ);

//1.7


SUBCASE("EFETIVIDADE DA SACI"){

    SUBCASE("CONTRA IARA"){

        CHECK(p1->Ataque(p2, 0.6) == (int) (1.5*(18-p2->getDefesa())));
        CHECK(p1->Ataque(p2, 0.7) == (int) (1.5*(21-p2->getDefesa())));
        
        CHECK(p1->Ataque(p2, 0.9) == 27-p2->getDefesa());
        }
    
    SUBCASE("CONTRA MULA, CURUPIRA E OUTRO SACI"){

        CHECK(p1->Ataque(p4, 0.8) == (int) (1.5*(24-p4->getDefesa())));

        CHECK(p1->Ataque(p1, 0.9) == (int) (1.5*(27-p1->getDefesa())));

        CHECK(p1->Ataque(p3, 0.7) == (int) (1.5*(21-p3->getDefesa())));

        CHECK(p1->Ataque(p1, 0.7) == 21-p1->getDefesa());

        }

    }
}
