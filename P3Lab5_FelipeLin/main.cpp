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

int** sumaMatrices(int**, int**, int**, int, int);
int** restaMatrices(int**, int**, int**, int, int);
int** multiplicacionMatrices(int**, int**, int**, int, int, int, int);

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
            case 3: // Solo funciona si es 1*1 o 0+1 o 1-0
            {

                for (int i = 0; i < arreglo_matrices.size(); i++) {
                    cout << "Posicion: " << i << endl;
                    printMatrix(arreglo_matrices[i], arreglo_matrices_fila[i], arreglo_matrices_columna[i]);

                }
                int cadena_sub, cadena_sub2, cadena_sub3, cadena_sub4;
                int** temporal = NULL;
                string cadena = "";
                cout << "Ingrese la operacion" << endl;
                cin >> cadena;

                int size_cadena = cadena.size() - 1;

                for (int i = 0; i < size_cadena; i++) {
                    if (cadena[i] == '*') {
                        cadena_sub = stoi(cadena.substr(i - 1));
                        cadena_sub2 = stoi(cadena.substr(i + 1));

                        temporal = InicializarMatriz(arreglo_matrices_fila[cadena_sub], arreglo_matrices_columna[cadena_sub2]);

                        temporal = LlenarMatriz(temporal, arreglo_matrices_fila[cadena_sub], arreglo_matrices_columna[cadena_sub2]);

                        temporal = multiplicacionMatrices(temporal, arreglo_matrices[cadena_sub], arreglo_matrices[cadena_sub2],
                                arreglo_matrices_fila[cadena_sub], arreglo_matrices_fila[cadena_sub2], arreglo_matrices_columna[cadena_sub],
                                arreglo_matrices_columna[cadena_sub2]);

                        arreglo_matrices.push_back(temporal);

                        cadena.replace(i - 1, i + 1, to_string(arreglo_matrices.size()));


                    } else if (cadena[i] == '+') {

                        cadena_sub = stoi(cadena.substr(i - 1));
                        cadena_sub2 = stoi(cadena.substr(i + 1));

                        temporal = InicializarMatriz(arreglo_matrices_fila[cadena_sub], arreglo_matrices_columna[cadena_sub]);

                        temporal = LlenarMatriz(temporal, arreglo_matrices_fila[cadena_sub], arreglo_matrices_columna[cadena_sub]);

                        temporal = sumaMatrices(temporal, arreglo_matrices[cadena_sub], arreglo_matrices[cadena_sub2], arreglo_matrices_fila[cadena_sub], arreglo_matrices_columna[cadena_sub]);


                        cadena.replace(i - 1, i + 1, to_string(arreglo_matrices.size()));


                    } else if (cadena[i] == '-') {
                        cadena_sub = stoi(cadena.substr(i - 1));
                        cadena_sub2 = stoi(cadena.substr(i + 1));

                        temporal = InicializarMatriz(arreglo_matrices_fila[cadena_sub], arreglo_matrices_columna[cadena_sub]);

                        temporal = LlenarMatriz(temporal, arreglo_matrices_fila[cadena_sub], arreglo_matrices_columna[cadena_sub]);

                        temporal = restaMatrices(temporal, arreglo_matrices[cadena_sub], arreglo_matrices[cadena_sub2], arreglo_matrices_fila[cadena_sub], arreglo_matrices_columna[cadena_sub]);


                        cadena.replace(i - 1, i + 1, to_string(arreglo_matrices.size()));
                    }

                }

                printMatrix(temporal, arreglo_matrices_fila[cadena_sub], arreglo_matrices_columna[cadena_sub]);

                liberarMatriz(temporal, arreglo_matrices_fila[cadena_sub]);


                break;
            }

                //            case 5:
                //            {
                //
                //                int** matriz_a = NULL;
                //                int** matriz_b = NULL;
                //
                //                matriz_a = InicializarMatriz(2, 3);
                //                matriz_b = InicializarMatriz(3, 2);
                //
                //                matriz_a = LlenarMatriz(matriz_a, 2, 3);
                //                matriz_b = LlenarMatriz(matriz_b, 3, 2);
                //                
                //                printMatrix(matriz_a,2,3);
                //                printMatrix(matriz_b,3,2);
                //
                //                multiplicacionMatrices(matriz_a, matriz_b, 2, 3, 3, 2);
                //                break;
                //
                //            }



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

int** sumaMatrices(int** matriz_c, int** matriz_a, int** matriz_b, int fila, int columna) {

    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            matriz_c[i][j] = matriz_a[i][j] + matriz_b[i][j];
        }
    }

    return matriz_c;
}

int** restaMatrices(int** matriz_c, int** matriz_a, int** matriz_b, int fila, int columna) {

    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            matriz_c[i][j] = matriz_a[i][j] - matriz_b[i][j];
        }
    }

    return matriz_c;
}

int** multiplicacionMatrices(int** matriz_c, int** matriz_a, int** matriz_b, int filaA, int filaB, int ColumnaA, int ColumnaB) {


    if (ColumnaA == filaB) {
        for (int i = 0; i < filaA; i++) {
            for (int j = 0; j < ColumnaB; j++) {
                matriz_c[i][j] = 0;
                for (int k = 0; k < ColumnaA; k++)
                    matriz_c[i][j] += matriz_a[i][k] * matriz_b[k][j];
            }
        }
    } else {
        cout << "solo se puede mutiplicar matriz si Matriz A Columna es igual a Matriz B Fila" << endl;
    }

    return matriz_c;

}



