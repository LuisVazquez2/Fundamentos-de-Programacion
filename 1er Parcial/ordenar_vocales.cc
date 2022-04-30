#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;
/*
    version: c++20 -> g++ 11.2.0
    02/03/2022
    Luis Manuel Vazquez Fierros
*/
int main()
{
    // usando bucket sort
    int n_vocales[5]; // 0:a, 1:e, 2:i, 3:o, 4:u como si fuera un diccionario
    char vocales[5] = {'a', 'e', 'i', 'o', 'u'}, vocales_ingresadas[5] = {'o', 'e', 'i', 'u', 'a'};
    memset(n_vocales, 0, sizeof(n_vocales));
    cout << "\t***Bienvenido al programa de ordenamiento de vocales***\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (vocales[j] == vocales_ingresadas[i])
            {
                n_vocales[j]++;
            }
        }
    }
    cout << "Las vocales ordenadas son:\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < n_vocales[i]; j++)
        {
            cout << vocales[i] << ' ';
        }
    }
    cout<<"\n";
    getch();
    return 0;
}