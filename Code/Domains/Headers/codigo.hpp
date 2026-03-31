#ifndef CODIGO_HPP_INCLUDED
#define CODIGO_HPP_INCLUDED

#include <string>

class Codigo{
    private:
        std::string codigo{"\0\0\0\0\0"};
        bool validar(std::string);

    public:
        Codigo(std::string);
        bool set(std::string);
        inline std::string get();
};

inline std::string Codigo::get(){
    return codigo;
}

#endif // CODIGO_HPP_INCLUDED
