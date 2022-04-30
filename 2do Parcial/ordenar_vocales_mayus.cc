#include <iostream>
#include <string.h>
#include <conio.h>
#include <ctime>
using namespace std;
/*
    version: c++20 -> g++ 11.2.0
    15/03/2022
    Luis Manuel Vazquez Fierros
*/
void saludar()
{
    time_t tiempo = time(0);
    tm *tlocal = localtime(&tiempo);
    int hora = tlocal->tm_hour;
    if (hora >= 0 && hora < 12)
    {
        cout << "Buenos dias, ";
    }
    else if (hora >= 12 && hora < 18)
    {
        cout << "Buenas tardes, ";
    }
    else if (hora >= 18 && hora < 24)
    {
        cout << "Buenas noches, ";
    }
    cout << "Bienvenido al programa de ordenamiento de vocales\n";
}
bool es_vocal(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return true;
    }
    return false;
}
int main()
{
    // usando bucket sort
    int contador_vocales[5]; // 0:a, 1:e, 2:i, 3:o, 4:u como si fuera un diccionario
    char vocales[5] = {'a', 'e', 'i', 'o', 'u'}, vocales_ingresadas[5];
    memset(contador_vocales, 0, sizeof(contador_vocales));
    memset(vocales_ingresadas, 0, sizeof(vocales_ingresadas));
    saludar();
    cout << "***Ingrese las vocales que desea ordenar***\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Ingrese la vocal (" << i + 1 << "): ";
        cin >> vocales_ingresadas[i];
        if (es_vocal(vocales_ingresadas[i]))
        {
            for (int j = 0; j < 5; j++)
            {
                if (vocales_ingresadas[i] == vocales[j])
                {
                    contador_vocales[j]++;
                }
            }
        }
        else
        {
            cout << "La vocal ingresada no es valida\n";
            i--;
        }
    }
    cout << "\nLas vocales ingresadas son: ";
    for (int i = 0; i < 5; i++)
    {
        cout << char(toupper(vocales_ingresadas[i])) << ' ';
    }
    cout << "\nLas vocales ordenadas son: ";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < contador_vocales[i]; j++)
        {
            cout << char(toupper(vocales[i])) << ' ';
        }
    }
    cout << "\n";
    getch();
    return 0;
}