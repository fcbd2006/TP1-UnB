#ifndef DOMAINS_HPP_INCLUDED
#define DOMAINS_HPP_INCLUDED

#include <Domains/Headers/dominio_base.hpp>

// CODIGO
class Codigo : public Dominio{
    private:
        void validar(const std::string&) override;

    public:
        Codigo(const std::string& v){
            setValor(v);
        }
};
////////////////////////////////////////////////////////////////

// DATA
class Data : public Dominio{
    private:
        bool ehBisexto(int) const;
        void validar(const std::string&) override;

    public:
        Data(std::string v){
            setValor(v);
        } 
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
        void validar(const std::string&) override;

    public:
        Email(std::string v){
            setValor(v);
        }
};

////////////////////////////////////////////////////////////////

// ESTADO
class Estado : public Dominio{
    private:
        void validar(const std::string&) override;

    public:
        Estado(std::string v){
            setValor(v);
        }
};

////////////////////////////////////////////////////////////////

// NOME
class Nome : public Dominio{
    private:
        void validar(const std::string&) override;

    public:
        Nome(std::string v){
            setValor(v);
        }
};

////////////////////////////////////////////////////////////////

// PAPEL
class Papel : public Dominio{
    private:
        void validar(const std::string&) override;

    public:
        Papel(std::string v){
            setValor(v);
        }
};

////////////////////////////////////////////////////////////////

// PRIORIDADE
class Prioridade : public Dominio{
    private:
        void validar(const std::string&) override;

    public:
        Prioridade(std::string v){
            setValor(v);
        };
};

////////////////////////////////////////////////////////////////

// SENHA
class Senha : public Dominio{
    private:
        void validar(const std::string&) override;

    public:
        Senha(std::string v){
            setValor(v);
        };
};

////////////////////////////////////////////////////////////////

// TEMPO
class Tempo : public Dominio{
    private:
        void validar(const std::string&) override;

    public:
        Tempo(std::string v){
            setValor(v);
        };
};
////////////////////////////////////////////////////////////////

// TEXTO
class Texto : public Dominio{
    private:
        void validar(const std::string&) override;

    public:
        Texto(std::string v){
            setValor(v);
        };
};

////////////////////////////////////////////////////////////////

#endif // DOMAINS_HPP_INCLUDED
