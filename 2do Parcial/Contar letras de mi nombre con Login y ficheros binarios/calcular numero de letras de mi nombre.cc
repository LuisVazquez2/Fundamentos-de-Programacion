#include <bits/stdc++.h> // Libreria para usar funciones de la libreria estandar de C++
#include <conio.h>       // Libreria para getch()
using namespace std;     // Espacio de nombres (Para usar cin y cout)
struct Usuario
{
    char nombre[100], nick[100], contrasena[100];
    int edad;
    Usuario()
    {
        memset(nombre, 0, sizeof(nombre));
        memset(nick, 0, sizeof(nick));
        memset(contrasena, 0, sizeof(contrasena));
        edad = 0;
    }
    void Resetear()
    {
        memset(nombre, 0, sizeof(nombre));
        memset(nick, 0, sizeof(nick));
        memset(contrasena, 0, sizeof(contrasena));
        edad = 0;
    }
    int longitud_contrasena()
    {
        int contador = 0;
        while (contrasena[contador] != '\0')
        {
            contador++;
        }
        return contador;
    }
    void pedir_contraseña()
    {
        char aux = 0;
        while (aux = getch())
        {
            if (aux == 13)
            {
                break;
            }
            else if (aux == 8)
            {
                if (longitud_contrasena() > 0)
                {
                    cout << "\b \b";
                    contrasena[longitud_contrasena() - 1] = '\0';
                }
            }
            else
            {
                contrasena[longitud_contrasena()] = aux;
                cout << "*";
            }
        }
        cout << endl;
    }
    bool nick_disponible(string nick)
    {
        ifstream archivo("database.dat", ios::in);
        if (archivo.fail())
        {
            return true;
        }
        Usuario x;
        while (!archivo.eof())
        {
            archivo.read((char *)&x, sizeof(Usuario));
            if (x.nick == nick)
            {
                archivo.close();
                return false;
            }
        }
        archivo.close();
        return true;
    }
    void registrar_en_archivo()
    {
        ofstream archivo("database.dat", ios::app); // ios::app para agregar al final del archivo
        archivo.write((char *)this, sizeof(Usuario));
        archivo.close();
        cout << "Registro exitoso" << endl;
    }
    void registrar()
    {
        fflush(stdin);
        cout << "Ingrese su nombre completo: ";
        cin.getline(nombre, 100);
        cout << "Ingrese su edad: ";
        cin >> edad;
        cout << "Ingrese su contrasena: ";
        pedir_contraseña();
        cout << "Ingrese su nickname: ";
        cin >> nick;
        if (nick_disponible(nick))
        {
            registrar_en_archivo();
        }
        else
        {
            cout << "El nickname ya esta en uso" << endl;
            Resetear();
            registrar();
            return;
        }
    }
    Usuario Login()
    {
        fflush(stdin);
        string t_nick, t_contrasena;
        cout << "Ingrese su nick: ";
        cin >> t_nick;
        cout << "Ingrese su contrasena: ";
        pedir_contraseña();
        t_contrasena = this->contrasena;
        ifstream archivo("database.dat", ios::in);
        if (archivo.fail())
        {
            return Usuario();
        }
        else
        {
            Usuario x;
            while (!archivo.eof())
            {
                archivo.read((char *)&x, sizeof(Usuario));
                if (t_contrasena == x.contrasena && t_nick == x.nick)
                {
                    archivo.close();
                    return x;
                }
            }
            archivo.close();
            return Usuario();
        }
    }
    vector<string> separar_nombre()
    {
        vector<string> nombre_separado;
        string nombre_separado_aux;
        for (int i = 0; nombre[i] != '\0'; i++)
        {

            if (nombre[i] == ' ' && nombre_separado_aux!="")
            {
                nombre_separado.push_back(nombre_separado_aux);
                nombre_separado_aux = "";
            }
            else if(nombre[i]!=' '){
                nombre_separado_aux += nombre[i];
            }
        }
        if (nombre_separado_aux != "")
            nombre_separado.push_back(nombre_separado_aux);
        return nombre_separado;
    }
    void calcular_numero_letras()
    {
        vector<string> nombre_separado = separar_nombre();
        int numero_letras = 0;
        for (auto x : nombre_separado)
        {
            cout << x << " tiene " << x.length() << " letras" << endl;
            numero_letras += x.length();
        }
        cout << "El numero de letras de tu nombre es: " << numero_letras << endl;
    }
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
        cout << nombre << " Bienvenido al programa para obtener el numero de letras de tu nombre c:\n";
    }
    void imprimir()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Contrasena: " << contrasena << endl;
        cout << "Nickname: " << nick << endl;
    }
};
int main()
{
    setlocale(LC_CTYPE, "Spanish");
    Usuario main_user;
    string aux = "";
    int op = 0;
    while (op != 3)
    {
        system("cls");
        main_user = Usuario();
        cout << "***Opciones***\n1. Registrar\n2. Login\n3. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> op;
        switch (op)
        {
        case 1:
            main_user.registrar();
            break;
        case 2:
            main_user = main_user.Login();
            aux = main_user.nombre;
            if (aux!= "")
            {
                main_user.saludar();
                main_user.calcular_numero_letras();
            }
            else
            {
                cout << "Usuario y/o contrasena incorrectos" << endl;
            }
            break;
        case 3:
            cout << "Adios" << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
        system("pause");
    }
    return 0; // Retorno de la funcion que indica que todo salio bien
}