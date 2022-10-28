#include "iara.hpp"

Iara::Iara(int pontos_vida, int ataque, int defesa, std::string nome, std::vector <int> vantagem, int tipo){
    this->pontos_vida = pontos_vida;
    this->ataque = ataque;
    this->defesa = defesa;
    this->nome = nome;
    this->vantagem = vantagem;
    this->tipo = tipo;
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

void Iara::Ataque(Personagem *p, float sorte){
    //Calcula o golpe baseado no ataque e na vantagem do respectivo adversário;
    float golpe = this->ataque * sorte; //+ p.vantagem;
    
    std::cout << "sorte: " << sorte << std::endl;

    if( golpe - (p->getDefesa()) > 0){
    int NovaVida = p->getVida() - (golpe - (p->getDefesa()));
    p->setVida(NovaVida);
    }
}

void Iara::imprimePersonagem(){
    std::cout << "Nome: " << nome << std::endl << "Ataque: " << ataque << std::endl;
    std::cout << "Defesa: " << defesa << std::endl << "Vida: " << pontos_vida << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Vantagem sobre o tipo: " << vantagem[0] << std::endl;
}