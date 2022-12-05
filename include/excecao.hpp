#ifndef EXCECAO_HPP
#define EXCECAO_HPP
#include <iostream>

class TipoInexistente : public std::exception {
    std::string tipo;
    std::string mensagem;

    public:
        TipoInexistente(std::string t) {
            tipo = t;
            mensagem = "O tipo '" + tipo + "' escolhido nao existe. Digite um tipo valido (apenas 1, 2, 3 ou 4): ";
        }

        const char* what() const throw() override {
            return mensagem.c_str();
        }
};

#endif