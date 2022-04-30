#include <iostream>  // Libreria Principal
#include <string.h>  // Libreria para usar string y memset
#include <conio.h>   // Libreria para usar getch()
using namespace std; // Espacio de nombres (Para usar cin y cout)
/*
    version: c++20 -> g++ 11.2.0
    25/03/2022
    Luis Manuel Vazquez Fierros
*/
void saludar()
{
    time_t tiempo = time(0);
    tm *tlocal = localtime(&tiempo);
    int hora = tlocal->tm_hour;
    if (hora >= 0 && hora < 12)
    {
        cout << "Buenos días, ";
    }
    else if (hora >= 12 && hora < 18)
    {
        cout << "Buenas tardes, ";
    }
    else if (hora >= 18 && hora < 24)
    {
        cout << "Buenas noches, ";
    }
    cout << "Bienvenido al programa de ordenamiento de numeros de manera descendente\n";
}
int main()
{
    saludar();
    int contador_numeros[10], numeros[10];
    memset(contador_numeros, 0, sizeof(contador_numeros)); // Inicializar el arreglo a 0
    memset(numeros, 0, sizeof(numeros)); // Inicializar el arreglo a 0
    cout << "***Ingrese los numeros que desea ordenar***\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "Ingrese el numero (" << i + 1 << "): ";
        cin >> numeros[i];
        if (numeros[i] >= 1 && numeros[i] <= 10)
        {
            contador_numeros[numeros[i] - 1]++;
        }
        else
        {
            cout << "El numero ingresado no es valido\n";
            i--;
        }
    }
    // Imprimir los números ordenados
    cout << "Los numero ordenados son: ";
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 0; j < contador_numeros[i]; j++)
        {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
    getch();
    return 0; // Retorno de la funcion que indica que todo salio bien
}