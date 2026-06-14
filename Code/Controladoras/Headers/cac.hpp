#ifndef CAC_HPP_INCLUDED
#define CAC_HPP_INCLUDED

#include "Interfaces/Headers/interfaces_apresentacao.hpp"
#include "Entities/Headers/entidades.hpp"

/**
 * @brief Classe controladora de apresentação do Cadastro de usuários.
 * Implementa a interface IACadastro, gerenciando os menus e interações 
 * relacionadas à criação, leitura, atualização e exclusão de contas de usuário (Pessoa).
 */
class CntrIACadastro : public IACadastro {
private:
    // Códigos dos serviços para o menu de Cadastro.
    const static int CRIAR     = 1;
    const static int RETORNAR  = 2;
    const static int LER       = 3;
    const static int ATUALIZAR = 4;
    const static int EXCLUIR   = 5;

    /** @brief Ponteiro para a interface de serviço de cadastro. */
    ISCadastro *cntrlISCadastro;

    /**
     * @brief Subrotina para o cadastro de novo usuário.
     * @param email Referência para o e-mail do usuário (esperado que seja vazio).
     * @param logado Valor booleano que indica se o usário de fato não está logado (false).
     */
    void cadastrar(Email& email, bool& logado);

    /**
     * @brief Subrotina para a leitura dos dados de um usuário.
     * @param email Referência para o e-mail do usuário.
     * @param logado Valor booleano que indica se o usário está logado (true).
     */
    void ler(const Email& email, bool logado);

    /**
     * @brief Subrotina para a atualização dos dados de um usuário.
     * @param email Referência para o e-mail do usuário.
     * @param logado Valor booleano que indica se o usário está logado (true).
     */
    void atualizar(const Email& email, bool logado);

public:
    /**
     * @brief Executa o menu principal de gerenciamento de contas.
     * @param email Referência para o e-mail do usuário logado (pode ser vazio caso o usuário não esteja autenticado).
     */
    void executar(Email& email) override;

    /**
     * @brief Define o módulo de serviço de cadastro que será dependência.
     * @param servico Ponteiro para a instância concreta do serviço de cadastro.
     */
    void setServicoCadastro(ISCadastro* servico) override;
};

inline void CntrIACadastro::setServicoCadastro(ISCadastro *servico) {
    this->cntrlISCadastro = servico;
}

#endif // CAC_HPP_INCLUDED