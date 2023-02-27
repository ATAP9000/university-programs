#ifndef DADOANGELO_H
#define DADOANGELO_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

class Dado{
    private:
        int caras,ultimo_giro,giros_totales,puntuacion_total;
        char r;
    public:
        Dado();
        void definir_caras(int cont,bool continuar);
        void girar_dado();
        void obtener_resultado();
        void reiniciar();
};
#endif // DADOANGELO_H
