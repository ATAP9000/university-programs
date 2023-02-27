#ifndef MAZOCARTA_H
#define MAZOCARTA_H

#include <deque>
#include <iostream>
#include "jugador.h"
using namespace std;

class mazocarta{  
public:
    mazocarta(int=40);         // constructor del mazo con un valor predeterminado de 40 cartas
    int obtenertamanio(void); // devuelve el tamanio de deque (numero de cartas en el mazo)
    void barajar(void);      // baraja las cartas en el mazo
    void repartir(int, jugador&); // reparte la carta al jugador
    void nuevomazo(void);        // aniade un nuevo mazo si el viejo se esta acabando
private:
    deque<int> cartas;  // deque almacena las cartas
};

#endif // MAZOCARTA_H
