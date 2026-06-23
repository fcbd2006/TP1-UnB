#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED
#include "Domains/Headers/outros_dominios.hpp"

/**
 * @file entidades.hpp
 * @brief Declaração das classes entidade do sistema: Pessoa, Projeto, PlanoDeSprint e HistoriaDeUsuario.
 */

/**
 * @class Pessoa
 * @brief Entidade que representa um usuário ou colaborador do sistema.
 * Agrupa as informações essenciais de um indivíduo, utilizando domínios 
 * já validados para garantir a integridade dos dados de contato, 
 * credenciais e responsabilidades.
 */
class Pessoa{
    private:
        Email email; ///< Endereço de email do usuário.
        Nome nome; ///< Nome formatado do usuário.
        Senha senha; ///< Credencial de acesso do usuário.
        Papel papel; ///< Função desempenhada pelo usuário dento do sistema (ex: desenvolvedor).

    public:
        // Construtor
        //Pessoa(const Email& email, const Nome& nome, const Senha& senha, const Papel& papel): 
        //papel(papel), email(email), nome(nome), senha(senha){};
        /**
         * @brief Construtor padrão da classe Pessoa.
         */
        Pessoa() = default;

        // Destrutor
        /**
         * @brief Destrutor virtual da classe Pessoa.
         */
        virtual ~Pessoa() = default;

        // Métodos getters referentes aos atributos da Entidade
        /** 
         * @brief Recupera o e-mail da pessoa. 
         * @return Objeto do domínio Email. 
         */
        Email getEmail() const{return email;};
        /** 
         * @brief Recupera o nome da pessoa. 
         * @return Objeto do domínio Nome. 
         */
        Nome getNome() const{return nome;};
        /** 
         * @brief Recupera a senha da pessoa. 
         * @return Objeto do domínio Senha. 
         */
        Senha getSenha() const{return senha;};
        /** 
         * @brief Recupera o papel da pessoa. 
         * @return Objeto do domínio Papel. 
         */
        Papel getPapel() const{return papel;};
        //Métodos setters referentes aos atributos da Entidade
        /** 
         * @brief Atribui um e-mail validado. 
         * @param email Objeto Email. 
         */
        void setEmail(const Email& email){this->email = email;};
        /** 
         * @brief Atribui um nome validado. 
         * @param nome Objeto Nome. 
         */
        void setNome(const Nome& nome){this->nome = nome;};
        /** 
         * @brief Atribui uma senha validada. 
         * @param senha Objeto Senha. 
         */
        void setSenha(const Senha& senha){this->senha = senha;};
        /** 
         * @brief Atribui um papel validado. 
         * @param papel Objeto Papel.
         */
        void setPapel(const Papel& papel){this->papel = papel;};
};

/**
 * @class Projeto
 * @brief Entidade que representa um Projeto.
 * Agrupa as informações de identificação e cronograma de um projeto, 
 * garantindo que as datas de início e término sejam válidas.
 */
class Projeto{
    private:
        Codigo codigo; ///< Identificador único do projeto.
        Nome nome; ///< Título ou nome do projeto.
        Data inicio; ///< Data de início do projeto.
        Data termino; ///< Data de encerramento prevista ou real do projeto.
    public:
        // Construtor
        //Projeto(const Codigo& codigo, const Nome& nome, const Data& inicio, const Data& termino) : termino(termino), inicio(inicio), nome(nome), codigo(codigo){};
        /**
         * @brief Construtor padrão da classe Projeto.
         */
        Projeto() = default;

        // Destrutor
        /**
         * @brief Destrutor virtual da classe Projeto.
         */
        virtual ~Projeto() = default;
        // Métodos getters referentes aos atributos da Entidade
        /** 
         * @brief Recupera o código do projeto. 
         * @return Objeto do domínio Codigo. 
         */
        Codigo getCodigo() const{return codigo;};
        /** 
         * @brief Recupera o nome do projeto. 
         * @return Objeto do domínio Nome. 
         */
        Nome getNome() const{return nome;};
        /** 
         * @brief Recupera a data de início. 
         * @return Objeto do domínio Data. 
         */
        Data getDataStart() const{return inicio;};
        /** 
         * @brief Recupera a data de término. 
         * @return Objeto do domínio Data. 
         */
        Data getDataEnd() const{return termino;};

        //Métodos setters referentes aos atributos da Entidade
        /** 
         * @brief Atribui um código validado. 
         * @param codigo Objeto Codigo. 
         */
        void setCodigo(const Codigo& codigo){this->codigo = codigo;};
        /** 
         * @brief Atribui um nome validado. 
         * @param nome Objeto Nome. 
         */
        void setNome(const Nome& nome){this->nome = nome;};
        /** 
         * @brief Atribui a data de início. 
         * @param inicio Objeto Data validado. 
         */
        void setDataStart(const Data& inicio){this->inicio = inicio;};
        /** 
         * @brief Atribui a data de término. 
         * @param termino Objeto Data validado. 
         */
        void setDataEnd(const Data& termino){this->termino = termino;};
};

/**
 * @class PlanoDeSprint
 * @brief Entidade que representa um Plano de Sprint.
 * Mantém os dados referentes a uma iteração de trabalho (Sprint), 
 * incluindo o seu objetivo principal e a capacidade de tempo alocada.
 */
class PlanoDeSprint{
    private:
        Codigo codigo; ///< Identificador único do plano de sprint.
        Texto objetivo; ///< Descrição do objetivo principal da sprint.
        Tempo capacidade; ///< Capacidade total de tempo alocada para a sprint.
    public:
        // Construtor
        //PlanoDeSprint(const Codigo& codigo, const Texto& objetivo, const Tempo& capacidade)
        // : capacidade(capacidade), objetivo(objetivo), codigo(codigo){};
        /**
         * @brief Construtor padrão da classe PlanoDeSprint.
         */
        PlanoDeSprint() = default;
        
        // Destrutor
        /**
         * @brief Destrutor virtual da classe PlanoDeSprint.
         */
        virtual ~PlanoDeSprint() = default;

        // Métodos getters referentes aos atributos da Entidade
        /** 
         * @brief Recupera o código da sprint. 
         * @return Objeto Codigo. 
         */
        Codigo getCodigo() const{return codigo;};
        /** 
         * @brief Recupera o objetivo da sprint. 
         * @return Objeto Texto. 
         */
        Texto getTexto() const{return objetivo;};
        /** 
         * @brief Recupera a capacidade da sprint. 
         * @return Objeto Tempo. 
         */
        Tempo getTempo() const{return capacidade;};

        //Métodos setters referentes aos atributos da Entidade
        /** 
         * @brief Atribui o código da sprint. 
         * @param codigo Objeto Codigo. 
         */
        void setCodigo(const Codigo& codigo){this->codigo = codigo;};
        /** 
         * @brief Atribui o objetivo da sprint. 
         * @param objetivo Objeto Texto. 
         */
        void setTexto(const Texto& objetivo){this->objetivo = objetivo;};
        /** 
         * @brief Atribui a capacidade de tempo. 
         * @param capacidade Objeto Tempo. 
         */
        void setTempo(const Tempo& capacidade){this->capacidade = capacidade;};

};

/**
 * @class HistoriaDeUsuario
 * @brief Entidade que representa uma História de Usuário.
 * Estrutura fundamental do desenvolvimento ágil, descrevendo uma 
 * funcionalidade sob a perspectiva do usuário, seu valor de negócio, 
 * estimativas e estado de progresso.
 */
class HistoriaDeUsuario{
    private:
        Codigo codigo; ///< Identificador único da história de usuário.
        Texto titulo; ///< Título da história de usuário.
        Texto papel; ///< Papel do usuário na história.
        Texto acao; ///< Ação que o usuário deseja realizar.
        Texto valor; ///< Valor de negócio da história.
        Tempo estimativa; ///< Estimativa de tempo para conclusão.
        Prioridade prioridade; ///< Prioridade da história.
        Estado estado; ///< Estado de progresso da história (ex: "A fazer").
    public:
        // Construtor
        //HistoriaDeUsuario(const Codigo& codigo, const Texto& titulo, const Texto& papel, const Texto& acao, const Texto& valor, 
        //const Tempo& estimativa, const Prioridade& prioridade, const Estado& estado) 
        //: titulo(titulo), papel(papel), acao(acao), codigo(codigo), valor(valor)
        //, estimativa(estimativa), prioridade(prioridade), estado(estado){};
        /**
         * @brief Construtor padrão da classe HistoriaDeUsuario.
         */
        HistoriaDeUsuario() = default;
        
        // Destrutor
        /**
         * @brief Destrutor virtual da classe HistoriaDeUsuario.
         */
        virtual ~HistoriaDeUsuario() = default;
        // Métodos getters referentes aos atributos da Entidade
        /** 
         * @brief Recupera o código da história. 
         * @return Objeto Codigo. 
         */
        Codigo getCodigo() const{return codigo;};
        /** 
         * @brief Recupera o título da história. 
         * @return Objeto Texto. 
         */
        Texto getTitulo() const{return titulo;};
        /** 
         * @brief Recupera o papel do usuário na história. 
         * @return Objeto Texto. 
         */
        Texto getPapel() const{return papel;};
        /** 
         * @brief Recupera a ação que o usuário deseja realizar. 
         * @return Objeto Texto. 
         */
        Texto getAcao() const{return acao;};
        /** 
         * @brief Recupera o valor de negócio da história. 
         * @return Objeto Texto. 
         */
        Texto getValor() const{return valor;};
        /** 
         * @brief Recupera a estimativa de tempo da história. 
         * @return Objeto Tempo. 
         */
        Tempo getTempo() const{return estimativa;};
        /** 
         * @brief Recupera a prioridade. 
         * @return Objeto Prioridade. 
         */
        Prioridade getPrioridade() const{return prioridade;};
        /** 
         * @brief Recupera o estado de progresso da história. 
         * @return Objeto Estado. 
         */
        Estado getEstado() const{return estado;};

        //Métodos setters referentes aos atributos da Entidade
        /** 
         * @brief Atribui um código. 
         * @param codigo Objeto Codigo. 
         */
        void setCodigo(const Codigo& codigo){this->codigo = codigo;};
        /** 
         * @brief Atribui um título. 
         * @param titulo Objeto Texto. 
         */
        void setTitulo(const Texto& titulo){this->titulo = titulo;};
        /** 
         * @brief Atribui um papel. 
         * @param papel Objeto Texto. 
         */
        void setPapel(const Texto& papel){this->papel = papel;};
        /** 
         * @brief Atribui uma ação. 
         * @param acao Objeto Texto. 
         */
        void setAcao(const Texto& acao){this->acao = acao;};
        /** 
         * @brief Atribui um valor de negócio. 
         * @param valor Objeto Texto. 
         */
        void setValor(const Texto& valor){this->valor = valor;};
        /** 
         * @brief Atribui uma estimativa de tempo. 
         * @param estimativa Objeto Tempo. 
         */
        void setTempo(const Tempo& estimativa){this->estimativa = estimativa;};
        /** 
         * @brief Atribui uma prioridade. 
         * @param prioridade Objeto Prioridade. 
         */
        void setPrioridade(const Prioridade& prioridade){this->prioridade = prioridade;};
        /** 
         * @brief Atribui o estado de progresso da história. 
         * @param estado Objeto Estado. 
         */
        void setEstado(const Estado& estado){this->estado = estado;};

};

#endif