#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "jogo.hpp"


TEST_CASE("TESTANDO ATAQUE"){

std::string NomeJ="test";
Personagem *p1 = new Mula(NomeJ);
Personagem *p2 = new Curupira(NomeJ);
Personagem *p3 = new Saci(NomeJ);
Personagem *p4 = new Iara(NomeJ);


SUBCASE("EFETIVIDADE DA MULA"){

    SUBCASE("CONTRA CURUPIRA"){

        CHECK(p1->Ataque(p2, 0.6) == (int) (1.2*(24-p2->getDefesa())));
        CHECK(p1->Ataque(p2, 0.7) == (int) (1.2*(28-p2->getDefesa())));
        
        CHECK(p1->Ataque(p2, 0.9) == 36-p2->getDefesa());
    }
    
    SUBCASE("CONTRA SACI, IARA E OUTRA MULA"){

        CHECK(p1->Ataque(p3, 0.8) == (int) (1.2*(32-p3->getDefesa())));
        CHECK(p1->Ataque(p3, 0.7) == 28-p3->getDefesa());

        CHECK(p1->Ataque(p4, 0.6) == (int) (1.2*(24-p4->getDefesa())));
        CHECK(p1->Ataque(p4, 0.9) == 36-p4->getDefesa());

        CHECK(p1->Ataque(p1, 0.8) == (int) (1.2*(32-p1->getDefesa())));
        CHECK(p1->Ataque(p1, 0.9) == 36-p1->getDefesa());

    }

    }
}
