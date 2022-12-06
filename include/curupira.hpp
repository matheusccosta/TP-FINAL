/**
 * @file curupira.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CURUPIRA_HPP
#define CURUPIRA_HPP
#include "personagem.hpp"

/**
 * @brief 
 * 
 */
class Curupira : public Personagem{ 
    public: 
/**
 * @brief Construct a new Curupira object
 * 
 * @param pontos_vida 
 * @param ataque 
 * @param defesa 
 * @param nome 
 * @param vantagem 
 * @param tipo 
 */
        Curupira(int pontos_vida, int ataque, int defesa, std::string nome, std::vector <int> vantagem, int tipo);
/**
 * @brief Get the Vida object
 * 
 * @return int 
 */
        int getVida() override;
/**
 * @brief Set the Vida object
 * 
 * @param vida 
 */
        void setVida(int vida) override;
/**
 * @brief Get the Ataque object
 * 
 * @return int 
 */
        int getAtaque() override;
/**
 * @brief Set the Ataque object
 * 
 * @param ataque 
 */
        void setAtaque(int ataque) override;

/**
 * @brief Get the Defesa object
 * 
 * @return int 
 */
        int getDefesa() override;
/**
 * @brief Set the Defesa object
 * 
 * @param defesa 
 */
        void setDefesa(int defesa) override;
/**
 * @brief Get the Nome object
 * 
 * @return std::string 
 */
        std::string getNome() override;
/**
 * @brief Set the Nome object
 * 
 * @param nome 
 */
        void setNome(std::string nome) override;
/**
 * @brief Get the Vantagem object
 * 
 * @return std::vector<int> 
 */
        std::vector<int> getVantagem() override;
/**
 * @brief Set the Vantagem object
 * 
 * @param vantagem 
 */
        void setVantagem(std::vector<int> vantagem) override;
/**
 * @brief Get the Tipo object
 * 
 * @return int 
 */
        int getTipo() override;
/**
 * @brief Set the Tipo object
 * 
 * @param tipo 
 */
        void setTipo(int tipo) override;
/**
 * @brief 
 * 
 */
        void imprimePersonagem() override;
/**
 * @brief 
 * 
 * @param p 
 * @param sorte 
 * @return int 
 */
        int Ataque(Personagem *p, float sorte) override;

};
#endif