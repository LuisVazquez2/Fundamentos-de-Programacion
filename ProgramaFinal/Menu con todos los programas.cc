#include <bits/stdc++.h> // Libreria Principal
using namespace std;     // Espacio de nombres (Para usar cin y cout)
/*
    version: c++20 -> g++ 11.2.0
    Date: 14/06/2022
    Luis Manuel Vazquez Fierros
*/
bool isNumber(const string &str)
{
    for (char const &c : str)
    {
        if (isdigit(c) == 0)
            return false;
    }
    return true;
}
int main()
{
    string opcion;
    int value = 0;
    do
    {
        system("cls");
        cout << "**Menu con todos los programas**\n1.Ordenar numeros de manera ascendente\n2.Ordena vocales\n3.Odenar numeros en forma descendente\n4.Ordenar vocales y convertir las salidas a mayusculas\n5.Contar letras de mi nombre con Login y Ficheros Binarios\n6.Convertir numeros arabigos a romanos del (1-30)\n7.Convertir numeros arabigos a romanos del (1-30)\n8.Convertir numeros arabigos a romanos del (1-50) y ordenarlos de manera ascendente\n9.Convertir numeros arabigos a romanos del (1-1000)\n10.Cuestionario de Recomendaciones de Covid\n11.Saber si tenemos nuestro peso ideal\n12.Salir\n";
        cout<<"Ingrese una opcion : ";
        cin >> opcion;
        value = (isNumber(opcion)) ? stoi(opcion) : 0;
        system("cls");
        switch (value)
        {
        case 1:
            system("ProgramaFinal\\ordenar_numeros.exe");
            break;
        case 2:
            system("ProgramaFinal\\ordenar_vocales.exe");
            break;
        case 3:
            system("ProgramaFinal\\ordenar-numeros-descendente.exe");
            break;
        case 4:
            system("ProgramaFinal\\ordenar_vocales_mayus.exe");
            break;
        case 5:
            system("ProgramaFinal\\Contarletras\\calcular-numero-de-letras-de-mi-nombre.exe");
            break;
        case 6:
            system("ProgramaFinal\\romanos-1-30.exe");
            break;
        case 7:
            system("ProgramaFinal\\romanos-1-50.exe");
            break;
        case 8:
            system("ProgramaFinal\\convertir-a-romanos-y-ordenar-de-manera-ascendente.exe");
            break;
        case 9:
            system("ProgramaFinal\\romanos-1-1000.exe");
            break;
        case 10:
            system("ProgramaFinal\\prueba-covid.exe");
            break;
        case 11:
            system("ProgramaFinal\\Calcular-peso-ideal.exe");
            break;
        case 12:
            break;
        default:
            cout << "Opcion invalida\n";
            system("pause");
            break;
        }
    } while (value!=12);
    cout<<"Gracias por usar este programa c:\n";
    system("pause");
    return 0; // Retorno de la funcion que indica que todo salio bien
}