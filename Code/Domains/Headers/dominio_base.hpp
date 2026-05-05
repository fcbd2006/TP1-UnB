#ifndef DOMINIO_HPP_INCLUDED
#define DOMINIO_HPP_INCLUDED

#include <string>

// Declaração de classe base para padronização dos domínios
class Dominio {
    private:
        std::string valor;
        virtual void validar(const std::string&) = 0;

    public:
        Dominio() = default;
        virtual ~Dominio() = default;
        void setValor(const std::string&);
        const std::string& getValor() const;
};

// Método para acesso do valor armazenado
inline const std::string& Dominio::getValor() const{
    return valor;
}

// Método para armazenar um valor
inline void Dominio::setValor(const std::string& value){
    validar(value);
    valor=value;
}

#endif