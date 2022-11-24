#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <list>
#include <random>

class Personagem {
	protected:
			
			int pontos_vida;
			int ataque;
			int defesa;
			std::string nome;
			std::vector<int> vantagem;
			int tipo;
			
	public: 

		//Personagem(int pontos_vida, int ataque, int defesa, std::string nome, int vantagem[2]);

		virtual int getVida() = 0;
		virtual void setVida(int vida) = 0;

		virtual int getAtaque() = 0;
		virtual void setAtaque(int ataque) = 0;

		virtual int getDefesa() = 0;
		virtual void setDefesa(int defesa) = 0;

		virtual std::string getNome() = 0;
		virtual void setNome(std::string nome) = 0;

		virtual std::vector<int> getVantagem() = 0;
		virtual void setVantagem(std::vector<int> vantagem) = 0;

		virtual int getTipo() = 0;
		virtual void setTipo(int tipo) = 0;

		virtual void imprimePersonagem() = 0;

		//virtual
		virtual void Ataque(Personagem *p, float sorte) = 0;

};
#endif