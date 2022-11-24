#include "saci.hpp"

Saci::Saci(int pontos_vida, int ataque, int defesa, std::string nome, std::vector <int> vantagem, int tipo){
    this->pontos_vida = pontos_vida;
    this->ataque = ataque;
    this->defesa = defesa;
    this->nome = nome;
    this->vantagem = vantagem;
    this->tipo = tipo; 
}

int Saci::getVida(){
    return this->pontos_vida;
}

void Saci::setVida(int vida){
    this->pontos_vida = vida;
}

int Saci::getAtaque(){
    return this->ataque;
}

void Saci::setAtaque(int ataque){
     this->ataque = ataque;
}

int Saci::getDefesa(){
    return this->defesa;
}

void Saci::setDefesa(int defesa){
    this->defesa = defesa;
}

std::string Saci::getNome(){
    return this->nome;
}
void Saci::setNome(std::string nome){
    this->nome = nome;
}

std::vector<int> Saci::getVantagem(){
    return this->vantagem;
}

void Saci::setVantagem(std::vector<int> vantagem){
    this->vantagem = vantagem;
}

int Saci::getTipo(){
    return this->tipo;
}

void Saci::setTipo(int tipo){
    this->tipo = tipo;
}

void Saci::Ataque(Personagem *p, float sorte){
    //Calcula o golpe baseado no ataque e na vantagem do respectivo adversário;
    float golpe = this->ataque * sorte; //+ p.vantagem;
    int dano = golpe - p->getDefesa();
    std::cout << "Dano: " <<dano <<std::endl;


    if( dano > 0){
    int NovaVida = p->getVida() - dano;
    p->setVida(NovaVida);
    std::cout<<"Vida do adversario: " << NovaVida<<std::endl<<std::endl;
    }
}

void Saci::imprimePersonagem(){
    std::cout << "Nome: " << nome << std::endl << "Ataque: " << ataque << std::endl;
    std::cout << "Defesa: " << defesa << std::endl << "Vida: " << pontos_vida << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Vantagem sobre o tipo: " << vantagem[0] << std::endl;
}