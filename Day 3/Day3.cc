#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream archivo;
    string linea;
    int n = 0;
    int c1 = 0;
    int c0 = 0;
    vector<string> fichero;
    string gammarate = "";
    string epsilonrate;
    archivo.open("3.txt");
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return 0;
    }

    while (getline(archivo, linea))
    {
        fichero.push_back(linea);
    }

    int stringlength = fichero[0].size();

    for (int i = 0; i < stringlength; i++)
    {
        c0 = 0;
        c1 = 0;
        for (int j = 0; j < fichero.size(); j++)
        {
            if (fichero[j].at(i) == '0')
            {
                c0++;
            }
            if (fichero[j].at(i) == '1')
            {
                c1++;
            }
        }
        if (c0 > c1)
        {
            gammarate += "0";
        }
        else
        {
            gammarate += "1";
        }
    }

    for (int i = 0; i < gammarate.size(); i++)
    {
        if (gammarate.at(i) == '0')
        {
            epsilonrate += "1";
        }
        if (gammarate.at(i) == '1')
        {
            epsilonrate += "0";
        }
    }

    cout << "Gamma rate in binary: " << gammarate << endl;
    cout << "Gamma rate in decimal: " << stoi(gammarate, nullptr, 2) << endl;
    cout << "Epsilon rate in binary: " << epsilonrate << endl;
    cout << "Epsilon rate in decimal: " << stoi(epsilonrate, nullptr, 2) << endl;

    cout << "Power consumption of the submarine: " << stoi(gammarate, nullptr, 2) * stoi(epsilonrate, nullptr, 2) << endl;
}

// g++ -o Day3 Day3.cc && ./Day3