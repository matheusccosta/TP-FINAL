#include "curupira.hpp"

Curupira::Curupira(std::string nome){
    this->pontos_vida = 100;
    this->ataque = 30;
    this->defesa = 15;
    this->nome = nome;
    vantagem.push_back(1);
    vantagem.push_back(3);
    this->tipo = 4;    

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

int Curupira::Ataque(Personagem *p, float sorte){
    //Calcula o golpe baseado no ataque e na vantagem do respectivo adversário;
    float golpe = this->ataque * sorte; //+ p.vantagem;
    int dano = golpe - p->getDefesa();

    if (p->getTipo() == 3 || p->getTipo() == 1)
        dano *=1.7;

    if( dano > 0)
            return dano;
        return 0;
   
}

void Curupira::imprimePersonagem(){
    std::cout << "Nome: " << nome << std::endl << "Ataque: " << ataque << std::endl;
    std::cout << "Defesa: " << defesa << std::endl << "Vida: " << pontos_vida << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Vantagem sobre os tipos: " << vantagem[0] << " e " << vantagem[1] << std::endl;
}