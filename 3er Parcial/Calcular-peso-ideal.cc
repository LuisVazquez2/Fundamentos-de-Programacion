#include <bits/stdc++.h> // Libreria Principal
using namespace std;     // Espacio de nombres (Para usar cin y cout)
/*
    version: c++20 -> g++ 11.2.0
    Date: 10/06/2022
    Luis Manuel Vazquez Fierros
*/

void saludar(string& name)
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
    cout << name << " bienvenido al programa para calcular si estas en tu peso ideal\n";
}
int main()
{
    // Funcion principal
    string name;
    cout << "Ingrese su nombre: ";
    cin >> name;
    saludar(name);
    double peso = 0, altura = 0;
    cout << "Ingrese su peso (en kg): ";
    cin >> peso;
    cout << "Ingrese su altura (en metros): ";
    cin >> altura;
    double imc = peso / (altura * altura);
    cout << "Su indice de masa corporal es: " << imc << endl;
    cout<<name<<" , ";
    if (imc>=24 | imc<=30){
        cout<<"Tienes sobrepeso de grado 1 (bajo riesgo), podrias asistir a un especialista para no poner en riesgo tu salud"<<endl;
    }else if(imc>30 | imc<=40){
        cout<<"Tienes sobrepeso de grado 2 (riesgo moderado), podrias asistir a un especialista para no poner en riesgo tu salud";
    }else if(imc>=40){
        cout<<"Tienes obecidad de grado 3 (riesgo severo), podrias asistir a un especialista para no poner en riesgo tu salud";
    }else{
        cout<<"Felicidades, Tienes peso normal";
    }
    system("pause");
    return 0;
}