#ifndef JUGADOR_H
#define JUGADOR_H

#include <deque>
#include <iostream>
using namespace std;

class jugador{
    friend ostream &operator<<(ostream &,jugador &); //operador de salida sobrecargado *motivo*
public:
    jugador(int=0,int=0);        // constructor
    void aniadircarta(int);     // aniade cartas a la mano del jugador
    double sumano();           // devuelve el valor de la mano
    int obtenerquedarse();    // devuelve si el jugador se queda
    int obteneresusuario();  // devuelve true(1) si el jugador es usuario *true 1 es para afirmar que es cierto*
    int obteneresdealer();  // devuelve true(1) si el jugador es dealer
    void usuariopide();        // pregunta al usuario si deberia seguir pidiendo
    void limpiarmano();       // limpia la mano de los jugadores y reinicia sequeda/findeturno a 0
    void aniadirvictoria();  // aniade la victoria al jugador que gano la partida anterior
    int obtenervictorias(); // devuele el numero de victorias del jugador
    void establecerquedarse();  // deja al jugador en modo de espera
    void establecerfinturno(); // termina el turno del jugador
private:
    int numerovictorias;      // numero de veces que el jugador ha ganado
    deque<int> mano;         // manos de jugadores
    int esusuario;          // verdadero si el jugador es usuario
    int esdealer;          // verdadero si el jugador es dealer
    int sequeda;          // 0 cuando el jugador sigue pidiendo y 1 cuando decide quedarse
    int finturno;        // 1 cuando el turno se termina
};

#endif // JUGADOR_H
