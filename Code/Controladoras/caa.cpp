#include "Controladoras/Headers/caa.hpp"
#include "Interfaces/Headers/interfaces_servico.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

bool CntrIAAutenticacao::autenticar(Email& email) {
    std::string entradaEmail, entradaSenha;
    int entrada = 0;
    Email emailTemp;
    Senha senhaTemp;

    while (true) {
        system("clear");
        std::cout << "======================================\n";
        std::cout << "                LOGIN                 \n";
        std::cout << "======================================\n";
        std::cout << "1 - Entrar\n";
        std::cout << "2 - Retornar\n";
        std::cout << "Escolha uma opcao: ";
        if(!(std::cin >> entrada)){
            std::cin.clear();
            entrada = 0;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (entrada == 2) {
            return false;
        }
        else if(entrada != 1) {
            std::cout << "Opcao invalida. Pressione ENTER para tentar novamente...";
            std::cin.get();
            continue;
        }
        std::cout << "Digite o E-mail: ";
        std::getline(std::cin, entradaEmail);

        std::cout << "Digite a Senha: ";
        std::getline(std::cin, entradaSenha);

        try {
            // a validação de formato acontece aqui
            emailTemp.setValor(entradaEmail);
            senhaTemp.setValor(entradaSenha);

            // chama a camada de serviço que vai verificar no banco de dados
            if (cntrlISAutenticacao->autenticar(emailTemp, senhaTemp)) {
                email.setValor(emailTemp.getValor()); // Salva o e-mail na sessão
                std::cout << "\nAutenticacao realizada com sucesso.\n";
                std::cout << "Pressione ENTER para continuar...";
                std::cin.get();
                return true;
            } else {
                std::cout << "\nFalha na autenticacao: E-mail ou senha incorretos.\n";
                std::cout << "Pressione ENTER para tentar novamente...";
                std::cin.get();
            }
        } 
        catch (std::invalid_argument &exp) {
            // Captura as exceções lançadas pelas classes Email e Senha
            std::cout << "\nErro de formato: " << exp.what() << "\n";
            std::cout << "Pressione ENTER para tentar novamente...";
            std::cin.get();
        }
    }
}
