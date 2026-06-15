#include "Controladoras/Headers/cai.hpp"
#include <iostream>
#include <limits>

void CntrIAInicial::executar() {
    int opcao = 0;
    bool executando = true;
    bool logado = false;
    Email emailSessao;

    while (executando) {
        system("clear");
        std::cout << "======================================\n";
        std::cout << "        SISTEMA DE GESTAO SCRUM       \n";
        std::cout << "======================================\n";

        if (!logado) {
            std::cout << AUTENTICAR << " - Fazer Login (Autenticar)\n";
            std::cout << CADASTRO << " - Criar uma nova conta\n";
            std::cout << SAIR << " - Encerrar o sistema\n";
        } else {
            std::cout << "Bem-vindo, " << emailSessao.getValor() << "!\n\n";
            std::cout << CADASTRO << " - Minha Conta (Visualizar/Editar/Excluir)\n";
            std::cout << GESTAO_P << " - Painel de Projetos e Sprints\n";
            std::cout << GESTAO_H << " - Painel de Historias de Usuario\n";
            std::cout << SAIR << " - Fazer Logout (Sair da sessao)\n";
        }
        std::cout << "Escolha uma opcao: ";
        if(!(std::cin >> opcao)){
            std::cin.clear();
            opcao = 0;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!logado) {
            switch (opcao) {
                case AUTENTICAR:
                    if (cntrlIAAutenticacao->autenticar(emailSessao)) {
                        logado = true;
                    }
                    break;
                case CADASTRO:
                    cntrlIACadastro->executar(emailSessao);
                    if(emailSessao.getValor() != ""){
                        logado = true;
                    }
                    break;
                case SAIR:
                    executando = false;
                    break;
                default:
                    std::cout << "\nOpcao invalida! Pressione ENTER para tentar novamente...\n";
                    std::cin.get();
                    break;
            }
        }else{
            switch (opcao) {
                case CADASTRO:
                    cntrlIACadastro->executar(emailSessao);
                    if (emailSessao.getValor() == "") {
                        logado = false;
                    }
                    break;
                case GESTAO_P:
                    cntrlIAGestaoProjetos->executar(emailSessao);
                    break;
                case GESTAO_H:
                    cntrlIAGestaoHistorias->executar(emailSessao);
                    break;
                case SAIR:
                    logado = false;
                    emailSessao = Email();
                    std::cout << "\nSessao terminada com sucesso.\n";
                    std::cout << "Pressione ENTER para continuar...";
                    std::cin.get();
                    break;
                default:
                    std::cout << "\nOpcao invalida! Pressione ENTER para tentar novamente...\n";
                    std::cout << "Pressione ENTER para continuar...";
                    std::cin.get();
                    break;
            }
        }
    }
}