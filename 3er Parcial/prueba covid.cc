#include <bits/stdc++.h> // Libreria Principal
using namespace std;     // Espacio de nombres (Para usar cin y cout)
/*
    version: c++20 -> g++ 11.2.0
    Date: 03/06/2022
    Luis Manuel Vazquez Fierros
*/
bool make_question(string question)
{
    cout << question;
    char answer;
    do
    {
        cout << "\nPresione 1 para si, 0 para no: ";
        cin >> answer;
        if (answer != '0' && answer != '1')
        {
            cout << "Respuesta invalida, intente de nuevo: ";
        }
    } while (answer != '1' && answer != '0');
    return answer == '1';
}
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
    cout << name << " bienvenido al cuestionario para determinar si tienes covid-19\n";
}
int main()
{
    // Funcion principal
    string name;
    cout << "Ingrese su nombre: ";
    cin >> name;
    saludar(name);
    bitset<10> answers;
    string questions[] = {
    "¿Tienes fiebre 35 grados o mas?",
    "¿Tienes tos?",
    "¿Te cuesta respirar?",
    "¿Has estado con alguien que ha tenido coronavirus?",
    "¿Tienes fluido nasal?",
    "¿Te duelen los musculos?",
    "¿Tienes malestar general?",
    "¿Tienes alguna enfermedad cronica de corazon, de pulmon o de rinon?",
    "¿Has perdido el olfato y el gusto?",
    "¿Llevas mas de 20 dias con estos sintomas?"};
    for (int i = 0; i < 10; i++)
    {
        answers[i] = make_question(questions[i]);
    }
    /*
    Critical questions:
    1. ¿Tienes fiebre 35 grados o mas?
    3. ¿Te cuesta respirar?
    4. ¿Has estado con alguien que ha tenido coronavirus?
    7. ¿Tienes alguna enfermedad crónica de corazón, de pulmón o de riñón?
    9. ¿Has perdido el olfato y el gusto?
    10. ¿Llevas más de 20 días con estos síntomas?
    */
    if (answers[0] || answers[2] || answers[3] || answers[6] || answers[8] || answers[9])
    {
        cout << name << " posiblemente tienes covid, consulta a tu medico.";
    }
    else
    {
        int c = answers.count();
        if (c >= 3)
        {
            cout << name << " posiblemente tienes covid, consulta a tu medico.";
        }
        else
        {
            cout << name << " posiblemente no tienes covid, pero podrias ser un pasiente asintomatico, asi que no estaria mal visitar a tu medico.";
        }
    }
    cout<<"\n";
    system("pause");
    return 0; // Retorno de la funcion que indica que todo salio bien
}