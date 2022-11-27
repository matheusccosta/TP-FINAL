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

int Iara::Ataque(Personagem *p, float sorte){
   //Calcula o golpe baseado no ataque e na vantagem do respectivo adversário;
    float golpe = this->ataque * sorte; //+ p.vantagem;
    
    int dano = golpe - p->getDefesa();
    std::cout << "Dano: " <<dano <<std::endl;

    int NovaVida = p->getVida() - dano;
    std::cout<<"Vida do adversario: " << (int)NovaVida<<std::endl<<std::endl;

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