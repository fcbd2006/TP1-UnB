#include "Controladoras/Headers/cagp.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

void CntrIAGestaoProjetos::executar(const Email& email) {
    int opcao;
    bool executando = true;

    while (executando) {
        system("clear");
        std::cout << "======================================\n";
        std::cout << "      GESTAO DE PROJETOS E SPRINTS    \n";
        std::cout << "      Utilizador: " << email.getValor() << "\n";
        std::cout << "======================================\n";
        std::cout << CRIAR_PROJETO << " - Criar novo Projeto\n";
        std::cout << LER_PROJETO << " - Visualizar Projeto\n";
        std::cout << ATUALIZAR_PROJETO << " - Atualizar Projeto\n";
        std::cout << EXCLUIR_PROJETO << " - Excluir Projeto\n";
        std::cout << LISTAR_PROJETOS_PESSOA << " - Listar Projetos de uma Pessoa\n";
        std::cout << "--------------------------------------\n";
        std::cout << CRIAR_SPRINT << " - Criar Plano de Sprint\n";
        std::cout << LER_SPRINT << " - Visualizar Plano de Sprint\n";
        std::cout << ATUALIZAR_SPRINT << " - Atualizar Plano de Sprint\n";
        std::cout << EXCLUIR_SPRINT << " - Excluir Plano de Sprint\n";
        std::cout << LISTAR_SPRINTS_PROJETO << "- Listar Planos de Sprint de um Projeto\n";
        std::cout << "--------------------------------------\n";
        std::cout << RETORNAR << " - Retornar\n";
        std::cout << "Escolha uma opcao: ";
        
        std::cin >> opcao;

        switch (opcao) {
            case CRIAR_PROJETO:
                std::cout << "\n--- Criacao de Projeto ---\n"; break;
            case LER_PROJETO:
                std::cout << "\n--- Visualizar Projeto ---\n"; break;
            case ATUALIZAR_PROJETO:
                std::cout << "\n--- Atualizar Projeto ---\n"; break;
            case EXCLUIR_PROJETO:
                std::cout << "\n--- Excluir Projeto ---\n"; break;
            case LISTAR_PROJETOS_PESSOA:
                std::cout << "\n--- Meus Projetos ---\n"; break; // cntrlISGestaoProjetos->listarProjetosDePessoa(email, &vetorProjetos)
            
            case CRIAR_SPRINT:
                std::cout << "\n--- Criacao de Plano de Sprint ---\n"; break;
            case LER_SPRINT:
                std::cout << "\n--- Visualizar Plano de Sprint ---\n"; break;
            case ATUALIZAR_SPRINT:
                std::cout << "\n--- Atualizar Plano de Sprint ---\n"; break;
            case EXCLUIR_SPRINT:
                std::cout << "\n--- Excluir Plano de Sprint ---\n"; break;
            case LISTAR_SPRINTS_PROJETO:
                std::cout << "\n--- Sprints do Projeto ---\n"; break; // cntrlISGestaoProjetos->listarPlanosSprintDeProjeto(codigoProjeto, &vetorSprints)

            case RETORNAR:
                executando = false;
                break;

            default:
                std::cout << "\nOpcao invalida!.\n";
                break;
        }

        if (executando) {
            std::cout << "Pressione ENTER para continuar...";
            std::cin.ignore(); std::cin.get();
        }
    }
}