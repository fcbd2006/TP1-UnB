#ifndef CAGH_HPP_INCLUDED
#define CAGH_HPP_INCLUDED

#include "Interfaces/Headers/interfaces_apresentacao.hpp"
#include "Entities/Headers/entidades.hpp"

/**
 * @brief Classe controladora de apresentação para a Gestão de Histórias de Usuário.
 * Implementa a interface IAGestaoHistorias, fornecendo os menus e submenus interativos 
 * para gerenciar os requisitos, estados e atribuições de histórias.
 */
class CntrIAGestaoHistorias : public IAGestaoHistorias {
private:
    // Códigos dos serviços para o menu principal de Histórias.
    const static int CRIAR                    = 1;
    const static int LER                      = 2;
    const static int ATUALIZAR                = 3;
    const static int EXCLUIR                  = 4;
    const static int ASSOCIAR                 = 5;
    const static int MOVER                    = 6;
    const static int ALTERAR_EST              = 7;
    const static int LISTAR_HISTORIAS_PROJETO = 8;
    const static int LISTAR_HISTORIAS_SPRINT  = 9; 
    const static int LISTAR_HISTORIAS_PESSOA  = 10; 
    const static int RETORNAR                 = 11;

    /** @brief Ponteiro para a interface de serviço de gestão de histórias. */
    ISGestaoHistorias *cntrlISGestaoHistorias;

    /**
     * @brief Subrotina para o cadastro de nova história.
     * @param email Referência para o e-mail do usuário.
     */
    void criar(const Email& email);

    /**
     * @brief Subrotina para a leitura de história.
     */
    void ler();

    /**
     * @brief Subrotina para a atualização de uma história.
     * @param email Referência para o e-mail do usuário.
     */
    void atualizar(const Email& email);

    /**
     * @brief Subrotina para a exclusão de uma história.
     * @param email Referência para o e-mail do usuário.
     */
    void excluir(const Email& email);

public:
    /**
     * @brief Executa o menu principal de gestão de Histórias de Usuário.
     * @param email Referência constante para o e-mail do usuário atualmente autenticado.
     */
    void executar(const Email& email, const Papel& papel) override;

    /**
     * @brief Define o módulo de serviço de gestão de histórias que será dependência.
     * @param servico Ponteiro para a instância concreta do serviço de gestão de histórias.
     */
    void setServicoGestaoHistorias(ISGestaoHistorias* servico) override;
};

inline void CntrIAGestaoHistorias::setServicoGestaoHistorias(ISGestaoHistorias *servico) {
    this->cntrlISGestaoHistorias = servico;
}

#endif // CAGH_HPP_INCLUDED