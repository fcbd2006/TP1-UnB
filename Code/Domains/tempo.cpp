#include <Domains/Headers/outros_dominios.hpp>

bool Tempo::validar(string tempo){
    if(tempo.size()>3) return false;
    for(auto c : tempo){
        if(c<'0'|| c>'9') return false;
    }
    int a = stoi(tempo);
    return(!(a<1 || a>365));
}

///////////////////////////////////////////

bool Data::validar(string data){
    if(data.size()!=10 or data[2]!='/' or data[5]!='/') return false;
    int dia = stoi(data.substr(0,2));
    int mes = stoi(data.substr(3,2));
    int ano = stoi(data.substr(6,4));

    if(mes>12 or mes<1) return false;
    if(ano>2999 or ano<2000) return false;

    int diasMensais[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if(mes==2 and ehBisexto(ano)) diasMensais[2]=29;
    
    return(dia>0 and dia<=diasMensais[mes]);
}

/////////////////////////////////////////////////

bool Codigo::validar(string codigo){
    for(int index=0;index<=1;index++){
        if(codigo[index]<'A' or codigo[index]>'Z') return false;
    }    
    for(int index=2;index<=4;index++){
        if(codigo[index]<'0' or codigo[index]>'9') return false;
    }    
    return true;
}