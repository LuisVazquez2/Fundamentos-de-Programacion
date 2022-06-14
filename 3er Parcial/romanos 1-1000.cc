#include <iostream> // Libreria Principal
#include<bits/stdc++.h>
using namespace std; // Espacio de nombres (Para usar cin y cout)
/*
    version: c++20 -> g++ 11.2.0
    21/05/2022
    Luis Manuel Vazquez Fierros
*/
void To_Roman(int numero)
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
    int tam = v.size(), posi = tam - 1;
    if (numero > 0 & numero <= 1000)
    {
        while (numero)
        {
            if ((numero - v[posi].first) >= 0)
            {
                int n = numero / v[posi].first;
                for (int i = 0; i < n; i++)
                {
                    cout << v[posi].second;
                }
                numero = numero % v[posi].first;
            }
            posi--;
        }
    }
    else
    {
        cout << "Lo siento no podemos convertir ese numero";
    }
}
int main()
{
    cout<<"***Bienvenido al programa que convierte numeros arabiicos a romanos del (1-1000)***"<<endl;
    cout << "Ingrese el numero que desea pasar a Romano: ";
    int numero;
    cin >> numero;
    To_Roman(numero);
    cout<<endl;
    system("pause");
    return 0; // Retorno de la funcion que indica que todo salio bien
}
