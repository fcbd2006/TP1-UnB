#include <Domains/Headers/codigo.hpp>

bool Codigo::validar(std::string codigo){
    for(int index=0;index<=1;index++){
        if(codigo[index]<'A' or codigo[index]>'Z') return false;
    }    
    for(int index=2;index<=4;index++){
        if(codigo[index]<'0' or codigo[index]>'9') return false;
    }    
    return true;
}

Codigo::Codigo(std::string codigo){
    set(codigo);
}

bool Codigo::set(std::string codigo){
    if(!validar(codigo)) return false;
    this->codigo=codigo;
    return true;
}