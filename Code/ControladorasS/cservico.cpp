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
// PROJETO
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