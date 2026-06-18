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