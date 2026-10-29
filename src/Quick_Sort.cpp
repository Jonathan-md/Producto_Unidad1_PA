#include <iostream>
using namespace std;

void QuickSort(int A[], int inicio, int fin) {
    int i = inicio;
    int j = fin;
    int pivote = A[(inicio + fin) / 2];

    while (i <= j) {
        while (A[i] < pivote) {
            i++;
        }

        while (A[j] > pivote) {
            j--;
        }

        if (i <= j) {
            int aux = A[i];
            A[i] = A[j];
            A[j] = aux;
            i++;
            j--;
        }
    }

    if (inicio < j) {
        QuickSort(A, inicio, j);
    }

    if (i < fin) {
        QuickSort(A, i, fin);
    }
}

int main() {
    int A[100], n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    QuickSort(A, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}

