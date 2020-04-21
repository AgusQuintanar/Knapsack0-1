# Tarea Knapsack 0-1

## Autores

* Jonathan de Jesús Chávez Tabares
* Carolina Pérez Alvarado
* Luis
* Agustín

## Organización de archivos

Existen dos carpetas:

* **DP**

* **Greedy**

Cada una contiene lo siguiente:

* `main.cpp`: Código fuente del problema.
* `resultados.txt`: Archivo de texto con la respuesta a la instancia del problema.
* `tests`: Carpeta que contiene los tests de prueba en formato *.txt*.
* `ejecutable.out`: Archivo ejecutable (no existe al inicio).

## Instrucciones de ejecución

Las instrucciones sirven para Linux/Mac, asegúrese de tener gcc instalado.

1. Compile el código `main.cpp` usando el siguiente comando: `g++ main.cpp -std=c++14 -O2 -o ejecutable.out`.

2. Una vez compilado, se generará el archivo `ejecutable.out`, este puede ejecutarse y recibir entrada por standard input. Para ejecutar una prueba ejecute el siguiente comando: `ejecutable.out < tests/dp01.txt > resultados.txt`. Esto guardará los resultados en `resultados.txt`.
