#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

class campo
{
public:
    int valor;
    bool marca;
    campo(int valor) : valor(valor), marca(false) {}
};

class tablaBingo
{
public:
    std::vector<std::vector<campo>> t;
    int marcar(int num)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (t.at(i).at(j).valor == num)
                {
                    t.at(i).at(j).marca = true;
                    bool bingo = true;
                    for (int k = 0; k < 5; k++)
                        if (t.at(i).at(k).marca != true)
                            bingo = false;
                    if (bingo)
                        return sumaNoMarcados() * num;

                    bingo = true;
                    for (int k = 0; k < 5; k++)
                        if (t.at(k).at(j).marca != true)
                            bingo = false;
                    if (bingo)
                        return sumaNoMarcados() * num;
                }
            }
        }
        return -1;
    }
    int sumaNoMarcados()
    {
        int suma = 0;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                if (t.at(i).at(j).marca != true)
                    suma += t.at(i).at(j).valor;
        return suma;
    }
};

int main()
{
    std::ifstream file("4.txt");
    if (file.is_open())
    {
        std::vector<int> v;
        std::vector<tablaBingo> tablas;
        std::string line;
        std::getline(file, line);
        std::stringstream ss(line);
        std::string num;

        while (std::getline(ss, num, ','))
            v.push_back(std::stoi(num));

        while (std::getline(file, line))
        {
            tablaBingo t1;
            for (int i = 0; i < 5; i++)
            {
                std::getline(file, line);
                std::stringstream temp(line);
                std::vector<campo> fila;
                while (std::getline(temp, num, ' '))
                    if (num != "")
                        fila.push_back(std::stoi(num));
                t1.t.push_back(fila);
            }
            tablas.push_back(t1);
        }
        file.close();

        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < tablas.size(); j++)
            {
                int resultado = tablas.at(j).marcar(v.at(i));
                if (resultado != -1)
                {
                    if (tablas.size() == 1)
                    {
                        std::cout << resultado << std::endl;
                        return 0;
                    }
                    else
                    {
                        tablas.erase(tablas.begin() + j);
                        j--;
                    }
                }
            }
        }
    }
    return 1;
}

// g++ -o Day4.2 Day4.2.cc && ./Day4.2