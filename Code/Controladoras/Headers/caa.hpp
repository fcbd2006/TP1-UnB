#ifndef CAA_HPP_INCLUDED
#define CAA_HPP_INCLUDED

#include "Interfaces/Headers/interfaces_apresentacao.hpp"
#include "Entities/Headers/entidades.hpp"

/**
 * @brief Classe controladora de apresentação de Autenticação.
 * Implementa a interface IAAutenticacao, gerenciando a interação com o 
 * usuário para a coleta de credenciais e invocação do serviço de validação.
 */
class CntrIAAutenticacao : public IAAutenticacao {
private:
    /** @brief Ponteiro para a interface de serviço de autenticação. */
    ISAutenticacao *cntrlISAutenticacao;
public:
    /**
     * @brief Executa o fluxo interativo de autenticação do usuário.
     * @param email o objeto Email onde será armazenado o e-mail do usuário caso a autenticação tenha sucesso.
     * @return true se a autenticação for bem-sucedida, false caso contrário.
     */
    bool autenticar(Email& email) override;

    /**
     * @brief Define o módulo de serviço de autenticação que será dependência.
     * @param servico Ponteiro para a instância concreta do serviço de autenticação.
     */
    void setServicoAutenticacao(ISAutenticacao* servico) override;
};

inline void CntrIAAutenticacao::setServicoAutenticacao(ISAutenticacao *servico) {
    this->cntrlISAutenticacao = servico;
}

#endif // CAA_HPP_INCLUDED