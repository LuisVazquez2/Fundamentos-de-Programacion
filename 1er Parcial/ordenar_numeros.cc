#include <iostream>
#include <string.h>
using namespace std;
/*
    version: c++20 -> g++ 11.2.0
    03/03/2022
    Luis Manuel Vazquez Fierros
*/
//intercambio de valores
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// quick sort partition
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
//quick sort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
//bubble sort
void buble_sort(int *arr, int n)
{
    // complexity is n^2
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
//buket sort
void bucket_sort(int *arr, int n)
{
    // complexity is 2n
    int contador_numeros[n + 1];
    memset(contador_numeros, 0, sizeof(contador_numeros));
    for (int i = 0; i < n; i++)
    {
        contador_numeros[arr[i]]++;
    }
    cout << "Los numeros ordenados son: ";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < contador_numeros[i]; j++)
        {
            cout << i << ' ';
        }
    }
}
int main()
{
    int numeros_ingresados[10] = {6, 1, 7, 10, 4, 3, 2, 8, 9, 5};
    cout << "\t***Bienvenido al programa de ordenamiento de numeros***\n\n";
    cout << "Escoge una opcion:\n1.Buble Sort\n2.Bucket Sort\n3.Quick Sort\n";
    int opcion;
    cin >> opcion;
    if (opcion == 1)
    {
        buble_sort(numeros_ingresados, 10);
    }
    else if (opcion == 2)
    {
        bucket_sort(numeros_ingresados, 10);
    }
    else if (opcion == 3)
    {
        quickSort(numeros_ingresados, 0, 9);
        cout << "Los numeros ordenados son: ";
        for (int i = 0; i < 10; i++)
        {
            cout << numeros_ingresados[i] << ' ';
        }
    }
    else
    {
        cout << "Opcion invalida";
    }
    cout << "\n\n";
    system("pause");
    return 0;
}