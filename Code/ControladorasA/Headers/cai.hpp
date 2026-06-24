#ifndef CAI_INCLUDED
#define CAI_INCLUDED

#include "Interfaces/Headers/interfaces_apresentacao.hpp"
#include "Entities/Headers/entidades.hpp"

/**
 * @file cai.hpp
 * @brief Declaração da classe controladora de apresentação do menu inicial (CntrIAInicial).
 */

/**
 * @class CntrIAInicial
 * @brief Classe controladora de apresentação do menu inicial.
 * Implementa a interface IAInicial, mantendo o estado da sessão (se o utilizador está logado) 
 * e roteando a navegação para os subsistemas corretos.
 */
class CntrIAInicial : public IAInicial {
private:
    // Códigos dos serviços para o menu inicial.
    const static int AUTENTICAR = 1;
    const static int CADASTRO   = 2;
    const static int GESTAO_P   = 3;
    const static int GESTAO_H   = 4;
    const static int SAIR       = 5;

    // Ponteiros para as outras controladoras de apresentação
    IAAutenticacao    *cntrlIAAutenticacao;
    IACadastro        *cntrlIACadastro;
    IAGestaoProjetos  *cntrlIAGestaoProjetos;
    IAGestaoHistorias *cntrlIAGestaoHistorias;

public:
    /**
     * @brief Executa o menu principal de apresentação inicial.
     */
    void executar() override;

    /**
     * @brief Define a interface de autenticação que será dependência.
     * @param interface Ponteiro para a instância concreta da apresentação de autenticação.
     */
    void setApresentacaoAutenticacao(IAAutenticacao* interface) override;

    /**
     * @brief Define a interface de cadastro que será dependência.
     * @param interface Ponteiro para a instância concreta da apresentação de cadastro.
     */
    void setApresentacaoCadastro(IACadastro* interface) override;

    /**
     * @brief Define a interface de gestão de projetos que será dependência.
     * @param interface Ponteiro para a instância concreta da apresentação de gestão de projetos.
     */
    void setApresentacaoProjetos(IAGestaoProjetos* interface) override;

    /**
     * @brief Define a interface de gestão de histórias que será dependência.
     * @param interface Ponteiro para a instância concreta da apresentação de gestão de histórias.
     */
    void setApresentacaoHistorias(IAGestaoHistorias* interface) override;
};

inline void CntrIAInicial::setApresentacaoAutenticacao(IAAutenticacao* interface){
    cntrlIAAutenticacao = interface;
}
inline void CntrIAInicial::setApresentacaoCadastro(IACadastro* interface){
    cntrlIACadastro = interface;
}
inline void CntrIAInicial::setApresentacaoProjetos(IAGestaoProjetos* interface){
    cntrlIAGestaoProjetos = interface;
}
inline void CntrIAInicial::setApresentacaoHistorias(IAGestaoHistorias* interface){
    cntrlIAGestaoHistorias = interface;
}

#endif // CAI_INCLUDED