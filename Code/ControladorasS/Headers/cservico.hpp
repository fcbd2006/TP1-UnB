#ifndef CNTRSERVICO_HPP_INCLUDED
#define CNTRSERVICO_HPP_INCLUDED

#include "Interfaces/Headers/interfaces_servico.hpp"

/**
 * @file cservico.hpp
 * @brief Declaração das classes controladoras da camada de Serviço (Autenticação, Cadastro, Gestão de Projetos e Gestão de Histórias).
 */

/**
 * @class CntrISAutenticacao
 * @brief Classe de controle para o serviço de Autenticação.
 * Implementa a interface ISAutenticacao. Responsável por verificar as credenciais
 * de um usuário para permitir o acesso ao sistema.
 */
class CntrISAutenticacao : public ISAutenticacao {
public:
    /**
     * @brief Autentica um usuário no sistema.
     * @param email Instância de Email contendo o endereço fornecido pelo usuário.
     * @param senha Instância de Senha contendo a senha fornecida pelo usuário.
     * @param papel Parâmetro de saída onde será armazenado o papel do usuário, caso autenticado.
     * @return true se as credenciais forem válidas, false caso contrário.
     */
    bool autenticar(const Email& email, const Senha& senha, Papel& papel) override;
};

/**
 * @class CntrISCadastro
 * @brief Classe de controle para o serviço de Cadastro.
 * Implementa a interface ISCadastro. Responsável por realizar as operações de
 * criação, leitura, atualização e exclusão (CRUD) de Pessoas.
 */
class CntrISCadastro : public ISCadastro {
public:
    /**
     * @brief Cadastra uma nova pessoa no sistema.
     * @param pessoa Objeto contendo os dados da pessoa a ser criada.
     * @return true se a criação for bem-sucedida, false caso contrário.
     */
    bool criar(const Pessoa& pessoa) override;

    /**
     * @brief Recupera os dados de uma pessoa.
     * @param pessoa Objeto Pessoa que contém o identificador (Email) e será preenchido com os demais dados.
     * @return true se a leitura for bem-sucedida, false caso contrário.
     */
    bool ler(Pessoa& pessoa) override;

    /**
     * @brief Atualiza os dados de uma pessoa existente.
     * @param pessoa Objeto Pessoa com os dados atualizados.
     * @return true se a atualização for bem-sucedida, false caso contrário.
     */
    bool atualizar(const Pessoa& pessoa) override;

    /**
     * @brief Exclui uma pessoa do sistema.
     * @param email Email que identifica a pessoa a ser excluída.
     * @return true se a exclusão for bem-sucedida, false caso contrário.
     */
    bool excluir(const Email& email) override;
};

/**
 * @class CntrISGestaoProjetos
 * @brief Classe de controle para o serviço de Gestão de Projetos.
 * Implementa a interface ISGestaoProjetos. Gerencia as operações relacionadas 
 * aos Projetos e seus respectivos Planos de Sprint.
 */
class CntrISGestaoProjetos : public ISGestaoProjetos {
public:
    /**
     * @brief Cria um novo projeto.
     * @param projeto Objeto contendo os dados do projeto a ser criado.
     * @return true se a criação for bem-sucedida, false caso contrário.
     */
    bool criarProjeto(const Projeto& projeto) override;

    /**
     * @brief Recupera os dados de um projeto.
     * @param projeto Objeto Projeto com o código preenchido para busca, que receberá os dados retornados.
     * @return true se a leitura for bem-sucedida, false caso contrário.
     */
    bool lerProjeto(Projeto& projeto) override;

    /**
     * @brief Atualiza as informações de um projeto.
     * @param projeto Objeto Projeto contendo as informações atualizadas.
     * @return true se a atualização for bem-sucedida, false caso contrário.
     */
    bool atualizarProjeto(const Projeto& projeto) override;

    /**
     * @brief Exclui um projeto do sistema.
     * @param codigoProjeto Código identificador do projeto a ser excluído.
     * @return true se a exclusão for bem-sucedida, false caso contrário.
     */
    bool excluirProjeto(const Codigo& codigoProjeto) override;
    
    /**
     * @brief Cria um novo plano de sprint associado a um projeto.
     * @param plano Objeto contendo os dados do plano de sprint.
     * @return true se a criação for bem-sucedida, false caso contrário.
     */
    bool criarPlanoSprint(const PlanoDeSprint& plano) override;

    /**
     * @brief Recupera os dados de um plano de sprint.
     * @param plano Objeto PlanoDeSprint contendo o código para busca, recebendo os dados completos.
     * @return true se a leitura for bem-sucedida, false caso contrário.
     */
    bool lerPlanoSprint(PlanoDeSprint& plano) override;

    /**
     * @brief Atualiza um plano de sprint existente.
     * @param plano Objeto PlanoDeSprint com os dados atualizados.
     * @return true se a atualização for bem-sucedida, false caso contrário.
     */
    bool atualizarPlanoSprint(const PlanoDeSprint& plano) override;

    /**
     * @brief Exclui um plano de sprint do sistema.
     * @param codigoPlano Código identificador do plano de sprint a ser excluído.
     * @return true se a exclusão for bem-sucedida, false caso contrário.
     */
    bool excluirPlanoSprint(const Codigo& codigoPlano) override;

    /**
     * @brief Lista todos os projetos associados a uma pessoa específica.
     * @param email Email identificador da pessoa.
     * @param projetos Vetor (passado por referência) onde os projetos encontrados serão armazenados.
     * @return true se a operação for bem-sucedida, false caso ocorra algum erro.
     */
    bool listarProjetosDePessoa(const Email& email, std::vector<Projeto>& projetos) override;

    /**
     * @brief Lista todos os planos de sprint associados a um projeto específico.
     * @param codigoProjeto Código identificador do projeto.
     * @param planos Vetor onde os planos de sprint encontrados serão armazenados.
     * @return true se a operação for bem-sucedida, false caso contrário.
     */
    bool listarPlanosSprintDeProjeto(const Codigo& codigoProjeto, std::vector<PlanoDeSprint>& planos) override;
};

/**
 * @class CntrISGestaoHistorias
 * @brief Classe de controle para o serviço de Gestão de Histórias.
 * Implementa a interface ISGestaoHistorias. Lida com o CRUD das Histórias de Usuário, 
 * bem como seu relacionamento com Pessoas, Planos de Sprint e controle de estados.
 */
class CntrISGestaoHistorias : public ISGestaoHistorias {
public:
    /**
     * @brief Cria uma nova história de usuário.
     * @param historia Objeto contendo os dados da história a ser criada.
     * @return true se a criação for bem-sucedida, false caso contrário.
     */
    bool criar(const HistoriaDeUsuario& historia) override;

    /**
     * @brief Recupera os dados de uma história de usuário.
     * @param historia Objeto HistoriaDeUsuario com o código preenchido, que receberá os dados da busca.
     * @return true se a leitura for bem-sucedida, false caso contrário.
     */
    bool ler(HistoriaDeUsuario& historia) override;

    /**
     * @brief Atualiza as informações de uma história de usuário.
     * @param historia Objeto HistoriaDeUsuario contendo os dados atualizados.
     * @return true se a atualização for bem-sucedida, false caso contrário.
     */
    bool atualizar(const HistoriaDeUsuario& historia) override;

    /**
     * @brief Exclui uma história de usuário do sistema.
     * @param codigoHistoria Código identificador da história a ser excluída.
     * @return true se a exclusão for bem-sucedida, false caso contrário.
     */
    bool excluir(const Codigo& codigoHistoria) override;

    /**
     * @brief Associa uma pessoa (desenvolvedor/responsável) a uma história de usuário.
     * @param codigoHistoria Código identificador da história.
     * @param emailPessoa Email da pessoa a ser associada.
     * @return true se a associação for bem-sucedida, false caso contrário.
     */
    bool associarPessoa(const Codigo& codigoHistoria, const Email& emailPessoa) override;

    /**
     * @brief Remove a associação entre uma pessoa e uma história de usuário.
     * @param codigoHistoria Código identificador da história.
     * @param emailPessoa Email da pessoa cuja associação será removida.
     * @return true se a remoção for bem-sucedida, false caso contrário.
     */
    bool removerAssociacaoPessoa(const Codigo& codigoHistoria, const Email& emailPessoa) override;

    /**
     * @brief Move uma história de usuário para um determinado plano de sprint.
     * @param codigoHistoria Código identificador da história.
     * @param codigoPlano Código identificador do plano de sprint destino.
     * @return true se a operação for bem-sucedida, false caso contrário.
     */
    bool moverParaPlanoSprint(const Codigo& codigoHistoria, const Codigo& codigoPlano) override;

    /**
     * @brief Altera o estado atual (ex: To Do, In Progress, Done) de uma história de usuário.
     * @param codigoHistoria Código identificador da história.
     * @param novoEstado Novo estado a ser atribuído.
     * @return true se a alteração for bem-sucedida, false caso contrário.
     */
    bool alterarEstado(const Codigo& codigoHistoria, const Estado& novoEstado) override;

    /**
     * @brief Lista todas as histórias de usuário pertencentes a um projeto.
     * @param codigoProjeto Código identificador do projeto.
     * @param historias Vetor onde as histórias encontradas serão armazenadas.
     * @return true se a listagem for bem-sucedida, false caso ocorra algum erro.
     */
    bool listarHistoriasDeProjeto(const Codigo& codigoProjeto, std::vector<HistoriaDeUsuario>& historias) override;

    /**
     * @brief Lista todas as histórias de usuário alocadas em um plano de sprint.
     * @param codigoPlano Código identificador do plano de sprint.
     * @param historias Vetor onde as histórias encontradas serão armazenadas.
     * @return true se a listagem for bem-sucedida, false caso ocorra algum erro.
     */
    bool listarHistoriasDePlanoSprint(const Codigo& codigoPlano, std::vector<HistoriaDeUsuario>& historias) override;

    /**
     * @brief Lista todas as histórias de usuário associadas a uma pessoa específica.
     * @param emailPessoa Email identificador da pessoa.
     * @param historias Vetor onde as histórias encontradas serão armazenadas.
     * @return true se a listagem for bem-sucedida, false caso ocorra algum erro.
     */
    bool listarHistoriasDePessoa(const Email& emailPessoa, std::vector<HistoriaDeUsuario>& historias) override;
};

#endif // CNTRSERVICO_HPP_INCLUDED