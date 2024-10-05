
//libreria
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <chrono>

using namespace std;

//mis prototipos...
void metodoBurbuja(int [],int );
void quickSort(int[], int, int);
int partition(int [], int, int );
void tiempoBurbuja(int a[], int n);
void tiempoQuickSort(int [], int, int);


int main(){
	SetConsoleOutputCP(CP_UTF8);
	int n,op,cantidad;
	
	cout << "Digite la cantidad:\n"; cin >> n;
	int numeros[n];
	int copia[n];
	cout << "Digite el limite del arreglo (¿desde 0 hasta?):\n"; cin >> cantidad;
	srand(time(0));
	for(int i =0;i<n;i++){
		numeros[i]= rand() % (cantidad+1);
	}
	cout <<endl;
	cout << "Arreglo no ordenado.\n";
	for (int i =0;i<n;i++){
		cout << numeros[i]<<" ";
	}
	do{
		//copia de seguridad.
		for(int i =0;i<n;i++){
			copia[i] = numeros[i];
		}
		//fin de copia de seguridad
			
		cout << "\n\n\nBienvenido a la comparacion de dos metodos de ordenamiento"
		<<"\n1. Método de Burbuja."
		<<"\n2. Método de QuickSort."
		<<"\n0.Salir."<<endl;
		cin >>op;
		switch (op){
			case 1:
				tiempoBurbuja(copia,n-1);	
				break;
			
			case 2:
				tiempoQuickSort(copia, 0, n-1);
				break;
		}
	}while(op != 0);
				
	return 0;
}

//primero a comprarar
void metodoBurbuja(int a[], int n) {
	int aux;
	for (int i =0; i<n; i++) {
		for (int j =0; j<n; j++) {
			if (a[j] > a[j+1]) {
				aux = a[j];
				a[j] = a[j+1];
				a[j+1] = aux;
			}
		}
	}
}

void tiempoBurbuja(int a[], int n) {
	auto inicio = chrono::high_resolution_clock::now();	
	metodoBurbuja(a, n);	
	auto fin = chrono::high_resolution_clock::now();
	chrono::duration<double> duracion = fin - inicio;
	cout << "\nArreglo ordenado.\n";
	for (int i =0;i<n;i++){
		cout << a [i]<<" ";
	}
	cout << "\nEl tiempo de ejecucion del algoritmo Burbuja fue de: " <<duracion.count()<<" segundos."<<endl;
}




//segundo a comparar
void quickSort(int A[], int inicio, int final) {
	if (inicio < final) {
		int pivotIndex = partition(A, inicio, final);
		quickSort(A, inicio, pivotIndex - 1); // Lado izquierdo del pivote
		quickSort(A, pivotIndex+1, final);  // Lado derecho del pivote
	}
}

int partition(int A[], int inicio, int final) {
	int pivot = A[final];
	int i = inicio-1;
	int aux;

	for (int j = inicio; j < final; j++) {
		if (A[j] <= pivot) {
			i++;
			aux = A[i];
			A[i] = A[j];
			A[j] = aux;
		}
	}
	aux = A[i+1];
	A[i+1] = A[final];
	A[final] = aux;

	return i+1;
}

void tiempoQuickSort(int A[], int inicio, int final) {
    auto empezar = chrono::high_resolution_clock::now();
    quickSort(A, inicio, final);   
    auto terminar = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = terminar - empezar;  
	cout << "\nArreglo ordenado.\n";
	for (int i =0;i<final;i++){
		cout << A[i]<<" ";
	} 
    cout << "\nEl tiempo de ejecucion del algoritmo QuickSort fue de: " << duracion.count() <<" segundos."<<endl;
}