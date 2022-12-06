#include "saci.hpp"

//Construtor seta os valores especificos do saci e recebe o nome do Jogador
Saci::Saci(std::string nome){
    this->pontos_vida = 100;
    this->ataque = 30;
    this->defesa = 20;
    this->nome = nome;
    vantagem.push_back(3);
    this->tipo = 1;   
}

//Funções gets e sets:
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

int Saci::Ataque(Personagem *p, float sorte){
    //Calcula o golpe baseado no ataque e na vantagem do respectivo adversário;
    float golpe = this->ataque * sorte; 
    
    int dano = golpe - p->getDefesa();

    if (p->getTipo() == 3)
        dano *=1.5;
    
    if( dano > 0)
            return dano;
        return 0;
}

//Imprime todos os atributos do personagem.
void Saci::imprimePersonagem(){
    std::cout << "Nome: " << nome << std::endl << "Ataque: " << ataque << std::endl;
    std::cout << "Defesa: " << defesa << std::endl << "Vida: " << pontos_vida << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Vantagem sobre o tipo: " << vantagem[0] << std::endl;
}