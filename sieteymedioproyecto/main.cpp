#include <sieteymedio.h>
#include <mazocarta.h>
#include <jugador.h>
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int esfindejuego=0;
    system("clear");
    cout << "Vamos a jugar 7 y medio!" << endl;

    // deja al usuario seleccionar la cantidad de computadores en la mesa
    cout << "\nComo cuantos jugadores le gustaria tener en la mesa?" << endl;
    int computores;
    cin >> computores;
    // para asegurarse que que no hay una cantidad negativa de jugadores
    if(computores<0){
         cout << "Valor invalido introducido, el valor predeterminado es 0 en su mesa." << endl;
         computores=0; // numero predeterminado de computadores
    }
    // aniade a los computadores al juego como entrada no predeterminada al constructor
    sieteymedio juegoactual(computores); // se comienza el juego de siete y medio

    while(esfindejuego!=1){
        juegoactual.nuevaronda();  // se comienza la primera ronda
        cout << "Manos iniciales..."  << endl;
        cout << juegoactual << endl;
        // se le reparte a todos los computadores
        if(computores>0){
            cout << "ahora los computadores comenzaran..." << endl << endl;
            for(int i=2; i<2+computores; i++){
                            juegoactual>(juegoactual.obtenerjugador(i));
                        }
                        cout << "Tablero despues de los turnos de los computadores" << endl << juegoactual << endl;
                    }
        // el usuario juega ahora
        while(!juegoactual.obtenerjugador(0).obtenerquedarse() && juegoactual.obtenerjugador(0).sumano()<7.5){  // mientras que el jugador no se quede o se pase
            juegoactual.obtenerjugador(0).usuariopide();
            if(!juegoactual.obtenerjugador(0).obtenerquedarse())
                juegoactual>(juegoactual.obtenerjugador(0));
            if(juegoactual.obtenerjugador(0).obtenerquedarse()==1 || juegoactual.obtenerjugador(0).sumano()>=7.5){
                juegoactual.obtenerjugador(0).establecerfinturno();
            }else{
                cout << endl << juegoactual << endl;
            }
        }
        if(juegoactual.obtenerjugador(0).sumano()>21){
            cout<<"\nlo siento, pero te pasaste!\n";
            juegoactual.obtenerjugador(0).establecerquedarse();
            juegoactual.obtenerjugador(0).establecerfinturno();
        }
        else if(juegoactual.obtenerjugador(0).sumano()==7.5){
            cout << "\n SIETE Y MEDIO!\n";
            juegoactual.obtenerjugador(0).establecerquedarse();
            juegoactual.obtenerjugador(0).establecerfinturno();
        }
        cout << endl << juegoactual << endl;
        // el dealer juega
        cout << "Ahora es turno del dealer" << endl;
        juegoactual>(juegoactual.obtenerjugador(1)); // el dealer pide hasta >=5
        juegoactual.obtenerjugador(1).establecerfinturno();
        cout << juegoactual << endl;

        juegoactual.ganadores();
        esfindejuego = juegoactual.terminar7ymedio(juegoactual.terminaronda());
        }

}
