/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: felipelinzhao
 *
 * Created on November 13, 2020, 1:02 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


int** LlenarMatriz(int**, int, int);
int** LlenarMatrizManual(int**, int, int);

int** InicializarMatriz(int, int);

void liberarMatriz(int**&, int);

void printMatrix(int**, int, int);

/*
 * 
 */
int main(int argc, char** argv) {
    vector <int**> arreglo_matrices;
    vector <int> arreglo_matrices_fila;
    vector <int> arreglo_matrices_columna;
    int menu;
    cout << "1. Ingresar Matriz\n2. Generar Matriz \n3. Realizar operacion entre matriz\n4. Salida\n";
    cout << "Ingrese la opcion: ";
    cin >> menu;
    while (menu != 4) {
        switch (menu) {
            case 1:
            {
                int fila, columna;
                int** Matrix = NULL;
                cout << "Elija la fila de su matriz: " << endl;
                cin >> fila;
                cout << "Elija la columna de su matriz: " << endl;
                cin >> columna;

                Matrix = InicializarMatriz(fila, columna);

                Matrix = LlenarMatrizManual(Matrix, fila, columna);


                arreglo_matrices.push_back(Matrix);
                arreglo_matrices_fila.push_back(fila);
                arreglo_matrices_columna.push_back(columna);

                liberarMatriz(Matrix, fila);

                break;
            }
            case 2:
            {
                int fila, columna;
                int** Matrix = NULL;
                cout << "Elija la fila de su matriz: " << endl;
                cin >> fila;
                cout << "Elija la columna de su matriz: " << endl;
                cin >> columna;

                Matrix = InicializarMatriz(fila, columna);

                Matrix = LlenarMatriz(Matrix, fila, columna);

                printMatrix(Matrix, fila, columna);


                arreglo_matrices.push_back(Matrix);
                arreglo_matrices_fila.push_back(fila);
                arreglo_matrices_columna.push_back(columna);

                liberarMatriz(Matrix, fila);

                break;
            }
            case 3:
            {

                for (int i = 0; i < arreglo_matrices.size(); i++) {
                    cout << "Posicion: " << i;
                    cout << "fila i: " << arreglo_matrices_fila[i];
                    cout << "columna i: " << arreglo_matrices_columna[i];
                    printMatrix(arreglo_matrices[i], arreglo_matrices_fila[i], arreglo_matrices_columna[i]);
                    cout << endl;
                }

                //string cadena = "";
                //cout << "Ingrese la operacion" << endl;
                //cin >> cadena;






                break;
            }

            default:
            {
                cout << "No existe esa opcion\n";
                break;
            }
        }

        cout << "1. Ingresar Matriz\n2. Generar Matriz \n3. Realizar operacion entre matriz\n4. Salida\n";
        cout << "Ingrese la opcion: ";
        cin >> menu;

    }


}

int** InicializarMatriz(int fila, int columna) {
    if (fila > 0 && columna > 0) {
        int** intArray = new int*[fila];
        for (int i = 0; i < fila; i++) {
            intArray[i] = new int[columna];
        }
        return intArray;

    }
    return NULL;

}

int** LlenarMatriz(int** matriz, int fila, int columna) {
    if (fila > 0 && columna > 0) {
        for (int i = 0; i < fila; i++) {
            for (int j = 0; j < columna; j++) {
                matriz[i][j] = rand() % 101 - 49;

            }
        }
    }
    return NULL;

}

int** LlenarMatrizManual(int** matriz, int fila, int columna) {
    if (fila > 0 && columna > 0) {
        int x;
        for (int i = 0; i < fila; i++) {
            for (int j = 0; j < columna; j++) {
                cout << "Ingrese al elemento: ";
                cin >> x;
                cout << endl;
                matriz[i][j] = x;

            }
        }
    }
    return NULL;
}

void liberarMatriz(int**& matriz, int fila) {
    if (matriz != NULL && fila > 0) {
        for (int i = 0; i < fila; i++) {
            if (matriz[i] != NULL) {
                delete[] matriz[i];
                matriz[i] = NULL;
            }
        }
        delete[] matriz;
        matriz = NULL;
    }
}

void printMatrix(int** matriz, int fila, int columna) {
    cout << "prueba 1";
    if (fila > 0 && matriz =! NULL && columna > 0) {
        cout << "prueba 2 ";
        for (int i = 0; i < fila; i++) {
            if (matriz[i] != NULL) {
                cout << "[";
                for (int j = 0; j < columna; j++) {
                    cout << setw(4) << matriz[i][j] << " ";
                }
                cout << "]" << endl;
            }



        }
        cout << endl;
    }

}

