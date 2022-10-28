#include "mula.hpp"

Mula::Mula(int pontos_vida, int ataque, int defesa, std::string nome, std::vector <int> vantagem, int tipo){
    this->pontos_vida = pontos_vida;
    this->ataque = ataque;
    this->defesa = defesa;
    this->nome = nome;
    this->vantagem = vantagem;
    this->tipo = tipo;
}

int Mula::getVida(){
    return this->pontos_vida;
}

void Mula::setVida(int vida){
    this->pontos_vida = vida;
}

int Mula::getAtaque(){
    return this->ataque;
}

void Mula::setAtaque(int ataque){
     this->ataque = ataque;
}

int Mula::getDefesa(){
    return this->defesa;
}

void Mula::setDefesa(int defesa){
    this->defesa = defesa;
}

std::string Mula::getNome(){
    return this->nome;
}
void Mula::setNome(std::string nome){
    this->nome = nome;
}

std::vector<int> Mula::getVantagem(){
    return this->vantagem;
}

void Mula::setVantagem(std::vector<int> vantagem){
    this->vantagem = vantagem;
}

int Mula::getTipo(){
    return this->tipo;
}

void Mula::setTipo(int tipo){
    this->tipo = tipo;
}

void Mula::Ataque(Personagem *p, float sorte){
    //Calcula o golpe baseado no ataque e na vantagem do respectivo adversário;
    float golpe = this->ataque * sorte; //+ p.vantagem;
    
    std::cout << "sorte: " << sorte << std::endl;

    if( golpe - (p->getDefesa()) > 0){
    int NovaVida = p->getVida() - (golpe - (p->getDefesa()));
    p->setVida(NovaVida);
    }
}

void Mula::imprimePersonagem(){
    std::cout << "Nome: " << nome << std::endl << "Ataque: " << ataque << std::endl;
    std::cout << "Defesa: " << defesa << std::endl << "Vida: " << pontos_vida << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Vantagem sobre o tipo: " << vantagem[0] << std::endl;
}