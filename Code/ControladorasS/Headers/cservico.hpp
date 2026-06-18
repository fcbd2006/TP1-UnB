#ifndef CNTRSERVICO_HPP_INCLUDED
#define CNTRSERVICO_HPP_INCLUDED

#include "Interfaces/Headers/interfaces_servico.hpp"

class CntrISAutenticacao : public ISAutenticacao {
public:
    bool autenticar(const Email& email, const Senha& senha, Papel& papel) override;
};

class CntrISCadastro : public ISCadastro {
public:
    bool criar(const Pessoa& pessoa) override;
    bool ler(Pessoa& pessoa) override;
    bool atualizar(const Pessoa& pessoa) override;
    bool excluir(const Email& email) override;
};

class CntrISGestaoProjetos : public ISGestaoProjetos {
public:
    bool criarProjeto(const Projeto& projeto) override;
    bool lerProjeto(Projeto& projeto) override;
    bool atualizarProjeto(const Projeto& projeto) override;
    bool excluirProjeto(const Codigo& codigoProjeto) override;
    
    bool criarPlanoSprint(const PlanoDeSprint& plano) override;
    bool lerPlanoSprint(PlanoDeSprint& plano) override;
    bool atualizarPlanoSprint(const PlanoDeSprint& plano) override;
    bool excluirPlanoSprint(const Codigo& codigoPlano) override;

    bool listarProjetosDePessoa(const Email& email, std::vector<Projeto>& projetos) override;
    bool listarPlanosSprintDeProjeto(const Codigo& codigoProjeto, std::vector<PlanoDeSprint>& planos) override;
};

class CntrSGestaoHistorias : public ISGestaoHistorias {
public:
    bool criar(const HistoriaDeUsuario& historia) override;
    bool ler(HistoriaDeUsuario& historia) override;
    bool atualizar(const HistoriaDeUsuario& historia) override;
    bool excluir(const Codigo& codigoHistoria) override;

    // Métodos de Relacionamento e Estado
    bool associarPessoa(const Codigo& codigoHistoria, const Email& emailPessoa) override;
    bool removerAssociacaoPessoa(const Codigo& codigoHistoria, const Email& emailPessoa) override;
    bool moverParaPlanoSprint(const Codigo& codigoHistoria, const Codigo& codigoPlano) override;
    bool alterarEstado(const Codigo& codigoHistoria, const Estado& novoEstado) override;

    // Listagens
    bool listarHistoriasDeProjeto(const Codigo& codigoProjeto, std::vector<HistoriaDeUsuario>& historias) override;
    bool listarHistoriasDePlanoSprint(const Codigo& codigoPlano, std::vector<HistoriaDeUsuario>& historias) override;
    bool listarHistoriasDePessoa(const Email& emailPessoa, std::vector<HistoriaDeUsuario>& historias) override;
};

#endif // CNTRSERVICO_HPP_INCLUDED