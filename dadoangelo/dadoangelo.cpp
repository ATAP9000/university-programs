#include "dadoangelo.h"

Dado::Dado(): ultimo_giro(0),giros_totales(0),puntuacion_total(0){ }

void Dado::definir_caras(int cont, bool continuar){
    cout << "Cuantas caras tiene el dado? (desde 3 hasta 200) " << endl;
    do{
        do{ continuar=false;
             cin.clear(); if(cont>0) cin.ignore(1024, '\n');
             cin>>caras;
             cont++;
             if(cin.fail()&&cin.rdstate()){
                cout << "no se ha insertado un valor numero, inserte un valor numero. " << endl;
                continuar=true;
		cin.clear();
             }}while(continuar);
        if(3<=caras&&caras<=200){ cout << "el numero de caras seleccionado es: " << caras << endl <<  endl;}
        else{cout << "ese no valor valido, solamente se permiten entre 3 y 200. " << endl; cin.clear();}
       ;}while(caras<3||caras>200);
}

void Dado::girar_dado(){
    srand(static_cast<unsigned int>(time(0)));  //generador de numero aleatorio//
        ultimo_giro=0;
        giros_totales++;
        ultimo_giro = (rand() % caras) +1;
        puntuacion_total+=ultimo_giro;
;}


void Dado::obtener_resultado(){
    cout << "Su giro fue de: " << ultimo_giro << "." << endl;
    cout << "Usted ha girado: " << giros_totales << " veces." << endl;
    cout << "Su puntuacion total es de: " << puntuacion_total << "." << endl << endl;
}

void Dado::reiniciar(){
    ultimo_giro=0;
    puntuacion_total=0;
    giros_totales=0;
    cout << string(60, '\n'); //comando para limpiar pantalla
}
