/**
 * @file mula.hpp
 * @author Henrique (htofantini@ufmg.br)
 * @brief Arquivo que contém as assinaturas da classe Mula.
 * @version 0.1
 * @date 2022-12-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MULA_HPP
#define MULA_HPP
#include "personagem.hpp"

/**
 * @brief Classe que comanda a criação e ações do personagem Mula.
 * @details Implementa o Personagem Mula com seus atributos e métodos responsáveis por obter 
 * e atribuir suas características. Como cada Personagem possui seus próprios valores, os métodos
 * são do tipo sobrescrita. Além disso, possui uma função que vai imprimir na tela o Personagem
 * com seus atributos específicos quando chamada e uma função para declarar ataque a outro Personagem.
 * 
 */
class Mula : public Personagem {
    public: 

    /**
     * @brief Construct a new Mula object
     * 
     * @param pontos_vida 
     * @param ataque 
     * @param defesa 
     * @param nome 
     * @param vantagem 
     * @param tipo 
     */
        Mula(int pontos_vida, int ataque, int defesa, std::string nome, std::vector <int> vantagem, int tipo);

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
    * @brief Imprime informações específicas do Personagem
    * @details Imprime o nome do Personagem para o jogador que escolheu a Mula,
    * mostra sua vantagem contra o Personagem Curupira, além de mostrar os atributos 
    * ataque, defesa, pontos_vida e tipo.
    */

        void imprimePersonagem() override;

    /**
     * @brief Controla o Ataque específico da Mula.
     * @details Verifica se o Ataque é contra o Curupira e, se sim, gera um ataque crítico.
     * Caso o Ataque seja contra outro Personagem, permanece com um valor base 60~100% do ataque base. 
     *
     * @param p 
     * @param sorte 
     * @return int 
     */
        int Ataque(Personagem *p, float sorte) override;

};
#endif