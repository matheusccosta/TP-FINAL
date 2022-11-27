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

int Curupira::Ataque(Personagem *p, float sorte){
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

void Curupira::imprimePersonagem(){
    std::cout << "Nome: " << nome << std::endl << "Ataque: " << ataque << std::endl;
    std::cout << "Defesa: " << defesa << std::endl << "Vida: " << pontos_vida << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Vantagem sobre os tipos: " << vantagem[0] << " e " << vantagem[1] << std::endl;
}