#ifndef DOMAINS_HPP_INCLUDED
#define DOMAINS_HPP_INCLUDED

#include <Domains/Headers/dominio_base.hpp>

// CODIGO
class Codigo : public Dominio{
    private:
        bool validar(string) override;

    public:
        Codigo(string v){
            if(!setValor(v));
        };
};
////////////////////////////////////////////////////////////////

// DATA
class Data : public Dominio{
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

// EMAIL
class Email : public Dominio{
    private:
        bool validar(string) override;

    public:
        Email(string v){
            if(!setValor(v));
        };
};

////////////////////////////////////////////////////////////////

// ESTADO
class Estado : public Dominio{
    private:
        bool validar(string) override;

    public:
        Estado(string v){
            if(!setValor(v));
        };
};

////////////////////////////////////////////////////////////////

// NOME
class Nome : public Dominio{
    private:
        bool validar(string) override;

    public:
        Nome(string v){
            if(!setValor(v));
        };
};

////////////////////////////////////////////////////////////////

// PAPEL
class Papel : public Dominio{
    private:
        bool validar(string) override;

    public:
        Papel(string v){
            if(!setValor(v));
        };
};

////////////////////////////////////////////////////////////////

// PRIORIDADE
class Prioridade : public Dominio{
    private:
        bool validar(string) override;

    public:
        Prioridade(string v){
            if(!setValor(v));
        };
};

////////////////////////////////////////////////////////////////

// SENHA
class Senha : public Dominio{
    private:
        bool validar(string) override;

    public:
        Senha(string v){
            if(!setValor(v));
        };
};

////////////////////////////////////////////////////////////////

// TEMPO
class Tempo : public Dominio{
    private:
        bool validar(string) override;

    public:
        Tempo(string v){
            if(!setValor(v));
        };
};
////////////////////////////////////////////////////////////////

// TEXTO
class Texto : public Dominio{
    private:
        bool validar(string) override;

    public:
        Texto(string v){
            if(!setValor(v));
        };
};

////////////////////////////////////////////////////////////////

#endif // DOMAINS_HPP_INCLUDED
