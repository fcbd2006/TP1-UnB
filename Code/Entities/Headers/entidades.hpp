#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED
#include "Domains/Headers/outros_dominios.hpp"

/**
 * @class Pessoa
 * @brief Entidade que representa um usuário ou colaborador do sistema.
 * * Agrupa as informações essenciais de um indivíduo, utilizando domínios 
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
        /** @brief Recupera o e-mail da pessoa. @return Objeto do domínio Email. */
        Email getEmail() const{return email;};
        /** @brief Recupera o nome da pessoa. @return Objeto do domínio Nome. */
        Nome getNome() const{return nome;};
        /** @brief Recupera a senha da pessoa. @return Objeto do domínio Senha. */
        Senha getSenha() const{return senha;};
        /** @brief Recupera o papel da pessoa. @return Objeto do domínio Papel. */
        Papel getPapel() const{return papel;};
        //Métodos setters referentes aos atributos da Entidade
        /** @brief Atribui um e-mail validado. @param email Objeto Email. */
        void setEmail(const Email& email){this->email = email;};
        /** @brief Atribui um nome validado. @param nome Objeto Nome. */
        void setNome(const Nome& nome){this->nome = nome;};
        /** @brief Atribui uma senha validada. @param senha Objeto Senha. */
        void setSenha(const Senha& senha){this->senha = senha;};
        /** @brief Atribui um papel validado. @param papel Objeto Papel. */
        void setPapel(const Papel& papel){this->papel = papel;};
};

/**
 * @class Projeto
 * @brief Entidade que representa um Projeto.
 * * Agrupa as informações de identificação e cronograma de um projeto, 
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
        /** @brief Recupera o código do projeto. @return Objeto do domínio Codigo. */
        Codigo getCodigo() const{return codigo;};
        /** @brief Recupera o nome do projeto. @return Objeto do domínio Nome. */
        Nome getNome() const{return nome;};
        /** @brief Recupera a data de início. @return Objeto do domínio Data. */
        Data getDataStart() const{return inicio;};
        /** @brief Recupera a data de término. @return Objeto do domínio Data. */
        Data getDataEnd() const{return termino;};

        //Métodos setters referentes aos atributos da Entidade
        /** @brief Atribui um código validado. @param codigo Objeto Codigo. */
        void setCodigo(const Codigo& codigo){this->codigo = codigo;};
        /** @brief Atribui um nome validado. @param nome Objeto Nome. */
        void setNome(const Nome& nome){this->nome = nome;};
        /** @brief Atribui a data de início. @param inicio Objeto Data validado. */
        void setDataStart(const Data& inicio){this->inicio = inicio;};
        /** @brief Atribui a data de término. @param termino Objeto Data validado. */
        void setDataEnd(const Data& termino){this->termino = termino;};
};

/**
 * @class PlanoDeSprint
 * @brief Entidade que representa um Plano de Sprint.
 * * Mantém os dados referentes a uma iteração de trabalho (Sprint), 
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
        /** @brief Recupera o código da sprint. @return Objeto Codigo. */
        Codigo getCodigo() const{return codigo;};
        /** @brief Recupera o objetivo da sprint. @return Objeto Texto. */
        Texto getTexto() const{return objetivo;};
        /** @brief Recupera a capacidade da sprint. @return Objeto Tempo. */
        Tempo getTempo() const{return capacidade;};

        //Métodos setters referentes aos atributos da Entidade
        /** @brief Atribui o código da sprint. @param codigo Objeto Codigo. */
        void setCodigo(const Codigo& codigo){this->codigo = codigo;};
        /** @brief Atribui o objetivo da sprint. @param objetivo Objeto Texto. */
        void setTexto(const Texto& objetivo){this->objetivo = objetivo;};
        /** @brief Atribui a capacidade de tempo. @param capacidade Objeto Tempo. */
        void setTempo(const Tempo& capacidade){this->capacidade = capacidade;};

};

class HistoriaDeUsuario{
    private:
        Codigo codigo;
        Texto titulo, papel, acao, valor;
        Tempo estimativa;
        Prioridade prioridade;
        Estado estado;
    public:
        // Construtor
        //HistoriaDeUsuario(const Codigo& codigo, const Texto& titulo, const Texto& papel, const Texto& acao, const Texto& valor, 
        //const Tempo& estimativa, const Prioridade& prioridade, const Estado& estado) 
        //: titulo(titulo), papel(papel), acao(acao), codigo(codigo), valor(valor)
        //, estimativa(estimativa), prioridade(prioridade), estado(estado){};
        HistoriaDeUsuario() = default;
        
        // Destrutor
        virtual ~HistoriaDeUsuario() = default;
        // Métodos get referente aos atributos da Entidade
        Codigo getCodigo() const{return codigo;};
        Texto getTitulo() const{return titulo;};
        Texto getPapel() const{return papel;};
        Texto getAcao() const{return acao;};
        Texto getValor() const{return valor;};
        Tempo getTempo() const{return estimativa;};
        Prioridade getPrioridade() const{return prioridade;};
        Estado getEstado() const{return estado;};

        //Métodos set referentes aos atributos dessa Entidades
        void setCodigo(const Codigo& codigo){this->codigo = codigo;};
        void setTitulo(const Texto& titulo){this->titulo = titulo;};
        void setPapel(const Texto& papel){this->papel = papel;};
        void setAcao(const Texto& acao){this->acao = acao;};
        void setValor(const Texto& valor){this->valor = valor;};
        void setTempo(const Tempo& estimativa){this->estimativa = estimativa;};
        void setPrioridade(const Prioridade& prioridade){this->prioridade = prioridade;};
        void setEstado(const Estado& estado){this->estado = estado;};

};

#endif