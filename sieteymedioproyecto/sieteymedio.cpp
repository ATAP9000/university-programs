#include "sieteymedio.h"
#include "jugador.h"
#include "mazocarta.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// operador de salida sobrecargado
ostream &operator<<(ostream &output, sieteymedio &sym){
    // muestra las manos de los jugadores con variacion dependiendo del progreso de la ronda
    for(int i=0; i<sym.obtenercantidadjugador();i++){
        // imprime la etiqueta del jugador
        if(sym.obtenerjugador(i).obteneresusuario()) cout << "Usuario:";
        else if(sym.obtenerjugador(i).obteneresdealer()) cout << "Dealer:";
        else cout << "COM" << i-1 << ":";
        // usa el operador de salida sobrecargado para la clase jugador
        cout << sym.obtenerjugador(i) << endl; // imprime la mano de los jugadores
    }
    return output;
}

// constructor
sieteymedio::sieteymedio(int computador){
    // aniade usuario al juego
    jugadores.push_back(jugador(1,0));
    // aniade el dealer al juego
    jugadores.push_back(jugador(0,1));
    // aniade al computador
    for(int i=0; i<computador; i++){
            jugadores.push_back(jugador());
    }
}

// Comienza una nueva ronda
void sieteymedio::nuevaronda(){
    // barajea el mazo al comienzo de la ronda
    mazoactual.barajar();
    // reparte a los jugadores 1 carta
    for(int i=0; i<obtenercantidadjugador(); i++){
        mazoactual.repartir(1,jugadores[i]);
    }
}

// fin del juego de siete y medio si el resultado es 1
int sieteymedio::terminar7ymedio(int findejuego){
    // si findejuego==1, se termina el juego
    if(findejuego){
        // mostrar tablero de puntuacion final
        cout << "Resultados de la partida:" << endl << endl;
        cout << "	Usuario: " << obtenerjugador(0).obtenervictorias() << endl;
        cout << "	Dealer: " << obtenerjugador(1).obtenervictorias() << endl;
        for(int i=2; i<obtenercantidadjugador(); i++) {
            cout << "	COM" << i-1 << ": " << obtenerjugador(i).obtenervictorias() << endl;
        }
        cout << endl<< "Gracias por jugar!" << endl;
    }
    return findejuego;
}

// devuelve el numero total de jugadores
int sieteymedio::obtenercantidadjugador(){
    return jugadores.size();
}

// terminar ronda
int sieteymedio::terminaronda(){
    // limpiar manos de los jugadores
    for(int i=0; i<obtenercantidadjugador();i++){
        jugadores[i].limpiarmano();
    }
    // chequeo para ver si el usuario quiere seguir jugando o salir
    char seguirjugando; //entrar el resultado 's' permitira continuar el juego
    cout << "[S]i, [N]o.\n le gustaria seguir jugando?: ";
    cin >> seguirjugando;
    // Chequeo de errores
    while(tolower(seguirjugando)!='s' && tolower(seguirjugando)!='n'){
        cout << "Esa no es una opcion valida.\n seleccione 's' o 'n'";
                cin >> seguirjugando;
    }
    // limpiar pantalla
    system("clear");
    if(tolower(seguirjugando)=='n') return 1;	// el jugador decidio no jugar mas
        else return 0;					       // el jugador aun quiere jugar 7 y medio
}

// devolver jugador
jugador& sieteymedio::obtenerjugador(int numerojugador){
    return jugadores[numerojugador];
}

// devolver mazo
mazocarta& sieteymedio::obtenermazo(void){
    return mazoactual;
}

// repartir una carta del mazo a la mano del jugador
sieteymedio & sieteymedio::operator >(jugador & mijugador){
    // si no es el usuario repartir hasta que el turno se termine
    if(mijugador.obteneresusuario()==0){
        // continua repartiendo hasta que un jugador se quede o se pase
        while(mijugador.obtenerquedarse()==0)
            mazoactual.repartir(1,mijugador);
        mijugador.establecerfinturno(); // termina turno del jugador
    }
    // si es el usuario repartir una carta a la vez
    mazoactual.repartir(1,mijugador);
    return(*this);
}

// encuentra quien o quienes son los ganadores y los muestra
void sieteymedio::ganadores(){
    deque<int> victorias;  // almacena por numero de jugador en el directorio correcto de deque
    int dirvictorias=0;   // directorio superior usado sobre vector y mantiene conteo de los ganadores por la ronda
    // para todos los jugadores excepto el dealer, vease fin del ciclo
    for(int i=0;i<obtenercantidadjugador();i++){
        // si la mano del jugador es mayor que la del dealer(cual es menor a 7.5) y menor a 7.5 o la mano del jugador sea mas o menos igual a 7.5(si la mano del dealer es mayor a 7.5)
        if((obtenerjugador(i).sumano()>obtenerjugador(1).sumano()&&obtenerjugador(i).sumano()<=7.5&&obtenerjugador(1).sumano()<=7.5) || (obtenerjugador(i).sumano()<=7.5&&obtenerjugador(1).sumano()>7.5)){
            obtenerjugador(i).aniadirvictoria();   // aniade una victoria al total del jugador
            victorias[dirvictorias]=i-1;          // recuerda quien va ganando se substrae 1 para que sirva con COM#
            dirvictorias++;                      // se aniade 1 al contador de victorias
        }
        if(i==0) i++;  // esto es para saltarse al dealer(i=1)
    }
    // si el directorio nunca se incremento el dealer gana
    if(dirvictorias==0){
        cout << "El dealer gano." << endl << endl;
        obtenerjugador(1).aniadirvictoria();}// se le aniade victoria al dealer
        // sino se le da al jugador o a algun computador usa el deque de victorias y el dirvictorias para mostrar quien gano
        else{
            cout << "Los ganadores son: ";
            for(int i=0;i<dirvictorias;i++){
                if(victorias[i]==-1) cout << "TU!";
                else cout << "COM" << victorias[i] << "!";
            }
            cout << endl << endl;
        }
    }

