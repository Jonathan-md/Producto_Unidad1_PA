#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <string>
#include "ordenamientos.h"
using namespace std;

int main() {
    int n;
    int A[100001], B[100001], C[100001];

    string nombres[] = {
        "aleatorio", "ascendente", "descendente",
        "casi_ordenado", "duplicados"
    };

    cout << "Cantidad de elementos: ";
    cin >> n;

    if (n < 1 || n > 100000) {
        cout << "Cantidad no valida" << endl;
        return 0;
    }

    string commit;
    cout << "Hash del commit: ";
    cin >> commit;

    for (int p = 0; p < 5; p++) {
        ofstream archivo(
            ("resultados_" + nombres[p] + ".csv").c_str()
        );
        
        archivo << fixed << setprecision(6);

        archivo << "algoritmo,n,patron,repeticion,tiempo_ms,"
                << "comparaciones,movimientos,profundidad,"
                << "semilla,commit_hash\n";

        cout << "\nPATRON: " << nombres[p] << endl;

        for (int r = 1; r <= 30; r++) {
            int semilla = 12345 + r;

            Generar(A, n, p, semilla);

            for (int i = 0; i < n; i++) {
                B[i] = A[i];
                C[i] = A[i];
            }

            long long comp = 0, mov = 0;
            int prof = 0;

            chrono::steady_clock::time_point ini =
                chrono::steady_clock::now();

            Insercion(A, n, comp, mov);

            chrono::steady_clock::time_point fin =
                chrono::steady_clock::now();

            double tiempo =
                chrono::duration<double, milli>(fin - ini).count();

            archivo << "insercion," << n << "," << nombres[p]
                    << "," << r << "," << tiempo << ","
                    << comp << "," << mov << ",0,"
                    << semilla << "," << commit << "\n";

            cout << "Insercion: " << tiempo << " ms" << endl;

            comp = 0;
            mov = 0;

            ini = chrono::steady_clock::now();

            Shell(B, n, comp, mov);

            fin = chrono::steady_clock::now();

            tiempo =
                chrono::duration<double, milli>(fin - ini).count();

            archivo << "shellsort," << n << "," << nombres[p]
                    << "," << r << "," << tiempo << ","
                    << comp << "," << mov << ",0,"
                    << semilla << "," << commit << "\n";

            cout << "Shell Sort: " << tiempo << " ms" << endl;

            comp = 0;
            mov = 0;
            prof = 0;

            ini = chrono::steady_clock::now();

            QuickSort(C, 0, n - 1, comp, mov, 1, prof);

            fin = chrono::steady_clock::now();

            tiempo =
                chrono::duration<double, milli>(fin - ini).count();

            archivo << "quicksort," << n << "," << nombres[p]
                    << "," << r << "," << tiempo << ","
                    << comp << "," << mov << "," << prof << ","
                    << semilla << "," << commit << "\n";

            cout << "Quick Sort: " << tiempo << " ms" << endl;
        }

        archivo.close();

        cout << "Guardado: resultados_" << nombres[p] << ".csv"
             << endl;
    }

    cout << "\nTodas las pruebas terminaron." << endl;

    return 0;
}

