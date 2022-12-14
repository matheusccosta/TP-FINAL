/**
 * @file personagem.hpp
 * @author Henrique (htofantini@ufmg.br)
 * @brief Arquivo que contém as assinaturas virtuais da classe Personagem, que é uma interface.
 * @version 0.1
 * @date 2022-12-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <list>
#include <random>


/**
 * @brief Classe que é a mãe das outras personagens, contendo apenas funções puramente virtuais
 * @details Sendo apenas funções virtuais, essa classe não precisa ter funções próprias, pois Mula, Iara, Curupira e Saci
 * são apenas "tipos" de Personagem, não fazendo sentido um Personagem sem ser de um desses tipos descritos.
 */
class Personagem {
	protected:
            /**
             * @brief variável que armazena a vida do Personagem 
             * 
             */
			int pontos_vida; 
			/**
			 * @brief variável que armazena o ataque do Personagem
			 * 
			 */
			int ataque;
			/**
			 * @brief variável que armazena a defesa do Personagem
			 * 
			 */
			int defesa;
			/**
			 * @brief variável que armazena o nome do Personagem
			 * 
			 */
			std::string nome;
			/**
			 * @brief variável que vai armazenar a vantagem para cada tipo de confronto entre os Personagens
			 * 
			 */
			std::vector<int> vantagem;
			/**
			 * @brief variável que armazena o ataque do Personagem
			 * 
			 */
			int tipo;
			
	public: 

		//Personagem(int pontos_vida, int ataque, int defesa, std::string nome, int vantagem[2]);
/**
 * @brief Get the Vida object
 * 
 * @return int 
 */
		virtual int getVida() = 0;
/**
 * @brief Set the Vida object
 * 
 * @param vida 
 */
		virtual void setVida(int vida) = 0;
/**
 * @brief Get the Ataque object
 * 
 * @return int 
 */
		virtual int getAtaque() = 0;
/**
 * @brief Set the Ataque object
 * 
 * @param ataque 
 */
		virtual void setAtaque(int ataque) = 0;
/**
 * @brief Get the Defesa object
 * 
 * @return int 
 */
		virtual int getDefesa() = 0;
/**
 * @brief Set the Defesa object
 * 
 * @param defesa 
 */
		virtual void setDefesa(int defesa) = 0;

/**
 * @brief Get the Nome object
 * 
 * @return std::string 
 */

		virtual std::string getNome() = 0;
/**
 * @brief Set the Nome object
 * 
 * @param nome 
 */
		virtual void setNome(std::string nome) = 0;
/**
 * @brief Get the Vantagem object
 * 
 * @return std::vector<int> 
 */
		virtual std::vector<int> getVantagem() = 0;
/**
 * @brief Set the Vantagem object
 * 
 * @param vantagem 
 */
		virtual void setVantagem(std::vector<int> vantagem) = 0;
/**
 * @brief Get the Tipo object
 * 
 * @return int 
 */
		virtual int getTipo() = 0;
/**
 * @brief Set the Tipo object
 * 
 * @param tipo 
 */
		virtual void setTipo(int tipo) = 0;
/**
 * @brief Imprime os atributos específicos de cada Personagem.
 * 
 */
		virtual void imprimePersonagem() = 0;
/**
 * @brief Ataque que tem especificidades para cada tipo de Personagem.
 * 
 * @param p 
 * @param sorte 
 * @return int 
 */
		
		virtual int Ataque(Personagem *p, float sorte) = 0;

};
#endif