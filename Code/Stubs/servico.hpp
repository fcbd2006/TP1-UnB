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
        if(email.getValor() == "carlos@abc" && senha.getValor() =="A1b2c3") return true;
        else return false; 
    }
};

//-----------------------------------------------------------
// STUB DE CADASTRO
//-----------------------------------------------------------

class StubCadastro : public ISCadastro {
public:
    bool criar(const Pessoa& pessoa) override {
        if(pessoa.getEmail().getValor()!="carlos@abc") return false;
        else return true;
    }

    bool ler(Pessoa* pessoa) override {
        if(pessoa == nullptr) return false;
        if(pessoa->getEmail().getValor() == "carlos@abc"){
            pessoa->setNome(Nome("carlos"));
            pessoa->setPapel(Papel("DESENVOLVEDOR"));
            pessoa->setSenha(Senha("A1b2c3"));
            return true;
        }
        return false;
    }

    bool atualizar(const Pessoa& pessoa) override {
        if(pessoa.getEmail().getValor() == "bruno@abc"){
            return false;
        }else return true;
    }

    bool excluir(const Email& email) override {
        if(email.getValor() == "bruno@abc"){
            return false;
        }else return true;
    }
};

//-----------------------------------------------------------
// STUB DE GESTÃO DE HISTÓRIAS
//-----------------------------------------------------------

class StubGestaoHistorias : public ISGestaoHistorias {
public:
    bool criar(const HistoriaDeUsuario& historia) override {
        if(historia.getCodigo().getValor() != "AB123") return false;
        else return true;
    }

    bool ler(HistoriaDeUsuario* historia) override {
        if(historia == nullptr) return false;
        if(historia->getCodigo().getValor() == "AB123"){
            historia->setAcao(Texto("texto1"));
            historia->setEstado(Estado("FAZENDO"));
            historia->setPapel(Texto("texto2"));
            historia->setPrioridade(Prioridade("MEDIA"));
            historia->setTempo(Tempo("150"));
            historia->setTitulo(Texto("texto3"));
            historia->setValor(Texto("texto4"));
            return true;
        }
        else return false;
    }

    bool atualizar(const HistoriaDeUsuario& historia) override {
        if(historia.getCodigo().getValor() != "AB123") return false;
        else return true;
    }

    bool excluir(const Codigo& codigoHistoria) override {
        if(codigoHistoria.getValor() != "AB123") return false;
        else return true;
    }

    bool associarPessoa(const Codigo& codigoHistoria, const Email& emailPessoa) override {
        if(codigoHistoria.getValor() == "AB123" && emailPessoa.getValor() == "carlos@abc") return true;
        else return false;
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