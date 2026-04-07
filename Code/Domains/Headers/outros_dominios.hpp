#ifndef DOMAINS_HPP_INCLUDED
#define DOMAINS_HPP_INCLUDED

#include <Domains/Headers/dominio_base.hpp>

class Tempo : Dominio{
    private:
        bool validar(string) override;

    public:
        Tempo(string v){
            if(!setValor(v));
        };
};
//////////////////////////////////////////////////////////
class Data : Dominio{
    private:
        bool ehBisexto(int) const;
        bool validar(string) override;

    public:
        Data(string v){
            if(!setValor(v));
        }  ; 
};

inline bool Data::ehBisexto(int ano) const{
    if((!ano%4 and ano%100) or (!ano%400 and !ano%100)) 
        return true;
    else 
        return false;
}
////////////////////////////////////////////////////////////////
class Codigo : Dominio{
    private:
        bool validar(string) override;

    public:
        Codigo(string v){
            if(!setValor(v));
        };
};
/////////////////////////////////////////////////////////////////

#endif // DOMAINS_HPP_INCLUDED
