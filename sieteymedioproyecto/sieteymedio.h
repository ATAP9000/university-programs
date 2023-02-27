#ifndef SIETEYMEDIO_H
#define SIETEYMEDIO_H

#include "jugador.h"
#include "mazocarta.h"
#include <deque>
using namespace std;

class sieteymedio{
    friend ostream &operator<<(ostream &, sieteymedio &);  //operador de salida sobrecargado *motivo*
public:
    sieteymedio(int=0);              // constructor no predeterminado
    void nuevaronda();              // comienza una nueva ronda de 7 y medio
    int terminar7ymedio(int);      // termina el juego si el jugador decide
    int obtenercantidadjugador(); // devuelve el numero total de jugadores
    int terminaronda();          // termina la ronda actual
    void ganadores();           //  encuentra los ganadores y devuelve los resultados
    jugador& obtenerjugador(int);           // devuelve el jugador
    mazocarta& obtenermazo();              // devuelve el mazo
    sieteymedio & operator>(jugador &);   // reparte la carta del mazo al jugador
private:
    deque<jugador> jugadores;     // deque de los jugadores
    mazocarta mazoactual;        // deque de las cartas a jugar
};

#endif // SIETEYMEDIO_H
