#ifndef DOMAINS_HPP_INCLUDED
#define DOMAINS_HPP_INCLUDED

#include <Domains/Headers/dominio_base.hpp>

// Declarações dos domínios

// CODIGO
/**
 * @class Codigo
 * @brief Representa o domínio de um código de identificação.
 * * Esta classe herda da classe base Dominio e garante a integridade de um valor de
 * código, que deve seguir todas as regras de formatação do sistema.
 */
class Codigo : public Dominio{
    private:
    /**
     * @brief Método de validação específico para o domínio Codigo.
     * * Este método é responsável por verificar se o valor do código atende aos critérios de formatação
     * estabelecidos pelo sistema.
     */
        void validar(const std::string&) override;

    public:
    /**
     * @brief Construtor para a classe Codigo.
     * @param v String contendo o valor do código a ser armazenado.
     * * Este construtor recebe uma string como argumento e utiliza o método setValor() para armazenar o valor do código,
     * garantindo que a validação seja realizada automaticamente.
     */
        Codigo(const std::string& v){
            setValor(v);
        }
};

//-----------------------------------------------------------

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

// Método para verificar se o ano é bissexto ou não
inline bool Data::ehBisexto(int ano) const{
    if((!ano%4 && ano%100) || (!ano%400 && !ano%100)) 
        return true;
    else 
        return false;
}

//-----------------------------------------------------------


// EMAIL
class Email : public Dominio{
    private:
        void validar(const std::string&) override;
        void validar_formato(const std::string&);

    public:
        Email(std::string v){
            setValor(v);
        }
};

//-----------------------------------------------------------

// ESTADO
class Estado : public Dominio{
    private:
        void validar(const std::string&) override;

    public:
        Estado(std::string v){
            setValor(v);
        }
};

//-----------------------------------------------------------

// NOME
class Nome : public Dominio{
    private:
        void validar(const std::string&) override;

    public:
        Nome(std::string v){
            setValor(v);
        }
};

//-----------------------------------------------------------

// PAPEL
class Papel : public Dominio{
    private:
        void validar(const std::string&) override;

    public:
        Papel(std::string v){
            setValor(v);
        }
};

//-----------------------------------------------------------

// PRIORIDADE
class Prioridade : public Dominio{
    private:
        void validar(const std::string&) override;

    public:
        Prioridade(std::string v){
            setValor(v);
        };
};

//-----------------------------------------------------------

// SENHA
class Senha : public Dominio{
    private:
        void validar(const std::string&) override;

    public:
        Senha(std::string v){
            setValor(v);
        };
};

//-----------------------------------------------------------

// TEMPO
class Tempo : public Dominio{
    private:
        void validar(const std::string&) override;

    public:
        Tempo(std::string v){
            setValor(v);
        };
};

//-----------------------------------------------------------

// TEXTO
class Texto : public Dominio{
    private:
        void validar(const std::string&) override;

    public:
        Texto(std::string v){
            setValor(v);
        };
};

//-----------------------------------------------------------

#endif // DOMAINS_HPP_INCLUDED