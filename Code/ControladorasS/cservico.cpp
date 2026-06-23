#include "ControladorasS/Headers/cservico.hpp"
#include "Containers/Headers/containers.hpp"

// ---------------------------
// AUTENTICACAO
// ---------------------------

bool CntrISAutenticacao::autenticar(const Email& email, const Senha& senha, Papel& papel){
    auto& container = Container<Email, Pessoa>::getInstance();
    Pessoa usuario;
    if(container.ler(email, usuario)){
        if(usuario.getSenha()==senha){
            papel=usuario.getPapel();
            return true;
        }
    }
    return false;
}

// ---------------------------
// CADASTRO
// ---------------------------

bool CntrISCadastro::criar(const Pessoa& pessoa){
    auto& container = Container<Email, Pessoa>::getInstance();
    return container.criar(pessoa.getEmail(), pessoa);
}

bool CntrISCadastro::ler(Pessoa& pessoa){
    auto& container = Container<Email, Pessoa>::getInstance();
    return container.ler(pessoa.getEmail(), pessoa);
}

bool CntrISCadastro::atualizar(const Pessoa& pessoa){
    auto& container = Container<Email, Pessoa>::getInstance();
    return container.atualizar(pessoa.getEmail(), pessoa);
}

bool CntrISCadastro::excluir(const Email& email){
    auto& container = Container<Email, Pessoa>::getInstance();
    return container.excluir(email);
}

// ---------------------------
// PROJETOS
// ---------------------------

bool CntrISGestaoProjetos::criarProjeto(const Projeto& projeto){
    auto& container = Container<Codigo, Projeto>::getInstance();
    return container.criar(projeto.getCodigo(), projeto);
}

bool CntrISGestaoProjetos::lerProjeto(Projeto& projeto){
    auto& container = Container<Codigo, Projeto>::getInstance();
    return container.ler(projeto.getCodigo(), projeto);
}

bool CntrISGestaoProjetos::atualizarProjeto(const Projeto& projeto){
    auto& container = Container<Codigo, Projeto>::getInstance();
    return container.atualizar(projeto.getCodigo(), projeto);
}

bool CntrISGestaoProjetos::excluirProjeto(const Codigo& codigo){
    auto& container = Container<Codigo, Projeto>::getInstance();
    return container.excluir(codigo);
}

bool CntrISGestaoProjetos::criarPlanoSprint(const PlanoDeSprint& sprint){
    auto& container = Container<Codigo, PlanoDeSprint>::getInstance();
    return container.criar(sprint.getCodigo(), sprint);
}

bool CntrISGestaoProjetos::lerPlanoSprint(PlanoDeSprint& sprint){
    auto& container = Container<Codigo, PlanoDeSprint>::getInstance();
    return container.ler(sprint.getCodigo(), sprint);
}

bool CntrISGestaoProjetos::atualizarPlanoSprint(const PlanoDeSprint& sprint){
    auto& container = Container<Codigo, PlanoDeSprint>::getInstance();
    return container.atualizar(sprint.getCodigo(), sprint);
}

bool CntrISGestaoProjetos::excluirPlanoSprint(const Codigo& codigo){
    auto& container = Container<Codigo, PlanoDeSprint>::getInstance();
    return container.excluir(codigo);
}

bool CntrISGestaoProjetos::listarProjetosDePessoa(const Email& email, std::vector<Projeto>& projetos){
    return true;
}

bool CntrISGestaoProjetos::listarPlanosSprintDeProjeto(const Codigo& codigoProjeto, std::vector<PlanoDeSprint>& planos){
    return true;
}

// ---------------------------
// HISTORIAS
// ---------------------------

bool CntrISGestaoHistorias::criar(const HistoriaDeUsuario& historia){
    auto& container = Container<Codigo, HistoriaDeUsuario>::getInstance();
    return container.criar(historia.getCodigo(), historia);
}

bool CntrISGestaoHistorias::ler(HistoriaDeUsuario& historia){
    auto& container = Container<Codigo, HistoriaDeUsuario>::getInstance();
    return container.ler(historia.getCodigo(), historia);
}

bool CntrISGestaoHistorias::atualizar(const HistoriaDeUsuario& historia){
    auto& container = Container<Codigo, HistoriaDeUsuario>::getInstance();
    return container.atualizar(historia.getCodigo(), historia);
}

bool CntrISGestaoHistorias::excluir(const Codigo& codigo){
    auto& container = Container<Codigo, HistoriaDeUsuario>::getInstance();
    return container.excluir(codigo);
}

bool CntrISGestaoHistorias::associarPessoa(const Codigo& codigoHistoria, const Email& emailPessoa){
    return true;
}

bool CntrISGestaoHistorias::removerAssociacaoPessoa(const Codigo& codigoHistoria, const Email& emailPessoa){
    return true;
}

bool CntrISGestaoHistorias::moverParaPlanoSprint(const Codigo& codigoHistoria, const Codigo& codigoPlano){
    return true;
}

bool CntrISGestaoHistorias::alterarEstado(const Codigo& codigoHistoria, const Estado& novoEstado){
    auto& container = Container<Codigo, HistoriaDeUsuario>::getInstance();
    HistoriaDeUsuario historia;
    if(container.ler(codigoHistoria, historia)){
        historia.setEstado(novoEstado);
        return container.atualizar(codigoHistoria, historia);
    }else{
        return false;
    }
}

bool CntrISGestaoHistorias::listarHistoriasDeProjeto(const Codigo& codigoProjeto, std::vector<HistoriaDeUsuario>& historias){
    return true;
}

bool CntrISGestaoHistorias::listarHistoriasDePlanoSprint(const Codigo& codigoPlano, std::vector<HistoriaDeUsuario>& historias){
    return true;
}

bool CntrISGestaoHistorias::listarHistoriasDePessoa(const Email& emailPessoa, std::vector<HistoriaDeUsuario>& historias){
    return true;
}
