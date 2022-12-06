#include "iara.hpp"

Iara::Iara(std::string nome){
    this->pontos_vida = 115;
    this->ataque = 30;
    this->defesa = 15;
    this->nome = nome;
    vantagem.push_back(2);
    this->tipo = 3;
}

int Iara::getVida(){
    return this->pontos_vida;
}

void Iara::setVida(int vida){
    this->pontos_vida = vida;
}

int Iara::getAtaque(){
    return this->ataque;
}

void Iara::setAtaque(int ataque){
     this->ataque = ataque;
}

int Iara::getDefesa(){
    return this->defesa;
}

void Iara::setDefesa(int defesa){
    this->defesa = defesa;
}

std::string Iara::getNome(){
    return this->nome;
}
void Iara::setNome(std::string nome){
    this->nome = nome;
}

std::vector<int> Iara::getVantagem(){
    return this->vantagem;
}

void Iara::setVantagem(std::vector<int> vantagem){
    this->vantagem = vantagem;
}

int Iara::getTipo(){
    return this->tipo;
}

void Iara::setTipo(int tipo){
    this->tipo = tipo;
}

int Iara::Ataque(Personagem *p, float sorte){
   //Calcula o golpe baseado no ataque e na vantagem do respectivo adversário;
   float golpe = this->ataque * sorte; //+ p.vantagem;
    
    int dano = golpe - p->getDefesa();

    if (p->getTipo() == 2)
        dano *=1.75;

    if( dano > 0)
            return dano;
        return 0;
}

void Iara::imprimePersonagem(){
    std::cout << "Nome: " << nome << std::endl << "Ataque: " << ataque << std::endl;
    std::cout << "Defesa: " << defesa << std::endl << "Vida: " << pontos_vida << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Vantagem sobre o tipo: " << vantagem[0] << std::endl;
}