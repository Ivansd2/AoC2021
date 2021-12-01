#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

int main() {

    //leer un archivo
    ifstream archivo;
    archivo.open("input.txt");
    if(archivo.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
        return 0;
    }

    //leer una linea
    string linea;
    //int numero a maximo posible de un entero
    int numero = numeric_limits<int>::max();
    int numero2;
    int veces = 0;
    //recorrer el archivo linea a linea
    while(getline(archivo, linea)) {
        //convertir linea a int
        numero2 = stoi(linea);
        if(numero2 > numero) {
            numero = numero2;
            veces++;
        }
        numero = numero2;
    }
    cout << "Veces: " << veces << endl;
}

//g++ -std=c++11 Day1.cc -o Day1 && ./Day1