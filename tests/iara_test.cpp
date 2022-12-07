#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "jogo.hpp"


TEST_CASE("TESTANDO ATAQUE"){

std::string NomeJ="test";
Personagem *p1 = new Iara (NomeJ);
Personagem *p2 = new Curupira (NomeJ);
Personagem *p3 = new Saci (NomeJ);
Personagem *p4 = new Mula (NomeJ);

//1.7


SUBCASE("EFETIVIDADE DA IARA"){

    SUBCASE("CONTRA MULA"){

        CHECK(p1->Ataque(p4, 0.6) == (int) (1.7*(18-p4->getDefesa())));
        CHECK(p1->Ataque(p4, 0.7) == (int) (1.7*(21-p4->getDefesa())));
        
        }
    
    SUBCASE("CONTRA SACI, CURUPIRA OU OUTRA IARA"){
        
        CHECK(p1->Ataque(p1, 0.8) == 24-p1->getDefesa());

        CHECK(p1->Ataque(p2, 0.9) == 27-p1->getDefesa());

        CHECK(p1->Ataque(p3, 0.7) == 21-p3->getDefesa());
        }

    }
}
