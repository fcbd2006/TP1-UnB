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
         * @param valor_candidato String contendo o valor do código a ser validado.
         * * Este método é responsável por verificar se o valor do código atende aos critérios de formatação
         * estabelecidos pelo sistema. Lançará uma exceção em caso de falha.
         */
        void validar(const std::string& valor_candidato) override;

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
        bool ehBisexto(int ano) const;

        /**
         * @brief Método de validação específico para o domínio Data.
         * @param valor_candidato String contendo o valor da data a ser validado.
         * * Este método é responsável por verificar se o valor da data atende aos critérios de formatação e validade, 
         * incluindo a verificação de dias, meses e anos, bem como a consideração de anos bissextos.
         */
        void validar(const std::string& valor_candidato) override;

    public:
        /**
         * @brief Construtor da classe Data.
         * @param v String contendo o valor da data a ser armazenada.
         * * Este construtor recebe uma string como argumento e utiliza o método setValor() para armazenar o valor da data, 
         * garantindo que a validação seja realizada automaticamente.
         */
        Data(const std::string& v){
            setValor(v);
        };
        
        /**
         * @brief Construtor padrão.
         */
        Data() = default;
};

// Método para verificar se o ano é bissexto ou não
inline bool Data::ehBisexto(int ano) const{
    if(((!(ano%4)) && (ano%100)) || ((!(ano%400)) && (!(ano%100)))) 
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
         * @param valor_candidato O valor do email a ser validado.
         * * Este método é responsável por verificar se o valor do email atende aos critérios de formatação específicos, como a presença de um símbolo '@'
         * e um domínio válido após o símbolo, garantindo que apenas endereços de email corretamente formatados sejam aceitos pelo sistema.
         * Lançará uma exceção em caso de falha na validação.
         */
        void validar(const std::string& valor_candidato) override;

        /**
         * @brief Método auxiliar para validar o formato do email.
         * @param parte String a ser analisada.
         * * Este método auxiliar verifica as regras sintáticas das partes do email, como a presença obrigatória e única do '@', uso correto de pontos e ausência de
         * caracteres inválidos.
         */
        void validar_formato(const std::string& parte) const;

    public:
        /**
         * @brief Construtor parametrizado da classe Email.
         * @param v String com o email a ser armazenado.
         * * Este construtor recebe uma string como argumento e utiliza o método setValor() para armazenar o valor do email, garantindo que a validação seja
         * realizada automaticamente e que apenas endereços de email corretamente formatados sejam aceitos pelo sistema. Lançará uma exceção em caso de falha na validação.
         * 
         */
        Email(const std::string& v){
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
/**
 * @class Estado
 * @brief Representa o domínio de um Estado (status de progresso).
 * * Esta classe herda da classe base Dominio e é responsável por armazenar 
 * e garantir a validade do status de uma atividade ou processo no sistema.
 */
class Estado : public Dominio{
    private:
        /**
         * @brief Método de validação específico para o dommínio Estado.
         * @param valor_candidato String contendo o estado a ser testado.
         * * Sobrescreve a função virtual pura da classe base. Este método 
         * deve verificar se a string fornecida corresponde a um estado válido dentro das epecificações do sistema. Lançará uma exceção em caso de falha na validação.
         */
        void validar(const std::string& valor_candidato) override;

    public:
        /**
         * @brief Construtor parametrizado da classe Estado.
         * @param v String contendo o estado a ser armazenado.
         * * Este construtor recebe uma string como argumento e utiliza o método setValor() para armazenar o valor do estado, garantindo que a validação
         *  seja realizada automaticamente e que apenas estados válidos sejam aceitos pelo sistema. Lançará uma exceção em caso de falha na validação.
         */
        Estado(const std::string& v){
            setValor(v);
        };

        /**
         * @brief Construtor padrão da classe Estado.
         * * Permite criar um objeto Estado sem um status inicial definido. 
         * Útil para instanciar o objeto primeiramente e atribuir o seu valor 
         * mais tarde através do método setValor().
         */
        Estado() = default;
};

//-----------------------------------------------------------

// NOME
/**
 * @class Nome
 * @brief Representa o domínio de um Nome.
 * * Esta classe herda da classe base Dominio e é responsável por armazenar 
 * e garantir a validade de uma string que representa um nome.
 */
class Nome : public Dominio{
    private:
        /**
         * @brief Implementa a regra de validação para um Nome.
         * @param valor_candidato String contendo o nome a ser testado.
         * * Sobrescreve a função virtual pura da classe base. Este método 
         * deve verificar se a string atende aos critérios de formatação 
         * do sistema para nomes. Lançará uma exceção em caso de falha na validação.
         */
        void validar(const std::string& valor_candidato) override;

    public:
        /**
         * @brief Construtor parametrizado da classe Nome.
         * @param v String com o nome inicial a ser atribuído.
         * * Ao ser instanciado, o construtor repassa o valor recebido para 
         * o método setValor(), que automaticamente invoca a validação antes de armazenar o dado. Lançará uma exceção em caso de falha na validação.
         */
        Nome(const std::string& v){
            setValor(v);
        };

        /**
         * @brief Construtor padrão da classe Nome.
         * * Permite a instanciação de um objeto Nome sem um valor inicial. 
         * O valor real deverá ser inserido posteriormente através do 
         * método setValor().
         */
        Nome() = default;
};

//-----------------------------------------------------------

// PAPEL
/**
 * @class Papel
 * @brief Representa o domínio de um Papel (contribuição no projeto).
 * * Esta classe herda da classe base Dominio e é responsável por armazenar 
 * e garantir a validade da função desempenhada por um indivíduo dentro 
 * do contexto de um projeto ou programa.
 */
class Papel : public Dominio{
    private:
        /**
         * @brief Implementa a regra de validação para o Papel.
         * @param valor_candidato String contendo o papel a ser testado.
         * * Sobrescreve a função virtual pura da classe base. Este método 
         * deve verificar se a string fornecida corresponde estritamente a 
         * um dos papéis permitidos pelo sistema (por exemplo: "desenvolvedor"). Lançará uma exceção em caso de falha na validação.
         */
        void validar(const std::string& valor_candidato) override;

    public:
    /**
         * @brief Construtor parametrizado da classe Papel.
         * @param v String com o papel inicial a ser atribuído.
         * * Ao ser instanciado, o construtor repassa o valor recebido para 
         * o método setValor(), que automaticamente 
         * invoca a validação restrita antes de armazenar o dado.
         */
        Papel(const std::string& v){
            setValor(v);
        };

        /**
         * @brief Construtor padrão da classe Papel.
         * * Permite a instanciação de um objeto Papel sem um valor inicial. 
         * Útil para alocação prévia, sendo que o valor real deverá ser 
         * inserido posteriormente através do método setValor().
         */
        Papel() = default;
};

//-----------------------------------------------------------

// PRIORIDADE
/**
 * @class Prioridade
 * @brief Representa o domínio de uma Prioridade.
 * * Esta classe herda da classe base Dominio e é responsável por armazenar 
 * e garantir a validade do nível de importância ou urgência de uma 
 * atividade/entidade no sistema.
 */
class Prioridade : public Dominio{
    private:
        /**
         * @brief Implementa a regra de validação para a Prioridade.
         * @param valor_candidato String contendo a prioridade a ser testada.
         * * Sobrescreve a função virtual pura da classe base. Este método 
         * deve verificar se a string fornecida corresponde estritamente a 
         * um dos níveis de prioridade permitidos pelas regras do sistema 
         * (por exemplo: "Alta", "Média" ou "Baixa"). Lançará uma exceção em caso de falha na validação.
         */
        void validar(const std::string& valor_candidato) override;

    public:
        /**
         * @brief Construtor parametrizado da classe Prioridade.
         * @param v String com a prioridade inicial a ser atribuída.
         * * Ao instanciar o objeto, o valor é repassado ao método setValor(), 
         * que aciona automaticamente a validação antes 
         * do armazenamento definitivo.
         */
        Prioridade(const std::string& v){
            setValor(v);
        };

        /**
         * @brief Construtor padrão da classe Prioridade.
         * * Permite a criação de um objeto Prioridade sem um valor inicial 
         * definido. O valor real deverá ser atribuído posteriormente 
         * utilizando o método setValor().
         */
        Prioridade() = default;
};

//-----------------------------------------------------------

// SENHA
/**
 * @class Senha
 * @brief Representa o domínio de uma Senha.
 * * Esta classe herda da classe base Dominio e é responsável por armazenar 
 * e garantir a validade e o nível de segurança (Presença de letras maiúsculas, minúsculas, números e tamanho) de uma senha utilizada 
 * para autenticação no sistema.
 */
class Senha : public Dominio{
    private:
        /**
         * @brief Implementa a regra de validação de segurança para a Senha.
         * @param valor_candidato String contendo a senha a ser testada.
         * * Sobrescreve a função virtual pura da classe base. Este método 
         * deve verificar se a string atende aos rigorosos critérios de 
         * formatação e segurança do sistema (por exemplo: tamanho mínimo/máximo, 
         * exigência de letras maiúsculas/minúsculas, números
         * e ausência de espaços em branco). Lançará uma exceção em caso de falha na validação.
         */
        void validar(const std::string& valor_candidato) override;

    public:
        /**
         * @brief Construtor parametrizado da classe Senha.
         * @param v String com a senha inicial a ser atribuída.
         * * Ao instanciar o objeto, o valor é repassado ao método setValor(), 
         * que aciona automaticamente a validação de 
         * segurança antes de permitir o armazenamento da senha.
         */
        Senha(const std::string& v){
            setValor(v);
        };

        /**
         * @brief Construtor padrão da classe Senha.
         * * Permite a criação de um objeto Senha sem um valor inicial 
         * definido. O valor real deverá ser atribuído posteriormente 
         * utilizando o método setValor().
         */
        Senha() = default;
};

//-----------------------------------------------------------

// TEMPO
/**
 * @class Tempo
 * @brief Representa o domínio de Tempo.
 * * Esta classe herda da classe base Dominio e é responsável por armazenar 
 * e garantir a validade de um período de tempo, estritamente limitado 
 * ao intervalo de 1 a 365.
 */
class Tempo : public Dominio{
    private:
        /**
         * @brief Implementa a regra de validação para o Tempo.
         * @param valor_candidato String contendo o valor numérico a ser testado.
         * * Sobrescreve a função virtual pura da classe base. Este método 
         * deve converter a string fornecida para um valor numérico (inteiro) 
         * e verificar se ele se encontra dentro do intervalo fechado [1, 365]. Lançará uma exceção em caso de falha na validação.
         */
        void validar(const std::string& valor_candidato) override;

    public:
        /**
         * @brief Construtor parametrizado da classe Tempo.
         * @param v String com o valor numérico de tempo a ser atribuído.
         * * Ao instanciar o objeto, o valor é repassado ao método setValor(), 
         * que aciona automaticamente a validação de 
         * intervalo matemático antes de permitir o armazenamento.
         */
        Tempo(const std::string& v){
            setValor(v);
        };

        /**
         * @brief Construtor padrão da classe Tempo.
         * * Permite a criação de um objeto Tempo sem um valor inicial 
         * definido. O valor real deverá ser atribuído posteriormente 
         * utilizando o método setValor().
         */
        Tempo() = default;
};

//-----------------------------------------------------------

// TEXTO
/**
 * @class Texto
 * @brief Representa o domínio de um Texto.
 * * Esta classe herda da classe base Dominio e é responsável por armazenar 
 * e garantir a validade de uma string de texto livre (como descrições, 
 * comentários, mensagens ou detalhamentos), respeitando as regras de 
 * formatação do sistema.
 */
class Texto : public Dominio{
    private:
        /**
         * @brief Implementa a regra de validação para o Texto.
         * @param valor_candidato String contendo o texto a ser testado.
         * * Sobrescreve a função virtual pura da classe base. Este método 
         * deve verificar se a string fornecida atende às regras do sistema
         * para textos (por exemplo: tamanho mínimo e máximo de caracteres, 
         * formatação de espaçamento ou restrição a determinados caracteres 
         * especiais). Lançará uma exceção em caso de falha na validação.
         */
        void validar(const std::string& valor_candidato) override;

    public:
        /**
         * @brief Construtor parametrizado da classe Texto.
         * @param v String com o texto inicial a ser atribuído.
         * * Ao ser instanciado, o construtor repassa o valor recebido para 
         * o método setValor(), que automaticamente 
         * invoca a validação antes de armazenar o dado.
         */
        Texto(const std::string& v){
            setValor(v);
        };

        /**
         * @brief Construtor padrão da classe Texto.
         * * Permite a instanciação de um objeto Texto sem um valor inicial. 
         * O valor real deverá ser inserido posteriormente através do 
         * método setValor().
         */
        Texto() = default;
};

//-----------------------------------------------------------

#endif // DOMAINS_HPP_INCLUDED