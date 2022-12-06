#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "jogo.hpp"


TEST_CASE("TESTANDO JOGO"){

Jogo j;
Personagem *p1;
Personagem *p2;
Personagem *p3;
Personagem *p4;

SUBCASE("FUNÇÃO JOGAR NOVAMENTE"){

    SUBCASE("ENTRADA INVÁLIDA"){

        CHECK_THROWS(j.jogarNovamente("fksjd"));
    }
    SUBCASE("ENTRADA VÁLIDA"){

        CHECK_THROWS(j.jogarNovamente("S"));
        CHECK_THROWS(j.jogarNovamente("s"));
        CHECK_THROWS(j.jogarNovamente("N"));
        CHECK_THROWS(j.jogarNovamente("n"));
        }
    
    }



    SUBCASE("FUNÇÃO DEFINE PERSONAGEM"){

        SUBCASE("ENTRADA INVÁLIDA"){

            CHECK_THROWS(j.definePersonagem(&p1,"5","teste"));
            CHECK_THROWS(j.definePersonagem(&p2,"-2","teste"));
            CHECK_THROWS(j.definePersonagem(&p3,"z","teste"));

        }
        SUBCASE("ENTRADA VÁLIDA"){

            CHECK_THROWS(j.definePersonagem(&p4, "2", "gustavo"));

            }
        
        }

}