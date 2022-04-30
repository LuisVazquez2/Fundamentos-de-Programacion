#include <iostream> // Libreria Principal
#include <bits/stdc++.h>
using namespace std; // Espacio de nombres (Para usar cin y cout)
/*
    version: c++20 -> g++ 11.2.0
    25/04/2022
    Luis Manuel Vazquez Fierros
*/
string To_Roman(vector<pair<int, string>> &v, int numero)
{
    string romano = "";
    int tam = v.size(), posi = tam - 1;
    if (numero > 0 & numero <= 50)
    {
        while (numero)
        {
            if ((numero - v[posi].first) >= 0)
            {
                int n = numero / v[posi].first;
                for (int i = 0; i < n; i++)
                {
                    romano += v[posi].second;
                }
                numero = numero % v[posi].first;
            }
            posi--;
        }
    }
    else
    {
        romano = "Lo siento no podemos convertir ese numero";
    }
    return romano;
}
int main()
{
    vector<pair<int, string>> v = {
        {1, "I"},
        {4, "IV"},
        {5, "V"},
        {9, "IX"},
        {10, "X"},
        {40, "XL"},
        {50, "L"},
        {90, "XC"},
        {100, "C"},
        {400, "CD"},
        {500, "D"},
        {900, "CM"},
        {1000, "M"},
    };
    int numeros[] = {7, 33, 50, 14, 4};
    int n_ord[52];
    memset(n_ord, 0, sizeof(n_ord));
    cout << "***Bienvenido al programa que convierte numeros arabigos a romanos del (1-50) y los ordena de forma ascendente***" << endl;
    for (int i = 0; i < 5; i++)
    {
        n_ord[numeros[i]]++;
    }
    for (int i = 0; i <= 50; i++)
    {
        if (n_ord[i] != 0)
        {
            string r = To_Roman(v, i);
            for (int j = 0; j < n_ord[i]; j++)
            {
                cout << i << ": " << r << "\n";
            }
        }
    }
    cout << endl;
    system("pause");
    return 0; // Retorno de la funcion que indica que todo salio bien
}
