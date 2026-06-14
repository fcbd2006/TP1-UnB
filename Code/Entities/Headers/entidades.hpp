#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED
#include "Domains/Headers/outros_dominios.hpp"

class Pessoa{
    private:
        Email email;
        Nome nome;
        Senha senha;
        Papel papel;
    public:
        // Construtor
        //Pessoa(const Email& email, const Nome& nome, const Senha& senha, const Papel& papel): 
        //papel(papel), email(email), nome(nome), senha(senha){};
        Pessoa() = default;

        // Destrutor
        virtual ~Pessoa() = default;
        // Métodos get referente aos atributos da Entidade
        Email getEmail() const{return email;};
        Nome getNome() const{return nome;};
        Senha getSenha() const{return senha;};
        Papel getPapel() const{return papel;};
        //Métodos set referentes aos atributos dessa Entidades
        void setEmail(const Email& email){this->email = email;};
        void setNome(const Nome& nome){this->nome = nome;};
        void setSenha(const Senha& senha){this->senha = senha;};
        void setPapel(const Papel& papel){this->papel = papel;};
};

class Projeto{
    private:
        Codigo codigo;
        Nome nome;
        Data inicio, termino;
    public:
        // Construtor
        //Projeto(const Codigo& codigo, const Nome& nome, const Data& inicio, const Data& termino) : termino(termino), inicio(inicio), nome(nome), codigo(codigo){};
        Projeto() = default;

        // Destrutor
        virtual ~Projeto() = default;
        // Métodos get referente aos atributos da Entidade
        Codigo getCodigo() const{return codigo;};
        Nome getNome() const{return nome;};
        Data getDataStart() const{return inicio;};
        Data getDataEnd() const{return termino;};

        //Métodos set referentes aos atributos dessa Entidades
        void setcodigo(const Codigo& codigo){this->codigo = codigo;};
        void setNome(const Nome& nome){this->nome = nome;};
        void setDataStart(const Data& inicio){this->inicio = inicio;};
        void setDataEnd(const Data& termino){this->termino = termino;};
};

class PlanoDeSprint{
    private:
        Codigo codigo;
        Texto objetivo;
        Tempo capacidade;
    public:
        // Construtor
        //PlanoDeSprint(const Codigo& codigo, const Texto& objetivo, const Tempo& capacidade)
        // : capacidade(capacidade), objetivo(objetivo), codigo(codigo){};
        PlanoDeSprint() = default;
        
        // Destrutor
        virtual ~PlanoDeSprint() = default;
        // Métodos get referente aos atributos da Entidade
        Codigo getCodigo() const{return codigo;};
        Texto getTexto() const{return objetivo;};
        Tempo getTempo() const{return capacidade;};

        //Métodos set referentes aos atributos dessa Entidades
        void setcodigo(const Codigo& codigo){this->codigo = codigo;};
        void setNome(const Texto& objetivo){this->objetivo = objetivo;};
        void setDataStart(const Tempo& capacidade){this->capacidade = capacidade;};

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
        void setTempo(const Tempo& estimetiva){this->estimativa = estimativa;};
        void setPrioridade(const Prioridade& prioridade){this->prioridade = prioridade;};
        void setEstado(const Estado& estado){this->estado = estado;};

};

#endif