#include "ControladorasA/Headers/cagp.hpp"
#include "Interfaces/Headers/interfaces_servico.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

void CntrIAGestaoProjetos::executar(const Email& email, const Papel& papel) {
    int opcao = 0;
    bool executando = true;

    while (executando) {
        system("clear");
        std::cout << "======================================\n";
        std::cout << "      GESTAO DE PROJETOS E SPRINTS    \n";
        std::cout << "      Utilizador: " << email.getValor() << "\n";
        std::cout << "      Papel: " << papel.getValor() << "\n";
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
        
        if(!(std::cin >> opcao)){
            std::cin.clear();
            opcao = 0;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcao) {

            // GESTÃO DE PROJETOS

            case CRIAR_PROJETO:
                if (papel.getValor() == "PROPRIETARIO DE PRODUTO") {
                    this->criarProjeto(email);
                } else {
                    std::cout << "\n[Acesso Negado] Apenas Proprietario de Produto pode criar projetos.\n";
                }
                break;
                
            case LER_PROJETO:
                this->lerProjeto();
                break;
                
            case ATUALIZAR_PROJETO:
                if (papel.getValor() == "PROPRIETARIO DE PRODUTO") {
                    this->atualizarProjeto(email);
                } else {
                    std::cout << "\n[Acesso Negado] Apenas Proprietario de Produto pode atualizar projetos.\n";
                }
                break;
                
            case EXCLUIR_PROJETO:
                if (papel.getValor() == "PROPRIETARIO DE PRODUTO") {
                    this->excluirProjeto(email);
                } else {
                    std::cout << "\n[Acesso Negado] Apenas Proprietario de Produto pode excluir projetos.\n";
                }
                break;
                
            case LISTAR_PROJETOS_PESSOA:
                std::cout << "\n--- Projetos de uma Pessoa ---\n"; 
                break;
            
            // ---- GESTÃO DE PLANOS DE SPRINT ----

            case CRIAR_SPRINT:
                if (papel.getValor() == "MESTRE SCRUM") {
                    this->criarSprint(email);
                } else {
                    std::cout << "\n[Acesso Negado] Apenas Mestre Scrum pode criar planos de sprint.\n";
                }
                break;
                
            case LER_SPRINT:
                this->lerSprint();
                break;
                
            case ATUALIZAR_SPRINT:
                if (papel.getValor() == "MESTRE SCRUM") {
                    this->atualizarSprint(email);
                } else {
                    std::cout << "\n[Acesso Negado] Apenas Mestre Scrum pode atualizar planos de sprint.\n";
                }
                break;
                
            case EXCLUIR_SPRINT:
                if (papel.getValor() == "MESTRE SCRUM") {
                    this->excluirSprint(email);
                } else {
                    std::cout << "\n[Acesso Negado] Apenas Mestre Scrum pode excluir planos de sprint.\n";
                }
                break;
                
            case LISTAR_SPRINTS_PROJETO:
                std::cout << "\n--- Sprints do Projeto ---\n";
                break; 

            case RETORNAR:
                executando = false;
                break;

            default:
                std::cout << "\nOpcao invalida!.\n";
                break;
        }

        if (executando) {
            std::cout << "Pressione ENTER para continuar...";
            std::cin.get();
        }
    }
}

void CntrIAGestaoProjetos::criarProjeto(const Email& email){
    std::string strCodigo, strNome, strDataI, strDataT;
    std::cout << "\n--- Criacao de Novo Projeto ---\n";
    
    std::cout << "\nDigite o Codigo: ";
    std::getline(std::cin, strCodigo);
    
    std::cout << "\nDigite o Nome: ";
    std::getline(std::cin, strNome);

    std::cout << "\nDigite a Data de Início (DD/MM/AAAA): ";
    std::getline(std::cin, strDataI);
    
    std::cout << "\nDigite a Data de Término (DD/MM/AAAA): ";
    std::getline(std::cin, strDataT);

    try {
        // Instancia os domínios e valida o formato
        Codigo codigo; codigo.setValor(strCodigo);
        Nome nome; nome.setValor(strNome);
        Data inicio; inicio.setValor(strDataI);
        Data termino; termino.setValor(strDataT);

        // Monta a entidade
        Projeto novoProjeto;
        novoProjeto.setCodigo(codigo);
        novoProjeto.setNome(nome);
        novoProjeto.setDataStart(inicio);
        novoProjeto.setDataEnd(termino);

        // Passa para a camada de serviço
        if (cntrlISGestaoProjetos->criarProjeto(novoProjeto)) {
            std::cout << "Projeto criado com sucesso!\n";
        } else {
            std::cout << "\nFalha no cadastro: Codigo informado ja esta em uso.\n";
        }
    } 
    catch (std::invalid_argument &exp) {
        std::cout << "\nErro nos dados informados: " << exp.what() << "\n";
    }
}

void CntrIAGestaoProjetos::lerProjeto(){
    std::string strCodigo;
    std::cout << "\n--- Visualizar Projeto ---\n";
    
    std::cout << "\nDigite o Codigo: ";
    std::getline(std::cin, strCodigo);

    try{
        Codigo codigo; codigo.setValor(strCodigo);
        Projeto projeto; projeto.setCodigo(codigo);

        if(cntrlISGestaoProjetos->lerProjeto(projeto)){
            std::cout << "\nProjeto requisitado:\n";
            std::cout << "- Codigo: " << projeto.getCodigo().getValor() << "\n";
            std::cout << "- Nome: " << projeto.getNome().getValor() << "\n";
            std::cout << "- Data de Inicio: " << projeto.getDataStart().getValor() << "\n";
            std::cout << "- Data de Termino: " << projeto.getDataEnd().getValor() << "\n";
        }else{
            std::cout << "\nFalha na visualizacao: O codigo informado nao esta cadastrado.\n";
        }

    }catch (std::invalid_argument &exp){
        std::cout << "\nErro nos dados informados: " << exp.what() << "\n";
    }
}

void CntrIAGestaoProjetos::atualizarProjeto(const Email& email){

    std::string strCodigo, strNome, strDataI, strDataT;
    std::cout << "\n--- Atualizar Projeto ---\n";
    
    std::cout << "\nDigite o Codigo: ";
    std::getline(std::cin, strCodigo);
    
    std::cout << "\nDigite o novo Nome: ";
    std::getline(std::cin, strNome);

    std::cout << "\nDigite a nova Data de Inicio (DD/MM/AAAA): ";
    std::getline(std::cin, strDataI);
    
    std::cout << "\nDigite a nova Data de Termino: ";
    std::getline(std::cin, strDataT);

    try {
        // Instancia os domínios e valida o formato
        Codigo codigo; codigo.setValor(strCodigo);
        Nome nome; nome.setValor(strNome);
        Data inicio; inicio.setValor(strDataI);
        Data termino; termino.setValor(strDataT);

        // Monta a entidade
        Projeto novoProjeto;
        novoProjeto.setCodigo(codigo);
        novoProjeto.setNome(nome);
        novoProjeto.setDataStart(inicio);
        novoProjeto.setDataEnd(termino);

        // Passa para a camada de serviço
        if (cntrlISGestaoProjetos->atualizarProjeto(novoProjeto)) {
            std::cout << "Projeto alterado com sucesso!\n";
        } else {
            std::cout << "\nFalha na ateracao: Codigo informado nao consta na base de dados.\n";
        }
    } 
    catch (std::invalid_argument &exp) {
        std::cout << "\nErro nos dados informados: " << exp.what() << "\n";
    }
}

void CntrIAGestaoProjetos::excluirProjeto(const Email& email){
    std::string strCodigo;
    std::cout << "\n--- Exclusao de Projeto ---\n";

    std::cout << "\nDigite o Codigo do projeto que deseja excluir: ";
    std::getline(std::cin, strCodigo);
    try{
        Codigo codigo; codigo.setValor(strCodigo);

        char confirmacao;
        std::cout << "ATENCAO: Esta acao e irreversivel.\n";
        std::cout << "Tem certeza que deseja excluir esse projeto? (S/N): ";
        if(!(std::cin >> confirmacao)){
            std::cin.clear();
            confirmacao = 0;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (confirmacao == 'S' || confirmacao == 's') {
            if (cntrlISGestaoProjetos->excluirProjeto(codigo)) {
                std::cout << "\nProjeto excluido com sucesso.\n";
            } else {
                std::cout << "\nErro ao tentar excluir o projeto. Codigo nao encontrado na base de dados.\n";
            }
        } else {
            std::cout << "\nExclusao cancelada.\n";
        }
    }
    catch (std::invalid_argument &exp) {
        std::cout << "\nErro nos dados informados: " << exp.what() << "\n";
    }
}

void CntrIAGestaoProjetos::criarSprint(const Email& email){
    std::string strCodigo, strTexto, strTempo;
    std::cout << "\n--- Criacao de Novo Plano de Sprint ---\n";
    
    std::cout << "\nDigite o Codigo: ";
    std::getline(std::cin, strCodigo);
    
    std::cout << "\nDigite o Objetivo: ";
    std::getline(std::cin, strTexto);

    std::cout << "\nDigite a Capacidade: ";
    std::getline(std::cin, strTempo);

    try {
        // Instancia os domínios e valida o formato
        Codigo codigo; codigo.setValor(strCodigo);
        Texto objetivo; objetivo.setValor(strTexto);
        Tempo capacidade; capacidade.setValor(strTempo);

        // Monta a entidade
        PlanoDeSprint novoSprint;
        novoSprint.setCodigo(codigo);
        novoSprint.setTexto(objetivo);
        novoSprint.setTempo(capacidade);

        // Passa para a camada de serviço
        if (cntrlISGestaoProjetos->criarPlanoSprint(novoSprint)) {
            std::cout << "Plano de Sprint criado com sucesso!\n";
        } else {
            std::cout << "\nFalha no cadastro: Codigo informado ja esta em uso.\n";
        }
    } 
    catch (std::invalid_argument &exp) {
        std::cout << "\nErro nos dados informados: " << exp.what() << "\n";
    }
}

void CntrIAGestaoProjetos::lerSprint(){
    std::string strCodigo;
    std::cout << "\n--- Visualizar Plano de Sprint ---\n";
    
    std::cout << "\nDigite o Codigo: ";
    std::getline(std::cin, strCodigo);

    try{
        Codigo codigo; codigo.setValor(strCodigo);
        PlanoDeSprint sprint; sprint.setCodigo(codigo);

        if(cntrlISGestaoProjetos->lerPlanoSprint(sprint)){
            std::cout << "\nPLano de Sprint requisitado:\n";
            std::cout << "- Codigo: " << sprint.getCodigo().getValor() << "\n";
            std::cout << "- Objetivo: " << sprint.getTexto().getValor() << "\n";
            std::cout << "- Capacidade: " << sprint.getTempo().getValor() << "\n";
        }else{
            std::cout << "\nFalha na visualizacao: O codigo informado nao esta cadastrado.\n";
        }

    }catch (std::invalid_argument &exp){
        std::cout << "\nErro nos dados informados: " << exp.what() << "\n";
    }
}

void CntrIAGestaoProjetos::atualizarSprint(const Email& email){

    std::string strCodigo, strTexto, strTempo;
    std::cout << "\n--- Atualizar Plano de Sprint ---\n";
    
    std::cout << "\nDigite o Codigo: ";
    std::getline(std::cin, strCodigo);
    
    std::cout << "\nDigite o novo Objetivo: ";
    std::getline(std::cin, strTexto);

    std::cout << "\nDigite a nova Capacidade: ";
    std::getline(std::cin, strTempo);

    try {
        // Instancia os domínios e valida o formato
        Codigo codigo; codigo.setValor(strCodigo);
        Texto objetivo; objetivo.setValor(strTexto);
        Tempo capacidade; capacidade.setValor(strTempo);

        // Monta a entidade
        PlanoDeSprint novoSprint;
        novoSprint.setCodigo(codigo);
        novoSprint.setTexto(objetivo);
        novoSprint.setTempo(capacidade);

        // Passa para a camada de serviço
        if (cntrlISGestaoProjetos->criarPlanoSprint(novoSprint)) {
            std::cout << "Plano de Sprint alterado com sucesso!\n";
        } else {
            std::cout << "\nFalha na alteracao: Codigo informado nao consta na base de dados.\n";
        }
    } 
    catch (std::invalid_argument &exp) {
        std::cout << "\nErro nos dados informados: " << exp.what() << "\n";
    }
}

void CntrIAGestaoProjetos::excluirSprint(const Email& email){
    std::string strCodigo;
    std::cout << "\n--- Exclusao de Plano de Sprint ---\n";

    std::cout << "\nDigite o Codigo do plano de sprint que deseja excluir: ";
    std::getline(std::cin, strCodigo);
    try{
        Codigo codigo; codigo.setValor(strCodigo);

        char confirmacao;
        std::cout << "ATENCAO: Esta acao e irreversivel.\n";
        std::cout << "Tem certeza que deseja excluir esse plano de sprint? (S/N): ";
        if(!(std::cin >> confirmacao)){
            std::cin.clear();
            confirmacao = 0;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (confirmacao == 'S' || confirmacao == 's') {
            if (cntrlISGestaoProjetos->excluirProjeto(codigo)) {
                std::cout << "\nPlano de Sprint excluido com sucesso.\n";
            } else {
                std::cout << "\nErro ao tentar excluir o plano de sprint. Codigo nao encontrado na base de dados.\n";
            }
        } else {
            std::cout << "\nExclusao cancelada.\n";
        }
    }
    catch (std::invalid_argument &exp) {
        std::cout << "\nErro nos dados informados: " << exp.what() << "\n";
    }
}