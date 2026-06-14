#ifndef STUBS_SERVICO_HPP_INCLUDED
#define STUBS_SERVICO_HPP_INCLUDED

#include "Interfaces/Headers/interfaces_servico.hpp"
#include "Entities/Headers/entidades.hpp"
#include <vector>

//-----------------------------------------------------------
// STUB DE AUTENTICAÇÃO
//-----------------------------------------------------------

class StubAutenticacao : public ISAutenticacao {
public:
    bool autenticar(const Email& email, const Senha& senha) override {
        if(senha.getValor()!="A1b2c3") return false;
        else return true; 
    }
};

//-----------------------------------------------------------
// STUB DE CADASTRO
//-----------------------------------------------------------

class StubCadastro : public ISCadastro {
public:
    bool criar(const Pessoa& pessoa) override {
        if(pessoa.getEmail().getValor()=="abc@abc") return false;
        else return true;
    }

    bool ler(Pessoa* pessoa) override {
        pessoa->setNome(Nome("carlos"));
        pessoa->setPapel(Papel("DESENVOLVEDOR"));
        pessoa->setSenha(Senha("A1b2c3"));
        return true;
    }

    bool atualizar(const Pessoa& pessoa) override {
        return true;
    }

    bool excluir(const Email& email) override {
        return true;
    }
};

//-----------------------------------------------------------
// STUB DE GESTÃO DE HISTÓRIAS
//-----------------------------------------------------------

class StubGestaoHistorias : public ISGestaoHistorias {
public:
    bool criar(const HistoriaDeUsuario& historia) override {
        return true;
    }

    bool ler(HistoriaDeUsuario* historia) override {
        return true;
    }

    bool atualizar(const HistoriaDeUsuario& historia) override {
        return true;
    }

    bool excluir(const Codigo& codigoHistoria) override {
        return true;
    }

    bool associarPessoa(const Codigo& codigoHistoria, const Email& emailPessoa) override {
        return true;
    }
    
    bool removerAssociacaoPessoa(const Codigo& codigoHistoria, const Email& emailPessoa) override {
        return true;
    }

    bool moverParaPlanoSprint(const Codigo& codigoHistoria, const Codigo& codigoPlano) override {
        return true;
    }

    bool alterarEstado(const Codigo& codigoHistoria, const Estado& novoEstado) override {
        return true;
    } 

    bool listarHistoriasDeProjeto(const Codigo& codigoProjeto, std::vector<HistoriaDeUsuario>* historias) override {
        // Simulação de listagem. Inserir instâncias fictícias de HistoriaDeUsuario no vetor para testes.
        return true;
    }

    bool listarHistoriasDePlanoSprint(const Codigo& codigoPlano, std::vector<HistoriaDeUsuario>* historias) override {
        return true;
    }

    bool listarHistoriasDePessoa(const Email& emailPessoa, std::vector<HistoriaDeUsuario>* historias) override {
        return true;
    }
};

#endif // STUBS_SERVICO_HPP_INCLUDED