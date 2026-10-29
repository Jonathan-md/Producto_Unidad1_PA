#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;


void Insercion(int A[], int n, long long &comp, long long &mov) {
    int aux, k;

    for (int i = 1; i < n; i++) {
        aux = A[i];
        k = i - 1;

        while (k >= 0) {
            comp++;

            if (A[k] > aux) {
                A[k + 1] = A[k];
                mov++;
                k--;
            } else {
                break;
            }
        }

        A[k + 1] = aux;
    }
}


void Shell(int A[], int n, long long &comp, long long &mov) {
    int salto, aux, j;

    for (salto = n / 2; salto > 0; salto /= 2) {
        for (int i = salto; i < n; i++) {
            aux = A[i];
            j = i;

            while (j >= salto) {
                comp++;

                if (A[j - salto] > aux) {
                    A[j] = A[j - salto];
                    mov++;
                    j -= salto;
                } else {
                    break;
                }
            }

            A[j] = aux;
        }
    }
}


void QuickSort(int A[], int inicio, int fin,
               long long &comp, long long &mov,
               int nivel, int &prof) {
    if (inicio >= fin) {
        return;
    }

    if (nivel > prof) {
        prof = nivel;
    }

    int i = inicio;
    int j = fin;
    int pivote = A[(inicio + fin) / 2];

    while (i <= j) {
        while (i <= fin) {
            comp++;
            if (A[i] < pivote) {
                i++;
            } else {
                break;
            }
        }

        while (j >= inicio) {
            comp++;
            if (A[j] > pivote) {
                j--;
            } else {
                break;
            }
        }

        if (i <= j) {
            if (i != j) {
                int aux = A[i];
                A[i] = A[j];
                A[j] = aux;
                mov++;
            }

            i++;
            j--;
        }
    }

    if (inicio < j) {
        QuickSort(A, inicio, j, comp, mov, nivel + 1, prof);
    }

    if (i < fin) {
        QuickSort(A, i, fin, comp, mov, nivel + 1, prof);
    }
}


void Generar(int A[], int n, int patron, int semilla) {
    srand(semilla);

    for (int i = 0; i < n; i++) {
        if (patron == 0) {
            A[i] = rand() % 100000;
        } else if (patron == 1) {
            A[i] = i + 1;
        } else if (patron == 2) {
            A[i] = n - i;
        } else if (patron == 3) {
            A[i] = i + 1;
        } else {
            A[i] = rand() % 10;
        }
    }

    if (patron == 3) {
        for (int i = 0; i < n / 100 + 1; i++) {
            int x = rand() % n;
            int y = rand() % n;

            int aux = A[x];
            A[x] = A[y];
            A[y] = aux;
        }
    }
}


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

        archivo << "algoritmo,n,patron,repeticion,tiempo_ms,"
                << "comparaciones,movimientos,profundidad,"
                << "semilla,commit_hash\n";

        cout << "\nPATRON: " << nombres[p] << endl;

        for (int r = 1; r <= 3; r++) {
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

