#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED

#include <string>

class Data{
    private:
        int dia, mes, ano;
        bool ehBisexto(int) const;
        bool validar(int, int, int);

    public:
        Data(int, int, int);
        Data(std::string);
        bool set(int, int, int);
        bool set(std::string);
        std::string get() const;
};

inline bool Data::ehBisexto(int ano) const{
    if((!ano%4 and ano%100) or (!ano%400 and !ano%100)) 
        return true;
    else 
        return false;
}

inline Data::Data(int dia, int mes, int ano){
    set(dia, mes, ano);
}

inline Data::Data(std::string data){
    set(data);
}

#endif // DATA_HPP_INCLUDED
