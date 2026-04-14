#ifndef DOMINIO_HPP_INCLUDED
#define DOMINIO_HPP_INCLUDED

#include <string>

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

inline const std::string& Dominio::getValor() const{
    return valor;
}

inline void Dominio::setValor(const std::string& value){
    validar(value);
    valor=value;
}

#endif