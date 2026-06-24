#ifndef INTERFACES_APRESENTACAO_HPP_INCLUDED
#define INTERFACES_APRESENTACAO_HPP_INCLUDED

#include "Entities/Headers/entidades.hpp"

/**
 * @file interfaces_apresentacao.hpp
 * @brief Declaração das interfaces da camada de Apresentação.
 */

//-----------------------------------------------------------
// FORWARD DECLARATIONS DAS INTERFACES DE SERVIÇO
//-----------------------------------------------------------

class ISAutenticacao;
class ISCadastro;
class ISGestaoHistorias;
class ISGestaoProjetos;

//-----------------------------------------------------------
// AUTENTICAÇÃO
//-----------------------------------------------------------

/**
 * @class IAAutenticacao
 * @brief Interface de apresentação de autenticação (IAA).
 *
 * Esta classe abstrata estabelece o contrato para a interação com o utilizador 
 * durante o fluxo de entrada e login no sistema.
 */
class IAAutenticacao {
public:
    /**
     * @brief Executa o menu de autenticação de usuário.
     *
     * Solicita as credenciais de acesso (e-mail e senha), realiza a validação de 
     * formato dos dados inseridos e invoca a camada de serviço para confirmar a autenticidade.
     *
     * @param email Objeto Email que será preenchido com o identificador do utilizador autenticado em caso de sucesso.
     * @param papel Objeto Papel que será preenchido com o papel do utilizador autenticado em caso de sucesso.
     * @return true se o utilizador for autenticado com sucesso, false caso contrário.
     */
    virtual bool autenticar(Email& email, Papel& papel) = 0;

    /**
     * @brief Define a ligação com o respectivo módulo de serviço de autenticação.
     *
     * @param servico Ponteiro para a interface de serviço de autenticação (ISA).
     */
    virtual void setServicoAutenticacao(ISAutenticacao* servico) = 0;

    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~IAAutenticacao() {}
};

//-----------------------------------------------------------
// CADASTRO
//-----------------------------------------------------------

/**
 * @class IACadastro
 * @brief Interface de apresentação de cadastro (IAC).
 *
 * Estabelece o contrato para a exibição de menus relacionados com 
 * o gerenciamento de contas (Pessoas).
 */
class IACadastro {
public:
    /**
     * @brief Executa o menu de gestão de conta ou registo inicial.
     *
     * Caso o e-mail fornecido esteja vazio, apresenta o fluxo de criação de uma nova conta.
     * Caso contrário, apresenta as opções de visualização, modificação ou exclusão dos dados da conta logada.
     *
     * @param email Referência para o e-mail do utilizador em sessão (pode ser um objeto vazio).
     * @param papel Referência para o papel do utilizador em sessão (pode ser um objeto vazio).
     */
    virtual void executar(Email& email, Papel& papel) = 0;

    /**
     * @brief Define a ligação com o respectivo módulo de serviço de cadastro.
     *
     * @param servico Ponteiro para a interface de serviço de cadastro (ISC).
     */
    virtual void setServicoCadastro(ISCadastro* servico) = 0;

    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~IACadastro() {}
};

//-----------------------------------------------------------
// GESTÃO
//-----------------------------------------------------------

/**
 * @class IAGestaoProjetos
 * @brief Interface de apresentação de gestão de projetos (IAGP).
 *
 * Estabelece o contrato para a exibição dos menus de controle de
 * projetos e planos de sprint.
 */
class IAGestaoProjetos {
public:
    /**
     * @brief Executa o menu principal de gestão de projetos e planos de sprint.
     *
     * Apresenta as opções de listagem, criação e edição de projetos e planos de sprint.
     * As opções exibidas devem respeitar as restrições de permissões do papel associado ao e-mail.
     *
     * @param email Referência constante para o e-mail do utilizador autenticado que está operando o sistema.
     * @param papel Referência constante para o papel do utilizador autenticado que está operando o sistema.
     */
    virtual void executar(const Email& email, const Papel& papel) = 0;

    /**
     * @brief Define a ligação com o respectivo módulo de serviço de gestão de projetos.
     *
     * @param servico Ponteiro para a interface de serviço de gestão de projetos (ISGP).
     */
    virtual void setServicoGestaoProjetos(ISGestaoProjetos* servico) = 0;

    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~IAGestaoProjetos() {}
};

/**
 * @class IAGestaoHistorias
 * @brief Interface de apresentação de gestão de histórias (IAGH).
 *
 * Estabelece o contrato para a exibição dos menus de controle de história.
 */
class IAGestaoHistorias {
public:
    /**
     * @brief Executa o menu principal de gestão de histórias.
     *
     * Apresenta as opções de listagem, criação e edição de histórias.
     * As opções exibidas devem respeitar as restrições de permissões do papel associado ao e-mail.
     *
     * @param email Referência constante para o e-mail do utilizador autenticado que está operando o sistema.
     * @param papel Referência constante para o papel do utilizador autenticado que está operando o sistema.
     */
    virtual void executar(const Email& email, const Papel& papel) = 0;

    /**
     * @brief Define a ligação com o respectivo módulo de serviço de gestão de histórias.
     *
     * @param servico Ponteiro para a interface de serviço de gestão de histórias (ISGH).
     */
    virtual void setServicoGestaoHistorias(ISGestaoHistorias* servico) = 0;

    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~IAGestaoHistorias() {}
};

//-----------------------------------------------------------
// INICIAL
//-----------------------------------------------------------

/**
 * @class IAInicial
 * @brief Interface de apresentação para a inicialização e coordenação do sistema.
 * Define o contrato para o menu principal de navegação, que interliga 
 * os fluxos de autenticação, cadastro e gestão.
 */
class IAInicial {
public:
    /**
     * @brief Inicia a execução do programa e o menu principal.
     */
    virtual void executar() = 0;

    /** 
     * @brief Injeta o módulo de apresentação de Autenticação. 
     * @param apr Ponteiro para a interface de apresentação de autenticação (IAA).
     */

    virtual void setApresentacaoAutenticacao(IAAutenticacao* apr) = 0;
    
    /** 
     * @brief Injeta o módulo de apresentação de Cadastro. 
     * @param apr Ponteiro para a interface de apresentação de cadastro (IAC).
     */
    virtual void setApresentacaoCadastro(IACadastro* apr) = 0;
    
    /** 
     * @brief Injeta o módulo de apresentação de Gestão de Projetos. 
     * @param apr Ponteiro para a interface de apresentação de gestão de projetos (IAGP).
     */
    virtual void setApresentacaoProjetos(IAGestaoProjetos* apr) = 0;
    
    /** 
     * @brief Injeta o módulo de apresentação de Gestão de Histórias. 
     * @param apr Ponteiro para a interface de apresentação de gestão de histórias (IAGH).
     */
    virtual void setApresentacaoHistorias(IAGestaoHistorias* apr) = 0;

    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~IAInicial() {}
};

#endif // INTERFACES_APRESENTACAO_HPP_INCLUDED