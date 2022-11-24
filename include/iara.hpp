#ifndef IARA_HPP
#define IARA_HPP
#include "personagem.hpp"

class Iara : public Personagem {
    public: 
    
        Iara(int pontos_vida, int ataque, int defesa, std::string nome, std::vector <int> vantagem, int tipo);

        int getVida() override;
        void setVida(int vida) override;

        int getAtaque() override;
        void setAtaque(int ataque) override;

        int getDefesa() override;
        void setDefesa(int defesa) override;

        std::string getNome() override;
        void setNome(std::string nome) override;

        std::vector<int> getVantagem() override;
        void setVantagem(std::vector<int> vantagem) override;

        int getTipo() override;
        void setTipo(int tipo) override;

        void imprimePersonagem() override;

        void Ataque(Personagem *p, float sorte) override;

};
#endif