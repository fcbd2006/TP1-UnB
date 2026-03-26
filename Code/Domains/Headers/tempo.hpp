#ifndef TEMPO_HPP_INCLUDED
#define TEMPO_HPP_INCLUDED

class Tempo{
    private:
        static const int LIM_SUP=365;
        static const int LIM_INF=1;
        inline static bool validar(int);
        int valor;

    public:
        Tempo(int);
        void set(int);
        inline int get();

};

inline bool Tempo::validar(int val){
    if(val<=LIM_SUP and val>=LIM_INF) return true;
    else return false;

}

inline int Tempo::get(){
    return valor;
}

#endif // TEMPO_HPP_INCLUDED
