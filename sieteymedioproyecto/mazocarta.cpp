#include "mazocarta.h"
#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include "jugador.h"
using namespace std;

mazocarta::mazocarta(int mitamanio){
    for(int i=0; i<mitamanio; i++){
        cartas.push_back(i);
    }
    // aqui se llama a srand
    srand(time(NULL));
}

// devuelve el numero de cartas en el mazo
int mazocarta::obtenertamanio(){
    return cartas.size();
}

// baraja las cartas en el mazo
void mazocarta::barajar(){
    // usa el algoritmo random_shuffle para barajar
    random_shuffle(cartas.begin(), cartas.end());
}

// reparte el numero de cartas del mazo al jugadoractual
void mazocarta::repartir(int numcartas, jugador &jugadoractual){
    // bandera de error
    if(numcartas<=0) cout << "ERROR las cartas repartidas son <= 0" << endl;
    for(int i=0;i<numcartas;i++){
        jugadoractual.aniadircarta(cartas[0]);  // aniade la carta del tope del mazo a la mano
        cartas.pop_front();                    // elimina la carta entregada del mazo
        if(obtenertamanio()<10) nuevomazo();  // si el mazo tiene pocas cartas se le aniaden mas
    }
}

// aniade un nuevo mazo al actual si tiene pocas cartas
void mazocarta::nuevomazo(){
    // aniade 40 cartas mas
    for(int i=0; i<40; i++){
        cartas.push_back(i);
    }
    barajar();	// barajea aleatoriamente despues de aniadir las nuevas cartas
}
