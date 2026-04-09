#include <Domains/Headers/outros_dominios.hpp>

// CODIGO
bool Codigo::validar(string codigo){
    for(int index=0;index<=1;index++){
        if(codigo[index]<'A' or codigo[index]>'Z') return false;
    }    
    for(int index=2;index<=4;index++){
        if(codigo[index]<'0' or codigo[index]>'9') return false;
    }    
    return true;
}
////////////////////////////////////////////////////////////////

// DATA
bool Data::validar(string data){
    if(data.size()!=10) return false;
    if(data[2]!='/' or data[5]!='/') return false;
    for(int index=0;index<= int (data.size());index++){
        if(index==2||index==5) continue;
        if(data[index]<'0' || data[index]>'9') return false;
    }
    int dia = stoi(data.substr(0,2));
    int mes = stoi(data.substr(3,2));
    int ano = stoi(data.substr(6,4));

    if(mes>12 or mes<1) return false;
    if(ano>2999 or ano<2000) return false;

    int diasMensais[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if(mes==2 and ehBisexto(ano)) diasMensais[2]=29;
    
    return(dia>0 and dia<=diasMensais[mes]);
}
////////////////////////////////////////////////////////////////

// EMAIL

////////////////////////////////////////////////////////////////

// ESTADO
bool Estado::validar(string estado){
    return (estado=="A FAZER" || estado=="FAZENDO" || estado=="FEITO");
}

////////////////////////////////////////////////////////////////

// NOME
bool Nome::validar(string nome){
    if(nome.size()>10) return false;
    if(nome[0]==' ' || nome[nome.size()-1]==' ') return false;
    for(int index=0;index<=(int(nome.size())-1);index++){

        if(nome[index]==' ' and ((nome[index+1]<'A' || nome[index+1]>'Z') and (nome[index+1]<'a' || nome[index+1]>'z')))
            return false;
    
        if((nome[index]<'A' || nome[index]>'Z') and (nome[index]<'a' || nome[index]>'z') and nome[index]!=' ')
            return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////

// PAPEL
bool Papel::validar(string papel){
    return (papel=="DESENVOLVEDOR" or papel=="MESTRE SCRUM" or papel=="PROPRIETARIO DE PRODUTO");
}

////////////////////////////////////////////////////////////////

// PRIORIDADE
bool Prioridade::validar(string prioridade){
    return (prioridade=="ALTA" or prioridade=="MEDIA" or prioridade=="BAIXA");
}

////////////////////////////////////////////////////////////////

// SENHA

////////////////////////////////////////////////////////////////

// TEMPO
bool Tempo::validar(string tempo){
    if(tempo.size()>3) return false;
    for(auto c : tempo){
        if(c<'0'|| c>'9') return false;
    }
    int a = stoi(tempo);
    return(!(a<1 || a>365));
}
////////////////////////////////////////////////////////////////

// TEXTO

////////////////////////////////////////////////////////////////