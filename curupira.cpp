#include "curupira.hpp"

Curupira::Curupira(int pontos_vida, int ataque, int defesa, std::string nome, std::vector <int> vantagem, int tipo){
    this->pontos_vida = pontos_vida;
    this->ataque = ataque;
    this->defesa = defesa;
    this->nome = nome;
    this->vantagem = vantagem;
    this->tipo = tipo;    
}

int Curupira::getVida(){
    return this->pontos_vida;
}

void Curupira::setVida(int vida){
    this->pontos_vida = vida;
}

int Curupira::getAtaque(){
    return this->ataque;
}

void Curupira::setAtaque(int ataque){
     this->ataque = ataque;
}

int Curupira::getDefesa(){
    return this->defesa;
}

void Curupira::setDefesa(int defesa){
    this->defesa = defesa;
}

std::string Curupira::getNome(){
    return this->nome;
}
void Curupira::setNome(std::string nome){
    this->nome = nome;
}

std::vector<int> Curupira::getVantagem(){
    return this->vantagem;
}

void Curupira::setVantagem(std::vector<int> vantagem){
    this->vantagem = vantagem;
}

int Curupira::getTipo(){
    return this->tipo;
}

void Curupira::setTipo(int tipo){
    this->tipo = tipo;
}

void Curupira::Ataque(Personagem *p, float sorte){
    //Calcula o golpe baseado no ataque e na vantagem do respectivo adversário;
    float golpe = this->ataque * sorte; //+ p.vantagem;
    
    std::cout << "sorte: " << sorte << std::endl;

    if( golpe - (p->getDefesa()) > 0){
    int NovaVida = p->getVida() - (golpe - (p->getDefesa()));
    p->setVida(NovaVida);
    }
}

void Curupira::imprimePersonagem(){
    std::cout << "Nome: " << nome << std::endl << "Ataque: " << ataque << std::endl;
    std::cout << "Defesa: " << defesa << std::endl << "Vida: " << pontos_vida << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Vantagem sobre os tipos: " << vantagem[0] << " e " << vantagem[1] << std::endl;
}