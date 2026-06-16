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
         * @param string String contendo o valor do código a ser validado.
         * * Este método é responsável por verificar se o valor do código atende aos critérios de formatação
         * estabelecidos pelo sistema. Lançará uma exceção em caso de falha.
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
        };

        /**
         * @brief Construtor padrão.
         */
        Codigo() = default;
};

//-----------------------------------------------------------

// DATA
/**
 * @class Data
 * @brief Representa o domínio de uma data.
 * * Esta classe herda da classe base Dominio e garante a integridade de um valor de data,
 * que deve seguir as regras de formatação e validade de datas estabelecidas pelo sistema, inclusive anos bissextos.
 */
class Data : public Dominio{
    private:
        /**
         * @brief Verifica se determinado ano é bissexto.
         * @param ano O ano a ser verificado.
         * @return Retorna true se o ano for bissexto, ou false caso contrário.
         * * Este método atua como uma função auxiliar para o método de validação da classe Data,
         * garantindo que datas como 29 de fevereiro sejam aceitas apenas em anos bissextos.
         */
        bool ehBisexto(int) const;

        /**
         * @brief Método de validação específico para o domínio Data.
         * * Este método é responsável por verificar se o valor da data atende aos critérios de formatação e validade,
         * incluindo a verificação de dias, meses e anos, bem como a consideração de anos bissextos.
         */
        void validar(const std::string&) override;

    public:
        /**
         * @brief Construtor da classe Data.
         * @param v String contendo o valor da data a ser armazenada.
         * * Este construtor recebe uma string como argumento e utiliza o método setValor() para armazenar o valor da data,
         * garantindo que a validação seja realizada automaticamente.
         */
        Data(std::string v){
            setValor(v);
        };
        
        /**
         * @brief Construtor padrão.
         */
        Data() = default;
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
/**
 * @class Email
 * @brief Representa o domínio de um endereço de email.
 * * Esta classe herda da classe base Dominio e armazena e garante a integridade de um valor de email, que deve seguir as regras de formatação
 * de endereço de email estabelecidas pelo sistema, incluindo a presença de um símbolo '@' e um domínio válido após o símbolo como em "usuario@dominio.com".
 */
class Email : public Dominio{
    private:
        /**
         * @brief Método de validação específico para o domínio Email.
         * @param string O valor do email a ser validado.
         * * Este método é responsável por verificar se o valor do email atende aos critérios de formatação específicos, como a presença de um símbolo '@'
         * e um domínio válido após o símbolo, garantindo que apenas endereços de email corretamente formatados sejam aceitos pelo sistema.
         * Lançará uma exceção em caso de falha na validação.
         */
        void validar(const std::string&) override;

        /**
         * @brief Método auxiliar para validar o formato do email.
         * @param string String a ser analisada.
         * * Este método auxiliar verifica as regras sintáticas do email, como a presença obrigatória e única do '@', uso correto de pontos e ausência de
         * caracteres inválidos.
         */
        void validar_formato(const std::string&);

    public:
        /**
         * @brief Construtor parametrizado da classe Email.
         * @param v String com o email a ser armazenado.
         * * Este construtor recebe uma string como argumento e utiliza o método setValor() para armazenar o valor do email, garantindo que a validação seja
         * realizada automaticamente e que apenas endereços de email corretamente formatados sejam aceitos pelo sistema. Lançará uma exceção em caso de falha na validação.
         * 
         */
        Email(std::string v){
            setValor(v);
        };
        
        /**
         * @brief Construtor padrão da classe Email.
         * * Permite a instanciação de um objeto Email sem um valor inicial. O valor real deverá ser inserido posteriormente através do método setValor().
         */
        Email() = default;
};

//-----------------------------------------------------------

// ESTADO
class Estado : public Dominio{
    private:
        void validar(const std::string&) override;

    public:
        Estado(std::string v){
            setValor(v);
        };

        Estado() = default;
};

//-----------------------------------------------------------

// NOME
class Nome : public Dominio{
    private:
        void validar(const std::string&) override;

    public:
        Nome(std::string v){
            setValor(v);
        };

        Nome() = default;
};

//-----------------------------------------------------------

// PAPEL
class Papel : public Dominio{
    private:
        void validar(const std::string&) override;

    public:
        Papel(std::string v){
            setValor(v);
        };

        Papel() = default;
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

        Prioridade() = default;
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

        Senha() = default;
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

        Tempo() = default;
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

        Texto() = default;
};

//-----------------------------------------------------------

#endif // DOMAINS_HPP_INCLUDED