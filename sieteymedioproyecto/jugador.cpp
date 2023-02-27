#include "jugador.h"
#include <deque>
#include <iostream>
#include <cstdlib>
using namespace std;

ostream &operator<<(ostream &output, jugador &mijugador){
    cout << "[";
    deque<int>::const_iterator r=mijugador.mano.begin();  //iterador de entrada hacia la mano del jugador
    deque<int>::const_iterator end=mijugador.mano.end(); // iterador de salida de lo anterior
    // saca primera carta del mazo
    if(*r==8) cout << "Sota";          // vendria siendo el 10
    else if(*r==9) cout << "Caballo"; // vendria siendo el 11
    else if(*r==10) cout << "Rey";   // vendria siendo el 12
    else cout << *r;                // valores entre 1-7
    // saca la carta del computador, no puede ser vista por el jugador
  /*  if(mijugador.obteneresusuario()==0 && (mijugador.sumano()<7.5 || mijugador.finturno==0) && (mijugador.esdealer!=1 || mijugador.finturno!=1)){
        // si no es el usuario Y ninguna de las manos es menor a 7.5 o su turno no esta listo Y no es el dealer y su turno listo
        cout << ",X"; //carta no visible al jugador
        ++r;        // incrementar iterador
    } */
// saca segunda o tercera carta dependiendo del IF superior
    for(r=r+1;r!=end; r++){
        cout << ",";
        if(*r==8) cout << "Sota";          // vendria siendo el 10
        else if(*r==9) cout << "Caballo"; // vendria siendo el 11
        else if(*r==10) cout << "Rey";   // vendria siendo el 12
        else cout << *r;                // valores entre 1-7
    }
    cout <<"]";
    if(mijugador.esusuario==1 && mijugador.finturno!=1) cout << " = " << mijugador.sumano(); // esto imprimira el valor de la mano antes de que termine el turno
    // si el turno del jugador termina, se muestra la sumatoria y su estatus en la partida
    if(mijugador.finturno){
        cout << " = " << mijugador.sumano() << "      ->";
        if(mijugador.sumano()>7.5)   // se pasa si tiene mas de 7 y medio
            cout << "Se paso.";
        else if(mijugador.sumano()==7.5)   // tiene justamente 7 y medio
            cout << "Siete y medio!";
        else if(mijugador.sequeda)    // se queda bajo 7 y medio
            cout << "Se queda.";
    }
    return output;
    }

// constructor
jugador::jugador(int yosoyusuario, int yosoydealer){
    // cuando el jugador es creado
    sequeda = 0;          // ninguno esta en modo de espera aun
    numerovictorias = 0; // aun nadie ha ganado
    finturno = 0;       // su turno aun no se ha terminado
    esusuario = yosoyusuario;  // ==1 si este es el usuario
    esdealer = yosoydealer;   // ==1 si este es el dealer
}

// aniadir cartas a la mano del jugador
void jugador::aniadircarta(int nuevacarta){
    // el rango de cartas del deck es de [0,39], el de cartas en mano es de [0.10]
    mano.push_back((nuevacarta%10)+1);  // aniade una nueva carta a la mano
    // si la sumatoria de la mano es mayor a 5 y no es el usuario, se queda
    if(sumano()>=5 && esusuario!=1) sequeda=1;
}

// devuelve la sumatoria de la mano del jugador
double jugador::sumano(){
    double sum=0;  // sumatorio de la mano
    for(int i=0; i<mano.size();i++){
        if(mano[i] > 7 ) sum+=0.5; // si la carta es sota caballo o rey, su valor es medio o 0.5
        else sum+= mano[i];
    }
    return(sum);
}

// devuelve si el jugador se queda
int jugador::obtenerquedarse(){
    return sequeda;
}

// devuelve 1 si el jugador es usuario, de otra forma da 0
int jugador::obteneresusuario(){
    return esusuario;
}

// devuelve 1 si el jugador es dealer, de otra forma da 0
int jugador::obteneresdealer(){
    return esdealer;
}

// instrucciones para el usuario para cuando es su turno para quedarse o pedir
void jugador::usuariopide(){
    char pideoqueda;  // metodo de acceso para pedir o quedarse
    cout << "[P]edir, [Q]uedarse.\n le gustaria pedir o quedarse?: ";
    cin >> pideoqueda;
    // Chequeo de errores
    while(tolower(pideoqueda)!='p' && tolower(pideoqueda)!='q'){
        cout << "Esa no es una opcion valida.\n seleccione 'p' o 'q'";
                cin >> pideoqueda;
    }
    // si el usuario se queda
    if(tolower(pideoqueda)=='q')
        sequeda=1;
    // limpiar pantalla
    system("clear");
    // mostrar eleccion para clarificar
    cout << "le gustaria pedir o quedarse?: " << pideoqueda << endl;
}

// liberar todas las cartas en las manos
void jugador::limpiarmano(){
    mano.clear();       // limpiar deque
    sequeda = 0;       // saca al jugador de modo espera
    finturno = 0;     // cambia al jugador cuyo turno no este terminado
}

// aniade victoria al jugador que gano la partida anterior
void jugador::aniadirvictoria(){
    numerovictorias++;
}

// devuelve el numero de victorias al jugador
int jugador::obtenervictorias(){
    return numerovictorias;
}

// coloca al jugador en modo de espera
void jugador::establecerquedarse(){
    sequeda=1;
}

// termina el turno del jugador
void jugador::establecerfinturno(){
    finturno=1;
}
