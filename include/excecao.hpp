/**
 * @file excecao.hpp
 * @author your name (you@domain.com)
 * @brief 
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
 * @brief 
 * 
 */

class TipoInexistente : public std::exception {
    std::string tipo;
    std::string mensagem;

    public:
/**
 * @brief Construct a new Tipo Inexistente object
 * 
 * @param t 
 */
        TipoInexistente(std::string t) {
            tipo = t;
            mensagem = "O tipo '" + tipo + "' escolhido nao existe. Digite um tipo valido (apenas 1, 2, 3 ou 4): ";
        }

/**
 * @brief 
 * 
 * @return const char* 
 */

        const char* what() const throw() override {
            return mensagem.c_str();
        }
};

#endif