#include <iostream>
using namespace std;
#include <fstream>

int mitad (int arr[], int pinicial, int pfinal);
void ordenar(int arr[], int pinicial, int pinal);
void registrar_arreglo_inicial(int arr[]);
void registrar_arreglo_final(int arr[]);

int main(){

    int A[10] = {80, -7, 4, 2, -34, 34, 8, 20};
    registrar_arreglo_inicial(A);

    ordenar(A, 0, 9);
    registrar_arreglo_final(A);
    for(int i = 0; i < 10; i++){

        cout << "[" << A[i] << "]" << endl;

    }

    
    return 0;
}

int mitad (int arr[], int pinicial,int pfinal){
    
    return arr[(pinicial+pfinal)/2];

}

void ordenar(int arr[], int pinicial,int pfinal){

    int i = pinicial;
    int j = pfinal;
    int temp; 
    int piv = mitad(arr, pinicial, pfinal);

    do{

        while(arr[i] < piv){

            i++;

        }
        while(arr[j] > piv){

            j--;

        }
        if(i <= j){

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }

    }while(i <= j);

    if( pinicial < j){

        ordenar(arr, pinicial, j);

    }
    if( i< pfinal){

        ordenar(arr, i, pfinal );

    }
}

void registrar_arreglo_inicial(int arr[]){

    ofstream archivo; 
    archivo.open("quicksort.txt");

    archivo << "Este es el arreglo sin ordenar: \n";
    for(int i = 0; i < 8 ; i++){

        archivo << arr[i] << " " ;

    }
    archivo << "\n";
    archivo.close();

}

void registrar_arreglo_final(int arr[])
{

    ofstream archivo;
    archivo.open("quicksort.txt", ios::app);
    archivo << "Este es el arreglo ordenado: \n"; 
    for (int i = 0; i < 8; i++)
    {

        archivo << arr[i] << " ";
    }
    archivo << " \nEl algoritmo utilizado para ordenar los elementos se llama 'quicksort' ";
    archivo.close();
}