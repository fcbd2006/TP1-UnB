#ifndef DOMINIO_HPP_INCLUDED
#define DOMINIO_HPP_INCLUDED
#include <string>

/**
 * @class Dominio
 * @brief Classe base abstrata para padronização dos domínios.
 * * Esta classe fornece a estrutura fundamental para armazenar um valor de domínio. 
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
         ** Este método é chamado automaticamente pelo método setValor().
         * Classes filhas devem implementá-lo, tipicamente lançando uma exceção (ex: std::invalid_argument)
         * caso a validação falhe.
         */
        virtual void validar(const std::string&) = 0;

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
        */ 
        void setValor(const std::string&);

        /** @brief Método para obter o valor do domínio.
         * @return Retorna uma referência constante para a string contendo o valor do domínio.
         */
        const std::string& getValor() const;
};

// Método para acesso do valor armazenado
inline const std::string& Dominio::getValor() const{
    return valor;
}

// Método para armazenar um valor
inline void Dominio::setValor(const std::string& value){
    validar(value);
    valor = value;
}

#endif