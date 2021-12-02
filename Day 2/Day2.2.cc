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
    int aim = 0;

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
            profundidad += aim * numero;
        }

        if (direccion == "up")
        {
            aim -= numero;
        }

        if (direccion == "down")
        {
            aim += numero;
        }
    }

    cout << profundidad * horizontal << endl;
}

// g++ -std=c++11 Day2.2.cc -o Day2.2 && ./Day2.2