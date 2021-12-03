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
    vector<string> oxygen;
    vector<string> co2;
    bool quedauno = false;
    archivo.open("3.txt");
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return 0;
    }

    while (getline(archivo, linea))
    {
        oxygen.push_back(linea);
    }

    co2 = oxygen;

    int stringlength = oxygen[0].size();

    for (int i = 0; i < stringlength; i++)
    {
        c0 = 0;
        c1 = 0;
        for (int j = 0; j < oxygen.size(); j++)
        {
            if (oxygen[j].at(i) == '0')
            {
                c0++;
            }
            else
            {
                c1++;
            }
        }
        if (c0 > c1)
        {
            vector<string>::iterator it;
            for (it = oxygen.begin(); it != oxygen.end(); it++)
            {
                if ((it)->at(i) == '1')
                {
                    oxygen.erase(it);
                    it--;
                }
            }
        }
        else if (c1 > c0 || c1 == c0)
        {
            vector<string>::iterator it;
            for (it = oxygen.begin(); it != oxygen.end(); it++)
            {
                if ((it)->at(i) == '0')
                {
                    oxygen.erase(it);
                    it--;
                }
            }
        }

        if (oxygen.size() == 1)
        {
            break;
        }
    }

    for (int i = 0; i < stringlength; i++)
    {
        c0 = 0;
        c1 = 0;
        for (int j = 0; j < co2.size(); j++)
        {
            if (co2[j].at(i) == '0')
            {
                c0++;
            }
            else
            {
                c1++;
            }
        }
        if (c0 < c1 || c1 == c0)
        {
            vector<string>::iterator it;
            for (it = co2.begin(); it != co2.end(); it++)
            {
                if ((it)->at(i) == '1')
                {
                    co2.erase(it);
                    it--;
                }
            }
        }
        else if (c1 < c0)
        {
            vector<string>::iterator it;
            for (it = co2.begin(); it != co2.end(); it++)
            {
                if ((it)->at(i) == '0')
                {
                    co2.erase(it);
                    it--;
                }
            }
        }

        if (co2.size() == 1)
        {
            break;
        }
    }

    cout << "Oxygen generator rating in binary: " << oxygen[0] << endl;
    cout << "Oxygen generator rating in decimal: " << stoi(oxygen[0], nullptr, 2) << endl;
    cout << "CO2 scrubber rating in binary: " << co2[0] << endl;
    cout << "CO2 scrubber rating in decimal: " << stoi(co2[0], nullptr, 2) << endl;

    cout << "Life support rating: " << stoi(oxygen[0], nullptr, 2) * stoi(co2[0], nullptr, 2) << endl;

    return 0;
}

// g++ -o Day3 Day3.cc && ./Day3