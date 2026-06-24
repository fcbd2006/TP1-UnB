#ifndef INTERFACES_SERVICO_HPP_INCLUDED
#define INTERFACES_SERVICO_HPP_INCLUDED

#include "Entities/Headers/entidades.hpp"
#include <vector>

/**
 * @file interfaces_servico.hpp
 * @brief Declaração das interfaces da camada de Serviço (Autenticação, Cadastro, Gestão de Projetos e Gestão de Histórias).
 */

//-----------------------------------------------------------
// AUTENTICAÇÃO
//-----------------------------------------------------------

/**
 * @class ISAutenticacao
 * @brief Interface de serviço de autenticação (ISA).
 * Esta classe abstrata define o contrato para a validação de acesso ao sistema.
 */
class ISAutenticacao {
public:
    /**
     * @brief Método virtual puro para autenticar um usuário.
     * @param email Instância da classe de domínio Email.
     * @param senha Instância da classe de domínio Senha.
     * @param papel Instância de classe papel a ser preenchida com o papel do usuário, caso a autenticação seja bem sucedida.
     * @return true se as credenciais forem válidas, false caso contrário.
     */
    virtual bool autenticar(const Email& email, const Senha& senha, Papel& papel) = 0;

    //-----------------------------------------------------------

    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~ISAutenticacao() {}
};

//-----------------------------------------------------------
// CADASTRO
//-----------------------------------------------------------

/**
 * @class ISCadastro
 * @brief Interface de serviço de cadastro (ISC).
 * Define o contrato para operações de criação, leitura, atualização e 
 * exclusão de instâncias da entidade Pessoa.
 */
class ISCadastro {
public:
    /**
     * @brief Cria um novo registro de Pessoa no sistema (Serviço 1).
     * @param pessoa Instância completa da entidade Pessoa a ser salva.
     * @return true se o cadastro foi realizado com sucesso, false caso contrário.
     */
    virtual bool criar(const Pessoa& pessoa) = 0;

    /**
     * @brief Lê os dados de uma Pessoa a partir do seu e-mail (Serviço 2).
     * @param pessoa Referência para o objeto Pessoa que será preenchido com os dados recuperados.
     * @return true se a leitura foi bem-sucedida, false se a pessoa não foi encontrada.
     */
    virtual bool ler(Pessoa& pessoa) = 0;

    /**
     * @brief Atualiza os dados de uma Pessoa existente (Serviço 3).
     * @param pessoa Instância da entidade Pessoa com os novos dados.
     * @return true se atualizado com sucesso, false caso contrário.
     */
    virtual bool atualizar(const Pessoa& pessoa) = 0;

    /**
     * @brief Exclui o registro de uma Pessoa do sistema (Serviço 4).
     * @param email Instância Email identificando a Pessoa a ser excluída.
     * @return true se a exclusão for bem-sucedida, false caso contrário.
     */
    virtual bool excluir(const Email& email) = 0;

    //-----------------------------------------------------------

    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~ISCadastro() {}
};

//-----------------------------------------------------------
// GESTÃO
//-----------------------------------------------------------

/**
 * @class ISGestaoProjetos
 * @brief Interface de serviço de Gestão de Projetos (ISGP).
 * * Centraliza as operações do sistema Scrum, relacionadas a projetos e planos de sprint.
 */
class ISGestaoProjetos {
public:
    //-----------------------------------------------------------
    // PROJETO
    //-----------------------------------------------------------

    /**
     * @brief Cria um novo Projeto no sistema (Serviço 5).
     * @param projeto Instância completa da entidade Projeto a ser salva no sistema.
     * @return true se o projeto foi criado com sucesso, false caso contrário.
     */
    virtual bool criarProjeto(const Projeto& projeto) = 0;

    /**
     * @brief Lê os dados de um Projeto cadastrado (Serviço 6).
     * @param projeto Referência para o objeto Projeto que receberá os dados recuperados do sistema.
     * @return true se a leitura foi bem-sucedida, false se o projeto não foi encontrado.
     */
    virtual bool lerProjeto(Projeto& projeto) = 0;

    /**
     * @brief Atualiza os dados de um Projeto existente (Serviço 7).
     * @param projeto Instância da entidade Projeto contendo as modificações a serem salvas.
     * @return true se a atualização foi realizada com sucesso, false caso contrário.
     */
    virtual bool atualizarProjeto(const Projeto& projeto) = 0;

    /**
     * @brief Exclui um Projeto do sistema (Serviço 8).
     * @param codigoProjeto Instância do domínio Codigo que identifica o Projeto a ser removido.
     * @return true se a exclusão foi bem-sucedida, false caso contrário.
     */
    virtual bool excluirProjeto(const Codigo& codigoProjeto) = 0;

    //-----------------------------------------------------------
    // SPRINT
    //-----------------------------------------------------------

    /**
     * @brief Cria um novo Plano de Sprint associado a um projeto (Serviço 9).
     * @param plano Instância completa da entidade PlanoDeSprint a ser salva no sistema.
     * @return true se o plano de sprint foi criado com sucesso, false caso contrário.
     */
    virtual bool criarPlanoSprint(const PlanoDeSprint& plano) = 0;

    /**
     * @brief Lê os dados de um Plano de Sprint cadastrado (Serviço 10).
     * @param plano Referência para o objeto PlanoDeSprint que receberá os dados do sistema.
     * @return true se a leitura foi bem-sucedida, false se o plano de sprint não foi encontrado.
     */
    virtual bool lerPlanoSprint(PlanoDeSprint& plano) = 0;

    /**
     * @brief Atualiza os dados de um Plano de Sprint existente (Serviço 11).
     * @param plano Instância da entidade PlanoDeSprint contendo as modificações a serem salvas.
     * @return true se a atualização foi realizada com sucesso, false caso contrário.
     */
    virtual bool atualizarPlanoSprint(const PlanoDeSprint& plano) = 0;

    /**
     * @brief Exclui um Plano de Sprint do sistema (Serviço 12).
     * @param codigoPlano Instância do domínio Codigo que identifica o Plano de Sprint a ser removido.
     * @return true se a exclusão foi bem-sucedida, false caso contrário.
     */
    virtual bool excluirPlanoSprint(const Codigo& codigoPlano) = 0;

    //-----------------------------------------------------------
    // LISTAGENS
    //-----------------------------------------------------------

    /**
     * @brief Lista todos os Projetos associados a uma Pessoa específica (Serviço 19).
     * @param emailPessoa Instância do domínio Email contendo o identificador da Pessoa.
     * @param projetos Referência para um vetor que será populado com as instâncias de Projeto encontradas.
     * @return true se a operação de busca foi bem-sucedida, false em caso de falha.
     */
    virtual bool listarProjetosDePessoa(const Email& emailPessoa, std::vector<Projeto>& projetos) = 0;

    /**
     * @brief Lista todos os Planos de Sprint associados a um Projeto (Serviço 21).
     * @param codigoProjeto Instância do domínio Codigo contendo o identificador do Projeto.
     * @param planos Referência para um vetor que será populado com as instâncias de PlanoDeSprint encontradas.
     * @return true se a operação de busca foi bem-sucedida, false em caso de falha.
     */
    virtual bool listarPlanosSprintDeProjeto(const Codigo& codigoProjeto, std::vector<PlanoDeSprint>& planos) = 0;

    //-----------------------------------------------------------

    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~ISGestaoProjetos() {}
};

/**
 * @class ISGestaoHistorias
 * @brief Interface de serviço de gestão de Histórias (ISGH).
 * Centraliza as operações relacionadas a Histórias de Usuário e relacionamentos.
 */
class ISGestaoHistorias {
public:

    /**
     * @brief Cria uma nova História de Usuário associada a um projeto (Serviço 13).
     * @param historia Instância completa da entidade HistoriaDeUsuario a ser salva no sistema.
     * @return true se a história de usuário foi criada com sucesso, false caso contrário.
     */
    virtual bool criar(const HistoriaDeUsuario& historia) = 0;

    /**
     * @brief Lê os dados de uma História de Usuário cadastrada (Serviço 14).
     * @param historia Referência para o objeto HistoriaDeUsuario que receberá os dados do sistema.
     * @return true se a leitura foi bem-sucedida, false se a história de usuário não foi encontrada.
     */
    virtual bool ler(HistoriaDeUsuario& historia) = 0;

    /**
     * @brief Atualiza os dados de uma História de Usuário existente (Serviço 15).
     * @param historia Instância da entidade HistoriaDeUsuario contendo as modificações a serem salvas.
     * @return true se a atualização foi realizada com sucesso, false caso contrário.
     */
    virtual bool atualizar(const HistoriaDeUsuario& historia) = 0;

    /**
     * @brief Exclui uma História de Usuário do sistema (Serviço 16).
     * @param codigoHistoria Instância do domínio Codigo que identifica exclusivamente a História de Usuário a ser removida.
     * @return true se a exclusão foi bem-sucedida, false caso contrário.
     */
    virtual bool excluir(const Codigo& codigoHistoria) = 0;

    //-----------------------------------------------------------

    /**
     * @brief Estabelece um vínculo de associação entre uma História de Usuário e uma Pessoa (Serviço 17).
     * @param codigoHistoria Instância do domínio Codigo contendo o identificador da História de Usuário.
     * @param emailPessoa Instância do domínio Email contendo o identificador da Pessoa.
     * @return true se o relacionamento foi estabelecido com sucesso, false caso contrário.
     */
    virtual bool associarPessoa(const Codigo& codigoHistoria, const Email& emailPessoa) = 0;
    
    /**
     * @brief Remove o vínculo de associação entre uma História de Usuário e uma Pessoa (Serviço 18).
     * @param codigoHistoria Instância do domínio Codigo contendo o identificador da História de Usuário.
     * @param emailPessoa Instância do domínio Email contendo o identificador da Pessoa associada.
     * @return true se a associação foi removida com sucesso, false caso contrário.
     */
    virtual bool removerAssociacaoPessoa(const Codigo& codigoHistoria, const Email& emailPessoa) = 0;

    /**
     * @brief Move uma História de Usuário de um Projeto para um Plano de Sprint (Serviço 24).
     * @param codigoHistoria Instância do domínio Codigo identificando a História de Usuário a ser movida.
     * @param codigoPlano Instância do domínio Codigo identificando o Plano de Sprint destino.
     * @return true se a história foi movida com sucesso, false caso contrário.
     */
    virtual bool moverParaPlanoSprint(const Codigo& codigoHistoria, const Codigo& codigoPlano) = 0;

    /**
     * @brief Altera o estado de uma História de Usuário (Serviço 25).
     * @param codigoHistoria Instância do domínio Codigo identificando a História de Usuário.
     * @param novoEstado Instância do domínio Estado com o novo estado a ser aplicado à história.
     * @return true se o estado foi alterado com sucesso, false caso contrário.
     */
    virtual bool alterarEstado(const Codigo& codigoHistoria, const Estado& novoEstado) = 0; 

    //-----------------------------------------------------------

    /**
     * @brief Lista todas as Histórias de Usuário associadas a um Projeto específico (Serviço 20).
     * @param codigoProjeto Instância do domínio Codigo contendo o identificador do Projeto.
     * @param historias Referência para um vetor que será populado com as instâncias de HistoriaDeUsuario encontradas.
     * @return true se a operação de busca foi bem-sucedida, false em caso de falha.
     */
    virtual bool listarHistoriasDeProjeto(const Codigo& codigoProjeto, std::vector<HistoriaDeUsuario>& historias) = 0;

    /**
     * @brief Lista todas as Histórias de Usuário associadas a um Plano de Sprint (Serviço 22).
     * @param codigoPlano Instância do domínio Codigo contendo o identificador do Plano de Sprint.
     * @param historias Referência para um vetor que será populado com as instâncias de HistoriaDeUsuario encontradas.
     * @return true se a operação de busca foi bem-sucedida, false em caso de falha.
     */
    virtual bool listarHistoriasDePlanoSprint(const Codigo& codigoPlano, std::vector<HistoriaDeUsuario>& historias) = 0;

    /**
     * @brief Lista todas as Histórias de Usuário associadas a uma Pessoa (Serviço 23).
     * @param emailPessoa Instância do domínio Email contendo o identificador da Pessoa (ex: Desenvolvedor).
     * @param historias Referência para um vetor que será populado com as instâncias de HistoriaDeUsuario encontradas.
     * @return true se a operação de busca foi bem-sucedida, false em caso de falha.
     */
    virtual bool listarHistoriasDePessoa(const Email& emailPessoa, std::vector<HistoriaDeUsuario>& historias) = 0;

    //-----------------------------------------------------------

    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~ISGestaoHistorias() {}
};

#endif // INTERFACES_SERVICO_HPP_INCLUDED