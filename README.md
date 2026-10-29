# Análisis comparativo de algoritmos de ordenamiento

## 1. Descripción del proyecto

Este proyecto compara el rendimiento de tres algoritmos de ordenamiento: Insertion Sort, Shell Sort y Quick Sort.

Las pruebas se realizan con diferentes cantidades de elementos y patrones de entrada para analizar sus tiempos de ejecución y su comportamiento.

## 2. Algoritmos utilizados

- **Insertion Sort:** ordena los elementos mediante inserciones sucesivas.
- **Shell Sort:** ordena los elementos utilizando intervalos que disminuyen progresivamente.
- **Quick Sort:** utiliza un pivote para dividir los elementos y ordenarlos recursivamente.

## 3. Estructura del proyecto

- `src/`: contiene el programa principal y las implementaciones de los algoritmos.
- `include/`: contiene el archivo de cabecera `ordenamientos.h`.
- `results/`: almacena los archivos CSV con los resultados experimentales.
- `docs/`: contiene la documentación y el artículo científico.
- `README.md`: describe el proyecto y explica cómo ejecutarlo.

## 4. Condiciones experimentales

Se consideran tres tamaños de entrada:

- 1 000 elementos.
- 10 000 elementos.
- 100 000 elementos.

Se utilizan cinco patrones de entrada:

- Aleatorio.
- Ascendente.
- Descendente.
- Casi ordenado.
- Con elementos duplicados.

Cada combinación de algoritmo, tamaño y patrón se ejecuta 30 veces.

## 5. Métricas registradas

Los archivos CSV almacenan las siguientes métricas:

- Tiempo de ejecución en milisegundos.
- Número de comparaciones.
- Número de movimientos.
- Profundidad de recursión de Quick Sort.
- Semilla utilizada para generar los datos.
- Hash del commit asociado a la prueba.

## 6. Compilación y ejecución

Para compilar el programa desde la carpeta `src`, se utiliza:

*g++ Analisis_Sort.cpp ordenamientos.cpp -I../include -o Analisis_Sort*


Para ejecutar el programa en Windows PowerShell:

*.\Analisis_Sort.exe*


El programa solicita la cantidad de elementos y el hash del commit correspondiente a la versión evaluada.

## 7. Resultados

Los resultados experimentales se almacenan en archivos CSV para facilitar su revisión, procesamiento y representación mediante tablas y gráficos.

## 8. Reproducibilidad

El proyecto utiliza Git y GitHub para registrar los cambios del código. El hash del commit permite identificar la versión asociada a cada ejecución experimental.