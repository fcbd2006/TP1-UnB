#include <Domains/Headers/tempo.hpp>

void Tempo::set(int val){
    if(validar(val)) valor=val;
}

Tempo::Tempo(int val){
    set(val);
}
