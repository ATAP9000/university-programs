#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
using std::string;

int main(){
string libros[5][2];
cout << "porfavor ingrese la siguiente informacion de los los libros: \n";
string titulo,autor;
for(int i=0;i<5;i++){
        cout << "\n******* Libro " << i + 1 << "********:\n";
        cout << "Titulo: ";
        getline(cin,titulo);
        cout << "Autor: ";
        getline(cin,autor);
        libros[i][0] = titulo;
        libros[i][1] = autor;
    }

    return 0;
}
