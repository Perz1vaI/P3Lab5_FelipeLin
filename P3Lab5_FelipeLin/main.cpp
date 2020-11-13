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
#include <string>
#include <iomanip>

using namespace std;


int** LlenarMatriz(int**&, int, int);
int** LlenarMatrizManual(int**&, int, int);

int** InicializarMatriz(int, int);

void liberarMatriz(int**&, int);

void printMatrix(int**, int, int);

void sumaMatrices(int**, int**, int, int);
void restaMatrices(int**, int**, int, int);
void multiplicacionMatrices(int**, int**, int, int, int, int);

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



                arreglo_matrices.push_back(Matrix);
                arreglo_matrices_fila.push_back(fila);
                arreglo_matrices_columna.push_back(columna);


                break;
            }
            case 3:
            {

                for (int i = 0; i < arreglo_matrices.size(); i++) {
                    cout << "Posicion: " << i << endl;
                    printMatrix(arreglo_matrices[i], arreglo_matrices_fila[i], arreglo_matrices_columna[i]);

                }
                int cadena_menos_1, cadena_menos_2, cadena_mas_1, cadena_mas_2;
                string cadena = "";
                cout << "Ingrese la operacion" << endl;
                cin >> cadena;

                for (int i = 0; i < cadena.size(); i++) {
                    cout << "prueba 1";
                    if (cadena[i] == '*') {
                        cout << "cadena[i]" << i << endl;
                        for (int j = 1; j < cadena.size(); j++) {
                            if (cadena == -1) {
                                break;
                            } else if (cadena[i - j] == '*') {
                                cadena_menos_1 = cadena[i - j] + 1;
                            } else if (cadena[i - j] == '+' || cadena[i - j] == '-') {
                                cadena_menos_1 = cadena[i - j] + 1;

                            } else {
                                cadena_menos_2 = cadena[i - j];

                            }

                            if (cadena[i + j] == cadena.size()) {
                                break;
                            } else if (cadena[i + j] == '*') {
                                cadena_mas_1 = cadena[i + j] - 1;

                            } else if (cadena[i + j] == '+' || cadena[i - j] == '-') {
                                cadena_mas_1 = cadena[i + j] - 1;

                            } else {
                                cadena_mas_2 = cadena[i + j];
                            }

                        }
                        cout << endl;
                        cout << "cadena mas_1=" << cadena_mas_1 << endl;
                        cout << "cadena mas_2=" << cadena_mas_2 << endl;
                        cout << "cadena menos_1=" << cadena_menos_1 << endl;
                        cout << "cadena menos_2=" << cadena_menos_2 << endl;
                    }

                }





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

int** LlenarMatriz(int**& matriz, int fila, int columna) {
    if (fila > 0 && columna > 0) {
        for (int i = 0; i < fila; i++) {
            for (int j = 0; j < columna; j++) {
                matriz[i][j] = rand() % 101 - 49;

            }
        }
    }
    return matriz;

}

int** LlenarMatrizManual(int**& matriz, int fila, int columna) {
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
    return matriz;
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
    if (fila > 0 && matriz != NULL && columna > 0) {
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

void sumaMatrices(int** matriz_a, int** matriz_b, int fila, int columna) {

    int** matriz_c = new int*[fila];
    for (int i = 0; i < fila; i++)
        matriz_c[i] = new int[columna];


    for (int i = 0; i < fila; i++)
        for (int j = 0; j < columna; j++)
            matriz_c[i][j] = matriz_a[i][j] + matriz_b[i][j];


}

void restaMatrices(int** matriz_a, int** matriz_b, int fila, int columna) {

    int** matriz_c = new int*[fila];
    for (int i = 0; i < fila; i++)
        matriz_c[i] = new int[columna];


    for (int i = 0; i < fila; i++)
        for (int j = 0; j < columna; j++)
            matriz_c[i][j] = matriz_a[i][j] - matriz_b[i][j];


}

void multiplicacionMatrices(int** matriz_a, int** matriz_b, int filaA, int filaB, int ColumnaA, int ColumnaB) {


    int** matriz_c = new int*[filaA];
    for (int i = 0; i < filaA; i++)
        matriz_c[i] = new int[ColumnaB];

    if (ColumnaA == filaB) {
        for (int i = 0; i < filaA; ++i) {
            for (int j = 0; j < ColumnaB; ++j) {
                matriz_c[i][j] = 0;
                for (int k = 0; k < ColumnaA; ++k)
                    matriz_c[i][j] += matriz_a[i][k] * matriz_b[k][j];
            }
        }



    } else
        cout << "solo se puede mutiplicar matriz si Matriz A Columna es igual a Matriz B Fila" << endl;

}



