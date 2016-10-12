/*Autor: Natalia Isaza
Funcion del programa: Calculadora de matrices
Fecha:05/10/2016*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <conio.h>
#define MAX 5
using namespace std;
//Mostrar menu
int menu();
void llenarMatriz(int[MAX][MAX], int orden);
void mostrarMatriz(int[MAX][MAX], int orden);
void transpuestaM(int [MAX][MAX], int [][MAX],int orden);
void mostrarT(int [MAX][MAX],int orden);
int determinante(int matriz[MAX][MAX],int orden );
int cofactor(int matriz[MAX][MAX], int orden, int fila, int columna);

void Pausa ();
void limpiarPantalla ();
//Funcion principal
int main ()

{


    system ("color");
    //Crear matriz
    int opcion = menu();
    return 0;
}
int menu(){
    int matriz [MAX][MAX];
    int T[MAX][MAX];
    int opcion;
    int orden;

   cout << "Ingresa el orden de la matriz (maximo " << MAX << "): ";
   cin >> orden;
   while (orden < 0 || orden > MAX) {
      cout << "\nEl orden de la matriz no puede ser mayor que " << MAX << endl;
      cout << "Ingrese nuevamente el orden de la matriz: ";
      cin >> orden;
      }
    do{
    //menu principal
    cout << "------Calcuadora de matrices------" << endl;
    cout << "----Marque una opcion del menu----" <<"" ""<< endl<<endl;
    cout << "1.Llenar matriz" << endl;
    cout << "2.Mostrar matriz" << endl;
    cout << "3.Traspuesta de una Matriz" << endl;
    cout << "4.Determinante matriz" << endl;
    cout << "5.Limpieza" << endl;
    cout << "0.Salir" << endl;
    cin >> opcion;

    }while(opcion>6 || opcion<0);
    switch(opcion){

        case 0: cout << "Programa finalizar" << endl;
        exit(0);
        case 1: cout << "Llenar matriz" << endl;
            llenarMatriz(matriz,orden);
            //mostrarMatriz(matriz,orden);
            Pausa ();
            menu ();
        break;
        case 2: cout << "Mostrar matriz" << endl;
            llenarMatriz(matriz,orden);
            mostrarMatriz(matriz,orden);
            Pausa ();
            menu ();
        break;
        case 3: llenarMatriz(matriz,orden);
                transpuestaM(matriz, T,orden);
                cout<<"Matriz Original"<<endl;
                mostrarMatriz(matriz,orden);
                cout<<"Matriz Transpuesta"<<endl;
                mostrarT(T,orden);
                Pausa ();
                menu();
        break;
        case 4: cout << "Determinante matriz" << endl;
            llenarMatriz(matriz,orden);
            mostrarMatriz(matriz,orden);
            cout << determinante(matriz,orden);
            Pausa ();
            menu();
        break;
        case 5:
            cout << "Limpiar" << endl;
             limpiarPantalla () ;
             menu ();
        default: cout << "Opcion no valida" << endl;

    }
    return opcion;


}
void llenarMatriz(int matriz[MAX][MAX],int orden){
    for (int j=0;j<orden;j++) {
        for (int i=0;i<orden;i++) {
               matriz [j][i]=rand ()%100;

               cout << matriz [j][i]<< "\t";

    }
    cout << endl;
    }
    cout << endl << "Matriz llenada con exito" << endl << endl << endl;
}
void mostrarMatriz(int matriz[MAX][MAX],int orden){
    for (int j=0;j<orden;j++) {
        for (int i=0;i<orden;i++) {
              cout << matriz [j][i]<< "\t";

    }
    cout << endl << endl;
    }
}

void transpuestaM(int matriz[MAX][MAX], int T[MAX][MAX], int orden){
    for(int j = 0; j < orden; j++){
        for(int i = 0; i < orden; i++){
           T[j][i] = matriz[i][j];
        }
    }
    cout << endl;
}

void mostrarT(int T[MAX][MAX], int orden){
    for(int j = 0; j < orden; j++){
        for(int i = 0; i < orden; i++){
            cout<<T[j][i]<< "\t";
        }
        cout<<endl;
    }
}
int determinante(int matriz[MAX][MAX], int orden)
{
   int det = 0.0;

   if (orden == 1) {
      det = matriz[0][0];
   } else {
      for (int j = 0; j < orden; j++) {
         det = det + matriz[0][j] * cofactor(matriz, orden, 0, j);
      }
   }

   return det;
}


int cofactor(int matriz[MAX][MAX], int orden, int fila, int columna)
{
   int submatriz[MAX][MAX];
   int n = orden - 1;

   int x = 0;
   int y = 0;
   for (int i = 0; i < orden; i++) {
      for (int j = 0; j < orden; j++) {
         if (i != fila && j != columna) {
            submatriz[x][y] = matriz[i][j];
            y++;
            if (y >= n) {
               x++;
               y = 0;
            }
         }
      }
   }

   return pow(-1.0, fila + columna) * determinante(submatriz, n);
}
void Pausa ()
{
cout << "Pulse una tecla para continuar...";
if (!getch ())
getch ();
}
void limpiarPantalla () {
    system ("cls");
}


