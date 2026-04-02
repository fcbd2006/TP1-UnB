#include <Domains/Headers/data.hpp>
#include <string>
#include <format>

bool Data::validar(int dia, int mes, int ano){
    if(mes>12 or mes<1) return false;
    if(ano>2999 or ano<2000) return false;

    int diasMensais[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if(mes==2 and ehBisexto(ano)) diasMensais[2]=29;
    
    return(dia>0 and dia<=diasMensais[mes]);
}

bool Data::set(int dia, int mes, int ano){
    if(!validar(dia, mes, ano)) return false;
    this->dia=dia;
    this->mes=mes;
    this->ano=ano;
    return true;
}

bool Data::set(std::string data){ 
    if(data.size()!=10 or data[2]!='/' or data[5]!='/') return false;
    int dia = std::stoi(data.substr(0,2));
    int mes = std::stoi(data.substr(3,2));
    int ano = std::stoi(data.substr(6,4));
    if(!validar(dia, mes, ano)) return false;
    this->dia=dia;
    this->mes=mes;
    this->ano=ano;
    return true;
}

std::string Data::get() const{
    return std::format(
        "{:02}/{:02}/{}", dia, mes, ano
    );
}