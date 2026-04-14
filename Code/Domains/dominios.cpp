#include <Domains/Headers/outros_dominios.hpp>
#include <stdexcept>

// CODIGO
void Codigo::validar(const std::string& codigo){
    for(int index=0;index<=1;index++){
        if(codigo[index]<'A' or codigo[index]>'Z') throw std::invalid_argument("Valor Inválido para Código.");
    }    
    for(int index=2;index<=4;index++){
        if(codigo[index]<'0' or codigo[index]>'9') throw std::invalid_argument("Valor Inválido para Código.");
    }
}
////////////////////////////////////////////////////////////////

// DATA
void Data::validar(const std::string& data){
    if(data.size()!=10) throw std::invalid_argument("Valor Inválido para Data.");
    if(data[2]!='/' or data[5]!='/') throw std::invalid_argument("Valor Inválido para Data.");
    for(int index=0;index<= int (data.size());index++){
        if(index==2||index==5) continue;
        if(data[index]<'0' || data[index]>'9') throw std::invalid_argument("Valor Inválido para Data.");
    }
    int dia = stoi(data.substr(0,2));
    int mes = stoi(data.substr(3,2));
    int ano = stoi(data.substr(6,4));

    if(mes>12 or mes<1) throw std::invalid_argument("Valor Inválido para Data.");
    if(ano>2999 or ano<2000) throw std::invalid_argument("Valor Inválido para Data.");

    int diasMensais[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if(mes==2 and ehBisexto(ano)) diasMensais[2]=29;
    
    if(!(dia>0 and dia<=diasMensais[mes])) throw std::invalid_argument("Valor Inválido para Data.");
}
////////////////////////////////////////////////////////////////

// EMAIL

////////////////////////////////////////////////////////////////

// ESTADO
void Estado::validar(const std::string& estado){
    if(!(estado=="A FAZER" || estado=="FAZENDO" || estado=="FEITO")) throw std::invalid_argument("Valor Inválido para Estado.");
}

////////////////////////////////////////////////////////////////

// NOME
void Nome::validar(const std::string& nome){
    if(nome.size()>10) throw std::invalid_argument("Valor Inválido para Nome.");
    if(nome[0]==' ' || nome[nome.size()-1]==' ') throw std::invalid_argument("Valor Inválido para Nome.");
    for(int index=0;index<=(int(nome.size())-1);index++){

        if(nome[index]==' ' and ((nome[index+1]<'A' || nome[index+1]>'Z') and (nome[index+1]<'a' || nome[index+1]>'z')))
            throw std::invalid_argument("Valor Inválido para Nome.");
    
        if((nome[index]<'A' || nome[index]>'Z') and (nome[index]<'a' || nome[index]>'z') and nome[index]!=' ')
            throw std::invalid_argument("Valor Inválido para Nome.");
    }
}

////////////////////////////////////////////////////////////////

// PAPEL
void Papel::validar(const std::string& papel){
    if(!(papel=="DESENVOLVEDOR" or papel=="MESTRE SCRUM" or papel=="PROPRIETARIO DE PRODUTO")) throw std::invalid_argument("Valor Inválido para Papel.");
}

////////////////////////////////////////////////////////////////

// PRIORIDADE
void Prioridade::validar(const std::string& prioridade){
    if(!(prioridade=="ALTA" or prioridade=="MEDIA" or prioridade=="BAIXA")) throw std::invalid_argument("Valor Inválido para Prioridade.");
}

////////////////////////////////////////////////////////////////

// SENHA

////////////////////////////////////////////////////////////////

// TEMPO
void Tempo::validar(const std::string& tempo){
    if(tempo.size()>3) throw std::invalid_argument("Valor Inválido para Tempo.");
    for(auto c : tempo){
        if(c<'0'|| c>'9') throw std::invalid_argument("Valor Inválido para Tempo.");
    }
    int a = stoi(tempo);
    if(a<1 || a>365) throw std::invalid_argument("Valor Inválido para Tempo.");
}
////////////////////////////////////////////////////////////////

// TEXTO

////////////////////////////////////////////////////////////////