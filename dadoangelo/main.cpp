#include "dadoangelo.h"

int main()
{
   char r,f;
do{
        Dado midado;
        midado.definir_caras(0,true);
            do{
                cout<<"Girando el dado! " << endl;
                midado.girar_dado();
                midado.obtener_resultado();
                cout << "Desea girar de nuevo el dado? (s para si, y cualquier otra tecla para no)" << endl;
                cin>>r;
            }while(r=='s');
    cin.get();
    midado.reiniciar();
    cout << "desea utilizar el programa de nuevo? (s para si y cualquier otra tecla para no). " << endl; cin>>f;
    if(f=='n'){
      break;
    };
    else{
      cin.ignore();
    };
}while(f=='s');

    return 0;
}

