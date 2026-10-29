#ifndef ORDENAMIENTOS_H
#define ORDENAMIENTOS_H

void Insercion(int A[], int n, long long &comp, long long &mov);
void Shell(int A[], int n, long long &comp, long long &mov);
void QuickSort(int A[], int inicio, int fin,
               long long &comp, long long &mov,
               int nivel, int &prof);
void Generar(int A[], int n, int patron, int semilla);

#endif
