#include "ControladorasA/Headers/cac.hpp"
#include "Interfaces/Headers/interfaces_servico.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

void CntrIACadastro::executar(Email& email, Papel& papel) {
    int opcao = 0;
    bool executando = true;

    // Se o email não estiver preenchido, 
    // significa que o usuário não está logado e quer se cadastrar.
    bool logado = (email.getValor() != ""); 

    while (executando) {
        system("clear");
        std::cout << "======================================\n";
        std::cout << "           MENU DE CADASTRO           \n";
        std::cout << "======================================\n";

        if (!logado) {
            std::cout << CRIAR << " - Criar nova conta\n";
            std::cout << RETORNAR << " - Retornar\n";
        } else {
            std::cout << RETORNAR << " - Retornar\n";
            std::cout << LER << " - Visualizar dados da conta\n";
            std::cout << ATUALIZAR << " - Atualizar dados da conta\n";
            std::cout << EXCLUIR << " - Excluir conta\n";
        }
        
        std::cout << "Escolha uma opcao: ";
        if(!(std::cin >> opcao)){
            std::cin.clear();
            opcao = 0;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(!logado){
            switch (opcao){
                case CRIAR: 
                    this->cadastrar(email, papel, logado);
                    break;

                case RETORNAR:
                    executando = false;
                    break;

                default:
                    std::cout << "\nOpcao invalida!\n";
                    break;
            }
        }else{
            switch (opcao) {
                case LER: 
                    this->ler(email, logado);
                    break;

                case ATUALIZAR: 
                    this->atualizar(email, papel, logado);
                    break;

                case EXCLUIR: {
                    if (!logado) break;

                    char confirmacao;
                    std::cout << "\n--- Exclusao de Conta ---\n";
                    std::cout << "ATENCAO: Esta acao e irreversivel.\n";
                    std::cout << "Tem certeza que deseja excluir sua conta? (S/N): ";
                    if(!(std::cin >> confirmacao)){
                        std::cin.clear();
                        confirmacao = 0;
                    }
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    if (confirmacao == 'S' || confirmacao == 's') {
                        if (cntrlISCadastro->excluir(email)) {
                            std::cout << "\nConta excluida com sucesso. Voce sera desconectado.\n";
                            email = Email();
                            papel = Papel();
                            executando = false; // Força a saída do menu e o fim da sessão
                        } else {
                            std::cout << "\nErro ao tentar excluir a conta.\n";
                        }
                    } else {
                        std::cout << "\nExclusao cancelada.\n";
                    }
                    break;
                }

                case RETORNAR: {
                    executando = false;
                    break;
                }

                default:
                    std::cout << "\nOpcao invalida!\n";
                    break;
            }
        }

        if (executando) {
            std::cout << "Pressione ENTER para continuar...";
            std::cin.get();
        }
    }
}

void CntrIACadastro::cadastrar(Email& email, Papel& papel, bool& logado){
    if (logado) return; // Bloqueia se já estiver logado

    std::string strNome, strPapel, strSenha, strEmail;
    int escPapel = 0;
    std::cout << "\n--- Criacao de Nova Conta ---\n";
    
    std::cout << "Digite o Nome: ";
    std::getline(std::cin, strNome);
    
    while(!escPapel){
        std::cout << "Selecione o Papel:\n";
        std::cout << "  1 - DESENVOLVEDOR\n";
        std::cout << "  2 - MESTRE SCRUM\n";
        std::cout << "  3 - PROPRIETARIO DE PRODUTO\n";
        std::cout << "-> ";
        if(!(std::cin >> escPapel)){
            std::cin.clear();
            escPapel = 0;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(escPapel){
            case 1:
                strPapel = "DESENVOLVEDOR";
                break;
            case 2:
                strPapel = "MESTRE SCRUM";
                break;
            case 3:
                strPapel = "PROPRIETARIO DE PRODUTO";
                break;
            default:
                escPapel=0;
                std::cout << "Entrada inválida. Tente novamente.\n\n";
                break;
        }
    }
    
    std::cout << "Digite a Senha: ";
    std::getline(std::cin, strSenha);
    
    std::cout << "Digite o E-mail: ";
    std::getline(std::cin, strEmail);

    try {
        // Instancia os domínios e valida o formato
        Nome nome;       nome.setValor(strNome);
        Papel novoPapel;     papel.setValor(strPapel);
        Senha senha;     senha.setValor(strSenha);
        Email novoEmail; novoEmail.setValor(strEmail);

        // Monta a entidade
        Pessoa novaPessoa;
        novaPessoa.setNome(nome);
        novaPessoa.setPapel(novoPapel);
        novaPessoa.setSenha(senha);
        novaPessoa.setEmail(novoEmail);

        // Passa para a camada de serviço
        if (cntrlISCadastro->criar(novaPessoa)) {
            email = novoEmail;
            papel = novoPapel;
            logado = true;
            std::cout << "\nConta criada com sucesso! Voce ja esta logado.\n";
        } else {
            std::cout << "\nFalha no cadastro: O E-mail informado ja existe.\n";
        }
    } 
    catch (std::invalid_argument &exp) {
        std::cout << "\nErro nos dados informados: " << exp.what() << "\n";
    }
}

void CntrIACadastro::ler(const Email& email, bool logado){
    if (!logado) return; // Bloqueia se não estiver logado

    int opcao = 0;
    Pessoa pessoa;

    while(opcao == 0){
        std::cout << "\n--- Buscar Conta ---\n";
        std::cout << "\n Deseja buscar: \n";
        std::cout << "  1 - Própria conta;\n";
        std::cout << "  2 - Outra conta.\n";
        std::cout << "   -> ";
        if(!(std::cin >> opcao)){
            std::cin.clear();
            opcao = 0;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch(opcao){
            case 1:{
                pessoa.setEmail(email);
                break;
            }

            case 2:{
                Email novoEmail;
                std::string strEmail;
                std::cout << "Digite o Email: ";
                std::getline(std::cin, strEmail);
                try{
                    novoEmail.setValor(strEmail);
                    pessoa.setEmail(strEmail);
                }catch(std::invalid_argument &exp){
                    opcao=0;
                    std::cout << "\nErro nos dados informados: " << exp.what() << "\n";
                }
                break;
            }

            default:{
                opcao=0;
                std::cout << "Entrada inválida. Tente novamente.\n\n";
                break;
            }
        }
    }
    
    // Envia o email da sessão para o serviço buscar
    if (cntrlISCadastro->ler(pessoa)) {
        std::cout << "\n--- Dados Pessoais ---\n";
        std::cout << "Nome:   " << pessoa.getNome().getValor() << "\n";
        std::cout << "Papel:  " << pessoa.getPapel().getValor() << "\n";
        std::cout << "E-mail: " << pessoa.getEmail().getValor() << "\n";
        std::cout << "Senha:  " << pessoa.getSenha().getValor() << "\n";
    } else {
        std::cout << "\nErro crítico: Dados da conta não encontrados.\n";
    }
}

void CntrIACadastro::atualizar(const Email& email, Papel& papel, bool logado){
    if (!logado) return;

    std::string strNome, strPapel, strSenha;
    int escPapel = 0;
    std::cout << "\n--- Atualizacao de Conta ---\n";
    
    std::cout << "Digite o novo Nome: ";
    std::getline(std::cin, strNome);
    
    while(!escPapel){
        std::cout << "Selecione o novo Papel:\n";
        std::cout << "  1 - DESENVOLVEDOR\n";
        std::cout << "  2 - MESTRE SCRUM\n";
        std::cout << "  3 - PROPRIETARIO DE PRODUTO\n";
        std::cout << "-> ";
        if(!(std::cin >> escPapel)){
            std::cin.clear();
            escPapel = 0;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(escPapel){
            case 1:
                strPapel = "DESENVOLVEDOR";
                break;
            case 2:
                strPapel = "MESTRE SCRUM";
                break;
            case 3:
                strPapel = "PROPRIETARIO DE PRODUTO";
                break;
            default:
                escPapel=0;
                std::cout << "Entrada inválida. Tente novamente.\n\n";
                break;
        }
    }
    
    std::cout << "Digite a nova Senha: ";
    std::getline(std::cin, strSenha);

    try {
        Nome nome;   nome.setValor(strNome);
        Papel novoPapel; novoPapel.setValor(strPapel);
        Senha senha; senha.setValor(strSenha);

        Pessoa pessoaAtualizada;
        pessoaAtualizada.setNome(nome);
        pessoaAtualizada.setPapel(novoPapel);
        pessoaAtualizada.setSenha(senha);
        pessoaAtualizada.setEmail(email);

        if (cntrlISCadastro->atualizar(pessoaAtualizada)) {
            papel = novoPapel;
            std::cout << "\nDados atualizados com sucesso!\n";
        } else {
            std::cout << "\nFalha na atualizacao dos dados.\n";
        }
    } 
    catch (std::invalid_argument &exp) {
        std::cout << "\nErro nos dados informados: " << exp.what() << "\n";
    }
}

