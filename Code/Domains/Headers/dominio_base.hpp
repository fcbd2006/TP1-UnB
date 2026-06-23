#ifndef DOMINIO_HPP_INCLUDED
#define DOMINIO_HPP_INCLUDED
#include <string>

/**
 * @file dominio_base.hpp
 * @brief Declaração da classe base abstrata para todos os domínios do sistema.
 */

/**
 * @class Dominio
 * @brief Classe base abstrata para padronização dos domínios.
 ** Esta classe fornece a estrutura fundamental para armazenar um valor de domínio. 
 * As classes derivadas devem obrigatoriamente implementar a lógica específica 
 * de validação através do método validar().
 */
class Dominio {
    private:
        /**
         * @brief Atributo que armazena o valor do domínio.
         */
        std::string valor;

        /**
         * @brief Método virtual puro para validação do valor.
         * @param valor_candidato O valor a ser testado pelas regras de validação da classe filha.
         ** Este método é chamado automaticamente pelo método setValor().
         * Classes filhas devem implementá-lo, tipicamente lançando uma exceção (ex: std::invalid_argument)
         * caso a validação falhe.
         */
        virtual void validar(const std::string& valor_candidato) = 0;

    public:
        /**
         * @brief Construtor padrão da classe domínio. 
        */
        Dominio() = default;

        /** 
         * @brief Destrutor virtual padrão da classe domínio.
         * Garante a destruição correta das classes derivadas.
        */
        virtual ~Dominio() = default;

        /** 
         * @brief Método para definir o valor do domínio.
         * @param valor O valor em formato de string a ser validado e armazenado no domínio.
        */ 
        void setValor(const std::string& valor);

        /**
         * @brief Método para obter o valor do domínio.
         * @return Retorna uma referência constante para a string contendo o valor do domínio.
         */
        const std::string& getValor() const;
        
        /**
         * @brief Sobrecarga do operador de igualdade.
         * Compara o valor deste domínio com o valor de outro domínio.
         * @param outro O objeto Dominio a ser comparado.
         * @return true Se os valores armazenados forem estritamente iguais.
         * @return false Se os valores forem diferentes.
         */
        bool operator==(const Dominio& outro) const;

        /**
         * @brief Sobrecarga do operador de desigualdade (menor que).
         * Compara o valor deste domínio com o valor de outro domínio.
         * @param outro O objeto Dominio a ser comparado.
         * @return true Se o valor à esquerda for menor que o à direita.
         * @return false caso contrário.
         */
        bool operator<(const Dominio& outro) const;

};

// Método para acesso do valor armazenado
inline const std::string& Dominio::getValor() const{
    return valor;
}

// Método para armazenar um valor
inline void Dominio::setValor(const std::string& valor){
    validar(valor);
    this->valor = valor;
}

// Operador de Igualdade
inline bool Dominio::operator==(const Dominio& outro) const {
    return this->valor == outro.valor;
}

// Operador de menor que
inline bool Dominio::operator<(const Dominio& outro) const {
    return this->valor < outro.valor;
}

#endif