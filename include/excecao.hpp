/**
 * @file excecao.hpp
 * @author Raony Marinho (raonym@ufmg.br)
 * @brief Arquivo responsável pela criação de uma exceção a partir da biblioteca padrão
 * @version 0.1
 * @date 2022-12-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef EXCECAO_HPP
#define EXCECAO_HPP
#include <iostream>

/**
 * @brief Classe que comanda a criação da nova exceção e sua construção
 * 
 * @details Implementa a exceção TipoInexistente que indica erro quando o jogador seleciona
 * um Personagem que não existe. Possui o construtor da mensagem de erros e a função what 
 * sobrescrita para retornar a mensagem de erro.
 */

class TipoInexistente : public std::exception {
    /**
     * @brief variável que armazena o tipo do Personagem selecionado
     * 
     */
    std::string tipo;
    /**
     * @brief variável que armazena a mensagem de erro que será exibida
     * 
     */
    std::string mensagem;

    public:
        /**
         * @brief Construct a new Tipo Inexistente object
         * @details O construtor recebe o tipo inválido escolhido pelo jogador e monta uma mensagem de erro
         * informando que o escolhido não existe e mostra quais existem.
         * @param t 
         */
        TipoInexistente(std::string t) {
            tipo = t;
            mensagem = "O tipo '" + tipo + "' escolhido nao existe. Digite um tipo valido (apenas 1, 2, 3 ou 4): ";
        }

        /**
         * @brief Função que retorna a mensagem de erro quando for chamada.
         * @details A função c_str() vai tornar a string mensagem em um tipo compatível (const char) e retornará a 
         * mensagem de erro quando ele for lançado e capturado.
         * @return const char* 
         */
        const char* what() const throw() override {
            return mensagem.c_str();
        }
};

#endif