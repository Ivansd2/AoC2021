#include <iostream>
#include <fstream>
#include <limits>
#include <vector>

using namespace std;

int main()
{

    ifstream archivo;
    archivo.open("input.txt");
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return 0;
    }

    string linea;
    int numero = numeric_limits<int>::max();
    int veces = 0;
    vector<int> v;
    vector<int> incrementos;
    int a;
    while (getline(archivo, linea))
    {
        a = stoi(linea);
        v.push_back(a);
    }

    int suma;
    for (int i = 0; i < v.size(); i++)
    {
        suma = 0;
        for (int j = 0; j < 3; j++)
        {
            suma += v[i + j];
        }

        incrementos.push_back(suma);
    }

    for (int i = 0; i < incrementos.size(); i++)
    {
        if (incrementos[i] > numero)
        {
            numero = incrementos[i];
            veces++;
        }
        numero = incrementos[i];
    }

    cout << "Veces: " << veces << endl;
}

//Comando para coimpilar el archivo
//g++ -std=c++11 Day1.2.cc -o Day1.2 && ./Day1.2