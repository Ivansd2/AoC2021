#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream archivo;
    string linea;
    string direccion;
    int numero;
    int corte = 0;

    int horizontal = 0;
    int profundidad = 0;

    archivo.open("2.txt");
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return 0;
    }

    while (getline(archivo, linea))
    {
        corte = linea.find(" ");
        direccion = linea.substr(0, corte);
        linea.erase(0, corte + 1);

        numero = stoi(linea);

        if (direccion == "forward")
        {
            horizontal += numero;
        }

        if (direccion == "up")
        {
            profundidad -= numero;
        }

        if (direccion == "down")
        {
            profundidad += numero;
        }
    }

    cout << profundidad * horizontal << endl;

}

// g++ -std=c++11 Day2.cc -o Day2 && ./Day2