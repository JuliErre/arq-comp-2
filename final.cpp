#include <iostream>
#include <omp.h>

int main()
{
    const int n = 10000; //
    int arr[n];

    // Inicializar el arreglo
    for (int i = 0; i < n; ++i)
    {
        arr[i] = i;
    }

    // Obtener el tiempo de inicio
    double start_time = omp_get_wtime();

    int sum = 0;

// Paralelizar el bucle usando OpenMP
#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
    }

    // Obtener el tiempo de finalización
    double end_time = omp_get_wtime();

    // Calcular el tiempo transcurrido
    double elapsed_time = end_time - start_time;

    std::cout << "La suma de los elementos del arreglo es: " << sum << std::endl;
    std::cout << "Tiempo de ejecución: " << elapsed_time << " segundos." << std::endl;

    return 0;
}
