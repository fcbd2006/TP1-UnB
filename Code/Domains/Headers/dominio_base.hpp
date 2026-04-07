#ifndef DOMINIO_HPP_INCLUDED
#define DOMINIO_HPP_INCLUDED

#include <string>
using namespace std;

class Dominio {
    private:
        string valor;
        virtual bool validar(string) = 0;

    public:
        Dominio() = default;
        bool setValor(string);
        string getValor() const;
};

inline string Dominio::getValor() const{
    return valor;
}

inline bool Dominio::setValor(string value){
    if(!validar(value)) return false;
    valor=value;
    return true;
}

#endif