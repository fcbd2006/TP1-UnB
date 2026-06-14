#ifndef CAGP_INCLUDED
#define CAGP_INCLUDED

#include "Interfaces/Headers/interfaces_apresentacao.hpp"
#include "Entities/Headers/entidades.hpp"

/**
 * @brief Classe controladora de apresentação para a Gestão de Projetos e Sprints.
 * Implementa a interface IAGestaoProjetos, fornecendo os menus e submenus interativos 
 * para gerenciar a estrutura temporal (Projetos e Sprints) do sistema Scrum.
 */
class CntrIAGestaoProjetos : public IAGestaoProjetos {
private:
    // Códigos dos serviços para os menus principais de Projetos e Sprints.
    const static int CRIAR_PROJETO          = 1;
    const static int LER_PROJETO            = 2;
    const static int ATUALIZAR_PROJETO      = 3;
    const static int EXCLUIR_PROJETO        = 4;
    const static int LISTAR_PROJETOS_PESSOA = 5; 
    const static int CRIAR_SPRINT           = 6;
    const static int LER_SPRINT             = 7;
    const static int ATUALIZAR_SPRINT       = 8;
    const static int EXCLUIR_SPRINT         = 9;
    const static int LISTAR_SPRINTS_PROJETO = 10;
    const static int RETORNAR               = 11;

    /** @brief Ponteiro para a interface de serviço de gestão de projetos. */
    ISGestaoProjetos *cntrlISGestaoProjetos;

public:
    /**
     * @brief Executa o menu principal de gestão de Projetos e Sprints.
     * @param email Referência constante para o e-mail do usuário atualmente autenticado.
     */
    void executar(const Email& email) override;

    /**
     * @brief Define o módulo de serviço de gestão de projetos que será dependência.
     * @param servico Ponteiro para a instância concreta do serviço de gestão de projetos e sprints.
     */
    void setServicoGestaoProjetos(ISGestaoProjetos* servico) override;
};

inline void CntrIAGestaoProjetos::setServicoGestaoProjetos(ISGestaoProjetos *servico) {
    this->cntrlISGestaoProjetos = servico;
}

#endif // CAGP_INCLUDED