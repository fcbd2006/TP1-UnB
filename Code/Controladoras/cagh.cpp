#include "Controladoras/Headers/cagh.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

void CntrIAGestaoHistorias::executar(const Email& email) {
    int opcao;
    bool executando = true;

    while (executando) {
        system("clear");
        std::cout << "======================================\n";
        std::cout << "      GESTAO DE HISTORIAS DE USUARIO  \n";
        std::cout << "      Utilizador: " << email.getValor() << "\n";
        std::cout << "======================================\n";
        std::cout << CRIAR << " - Criar nova Historia\n";
        std::cout << LER << " - Visualizar Historia\n";
        std::cout << ATUALIZAR << " - Atualizar Historia\n";
        std::cout << EXCLUIR << " - Excluir Historia\n";
        std::cout << "--------------------------------------\n";
        std::cout << ASSOCIAR << " - Associar Historia a Desenvolvedor\n";
        std::cout << MOVER << " - Mover Historia para Plano de Sprint\n";
        std::cout << ALTERAR_EST << " - Alterar Estado da Historia\n";
        std::cout << "--------------------------------------\n";
        std::cout << LISTAR_HISTORIAS_PROJETO << " - Listar Historias de um Projeto\n";
        std::cout << LISTAR_HISTORIAS_SPRINT << " - Listar Historias de um Sprint\n";
        std::cout << LISTAR_HISTORIAS_PESSOA << " - Listar Historias de uma Pessoa\n";
        std::cout << "--------------------------------------\n";
        std::cout << RETORNAR << " - Retornar\n";
        std::cout << "Escolha uma opcao: ";
        
        std::cin >> opcao;

        switch (opcao) {
            case CRIAR:
                this->criar(email);
                break;
            case LER:
                this->ler();
                break;
            case ATUALIZAR:
                this->atualizar(email);
                break;
            case EXCLUIR:{
                std::string strCodigo;
                std::cout << "\n--- Exclusao de Historia ---\n";

                std::cin.ignore();
                std::cout << "\nDigite o Codigo da historia que deseja excluir: ";
                std::getline(std::cin, strCodigo);
                try{
                    Codigo codigo; codigo.setValor(strCodigo);

                    char confirmacao;
                    std::cout << "ATENCAO: Esta acao e irreversivel.\n";
                    std::cout << "Tem certeza que deseja excluir essa historia? (S/N): ";
                    std::cin.ignore();
                    std::cin >> confirmacao;

                    if (confirmacao == 'S' || confirmacao == 's') {
                        if (cntrlISGestaoHistorias->excluir(codigo)) {
                            std::cout << "\nHistoria excluida com sucesso.\n";
                        } else {
                            std::cout << "\nErro ao tentar excluir a historia. Codigo nao encontrado na base de dados.\n";
                        }
                    } else {
                        std::cout << "\nExclusao cancelada.\n";
                    }
                }
                catch (std::invalid_argument &exp) {
                    std::cout << "\nErro nos dados informados: " << exp.what() << "\n";
                }
                
                break;
            }
                
            case ASSOCIAR:
                std::cout << "\n--- Associar Desenvolvedor ---\n"; break;
            case MOVER:
                std::cout << "\n--- Mover para Sprint ---\n"; break;
            case ALTERAR_EST:
                std::cout << "\n--- Alterar Estado ---\n"; break;

            case LISTAR_HISTORIAS_PROJETO:
                std::cout << "\n--- Historias do Projeto ---\n"; break;
            case LISTAR_HISTORIAS_SPRINT:
                std::cout << "\n--- Historias do Sprint ---\n"; break;
            case LISTAR_HISTORIAS_PESSOA:
                std::cout << "\n--- As minhas Historias ---\n"; break; // cntrlISGestaoHistorias->listarHistoriasDePessoa(email, &vetorHistorias)
            
            case RETORNAR:
                executando = false;
                break;

            default:
                std::cout << "\nOpcao invalida!\n";
                break;
        }

        if (executando) {
            std::cout << "Pressione ENTER para continuar...";
            std::cin.ignore(); std::cin.get();
        }
    }
}

void CntrIAGestaoHistorias::criar(const Email& email){
    std::string strCodigo, strTextoT, strTextoP, strTextoA, strTextoV, strTempoE, strPrioridade, strEstado;
    std::cout << "\n--- Criacao de Nova Historia ---\n";
    
    std::cin.ignore();
    std::cout << "\nDigite o Codigo: ";
    std::getline(std::cin, strCodigo);
    
    std::cout << "\nDigite o Titulo: ";
    std::getline(std::cin, strTextoT);

    std::cout << "\nDigite o Papel: ";
    std::getline(std::cin, strTextoP);
    
    std::cout << "\nDigite a Acao: ";
    std::getline(std::cin, strTextoA);

    std::cout << "\nDigite o Valor: ";
    std::getline(std::cin, strTextoV);

    std::cout << "\nDigite a Estimativa: ";
    std::getline(std::cin, strTempoE);

    int esc;
    while(!esc){
        std::cout << "Selecione a Prioridade:\n";
        std::cout << "  1 - ALTA\n";
        std::cout << "  2 - MEDIA\n";
        std::cout << "  3 - BAIXA\n";
        std::cout << "-> ";
        std::cin >> esc;
        switch(esc){
            case 1:
                strPrioridade = "ALTA";
                break;
            case 2:
                strPrioridade = "MEDIA";
                break;
            case 3:
                strPrioridade = "BAIXA";
                break;
            default:
                esc=0;
                std::cout << "Entrada inválida. Tente novamente.\n\n";
                break;
        }
    }

    esc=0;
    while(!esc){
        std::cout << "Selecione o Estado:\n";
        std::cout << "  1 - A FAZER\n";
        std::cout << "  2 - FAZENDO\n";
        std::cout << "  3 - FEITO\n";
        std::cout << "-> ";
        std::cin >> esc;
        switch(esc){
            case 1:
                strEstado = "A FAZER";
                break;
            case 2:
                strEstado = "FAZENDO";
                break;
            case 3:
                strEstado = "FEITO";
                break;
            default:
                esc=0;
                std::cout << "Entrada inválida. Tente novamente.\n\n";
                break;
        }
    }
    

    try {
        // Instancia os domínios e valida o formato
        Codigo codigo; codigo.setValor(strCodigo);
        Texto titulo; titulo.setValor(strTextoT);
        Texto papel; papel.setValor(strTextoP);
        Texto acao; acao.setValor(strTextoA);
        Texto valor; valor.setValor(strTextoV);
        Tempo estimativa; estimativa.setValor(strTempoE);
        Prioridade prioridade; prioridade.setValor(strPrioridade);
        Estado estado; estado.setValor(strEstado);

        // Monta a entidade
        HistoriaDeUsuario novaHistoria;
        novaHistoria.setCodigo(codigo);
        novaHistoria.setTitulo(titulo);
        novaHistoria.setPapel(papel);
        novaHistoria.setAcao(acao);
        novaHistoria.setValor(valor);
        novaHistoria.setTempo(estimativa);
        novaHistoria.setPrioridade(prioridade);
        novaHistoria.setEstado(estado);

        // Passa para a camada de serviço
        if (cntrlISGestaoHistorias->criar(novaHistoria)) {
            std::cout << "Historia criada com sucesso!\n";
        } else {
            std::cout << "\nFalha no cadastro: Codigo informado ja esta em uso.\n";
        }
    } 
    catch (std::invalid_argument &exp) {
        std::cout << "\nErro nos dados informados: " << exp.what() << "\n";
    }
}

void CntrIAGestaoHistorias::ler(){
    std::string strCodigo;
    std::cout << "\n--- Visualizar Historia ---\n";
    
    std::cin.ignore();
    std::cout << "\nDigite o Codigo: ";
    std::getline(std::cin, strCodigo);

    try{
        Codigo codigo; codigo.setValor(strCodigo);
        HistoriaDeUsuario historia; historia.setCodigo(codigo);

        if(cntrlISGestaoHistorias->ler(&historia)){
            std::cout << "\nHistoria requisitada:\n";
            std::cout << "- Codigo: " << historia.getCodigo().getValor() << "\n";
            std::cout << "- Titulo: " << historia.getTitulo().getValor() << "\n";
            std::cout << "- Papel: " << historia.getPapel().getValor() << "\n";
            std::cout << "- Acao: " << historia.getAcao().getValor() << "\n";
            std::cout << "- Valor: " << historia.getValor().getValor() << "\n";
            std::cout << "- Estimativa: " << historia.getEstimativa().getValor() << "\n";
            std::cout << "- Prioridade: " << historia.getPrioridade().getValor() << "\n";
            std::cout << "- Estado: " << historia.getEstado().getValor() << "\n";
        }else{
            std::cout << "\nFalha na visualizacao: O codigo informado nao esta cadastrado.\n";
        }

    }catch (std::invalid_argument &exp){
        std::cout << "\nErro nos dados informados: " << exp.what() << "\n";
    }
}

void CntrIAGestaoHistorias::atualizar(const Email& email){

    std::string strCodigo, strTextoT, strTextoP, strTextoA, strTextoV, strTempoE, strPrioridade, strEstado;
    int esc = 0;
    std::cout << "\n--- Atualizar Historia ---\n";
    
    std::cin.ignore();
    std::cout << "\nDigite o Codigo: ";
    std::getline(std::cin, strCodigo);
    
    std::cout << "\nDigite o novo Titulo: ";
    std::getline(std::cin, strTextoT);

    std::cout << "\nDigite o novo Papel: ";
    std::getline(std::cin, strTextoP);
    
    std::cout << "\nDigite a nova Acao: ";
    std::getline(std::cin, strTextoA);

    std::cout << "\nDigite o novo Valor: ";
    std::getline(std::cin, strTextoV);

    std::cout << "\nDigite a nova Estimativa: ";
    std::getline(std::cin, strTempoE);

    int esc;
    while(!esc){
        std::cout << "Selecione a nova Prioridade:\n";
        std::cout << "  1 - ALTA\n";
        std::cout << "  2 - MEDIA\n";
        std::cout << "  3 - BAIXA\n";
        std::cout << "-> ";
        std::cin >> esc;
        switch(esc){
            case 1:
                strPrioridade = "ALTA";
                break;
            case 2:
                strPrioridade = "MEDIA";
                break;
            case 3:
                strPrioridade = "BAIXA";
                break;
            default:
                esc=0;
                std::cout << "Entrada inválida. Tente novamente.\n\n";
                break;
        }
    }

    esc=0;
    while(!esc){
        std::cout << "Selecione o novo Estado:\n";
        std::cout << "  1 - A FAZER\n";
        std::cout << "  2 - FAZENDO\n";
        std::cout << "  3 - FEITO\n";
        std::cout << "-> ";
        std::cin >> esc;
        switch(esc){
            case 1:
                strEstado = "A FAZER";
                break;
            case 2:
                strEstado = "FAZENDO";
                break;
            case 3:
                strEstado = "FEITO";
                break;
            default:
                esc=0;
                std::cout << "Entrada inválida. Tente novamente.\n\n";
                break;
        }
    }
    

    try {
        // Instancia os domínios e valida o formato
        Codigo codigo; codigo.setValor(strCodigo);
        Texto titulo; titulo.setValor(strTextoT);
        Texto papel; papel.setValor(strTextoP);
        Texto acao; acao.setValor(strTextoA);
        Texto valor; valor.setValor(strTextoV);
        Tempo estimativa; estimativa.setValor(strTempoE);
        Prioridade prioridade; prioridade.setValor(strPrioridade);
        Estado estado; estado.setValor(strEstado);

        // Monta a entidade
        HistoriaDeUsuario novaHistoria;
        novaHistoria.setCodigo(codigo);
        novaHistoria.setTitulo(titulo);
        novaHistoria.setPapel(papel);
        novaHistoria.setAcao(acao);
        novaHistoria.setValor(valor);
        novaHistoria.setTempo(estimativa);
        novaHistoria.setPrioridade(prioridade);
        novaHistoria.setEstado(estado);

        // Passa para a camada de serviço
        if (cntrlISGestaoHistorias->atualizar(novaHistoria)) {
            std::cout << "Historia alterada com sucesso!\n";
        } else {
            std::cout << "\nFalha na alteracao: Codigo informado nao consta na base de dados.\n";
        }
    } 
    catch (std::invalid_argument &exp) {
        std::cout << "\nErro nos dados informados: " << exp.what() << "\n";
    }
}
